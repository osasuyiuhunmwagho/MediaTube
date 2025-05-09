#include "MediaPlayer.h"
#include "Media.h"
#include <fstream>
#include <string>

void AudioPlayer::play(std::ostream& ost, const Media& m) const {
    ost << m.getAudioContent() << std::endl;
}

void VideoPlayer::play(std::ostream& ost, const Media& m) const {
    AudioPlayer::play(ost, m);
    std::ifstream file(m.getVideoFile());
    std::string line;
    while (getline(file, line)) {
        ost << line << std::endl;
    }
    file.close();
}

const MediaPlayer& operator<<(const MediaPlayer& player, const Media& media) {
    player.play(std::cout, media);
    return player;
}