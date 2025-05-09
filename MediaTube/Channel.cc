#include "Channel.h"
#include <iostream>

Channel::Channel(const std::string& title, const std::string& owner) : title(title), owner(owner) {}

Channel::~Channel() {
    for (int i = 0; i < mediaArray.getSize(); ++i) {
        delete mediaArray[i];
    }
}

bool Channel::equals(const std::string& title) const { return this->title == title; }


Media* Channel::get(int index) const { return mediaArray[index]; }


int Channel::getSize() const { return mediaArray.getSize(); }


void Channel::print(std::ostream& ost) const {
    ost << "Channel: " << title << " (Owner: " << owner << ")";
}


void Channel::printWithMedia(std::ostream& ost) const {

    print(ost);
    
    for (int i = 0; i < mediaArray.getSize(); ++i) {
        ost << *mediaArray[i] << std::endl;
    }
}

void Channel::add(Media* media) { mediaArray += media; }

std::ostream& operator<<(std::ostream& ost, const Channel& channel) {
    channel.print(ost);
    return ost;
}