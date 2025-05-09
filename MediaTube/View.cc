
#include "View.h"
#include <limits>
#include <vector>

View::View() : player(&audioPlayer){
  
}

void View::menu(vector<string>& menu, int& choice)
{
  cout << endl;
  cout << "Please make a selection:"<< endl<<endl;
  for (int i = 0; i < menu.size(); ++i){
    cout<<"  ("<<i+1<<") "<<menu[i]<<endl;
  }
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > menu.size()) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}


void View::printAllChannels(const Array<Channel*>& channels){
  for (int i = 0; i < channels.getSize(); ++i){
    cout <<i+1<<": " << *channels[i] <<endl;
  } 
}

void View::printChannel(const Channel* channel){
    channel->printWithMedia(cout);
}

void View::channelMenu(const Array<Channel*>& channels, int& choice){
  int numOptions = channels.getSize();

  printAllChannels(channels);

  cout << endl;
  cout << "Choose an channel"<< endl;
  cout << "or select (0) to exit" << endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
  --choice;
}


void View::promptOwner(string& owner){
    cout <<"Enter owner: ";
    char str[80];
    cin.clear();
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(str, 80);
    owner = str;
    // cin >> owner;
}
		
void View::promptCategory(string& category){
    cout <<"Enter category: ";
    char str[80];
    cin.clear();
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(str, 80);
    category = str;
    // cin >> category;
  
}

void View::printPlaylist(Array<Media*>& media){
  for (int i = 0; i < media.getSize(); ++i){
      cout<<*media[i]<<endl;
  }
}

void View::playPlaylist(Array<Media*>& media){
  cout <<"Playing playlist size "<<media.getSize()<<endl;;
  for (int i = 0; i < media.getSize(); ++i){
      cout << endl << *media[i] <<endl;
      (*player) << *media[i];
      cout<<endl;
  }
}

void View::promptVideo(){
  int numOptions = 2;
  int choice = -1;

  cout << endl;
  cout << "  (0) Exit (no change)" << endl;
  cout << "  (1) Audio player only" << endl;
  cout << "  (2) Audio and Video player" << endl <<endl;

  cout << "Enter your selection: ";

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

  toggleVideo(choice == 2);
}

void View::toggleVideo(bool video){
  // TODO complete this function
  if (video) {
    player = &videoPlayer;
  } else {
    player = &audioPlayer;
  }
}

