#include "Song.hpp"

Song::Song() {
  ;
}

string Song::get_artist() {
  return artist;
}

string Song::get_title() {
  return title;
}

float Song::get_rating() {
  return float(rating) / float(rate_count);
}

Song::~Song() {
  ;
}
