
#include "TestControl.h"
#include <limits>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Search.h"

using namespace std;

void TestControl::launch(){

    vector<string> menu ={
        "Test add and print Channels",
        "Test add and print Media",
        "Test get Media by owner, and test print media from View class",
        "Test get Media by category",
        "Test get Media by owner or category",
        //"Test print current media list",
        "Test play current media list with video",
        "Test all and get mark"
    };

    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        tester.clearInputBuffer();
        switch(choice){
            case 1: tester.recordMark(1, testAddChannels()); break;
            case 2: tester.recordMark(2, testAddMedia()); break;
            case 3: tester.recordMark(3, testGetMediaByOwner()); break;
            case 4: tester.recordMark(4, testGetMediaByCategory()); break;
            case 5: tester.recordMark(5, testGetMediaByOwnerAndCategory()); break;
            // case 6: testPrintCurrentMediaList(); break;
            case 6: tester.recordMark(6, testPlayCurrentMediaList()); break;
            case 7: tester.recordMark(7, testAllAndMark(), 22); break;
        }
    }
    std::cout<<"exiting program!!!"<<endl;
}

void TestControl::initChannels(MediaTube& mediaTube,vector<string>& channels, vector<string>& owners){
    ifstream mediaFile;
    mediaFile.open("media/media.txt");
    string channel, owner, temp;
    string title, audioContent, category, videoFile;
    int numMedia = 0;

    while( true ){
        if(!getline(mediaFile, channel))break;
        getline(mediaFile, owner);
        getline(mediaFile, temp);
        numMedia = stoi(temp);
        //this one should be an integer representing the 
        //number of media on this channel
        mediaTube.addChannel(mf.createChannel(channel, owner));
        // we will use these vectors to test the output
        channels.push_back(channel);
        owners.push_back(owner);
        for (int i = 0; i < numMedia; ++i){
            getline(mediaFile, title);
            // we skip adding the media to the channel
            // but we still have to read in the titles
        }
        
    }

    mediaFile.close();
}

void TestControl::initWithMedia(MediaTube& mediaTube,
                            vector<string>& channels, 
                            vector<string>& owners, 
                            vector<string>& mediaTitles){
    ifstream mediaFile;
    mediaFile.open("media/media.txt");
    string channel, owner, temp;
    string title, audioContent, category, videoFile;
    int numMedia = 0;

    while( true ){
        if(!getline(mediaFile, channel))break;
        getline(mediaFile, owner);

        getline(mediaFile, temp);
        numMedia = stoi(temp);
        mediaTitles.push_back(channel);
        mediaTitles.push_back(temp); //the number of media stored as a string
        channels.push_back(channel);
        owners.push_back(owner);
        mediaTube.addChannel(mf.createChannel(channel, owner));
        for (int i = 0; i < numMedia; ++i){
            getline(mediaFile, title);
            Media* media = mf.createMedia(channel, owner, title);
            if (media == nullptr){
                cout<<"WARNING*** Media "<<title<< " not found"<<endl;
                continue;
            }else{
                mediaTitles.push_back(title);
            }
            mediaTube.addMedia(media, channel);
        }
        
    }
    mediaFile.close();
    
}

int TestControl::testAddChannels(){
    cout<<"Testing addChannels()"<<endl;
    MediaTube mediaTube;
    vector<string> channels;
    vector<string> owners;
    initChannels(mediaTube, channels, owners);

    cout<<endl<<"Printing all channels"<<endl<<endl;
    tester.initCapture();
    view.printAllChannels(mediaTube.getChannels());
    tester.endCapture();

    int error = 0;
    tester.find(channels, error);
    if (error>0){
        cout<<"Error: "<<error<<" channels not found"<<endl;
    }else{
        cout<<"All channel titles found"<<endl;
    }
    tester.find(owners, error);
    if (error>0){
        cout<<"Error: "<<error<<" owners not found"<<endl;
    }else{
        cout<<"All owners found"<<endl;
    }

    int mark = 2 - error;
    if (mark < 0)mark = 0;

    mark += 1; // Your code didn't crash - congrats!

    cout<<"Test complete, mark: "<<mark<<"/3"<<endl;
    return mark;
}

