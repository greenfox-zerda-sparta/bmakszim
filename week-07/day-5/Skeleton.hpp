#ifndef SKELETON_HPP_
#define SKELETON_HPP_

#include "game_object.hpp"
#include "Map.hpp"

class Skeleton: public Game_object {
private:
  vector<vector<string>>v;
public:
  Skeleton(Map* map);
};



#endif
