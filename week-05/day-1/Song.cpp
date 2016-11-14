#include "Song.hpp"
#include <string>
#include <iostream>

using namespace std;

int LAST_ID = -1;

Song::Song() {
  LAST_ID++;
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
