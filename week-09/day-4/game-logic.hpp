#ifndef GAME_LOGIC_HPP_
#define GAME_LOGIC_HPP_
#include <vector>

using namespace std;

class Game {
private:
  vector<vector<char>> v;
  bool x_next;
public:
  Game();
  vector<vector<char>> get_vector();
  char get_v(unsigned int _x, unsigned int _y);
  void set_v(unsigned int _x, unsigned int _y, char c);
  void set_cell(unsigned int _x, unsigned int _y);
  bool is_5in_lineh(unsigned int _x, unsigned int _y);
  bool is_5in_linev(unsigned int _x, unsigned int _y);
  bool is_5in_linec1(unsigned int _x, unsigned int _y);
  bool is_5in_linec2(unsigned int _x, unsigned int _y);
  void is_danger_h(unsigned int _x, unsigned int _y);
  void is_danger_v(unsigned int _x, unsigned int _y);
  void is_danger_c1(unsigned int _x, unsigned int _y);
  void is_danger_c2(unsigned int _x, unsigned int _y);
  void can_i_win(unsigned int _x, unsigned int _y);
  void make_4(unsigned int _x, unsigned int _y);
  void make_3(unsigned int _x, unsigned int _y);
  bool can_be_danger();
  bool is_won();
  void set_next();
  bool get_next();
};

#endif
