#include "Boss.hpp"

Boss::Boss(Map* map) {
  v = map->get_m();
  do {
    x = rand() % 7 + 3;
    y = rand() % 7 + 3;
  } while (v[x][y] != "floor.bmp");
  image = "boss.bmp";
}
