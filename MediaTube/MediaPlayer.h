#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H
#include <iostream>
class Media;

class MediaPlayer {
public:
    virtual ~MediaPlayer() {}
    virtual void play(std::ostream& ost, const Media& m) const = 0;
};

class AudioPlayer : public MediaPlayer {
public:
    void play(std::ostream& ost, const Media& m) const override;
};


class VideoPlayer : public AudioPlayer {
public:
    void play(std::ostream& ost, const Media& m) const override;
};


const MediaPlayer& operator<<(const MediaPlayer& player, const Media& media);

#endif