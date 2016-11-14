#include "Song.hpp"
#include "Reggae.hpp"
#include <string>
#include <iostream>

using namespace std;

Reggae::Reggae(string _a, string _t){
  artist = _a;
  title = _t;
  rating = 0;
  genre = "reggae";
  rate_count = 0;
}

string Reggae::get_genre() {
  return genre;
}

bool Reggae::rate(unsigned int _r){
  if (_r >= 1 &&_r <= 5) {
    ++rate_count;
    rating += _r;
  }
  return _r >= 1 &&_r <= 5;
}
