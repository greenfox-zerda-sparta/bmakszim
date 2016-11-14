#ifndef SONG_HPP_
#define SONG_HPP_

#include <string>

using namespace std;

class Song {
private:

protected:
  string artist;
  string title;
  unsigned int rating;
  unsigned int rate_count;
public:
  Song();
  virtual ~Song();
  string get_artist();
  string get_title();
  float get_rating();
  virtual string get_genre() = 0;
  virtual bool rate(unsigned int _r) = 0;
};




#endif
