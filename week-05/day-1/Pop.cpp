#include "Song.hpp"
#include "Pop.hpp"
#include <string>
#include <iostream>

using namespace std;

Pop::Pop(string _a, string _t){
  artist = _a;
  title = _t;
  rating = 0;
  genre = "pop";
}

string Pop::get_genre() {
  return genre;
}

bool Pop::rate(unsigned int _r){
  if (0 < _r && _r < 5) {
    ++rate_count;
    rating += _r;
  }
  return 0 < _r && _r < 5;
}
