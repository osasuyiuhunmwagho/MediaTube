
#include "MediaFactory.h"

#include <fstream>
#include <limits>


Media* MediaFactory::createMedia(const string& channelTitle, const string& owner, const string& mTitle){
    ifstream mediaFile;
    mediaFile.open("media/media2.txt");
    string temp;
    string mediaTitle, audioContent, category, videoFile;

    while( true ){
        if(!getline(mediaFile, mediaTitle))break;

        if (mediaTitle == mTitle){
            //found the correct Media
            getline(mediaFile, category);
            getline(mediaFile, audioContent);
            getline(mediaFile, videoFile);
        
            // if we have a VideoFactory we have one more element
            return new Media(channelTitle, owner, mediaTitle,  category, audioContent, "videos/"+videoFile);
        }else{
            // We are not interested in this record, so we skip it
            //this is slightly more efficient than reading it into a 
            //string if we don't have to 
            mediaFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            mediaFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            mediaFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');    
        }

    }
    return nullptr;
}

Channel* MediaFactory::createChannel(const string& mediaTitle, const string& owner){
    return new Channel(mediaTitle, owner);
}

Search* MediaFactory::ownerSearch(const string& owner){
    return new O_Search(owner);
}
Search* MediaFactory::categorySearch(const string& category){
    return new C_Search(category);
}
Search* MediaFactory::ownerCatSearch(const string& owner, const string& category){
    return new OorC_Search(owner, category);
}

