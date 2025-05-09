Name: Osasuyi Uhunmwagho
Student Number: 101301977

Brief Descriptions:
    main.cc – Runs the main program (a4)

    test.cc – Runs the test program (test)

    Media.h / Media.cc – Code for media items like audio or video

    Channel.h / Channel.cc – Code for channels that hold media

    Array.h – A resizable list that can store any type of data

    Search.h / Search.cc – Code for searching media by owner or category

    MediaPlayer.h / MediaPlayer.cc – Plays media with or without video

    MediaTube.h / MediaTube.cc – Manages all channels and media

    View.h / View.cc – Handles input and output with the user

    Control.h / Control.cc – Connects the view and the backend

    TestControl.h / TestControl.cc – Test code for checking if things work
    MediaFactory.h – Makes media and search objects 

    Tester.h / Tester.cc – Extra test tools

    Makefile – Used to build the project
To compile both of the executables:

    - make

    To run the main app:
        - ./a4
    To run the tests:
        - ./test

Note: i included #fstream in TestControl.cc to make it work