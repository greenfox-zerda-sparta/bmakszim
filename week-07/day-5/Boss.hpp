#ifndef BOSS_HPP_
#define BOSS_HPP_

#include "game_object.hpp"
#include "Map.hpp"

class Boss: public Game_object {
private:
  vector<vector<string>>v;
public:
  Boss(Map* map);
};


#endif
