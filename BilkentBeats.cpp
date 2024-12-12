#include "BilkentBeats.h"
#include <string>
#include "User.h"
#include "Song.h"
#include "Playlist.h"
#include "LinkedList.h"
#include <iostream>

BilkentBeats::BilkentBeats() {}

BilkentBeats::~BilkentBeats() {
    // Clean up users and their playlists
    Node<User>* currentUser = users.headptr;
    while (currentUser != nullptr) {
        User user = currentUser->getItem();

        // Clean up playlists for each user
        Node<Playlist>* currentPlaylist = user.playlists->headptr;
        while (currentPlaylist != nullptr) {
            Playlist playlist = currentPlaylist->getItem();
            // No need to delete songs in playlist as they're just pointers to songs in the main list

            currentPlaylist = currentPlaylist->next;
        }


        currentUser = currentUser->next;
    }

    // Clean up songs
    Node<Song>* currentSong = songs.headptr;
    while (currentSong != nullptr) {

        currentSong = currentSong->next;
    }
}


void BilkentBeats::addUser(const int userId, const std::string userName) {
    User* newUser = new User(userId, userName);
    if (users.exists(*newUser)) {
        delete newUser;
        std::cout << "Cannot add user. There is already a user with ID " << userId << "." << std::endl;
        return;
    }
    users.insertSorted(*newUser);
    std::cout << "Added user " << userId << "." << std::endl;
}

void BilkentBeats::removeUser(const int userId) {
    User* dummyUser = new User(userId, "");
    if (users.remove(*dummyUser)) {
        delete dummyUser;
        std::cout << "Removed user " << userId << "." << std::endl;
    } else {
        delete dummyUser;
        std::cout << "Cannot remove user. There is no user with ID " << userId << "." << std::endl;
    }
}

void BilkentBeats::printUsers() const {
    if (users.isEmpty()) {
        std::cout << "There are no users to show." << std::endl;
        return;
    }

    std::cout << "Users in the system:" << std::endl;
    Node<User>* current = users.getNodeAt(0);


    while (current != nullptr) {


        current->getItem().print();
        current = current->getNext();

    }
}

void BilkentBeats::addSong(const int songID, const std::string songName, const std::string artists) {
    Song* newSong = new Song(songID, songName, artists);
    if (songs.exists(*newSong)) {
        delete newSong;  // Clean up if song already exists
        std::cout << "Cannot add song. BilkentBeats already contains song " << songID << "." << std::endl;
        return;
    }
    songs.insertSorted(*newSong);
    std::cout << "Added song " << songID << "." << std::endl;
}

void BilkentBeats::removeSong(const int songId) {
    Song temp(songId, "", "");
    if (!songs.exists(temp)) {
        std::cout << "Cannot remove song. There is no song with ID " << songId << "." << std::endl;
        return;
    }

    Song songToRemove = songs.find(temp)->getItem();

    // Remove from all playlists first
    for (int i = 0; i < users.getLength(); i++) {
        User user = users.getNodeAt(i)->getItem();
        for (int j = 0; j < user.playlists->getLength(); j++) {
            Playlist playlist = user.playlists->getNodeAt(j)->getItem();
            playlist.songIds->remove(songToRemove);
        }
    }

    // Remove and delete the song
    songs.remove(songToRemove);

    std::cout << "Removed song " << songId << "." << std::endl;
}

void BilkentBeats::printSongs() const {
    if (songs.isEmpty()) {
        std::cout << "Cannot print songs. There is no song in the music library." << std::endl;
        return;
    }
    std::cout << "Music Library:" << std::endl;
    songs.print();
}

void BilkentBeats::addPlaylist(const int userId, const int playlistId) {
    // Check if user exists
    User tempUser(userId, "");  // Create temporary user for comparison
    Node<User>* userNode = users.find(tempUser);

    if (!userNode) {
        std::cout << "Cannot add playlist. There is no user with ID " << userId << "." << std::endl;
        return;
    }

    // Create temporary playlist for existence check
    Playlist tempPlaylist(playlistId);

    // Check all users for duplicate playlist ID
    Node<User>* current = users.headptr;
    while (current != nullptr) {
        if (current->getItem().playlists->exists(tempPlaylist)) {
            std::cout << "Cannot add playlist. There is a user having a playlist with ID " << playlistId << "." << std::endl;
            return;
        }
        current = current->getNext();
    }

    // Create new playlist and add it
    Playlist* newPlaylist = new Playlist(playlistId);

   bool success = userNode->getItem().addPlaylist(*newPlaylist);

    if (!success) {

        std::cout << "Failed to add playlist " << playlistId << "." << std::endl;
        return;
    }

    std::cout << "Added playlist " << playlistId << " to user " << userId << "." << std::endl;
}

