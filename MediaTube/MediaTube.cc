#include "MediaTube.h"
#include <iostream>

MediaTube::~MediaTube() {
    for (int i = 0; i < channels.getSize(); ++i) {
        delete channels[i];
    }
}

void MediaTube::addChannel(Channel* channel) { channels += channel; }

void MediaTube::addMedia(Media* media, const std::string& channelTitle) {
    for (int i = 0; i < channels.getSize(); ++i) {
        if (channels[i]->equals(channelTitle)) {
            channels[i]->add(media);
            return;
        }
    }
    std::cerr << "Channel not found: " << channelTitle << std::endl;
}

const Array<Channel*>& MediaTube::getChannels() const { return channels; }

Channel* MediaTube::getChannel(int index) const { return channels[index]; }


Channel* MediaTube::getChannel(const std::string& title) const {
    
    for (int i = 0; i < channels.getSize(); ++i) {
        if (channels[i]->equals(title)) return channels[i];
    }
    std::cerr << "Channel not found: " << title << std::endl;
    exit(1);
}


void MediaTube::getMedia(const Search& search, Array<Media*>& results) const {
    for (int i = 0; i < channels.getSize(); ++i) {

        Channel* channel = channels[i];

        for (int j = 0; j < channel->getSize(); ++j) {
            Media* media = channel->get(j);

            if (search.matches(media)) results += media;
        }
    }
}