int TestControl::testAddMedia(){
    cout<<"Testing addMedia()"<<endl;
    MediaTube mediaTube;
    vector<string> channels;
    vector<string> owners;
    vector<string> mediaTitles;
    initWithMedia(mediaTube, channels, owners, mediaTitles);

    cout<<endl<<"Printing channels with media"<<endl<<endl;
    int errors = 0;
    int index = 0;
    for (int i = 0; i < mediaTube.getChannels().getSize(); ++i){
        tester.initCapture();
        mediaTube.getChannel(i)->printWithMedia(cout);
        tester.endCapture();

        string channel = mediaTitles[index++];
        // cout<<"stoi "<<mediaTitles[index]<<endl;   
        int numEps = stoi(mediaTitles[index++]);
        vector<string> media;
        for (int j = 0; j < numEps; ++j){
            media.push_back(mediaTitles[index++]);
        }
        int error = 0;
        tester.find(media, error);
        if (error>0){
            cout<<"Error: "<<error<<" media not found"<<endl;
        }else{
            cout<<"All media found for "<<channel<<endl;
        }
        errors += error;
    }

    int mark = 2 - errors;
    if (mark < 0)mark = 0;
    mark += 1; // Your code didn't crash - congrats!
    cout<<"Test complete, mark: "<<mark<<"/3"<<endl;
    return mark;
   
}

int TestControl::testGetMediaByOwner(){
    cout<<"Testing get media by owner and playPlaylist"<<endl;
    MediaTube mediaTube;
    vector<string> channels;
    vector<string> owners;
    vector<string> mediaTitles;
    initWithMedia(mediaTube, channels, owners, mediaTitles);

    string owners[] = {"Bif", "Elsa", "Weird Al", "Pat", "Dave Grohl"};
    vector<int> findOwners;
    int numOwners = 5;
    tester.ran(findOwners, 2, numOwners);

    vector<string> absentOwners;
    for (int i = 0; i < owners.size(); ++i){
        if (find(findOwners.begin(), findOwners.end(), i) == findOwners.end()){
            absentOwners.push_back(owners[i]);
        }
    }
    
    int errors = 0;

    for (vector<int>::iterator it = findOwners.begin(); it != findOwners.end(); ++it){
        
        int owner = *it;
        Search* search = mf.ownerSearch(owners[owner]);
        Array<Media*> media;
        mediaTube.getMedia(*search, media);
        delete search;
        cout<<"Printing media by owner "<<owners[owner]<<endl;
        tester.initCapture();
        view.playPlaylist(media);
        tester.endCapture();

        int errors = 0;
        vector<string> titles;
        titles.push_back(owners[owner]);
        // this should gather all the media titles with this owner
        for (int i = 0; i < mediaTitles.size(); ++i){
            if (mediaTitles[i] == owners[owner]){
                int numEps = stoi(mediaTitles[++i]);
                for (int j = 0; j < numEps; ++j){
                    titles.push_back(mediaTitles[++i]);
                }
                break;
            }
        }
        tester.find(titles, errors);
        if (errors>0){
            cout<<"Error: "<<errors<<" media not found"<<endl;
        }else{
            cout<<"All media found for "<<owners[owner]<<endl;
        }

        tester.confirmAbsent(absentOwners, errors);
        if (errors>0){
            cout<<"Error: "<<errors<<" media found for absent owners"<<endl;
        }else{
            cout<<"No media found for absent owners"<<endl;
        }
    }

    int mark = 4 - errors;
    if (mark < 0)mark = 0;
    mark += 1; // Your code didn't crash - congrats!
    cout<<"Test complete, mark: "<<mark<<"/5"<<endl;
    return mark;
}

int TestControl::testGetMediaByCategory(){
    cout<<"Testing get media by category - choosing 2 categories at random"<<endl;
    MediaTube mediaTube;
    vector<string> channels;
    vector<string> owners;
    vector<string> mediaTitles;
    initWithMedia(mediaTube, channels, owners, mediaTitles);

    string categories[] = {"History", "Local", "R&B", "Parody", "Grunge", "Politics", "Health"};
    int numEachCat[] = {4, 1, 5, 5, 2, 1, 2};
    
    vector<int> findCats;
    int numCats = 7;
    tester.ran(findCats, 2, numCats);
    
    int errors = 0;

    for (vector<int>::iterator it = findCats.begin(); it != findCats.end(); ++it){
        int cat = *it;    
    
        Search* search = mf.categorySearch(categories[cat]);
        Array<Media*> media;
        mediaTube.getMedia(*search, media);
        delete search;
        cout<<"Printing media by category "<<categories[cat]<<endl;
        view.playPlaylist(media);

        

        if (media.getSize() != numEachCat[cat]){
            cout<<"Error: "<<numEachCat[cat]<<" media expected, "<<media.getSize()<<" found"<<endl;
            errors++;
        }
        
        for (int i = 0; i < media.getSize(); ++i){
            if (media[i]->getCategory() != categories[cat]){
                errors++;
            }
        }
        if (errors>0){
            cout<<"Error: "<<errors<<" incorrect categories found"<<endl;
        }else{
            cout<<"All media found for "<<categories[cat]<<endl;
        }

    }

    int mark = 2 - errors;
    if (mark < 0)mark = 0;

    mark += 1; // Your code didn't crash - congrats!

    cout<<"Test complete, mark: "<<mark<<"/3"<<endl;
    return mark;
}

