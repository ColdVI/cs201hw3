#ifndef BILKENTBEATS_H
#define BILKENTBEATS_H

#include <string>
#include "User.h"
#include "Song.h"
#include "Playlist.h"
#include "LinkedList.h"

class BilkentBeats {
private:


public:
    BilkentBeats();
    ~BilkentBeats();
    LinkedList<User> users;
    LinkedList<Song> songs;

    void addUser(const int userId, const std::string userName);
    void removeUser(const int userId);
    void printUsers() const;

    void addSong(const int songID, const std::string songName, const std::string artists);
    void removeSong(const int songID);
    void printSongs() const;

    void addPlaylist(const int userId, const int playlistId);
    void removePlaylist(const int userId, const int playlistId);
    void addSongToPlaylist(const int playlistId, const int songId);
    void removeSongFromPlaylist(const int playlistId, const int songId);
    void printSongsInPlaylist(const int playlistId) const;


};



#endif // BILKENTBEATS_H
