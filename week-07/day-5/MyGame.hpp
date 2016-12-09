#ifndef MYGAME_HPP_
#define MYGAME_HPP_

#include <string>
#include <vector>
#include "game-engine.hpp"
#include "game_object.hpp"
#include "game_logic.hpp"
#include "Map.hpp"
#include "Hero.hpp"
#include "Skeleton.hpp"
#include "Boss.hpp"


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
  unsigned int steps;
  Map* map;
  vector<vector<string>>v;
  vector<Game_object*> obj;
  Game_logic* game_logic;
  int level;

public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  bool move_right(int _index);
  bool move_down(int _index);
  bool move_left(int _index);
  bool move_up(int _index);
};

#endif
