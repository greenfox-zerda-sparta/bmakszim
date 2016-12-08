#include "MyGame.hpp"
#include "SDL2/SDL_ttf.h"
#include <iostream>

MyGame::MyGame() {
  this->read_map();
  this->place_skeletons();
  this->place_boss();
  char_x = 0;
  char_y = 0;
  hero_stance = 0;
}

void MyGame::init(GameContext& context) {
  context.load_file(FLOOR);
  context.load_file(WALL);
  context.load_file(HERO);
  context.load_file(HERO_UP);
  context.load_file(HERO_DOWN);
  context.load_file(HERO_LEFT);
  context.load_file(HERO_RIGHT);
  context.load_file(SKELETON);
  context.load_file(BOSS);
}

void MyGame::render(GameContext& context) {
  v[char_x][char_y] = set_hero();
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
  	  context.draw_sprite(v[i][j], i*72, j*72);
    }
  }
  if (context.was_key_pressed(ARROW_DOWN)) {
    hero_stance = 3;
    if (char_y != 9 && v[char_x][char_y + 1] != WALL) {
      v[char_x][char_y] = FLOOR;
      char_y++;
    }
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    hero_stance = 2;
    if (char_x != 9 && v[char_x + 1][char_y] != WALL) {
      v[char_x][char_y] = FLOOR;
      char_x++;
    }
  }
  if (context.was_key_pressed(ARROW_UP)) {
    hero_stance = 1;
    if (char_y != 0 && v[char_x][char_y - 1] != WALL) {
      v[char_x][char_y] = FLOOR;
      char_y--;
    }
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    hero_stance = 4;
    if (char_x != 0 && v[char_x - 1][char_y] != WALL) {
      v[char_x][char_y] = FLOOR;
      char_x--;
    }
  }
  context.render();
}

string MyGame::set_hero() {
  string hero_;
  switch (hero_stance) {
    case 1:
      hero_ = "hero-up.bmp";
      break;
    case 2:
      hero_ = "hero-right.bmp";
      break;
    case 3:
      hero_ = "hero-down.bmp";
      break;
    case 4:
      hero_ = "hero-left.bmp";
      break;
    case 0:
      hero_ = "hero.bmp";
      break;
  }
  return hero_;
}

void MyGame::read_map() {
  ifstream file;
  file.open("map.txt");
  string buffer;
  char temp;
  int i = 0;
  while (file >> buffer) {
    v.push_back(vector<string>());
    for (int j = 0; j < 10; j++) {
      temp = buffer[j];
      if (temp == '1') {
        v[i].push_back(FLOOR);
      } else {
        v[i].push_back(WALL);
      }
    }
    i++;
  }
  file.close();
}

void MyGame::place_skeletons() {
  int x;
  int y;
  int m = 0;
  bool u;
  for (int i = 0; i < 3; i++) {
    do {
      u = true;
      x = rand() % 5 + (((i%2) + 1) % 2) * 5; //in order to be placed in different quarter of the map
      if (i > 0) {
        m = 1;
      }
      y = rand() % 5 + (m * 5);  //in order to be placed in different quarter of the map
      if (v[x][y] == WALL || v[x][y] == SKELETON) {
        u = false;
      }
    } while (u == false);
    v[x][y] = SKELETON;
  }
}

void MyGame::place_boss() {
  int x;
  int y;
  bool u;
  do {
    u = false;
    x = rand() % 7 + 3;
    y = rand() % 7 + 3;
    if (v[x][y] == FLOOR) {
      u = true;
    }
  } while (u == false);
  v[x][y] = BOSS;
}
