#pragma once
#include "LinkedList.h"
#include "Playlist.h"
#ifndef USER_H
#define USER_H
class User {
public:
    int userId;
    std::string name;
    LinkedList<Playlist>* playlists; // Use LinkedList for managing playlists

    User(int userId, const std::string name);
    User(int usedId);
    ~User();
    void print();
    bool addPlaylist(Playlist playlist);
    bool removePlaylist(const Playlist playlistId);
    void printPlaylists() const;
    int getId() const;
    bool operator==(const User& other) const;
};
#endif