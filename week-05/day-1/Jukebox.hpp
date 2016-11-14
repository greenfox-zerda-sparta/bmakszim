#ifndef JUKEBOX_HPP_
#define JUKEBOX_HPP_

#include <string>

using namespace std;

#include "Song.hpp"

class Jukebox {
private:
  Song** songs;
  unsigned int song_count;
public:
  Jukebox();
  ~Jukebox();
  void add_song(Song& song);
  void rate_song(string _a, string _t, unsigned int _r);
  float get_artist_rating(string _a);
  float get_genre_rating(string _g);
  string get_top_rated_title();
  string get_top_rated_genre();
  void get_genres();
};


#endif
