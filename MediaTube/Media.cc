#include "Media.h"
#include <iostream>

Media::Media(const std::string& channelTitle, const std::string& owner, const std::string& mediaTitle,
             const std::string& category, const std::string& audioContent, const std::string& videoFile)
    : channelTitle(channelTitle), owner(owner), mediaTitle(mediaTitle), category(category),
      audioContent(audioContent), videoFile(videoFile) {}

std::string Media::getChannelTitle() const { return channelTitle; }
std::string Media::getOwner() const { return owner; }

std::string Media::getMediaTitle() const { return mediaTitle; }
std::string Media::getCategory() const { return category; }

std::string Media::getAudioContent() const { return audioContent; }
std::string Media::getVideoFile() const { return videoFile; }

void Media::print(std::ostream& ost) const {

    ost << "Channel Title: " << channelTitle << "\n"
        << "Owner: " << owner << "\n"
        << "Category: " << category << "\n"
        << "Media Title: " << mediaTitle << std::endl;
}

std::ostream& operator<<(std::ostream& ost, const Media& media) {
    
    media.print(ost);
    return ost;
}