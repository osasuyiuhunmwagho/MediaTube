#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>

class Media {
private:

    std::string channelTitle;
    std::string owner;
    std::string mediaTitle;
    std::string category;
    std::string audioContent;
    std::string videoFile;

public:

    Media(const std::string& channelTitle, const std::string& owner, const std::string& mediaTitle,
          const std::string& category, const std::string& audioContent, const std::string& videoFile);
    
    std::string getChannelTitle() const;
    std::string getOwner() const;
    std::string getMediaTitle() const;
    std::string getCategory() const;
    std::string getAudioContent() const;
    std::string getVideoFile() const;
    //printfunction
    void print(std::ostream& ost) const;
    //overloading operator
    friend std::ostream& operator<<(std::ostream& ost, const Media& media);
};

#endif