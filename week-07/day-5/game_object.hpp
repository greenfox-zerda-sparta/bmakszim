#ifndef GAME_OBJECT_HPP_
#define GAME_OBJECT_HPP_

#include <string>

using namespace std;

class Game_object {
protected:
  int x;
  int y;
  string image;
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
};




#endif
