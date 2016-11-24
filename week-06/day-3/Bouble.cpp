#include "Bouble.hpp"

Bouble::Bouble(int px, int py, int vx, int vy) {
  pos_x = px;
  pos_y = py;
  vec_x = vx;
  vec_y = vy;
  hit_counter = 0;
}

int Bouble::get_pos_x() {
  return pos_x;
}

int Bouble::get_pos_y() {
  return pos_y;
}

int Bouble::get_hit_counter() {
  return hit_counter;
}

void Bouble::move() {
  for (int i = 0; i < abs(vec_x); i++) {
    if (pos_x == 9) {
      int new_vector9 = abs(vec_x) * (-1);
      if (new_vector9 != vec_x) {
        hit_counter++;
      }
      vec_x = new_vector9;
    }
    if (pos_x == 0) {
      int new_vector0 = abs(vec_x);
      if (new_vector0 != vec_x) {
        hit_counter++;
      }
      vec_x = new_vector0;
    }
    if (vec_x > 0) {
      pos_x++;
    } else {
      pos_x--;
    }
  }
  for (int i = 0; i < abs(vec_y); i++) {
    if (pos_y == 9) {
      int new_vector9 = abs(vec_y) * (-1);
      if (new_vector9 != vec_y) {
        hit_counter++;
      }
      vec_y = new_vector9;
    }
    if (pos_y == 0) {
      int new_vector0 = abs(vec_y);
      if (new_vector0 != vec_y) {
        hit_counter++;
      }
      vec_y = new_vector0;
    }
    if (vec_y > 0) {
      pos_y++;
    } else {
      pos_y--;
    }
  }
}
