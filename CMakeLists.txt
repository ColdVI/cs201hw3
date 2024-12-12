cmake_minimum_required(VERSION 3.30)
project(HW3)

set(CMAKE_CXX_STANDARD 20)

add_executable(HW3 main.cpp
        BilkentBeats.cpp
        BilkentBeats.h
        User.cpp
        User.h
        Song.cpp
        Song.h
        LinkedList.cpp
        LinkedList.h
        Playlist.cpp
        Playlist.h
        Node.cpp
        Node.h
)
