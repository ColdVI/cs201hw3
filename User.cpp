#include "User.h"
#include <iostream>

User::User(int userId, const std::string name)
    : userId(userId), name(name) {}

User::User(int usedId) {
    userId = usedId;
}
/*
User::~User() {
    // Need to delete all Playlist objects as User owns them
    Node<Playlist*>* current = playlists.headptr;
    while (current != nullptr) {
        delete current->getItem();
        current = current->getNext();
    }

    }*/
User::~User() {
    // Properly cleanup playlists using the LinkedList's clear method
    playlists->clear();
}



void User::print() {
    std::cout << "User ID : " << userId << ", Name : " << name;

    // Handle playlist printing
    if (playlists->isEmpty()) {
        std::cout << ", Playlist IDs : None";
    } else {
        std::cout << ", Playlist IDs : [";

        // Traverse through playlists
        Node<Playlist>* current = playlists->getNodeAt(0);
        bool isFirst = true;

        while (current != nullptr) {
            if (!isFirst) {
                std::cout << ",";
            }
            std::cout << current->getItem().playlistId;
            isFirst = false;
            current = current->getNext();
        }
        std::cout << "]";
    }
    std::cout << std::endl;
}

bool User::addPlaylist(Playlist playlist) {
    if (!playlists->exists(playlist)) {

        playlists->insertSorted(playlist); // Playlists are unsorted
        return true;
    }
return false;
}

bool User::removePlaylist(Playlist playlistId) {

    Playlist* dummyPtr = &playlistId;
    if (playlists->exists(*dummyPtr)) {
        Node<Playlist>* node = playlists->find(*dummyPtr);
        if (node != nullptr) {
            Playlist toDelete = node->getItem();
            playlists->remove(*dummyPtr);

            return true;
        }
    }
    return false;
}

void User::printPlaylists() const {
    if (playlists->isEmpty()) {
        std::cout << "Playlist IDs: None" << std::endl;
        return;
    }
    std::cout << "Playlist IDs: [";
    playlists->print();
    std::cout << "]" << std::endl;
}

int User::getId() const {
    return userId;
}

bool User::operator==(const User &other) const {
    return userId == other.userId;
}
