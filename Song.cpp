#include "Song.h"

#include <iostream>


void Song::print() {
    std::cout << "Song " << songId << " : " << name << " - "<< artist <<std::endl;
}

int Song::getId() const{
    return songId;
}

bool Song::operator==(const Song &other) const {
    return songId == other.songId;
}

Song::Song(int songId, const std::string& name, const std::string& artist)
    : songId(songId), name(name), artist(artist) {}


