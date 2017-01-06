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
  void set_cell(unsigned int x, unsigned int y);
  bool is_5in_lineh(unsigned int x, unsigned int y);
  bool is_5in_linev(unsigned int x, unsigned int y);
  bool is_5in_linec1(unsigned int x, unsigned int y);
  bool is_5in_linec2(unsigned int x, unsigned int y);
  bool is_won();
  bool get_next();
};

#endif
