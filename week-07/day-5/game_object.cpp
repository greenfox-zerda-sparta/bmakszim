#include "game_object.hpp"

Game_object::Game_object() {

}

Game_object::~Game_object() {

}

string Game_object::get_image() {
  return image;
}

int Game_object::get_x() {
  return x;
}

int Game_object::get_y() {
  return y;
}

void Game_object::set_x(int _x) {
  x = _x;
}

void Game_object::set_y(int _y) {
  y = _y;
}

int Game_object::get_hero_stance() {
  return 0;
}

void Game_object::set_hero_stance(int s) {

}
