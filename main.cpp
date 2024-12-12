#include <iostream>

#include "BilkentBeats.h"
using namespace std;

int main() {
    BilkentBeats bilkentBeats;
    bilkentBeats.addSong(45, "Stairway to Heaven"
    ,
    "Led Zeppelin");
    bilkentBeats.addSong(42, "Billie Jean","Michael Jackson");
    bilkentBeats.addSong(43, "Hotel California","Eagles");
    bilkentBeats.addSong(48, "Imagine","John Lennon");
    bilkentBeats.addSong(42, "Bohemian Rhapsody","Queen");
    cout<<endl;
    bilkentBeats.printSongs();
    cout<<endl;
    bilkentBeats.addUser(26, "Ebru");
    bilkentBeats.addUser(21, "Bora");
    bilkentBeats.addUser(29, "Melda");
    bilkentBeats.addUser(25, "Filiz");
    bilkentBeats.addUser(21, "Bugra");
    cout<<endl;
    bilkentBeats.addPlaylist(21,16);
    bilkentBeats.addPlaylist(21,18);
    bilkentBeats.addPlaylist(26,19);
    bilkentBeats.addPlaylist(29,15);
    bilkentBeats.addPlaylist(26,16);
    bilkentBeats.addPlaylist(49,13);
    cout<<endl;
    bilkentBeats.printUsers();
    cout<<endl;
    bilkentBeats.addSongToPlaylist(16,45);
    bilkentBeats.addSongToPlaylist(19,45);
    bilkentBeats.addSongToPlaylist(19,43);
    bilkentBeats.addSongToPlaylist(18,42);
    bilkentBeats.addSongToPlaylist(16,45);
    bilkentBeats.addSongToPlaylist(86,43);
    bilkentBeats.addSongToPlaylist(16,86);
    cout<<endl;
    bilkentBeats.printSongsInPlaylist(16);
    cout<<endl;
    bilkentBeats.printSongsInPlaylist(19);
    cout<<endl;
    bilkentBeats.printSongsInPlaylist(18);
    cout<<endl;
    bilkentBeats.printSongsInPlaylist(65);
    cout<<endl;
    bilkentBeats.removeSong(48);
    bilkentBeats.removeSong(45);
    bilkentBeats.removeSong(95);
    cout<<endl;
    bilkentBeats.printSongsInPlaylist(19);
    cout<<endl;
    bilkentBeats.printSongsInPlaylist(18);
    cout<<endl;
    bilkentBeats.printSongsInPlaylist(16);
    cout<<endl;
    bilkentBeats.removePlaylist(26,19);
    bilkentBeats.removePlaylist(26,15);
    bilkentBeats.removePlaylist(92,16);
    cout<<endl;
    bilkentBeats.removeSongFromPlaylist(18,42);
    bilkentBeats.removeSongFromPlaylist(19,43);
    bilkentBeats.removeSongFromPlaylist(18,85);
    cout<<endl;
    bilkentBeats.removeUser(21);
    bilkentBeats.removeUser(25);
    bilkentBeats.removeUser(95);
    cout<<endl;
    bilkentBeats.printUsers();
    cout<<endl;
    bilkentBeats.printSongs();
    cout<<endl;
    bilkentBeats.removeUser(26);
    bilkentBeats.removeUser(29);
    bilkentBeats.removeSong(42);
    bilkentBeats.removeSong(43);
    cout<<endl;
    bilkentBeats.printUsers();
    cout<<endl;
    bilkentBeats.printSongs();
    return 0;
}