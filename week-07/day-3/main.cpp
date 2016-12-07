#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>
#include "game-engine.hpp"

using namespace std;

class MyGame : public Game {
private:
  vector<vector<int>>v;
  int char_x;
  int char_y;
  int hero_stance;
public:
  MyGame() {
    for (int i = 0; i < 10; i++) {
      v.push_back(vector<int>());
    }
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        v[i].push_back(0);
      }
    }
    this->read_map();
    char_x = 0;
    char_y = 0;
    hero_stance = 0;
  }
  virtual void init(GameContext& context) {
    context.load_file("floor.bmp");
    context.load_file("wall.bmp");
    context.load_file("hero.bmp");
    context.load_file("hero-up.bmp");
    context.load_file("hero-down.bmp");
    context.load_file("hero-left.bmp");
    context.load_file("hero-right.bmp");
  }
  virtual void render(GameContext& context) {
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
        }
      }
    }
    if (context.was_key_pressed(ARROW_DOWN)) {
      hero_stance = 3;
      if (char_y != 9 && v[char_x][char_y + 1] == 1) {
        v[char_x][char_y] = 1;
        char_y++;
      }
    }
    if (context.was_key_pressed(ARROW_RIGHT)) {
      hero_stance = 2;
      if (char_x != 9 && v[char_x + 1][char_y] == 1) {
        v[char_x][char_y] = 1;
        char_x++;
      }
    }
    if (context.was_key_pressed(ARROW_UP)) {
      hero_stance = 1;
      if (char_y != 0 && v[char_x][char_y - 1] == 1) {
        v[char_x][char_y] = 1;
        char_y--;
      }
    }
    if (context.was_key_pressed(ARROW_LEFT)) {
      hero_stance = 4;
      if (char_x != 0 && v[char_x - 1][char_y] == 1) {
        v[char_x][char_y] = 1;
        char_x--;
      }
    }
    context.render();
  }

  string set_hero() {
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

  void read_map() {
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
};

int main(int argc, char* argv[]) {
  srand(time(NULL));
  MyGame game;
  GameEngine engine(&game, 720, 720);
  engine.run();
  return 0;
}
