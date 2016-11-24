#ifndef BOUBLE_HPP_
#define BOUBLE_HPP_

#include <cmath>

class Bouble {
private:
  int pos_x;
  int pos_y;
  int vec_x;
  int vec_y;
  int hit_counter;
public:
  Bouble(int px, int py, int vx, int vy);
  int get_pos_x();
  int get_pos_y();
  int get_hit_counter();
  void move();
};

#endif
