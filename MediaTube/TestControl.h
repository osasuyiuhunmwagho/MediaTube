#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <sstream>
#include "MediaTube.h"
#include "View.h"
#include "Tester.h"
#include "MediaFactory.h"

using namespace std;

class TestControl {
		
	public:
		void launch();
	
	private:
		void initChannels(MediaTube& mediaTube, vector<string>& channels, vector<string>& owners);
		void initWithMedia(MediaTube& mediaTube, 
						vector<string>& channels, 
						vector<string>& owners, 
						vector<string>& mediaTitles);
		// vector<string> menu ={
		// 	"Test add and print Channels",
		// 	"Test add and print Media",
		// 	"Test get Media by owner",
		// 	"Test get Media by category",
		// 	"Test get Media by owner or category",
		// 	"Test print current media list",
		// 	"Test play current media list",
		// 	"Test all and get mark"
		// };
		int testAddChannels();
		int testAddMedia();
		int testGetMediaByOwner();
		int testGetMediaByCategory();
		int testGetMediaByOwnerAndCategory();
		// int testPrintCurrentMediaList();
		int testPlayCurrentMediaList();
		int testAllAndMark();

		

		View view;
		Tester tester;
		MediaFactory mf;	

		
	
};
#endif