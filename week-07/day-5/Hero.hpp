#ifndef HERO_HPP_
#define HERO_HPP_

#include "game_object.hpp"
#include "Map.hpp"

class Hero: public Game_object {
private:
  int hero_stance;
public:
  Hero();
  int get_hero_stance();
  void set_hero_stance(int s);
};


#endif
