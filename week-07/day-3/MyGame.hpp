#ifndef MYGAME_HPP_
#define MYGAME_HPP_

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
  MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  string set_hero();
  void read_map();
  void place_skeletons();
};

#endif
