#ifndef MAP_HPP_
#define MAP_HPP_

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Map {
private:
  vector<vector<string>>m;
public:
  Map();
  unsigned int get_level();
  vector<vector<string>> get_m();
};



#endif
