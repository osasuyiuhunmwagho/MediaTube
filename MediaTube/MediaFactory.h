#ifndef PODCASTFACTORY_H
#define PODCASTFACTORY_H

#include <iostream>
#include <string>
#include "Channel.h"
#include "Search.h"
#include "Media.h"

using namespace std;

class MediaFactory {
		
	public:

		// create an Media
		Media* createMedia(const string& pod, const string& owner, const string& title);

		// create a Channel
		Channel* createChannel(const string& title, const string& owner);

		// create a Search
		Search* ownerSearch(const string& owner);
		Search* categorySearch(const string& category);
		Search* ownerCatSearch(const string& artist, const string& category);

	
};
#endif