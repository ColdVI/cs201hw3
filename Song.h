#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
public:
    int songId{};
    std::string name;
    std::string artist;
    void print();
    int getId() const;
    bool operator==(const Song& other) const;
    Song(int songId, const std::string& name, const std::string& artist);

};

#endif // SONG_H
