#include "Song.hpp"
#include "Rock.hpp"
#include <string>
#include <iostream>

using namespace std;

Rock::Rock(string _a, string _t){
  artist = _a;
  title = _t;
  rating = 0;
  genre = "rock";
  rate_count = 0;
}

string Rock::get_genre() {
  return genre;
}

bool Rock::rate(unsigned int _r){
  if (_r > 1 && _r <= 5) {
    ++rate_count;
    rating += _r;
  }
  return 1 < _r && _r <= 5;
}
