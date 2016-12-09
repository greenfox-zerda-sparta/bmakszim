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

int Game_object::get_max_hp() {
  return max_hp;
}
void Game_object::set_max_hp(int _max_hp) {
  max_hp = _max_hp;
}
int Game_object::get_current_hp() {
  return current_hp;
}
void Game_object::set_current_hp(int _current_hp) {
  current_hp = _current_hp;
}
int Game_object::get_defend() {
  return defend;
}
void Game_object::set_defend(int _defend) {
  defend = _defend;
}
int Game_object::get_strike() {
  return strike;
}
void Game_object::set_strike(int _strike) {
  strike = _strike;
}
