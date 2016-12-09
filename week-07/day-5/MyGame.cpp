#include "MyGame.hpp"
//#include <iostream>

MyGame::MyGame() {
  level = 1;
  game_logic = new Game_logic();
  steps = 1;
  map = new Map();
  v = map->get_m();
  for (int i = 0; i < (rand() % 3) + 3; i++) {
    obj.push_back(new Skeleton(map));
  }
  obj.push_back(new Boss(map));
  obj.push_back(new Hero());
}

MyGame::~MyGame() {
  for (unsigned int i = 1; i < obj.size(); i++) {
    delete obj[i];
    obj[i] = NULL;
  }
  delete map;
  map = NULL;
  delete game_logic;
  game_logic = NULL;
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
  unsigned int h_index = obj.size() - 1;
  v = map->get_m();
  for (unsigned int i = 0; i < obj.size(); i++) {
    v[obj[i]->get_x()][obj[i]->get_y()] = obj[i]->get_image();
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
  	  context.draw_sprite(v[i][j], i*72, j*72);
    }
  }
  if (context.was_key_pressed(ARROW_DOWN)) {
    obj[h_index]->set_hero_stance(3);
    if (move_down(h_index) == 1) {
      steps++;
    }
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    obj[h_index]->set_hero_stance(2);
    if (move_right(h_index) == 1) {
      steps++;
    }
  }
  if (context.was_key_pressed(ARROW_UP)) {
    obj[h_index]->set_hero_stance(1);
    if (move_up(h_index) == 1) {
      steps++;
    }
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    obj[h_index]->set_hero_stance(4);
    if (move_left(h_index) == 1) {
      steps++;
    }
  }
  if (steps != 1 && (steps % 3 == 0)) {
    int n;
    bool m = false;
    for (unsigned int i = 0; i < obj.size() - 2; i++) {
      do {
        n = rand() % 4;
        switch (n) {
          case 0:
            m = move_right(i);
            break;
          case 1:
            m = move_down(i);
            break;
          case 2:
            m = move_left(i);
            break;
          case 3:
            m = move_up(i);
            break;
        }
      } while (m == false);
    }
    steps++;
  }
  context.render();
}

bool MyGame::move_right(int _index) {
  bool if_character_moved = false;
  if (obj[_index]->get_x() != 9 && v[obj[_index]->get_x() + 1][obj[_index]->get_y()] != WALL) {
    obj[_index]->set_x(obj[_index]->get_x() + 1);
    if_character_moved = true;
  }
  return if_character_moved;
}

bool MyGame::move_down(int _index) {
  bool if_character_moved = false;
  if (obj[_index]->get_y() != 9 && v[obj[_index]->get_x()][obj[_index]->get_y() + 1] != WALL) {
    obj[_index]->set_y(obj[_index]->get_y() + 1);
    if_character_moved = true;
  }
  return if_character_moved;
}

bool MyGame::move_left(int _index) {
  bool if_character_moved = false;
  if (obj[_index]->get_x() != 0 && v[obj[_index]->get_x() - 1][obj[_index]->get_y()] != WALL) {
    obj[_index]->set_x(obj[_index]->get_x() - 1);
    if_character_moved = true;
  }
  return if_character_moved;
}

bool MyGame::move_up(int _index) {
  bool if_character_moved = false;
  if (obj[_index]->get_y() != 0 && v[obj[_index]->get_x()][obj[_index]->get_y() - 1] != WALL) {
    obj[_index]->set_y(obj[_index]->get_y() - 1);
    if_character_moved = true;
  }
  return if_character_moved;
}
