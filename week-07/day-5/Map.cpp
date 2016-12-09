#include "Map.hpp"

Map::Map() {
  ifstream file;
  file.open("map.txt");
  string buffer;
  int i = 0;
  while (file >> buffer) {
    m.push_back(vector<string>());
    for (int j = 0; j < 10; j++) {
      if (buffer[j] == '1') {
        m[i].push_back("floor.bmp");
      } else {
        m[i].push_back("wall.bmp");
      }
    }
    i++;
  }
  file.close();
}

unsigned int Map::get_level() {
}

vector<vector<string>> Map::get_m() {
  return m;
}
