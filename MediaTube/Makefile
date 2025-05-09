objects = main.o View.o Control.o MediaTube.o Channel.o Media.o MediaPlayer.o MediaFactory.o Search.o
testobjects = test.o View.o TestControl.o Tester.o MediaTube.o Channel.o Media.o MediaPlayer.o MediaFactory.o Search.o

all: a4 test

a4: $(objects)
	g++ -o a4 $(objects)

main.o: main.cc Array.h
	g++ -c main.cc 

test: $(testobjects)
	g++ -o test $(testobjects)

test.o: test.cc Array.h
	g++ -c test.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

TestControl.o: TestControl.cc TestControl.h
	g++ -c TestControl.cc

View.o: View.h View.cc Array.h
	g++ -c View.cc

Control.o: Control.h Control.cc Array.h
	g++ -c Control.cc


MediaTube.o: MediaTube.h MediaTube.cc Array.h
	g++ -c MediaTube.cc


Channel.o: Channel.cc Channel.h Array.h
	g++ -c Channel.cc

Media.o: Media.cc Media.h
	g++ -c Media.cc
	
MediaPlayer.o: MediaPlayer.cc MediaPlayer.h
	g++ -c MediaPlayer.cc
	
MediaFactory.o: MediaFactory.cc MediaFactory.h
	g++ -c MediaFactory.cc

Search.o: Search.cc Search.h
	g++ -c Search.cc

clean:
	rm -f a4 *.o	