int TestControl::testGetMediaByOwnerAndCategory(){
    cout<<"Testing get media by owner or category - choosing 2 categories at random"<<endl;
    MediaTube mediaTube;
    vector<string> channels;
    vector<string> owners;
    vector<string> mediaTitles;
    initWithMedia(mediaTube, channels, owners, mediaTitles);

    string categories[] = {"History", "Local", "R&B", "Parody", "Grunge", "Politics", "Health"};
    int numEachCat[] = {4, 1, 5, 5, 2, 1, 2};
    
    int numCats = 7;
    int cat = tester.ran(0, numCats);
    int numOwners = 5;
    int owner = tester.ran(0, numOwners);
    
    int errors = 0;

    
    Search* search = mf.ownerCatSearch(owners[owner],categories[cat]);
    Array<Media*> media;
    mediaTube.getMedia(*search, media);
    delete search;
    cout<<"Printing media by owner "<<owners[owner]<<" or category "<<categories[cat]<<endl;
    view.playPlaylist(media);

    
    
    for (int i = 0; i < media.getSize(); ++i){
        if (media[i]->getCategory() != categories[cat] && media[i]->getOwner() != owners[owner]){
            errors++;
        }
    }
    if (errors>0){
        cout<<"Error: "<<errors<<" incorrect categories or owners found"<<endl;
    }else{
        cout<<"All media found for "<<categories[cat]<<" or "<<owners[owner]<<endl;
    }



    int mark = 4 - errors;
    if (mark < 0)mark = 0;
    mark += 1; // Your code didn't crash - congrats!

    cout<<"Test complete, mark: "<<mark<<"/5"<<endl;
    return mark;
}

// int TestControl::testPrintCurrentMediaList(){

// }

int TestControl::testPlayCurrentMediaList(){
    vector<string> toFind = {"[[[[]", "[[[[]", "(~v~)",
                            ",'SSt`.", "<( ^.^ )"
                            };
    cout<<"Testing get media by owner and playPlaylist"<<endl;
    MediaTube mediaTube;
    vector<string> channels;
    vector<string> owners;
    vector<string> mediaTitles;
    initWithMedia(mediaTube, channels, owners, mediaTitles);

    string owner= "Bif";
    
    Search* search = mf.ownerSearch(owner);
    Array<Media*> media;
    mediaTube.getMedia(*search, media);
    delete search;
    for (int i = 0; i < media.getSize(); ++i){
        cout<<media[i]->getVideoFile()<<endl;
    }
    view.toggleVideo(true);
    cout<<"Playing media (with videoFile) by owner "<<owner<<endl;
    tester.initCapture();
    view.playPlaylist(media);
    tester.endCapture();
    view.toggleVideo(false);
    int errors = 0;

    tester.find(toFind, errors);

    if (errors>0){
        cout<<"Error: "<<errors<<" videoFiles not found"<<endl;   
    }else{
        cout<<"Evidence of videoFiles found"<<endl;
    }
    

    

    int mark = 2 - errors;
    if (mark < 0)mark = 0;
    mark += 1; // Your code didn't crash - congrats!

    cout<<"Test complete, mark: "<<mark<<"/3"<<endl;
    return mark;
}

int TestControl::testAllAndMark(){
    int mark = 0;
    mark += testAddChannels();
    mark += testAddMedia();
    mark += testGetMediaByOwner();
    mark += testGetMediaByCategory();
    mark += testGetMediaByOwnerAndCategory();
    // mark += testPrintCurrentMediaList();
    mark += testPlayCurrentMediaList();
    return mark;
}



