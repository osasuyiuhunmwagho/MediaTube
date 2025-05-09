
#include "Control.h"
#include "View.h"
#include <fstream>
#include <limits>
#include <vector>

void Control::launch(){
    cout<<"Launching..."<<endl;
    initFromFile();
    cout<<"Done initializing"<<endl;
    int choice = -1;

    // This is what the View shows:
    // cout << "What would you like to do?"<< endl;
    // cout << "  (1) Show all Channels" << endl;
    // cout << "  (2) Show single Channel" << endl;
    // cout << "  (3) Get media by owner" << endl;
    // cout << "  (4) Get media by category" << endl;
    // cout << "  (5) Get media by owner or category" << endl;
    // cout << "  (6) Print current media list" << endl;
    // cout << "  (7) Play current media list" << endl;
    // cout << "  (8) Toggle video" << endl;
    // cout << "  (0) Exit" << endl<<endl;

    while (true){
        choice = -1;
        vector<string> menu ={
            "Show all Channels",
            "Show single Channel",
            "Get media by owner",
            "Get media by category",
            "Get media by owner or category",
            "Print current media list",
            "Play current media list",
            "Toggle video"
        };
        view.menu(menu, choice);
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
        if (choice == 0)break;
        switch (choice)
        {
            case 1: showAllChannels(); break;
            case 2: showSingleChannel(); break;
            case 3: getMediaByH(); break;
            case 4: getMediaByC(); break;
            case 5: getMediaByHandC(); break;
            case 6: printCurrentMedia(); break;
            case 7: playCurrentMedia(); break;
            case 8: toggleVideo(); break;
        }
        
    }

    cout << "Good-bye!"<<endl;
}



void Control::initFromFile(){
    ifstream mediaFile;
    mediaFile.open("media/media.txt");
    string channel, owner, temp;
    string title, content, category, video;
    int numMedia = 0;

    while( true ){
        if(!getline(mediaFile, channel))break;
        getline(mediaFile, owner);

        getline(mediaFile, temp);
        numMedia = stoi(temp);
        //this one should be an integer representing the 
        //number of media on this channel
        mt.addChannel(mf.createChannel(channel, owner));
        for (int i = 0; i < numMedia; ++i){
            getline(mediaFile, title);
            Media* media = mf.createMedia(channel, owner, title);
            if (media == nullptr){
                cout<<"WARNING*** Media "<<title<< " not found"<<endl;
                continue;
            }
            mt.addMedia(media, channel);
        }
        
    }

    mediaFile.close();
    
}

void Control::showAllChannels(){
    cout<<"Showing all channels: "<<endl;
    view.printAllChannels(mt.getChannels());
}

void Control::showSingleChannel(){
    int choice = - 1;
    view.channelMenu(mt.getChannels(), choice);
    Channel* channel = mt.getChannel(choice);
    view.printChannel(channel);
}

void Control::getMediaByH(){
    string owner;
    view.promptOwner(owner);
    Search* search = mf.ownerSearch(owner);
    playlist.clear();
    mt.getMedia(*search, playlist);
    delete search;
} 
void Control::getMediaByC(){
    string cat;
    view.promptCategory(cat);
    Search* search = mf.categorySearch(cat);
    playlist.clear();
    mt.getMedia(*search, playlist);
    delete search;
} 
void Control::getMediaByHandC(){
    string owner, cat;
    view.promptOwner(owner);
    view.promptCategory(cat);
    Search* search = mf.ownerCatSearch(owner, cat);
    playlist.clear();
    mt.getMedia(*search, playlist);
    delete search;
} 
void Control::printCurrentMedia(){
    cout<<"Playlist size: "<<playlist.getSize()<<endl;
    view.printPlaylist(playlist);
} 
void Control::playCurrentMedia(){
    view.playPlaylist(playlist);
}
void Control::toggleVideo(){
    view.promptVideo();
}