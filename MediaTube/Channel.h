#ifndef CHANNEL_H
#define CHANNEL_H
#include "Array.h"
#include "Media.h"
#include <iostream>

class Channel {
    Array<Media*> mediaArray;
    std::string title;
    std::string owner;

public:

    Channel(const std::string& title, const std::string& owner);
    ~Channel();
    bool equals(const std::string& title) const;
    Media* get(int index) const;
    int getSize() const;
    void print(std::ostream& ost) const;
    void printWithMedia(std::ostream& ost) const;
    void add(Media* media);
    friend std::ostream& operator<<(std::ostream& ost, const Channel& channel);

};

#endif