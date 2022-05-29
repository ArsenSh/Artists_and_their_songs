#ifndef Header_h
#define Header_h
#include <vector>

class Song
{
private:
    std::string song_name{};
    u_short data{};
    std::string publisher{};
    u_int duration{};
public:
    Song();
    ~Song();
public:
    std::string get_song_name() const;
    u_short get_data() const;
    std::string get_publisher() const;
    u_int get_song_duration() const;
};

class Musician
{
private:
    std::string name{};
    std::string surename{};
    std::string country{};
    u_short yearOfBirth{};
    std::vector <std::string> allsongs{};
public:
    Musician();
    ~Musician();
public:
    std::string get_name() const;
    std::string get_surename() const;
    std::string get_country() const;
    u_short get_birth() const;
    std::vector <std::string> get_songs() const;
};

struct Favorite
{
    std::vector <Song> favourite_s;
    std::vector <Musician> favourite_m;
}favour;

struct Cloud
{
    std::vector <Song> cloud_s;
    std::vector <Musician> cloud_m;
}cloud;

void musician();
void operation(int choice);
void song_insertion();
void musician_insertion();
void song_searching();
void musician_searching();
void adding_song();
void removing_song();
void adding_to_favourits();

#include "music.hpp"
#endif
