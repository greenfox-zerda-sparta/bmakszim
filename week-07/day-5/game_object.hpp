#ifndef GAME_OBJECT_HPP_
#define GAME_OBJECT_HPP_

#include <string>

using namespace std;

class Game_object {
protected:
  int x;
  int y;
  string image;
  int max_hp;
  int current_hp;
  int defend;
  int strike;
public:
  Game_object();
  virtual ~Game_object();
  string get_image();
  int get_x();
  int get_y();
  void set_x(int _x);
  void set_y(int _y);
  virtual int get_hero_stance();
  virtual void set_hero_stance(int s);
  int get_max_hp();
  void set_max_hp(int _max_hp);
  int get_current_hp();
  void set_current_hp(int _current_hp);
  int get_defend();
  void set_defend(int _defend);
  int get_strike();
  void set_strike(int _strike);

};




#endif
