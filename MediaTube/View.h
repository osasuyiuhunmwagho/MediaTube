#ifndef VIEW_H
#define VIEW_H

#include "Channel.h"
#include "MediaPlayer.h"  
#include "Array.h"
#include <vector>

using namespace std;

class View {
		
	public:
		//constructors
		View();
		void menu(vector<string>&, int& choice);
		void printAllChannels(const Array<Channel*>& channels);
		void channelMenu( const Array<Channel*>& channels, int& choice);
		void printChannel(const Channel*);
		// void mediaMenu(Channel&, int& choice);
        void promptOwner(string& owner);
		void promptCategory(string& category);
		void printPlaylist(Array<Media*>&);
		void playPlaylist(Array<Media*>&);

		void promptVideo();
		void toggleVideo(bool);


	private:
		AudioPlayer audioPlayer;
    	VideoPlayer videoPlayer;
		MediaPlayer* player;	
};
#endif