void BilkentBeats::removePlaylist(const int userId, const int playlistId)  {
    User tempUser(userId);
    Node<User>* userNode = users.find(tempUser);

    if (!userNode) {
        std::cout << "Cannot remove playlist. There is no user with ID " << userId << "." << std::endl;
        return;
    }

    Playlist tempPlaylist(playlistId);

    Node<Playlist>* playlistNode = userNode->getItem().playlists->find(tempPlaylist);


    if (playlistNode != nullptr) {
    std::cout<<"Cannot remove playlist. There is no playlist with ID " << playlistId << "." << std::endl;
    }
    if (userNode->getItem().removePlaylist(tempPlaylist)) {

        std::cout << "Removed playlist " << playlistId << " from user " << userId << "." << std::endl;
    } else {
        std::cout << "Cannot remove playlist. User " << userId << " does not have a playlist with ID " << playlistId << "." << std::endl;
    }
}

void BilkentBeats::addSongToPlaylist(const int playlistId, const int songId) {
    // First verify the song exists
    Song tempSong(songId, "", "");
    if (!songs.exists(tempSong)) {
        std::cout << "Cannot add song. There is no song with ID " << songId << "." << std::endl;
        return;
    }

    // Get the actual song pointer
    Song songToAdd = songs.find(tempSong)->getItem();

    // Look for the playlist
    Playlist tempPlaylist(playlistId);
    bool playlistFound = false;

    // Search through all users to find the playlist
    for (int i = 0; i < users.getLength(); i++) {
        User currentUser = users.getNodeAt(i)->getItem();
        if (currentUser.playlists->exists(tempPlaylist)) {
            // Found the playlist
            Playlist targetPlaylist = currentUser.playlists->find(tempPlaylist)->getItem();

            // Check if song is already in the playlist
            if (targetPlaylist.songIds->exists(songToAdd)) {
                std::cout << "Cannot add song. The playlist already contains song " << songId << "." << std::endl;
                return;
            }

            // Add song to playlist
            targetPlaylist.songIds->insert(songToAdd);
            std::cout << "Added song " << songId << " to playlist " << playlistId << "." << std::endl;
            return;
        }
    }

    // If we get here, the playlist wasn't found
    std::cout << "Cannot add song. There is no playlist with ID " << playlistId << "." << std::endl;
}

void BilkentBeats::removeSongFromPlaylist(const int playlistId, const int songId) {
    Song tempSong(songId, "", "");
    Playlist tempPlaylist(playlistId);

    // Find the playlist first
    for (int i = 0; i < users.getLength(); i++) {
        User currentUser = users.getNodeAt(i)->getItem();
        Node<Playlist>* playlistNode = currentUser.playlists->find(tempPlaylist);

        if (playlistNode) {
            // Found the playlist, now try to remove the song
            if (playlistNode->getItem().songIds->remove(tempSong)) {
                std::cout << "Removed song " << songId << " from playlist " << playlistId << "." << std::endl;
                return;
            } else {
                std::cout << "Cannot remove song. There is no song " << songId << " in playlist " << playlistId << "." << std::endl;
                return;
            }
        }
    }

    // If we get here, playlist wasn't found
    std::cout << "Cannot remove song. There is no playlist with ID " << playlistId << "." << std::endl;
}

void BilkentBeats::printSongsInPlaylist(const int playlistId) const {
    Playlist tempPlaylist(playlistId);

    // Search through all users to find the playlist
    for (int i = 0; i < users.getLength(); i++) {
        User currentUser = users.getNodeAt(i)->getItem();
        Node<Playlist>* playlistNode = currentUser.playlists->find(tempPlaylist);

        if (playlistNode) {
            // Found the playlist, print its songs
            Playlist playlist = playlistNode->getItem();
            if (playlist.songIds->isEmpty()) {
                std::cout << "There are no songs to show in playlist " << playlistId << "." << std::endl;
            } else {
                std::cout << "Songs in playlist " << playlistId << ":" << std::endl;
                playlist.printSongs();
            }
            return;
        }
    }

    // If we get here, playlist wasn't found
    std::cout << "Cannot print songs. There is no playlist with ID " << playlistId << "." << std::endl;
}