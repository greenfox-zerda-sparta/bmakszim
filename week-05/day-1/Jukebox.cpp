#include "Jukebox.hpp"
#include <iostream>
#include <string>

using namespace std;

string genres[50];
unsigned int count_genres = 0;

Jukebox::Jukebox() {
  songs = NULL;
  song_count = 0;
}

Jukebox::~Jukebox() {
  if (songs != NULL) {
    delete[] songs;
    songs = NULL;
  }
}

void Jukebox::add_song(Song& song) {
  Song** temp = new Song*[song_count + 1];
  if (songs != NULL) {
    for (unsigned int i = 0; i < song_count; i++) {
    temp[i] = songs[i];
    }
  }
  temp[song_count] = &song;
  delete[] songs;
  songs = temp;
  song_count++;
  bool a = 0;
  for (unsigned int i = 0; i < count_genres; i++) {
    if (genres[i] == song.get_genre()) {
      a = 1;
      break;
    }
  }
  if (a == 0) {
    genres[count_genres] = song.get_genre();
    count_genres++;
  }
}

void Jukebox::rate_song(string _a, string _t, unsigned int _r) {
  for (unsigned int i = 0; i < song_count; i++) {
    if (songs[i]->get_artist() == _a && songs[i]->get_title() == _t) {
      songs[i]->rate(_r);
    }
  }
}

float Jukebox::get_artist_rating(string _a) {
  unsigned int counter = 0;
  float ratings = 0;
  for (unsigned int i = 0; i < song_count; i++) {
    if (songs[i]->get_artist() == _a) {
      counter++;
      ratings += songs[i]->get_rating();
    }
  }
  return ratings / float(counter);
}

float Jukebox::get_genre_rating(string _g) {
  unsigned int counter = 0;
  float ratings = 0;
  for (unsigned int i = 0; i < song_count; i++) {
    if (songs[i]->get_genre() == _g) {
      counter++;
      ratings += songs[i]->get_rating();
    }
  }
  return ratings / float(counter);
}

string Jukebox::get_top_rated_title() {
  float top_rating = 0;
  string title = "";
  for (unsigned int i = 0; i < song_count; i++) {
    if (songs[i]->get_rating() == top_rating) {
      title += ", " + songs[i]->get_title();
    } else if (songs[i]->get_rating() > top_rating) {
      title = songs[i]->get_title();
      top_rating = songs[i]->get_rating();
    }
  }
  return title;
}

string Jukebox::get_top_rated_genre() {
  string top_genre = "";
  float top_rate = 0;
  for (unsigned int i = 0; i < count_genres; i++) {
	if ((this->get_genre_rating(genres[i])) == top_rate) {
	  top_genre += ", " + genres[i];
	} else if ((this->get_genre_rating(genres[i])) > top_rate) {
      top_genre = genres[i];
      top_rate = (this->get_genre_rating(genres[i]));
    }
  }
  return top_genre;
}

void Jukebox::get_genres() {
  for (unsigned int i = 0; i < count_genres; i++) {
    cout << genres[i] << endl;
  }
}
