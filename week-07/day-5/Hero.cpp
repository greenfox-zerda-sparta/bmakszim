#include "Hero.hpp"

Hero::Hero() {
  x = 0;
  y = 0;
  hero_stance = 0;
  image = "hero.bmp";
}

int Hero::get_hero_stance() {
  return hero_stance;
}

void Hero::set_hero_stance(int s) {
  hero_stance = s;
  switch (hero_stance) {
    case 1:
      image = "hero-up.bmp";
      break;
    case 2:
      image = "hero-right.bmp";
      break;
    case 3:
      image = "hero-down.bmp";
      break;
    case 4:
      image = "hero-left.bmp";
      break;
    case 0:
      image = "hero.bmp";
      break;
  }
}
