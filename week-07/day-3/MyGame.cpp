#include "MyGame.hpp"

MyGame::MyGame() {
  for (int i = 0; i < 10; i++) {
    v.push_back(vector<int>());
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
	  v[i].push_back(0);
    }
  }
  this->read_map();
  this->place_skeletons();
  char_x = 0;
  char_y = 0;
  hero_stance = 0;
}
void MyGame::init(GameContext& context) {
  context.load_file("floor.bmp");
  context.load_file("wall.bmp");
  context.load_file("hero.bmp");
  context.load_file("hero-up.bmp");
  context.load_file("hero-down.bmp");
  context.load_file("hero-left.bmp");
  context.load_file("hero-right.bmp");
  context.load_file("skeleton.bmp");
}
void MyGame::render(GameContext& context) {
  v[char_x][char_y] = 2;
  string hero = set_hero();
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
  	  if (v[i][j] == 2) {
  	    context.draw_sprite(hero, i*72, j*72);
  	  } else if (v[i][j] == 1) {
      context.draw_sprite("floor.bmp", i*72, j*72);
      } else if (v[i][j] == 0) {
        context.draw_sprite("wall.bmp", i*72, j*72);
      } else if (v[i][j] == 3) {
        context.draw_sprite("skeleton.bmp", i*72, j*72);
      }
    }
  }
  if (context.was_key_pressed(ARROW_DOWN)) {
    hero_stance = 3;
    if (char_y != 9 && v[char_x][char_y + 1] != 0) {
      v[char_x][char_y] = 1;
      char_y++;
    }
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    hero_stance = 2;
    if (char_x != 9 && v[char_x + 1][char_y] != 0) {
      v[char_x][char_y] = 1;
      char_x++;
    }
  }
  if (context.was_key_pressed(ARROW_UP)) {
    hero_stance = 1;
    if (char_y != 0 && v[char_x][char_y - 1] != 0) {
      v[char_x][char_y] = 1;
      char_y--;
    }
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    hero_stance = 4;
    if (char_x != 0 && v[char_x - 1][char_y] != 0) {
      v[char_x][char_y] = 1;
      char_x--;
    }
  }
  context.render();
}

string MyGame::set_hero() {
  string hero;
  switch (hero_stance) {
    case 1:
      hero = "hero-up.bmp";
      break;
    case 2:
      hero = "hero-right.bmp";
      break;
    case 3:
      hero = "hero-down.bmp";
      break;
    case 4:
      hero = "hero-left.bmp";
      break;
    case 0:
      hero = "hero.bmp";
      break;
  }
  return hero;
}

void MyGame::read_map() {
  ifstream file;
  file.open("map.txt");
  string buffer;
  char temp;
  int i = 0;
  while (file >> buffer) {
    for (int j = 0; j < 10; j++) {
      temp = buffer[j];
      v[j][i] = int(temp) - 48;
    }
    i++;
  }
  file.close();
}

void MyGame::place_skeletons() {
  int x;
  int y;
  int m = 0;
  bool u = true;
  for (int i = 0; i < 3; i++) {
    do {
      u = true;
      x = rand() % 5 + (((i%2) + 1) % 2) * 5;
      if (i > 0) {
        m = 1;
      }
      y = rand() % 5 + (m * 5);
      if (v[x][y] == 0 || v[x][y] == 3) {
        u = false;
      }
    } while (u == false);
    v[x][y] = 3;
  }
}
