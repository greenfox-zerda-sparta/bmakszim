#ifndef MYGAME_HPP_
#define MYGAME_HPP_

#include <string>
#include <vector>
#include <fstream>
#include "game-engine.hpp"

using namespace std;

const string FLOOR = "floor.bmp";
const string WALL = "wall.bmp";
const string HERO = "hero.bmp";
const string HERO_UP = "hero-up.bmp";
const string HERO_DOWN = "hero-down.bmp";
const string HERO_LEFT = "hero-left.bmp";
const string HERO_RIGHT = "hero-right.bmp";
const string SKELETON = "skeleton.bmp";
const string BOSS = "boss.bmp";

class MyGame : public Game {
private:
  int char_x;
  int char_y;
  int hero_stance;
protected:
  vector<vector<string>>v;
public:
  MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  string set_hero();
  void read_map();
  void place_skeletons();
  void place_boss();
};

#endif
