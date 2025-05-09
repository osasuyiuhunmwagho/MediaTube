#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include "MediaTube.h"
#include "View.h"
#include "MediaFactory.h"

using namespace std;

class Control {
		
	public:
				
		void launch();
	
	private:
		void initFromFile();
		void showAllChannels();
		void showSingleChannel();
		void getMediaByH(); 
		void getMediaByC(); 
		void getMediaByHandC(); 
		void printCurrentMedia(); 
		void playCurrentMedia(); 
		void toggleVideo(); 
		View view;
		MediaTube mt;
		MediaFactory mf;
		Array<Media*> playlist;

	
};
#endif