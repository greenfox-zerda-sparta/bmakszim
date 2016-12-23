#include <iostream>

using namespace std;

#include "game-logic.hpp"

Game::Game() {
  vector<char> row;
  for (int i = 0; i < 19; i++) {
    row.push_back('_');
  }
  for (int i = 0; i < 19; i++) {
    v.push_back(row);
  }
  x_next = false;
}

vector<vector<char>> Game::get_vector() {
  return v;
}

char Game::get_v(unsigned int _x, unsigned int _y) {
  return v[_y][_x];
}

void Game::set_v(unsigned int _x, unsigned int _y, char c) {
    v[_y][_x] = c;
}

void Game::set_cell(unsigned int x, unsigned int y) {
  if (v[y][x] != 'X' && v[y][x] != 'O') {
    if (x_next) {
      v[y][x] = 'X';
    } else {
      v[y][x] = 'O';
    }
    x_next = !x_next;
  }
}

bool Game::is_5in_lineh(unsigned int _x, unsigned int _y) {
  int x = _x;
  int y = _y;
  int i = 1;
  if (x < 15) {
    while (i < 5 && v[x][y] == v[x + 1][y]) {
      i++;
      x++;
    }
  }
  return (i >= 5);
}

bool Game::is_5in_linev(unsigned int _x, unsigned int _y) {
  int x = _x;
  int y = _y;
  int j = 1;
  if (y < 15) {
    while (j < 5 && v[x][y] == v[x][y + 1]) {
      j++;
      y++;
    }
  }
  return (j >= 5);
}

bool Game::is_5in_linec1(unsigned int _x, unsigned int _y) {
  int x = _x;
  int y = _y;
  int k = 1;
  if (x < 15 && y < 15) {
    while (k < 5 && v[x][y] == v[x + 1][y + 1]) {
      k++;
      x++;
      y++;
    }
  }
  return (k >= 5);
}

bool Game::is_5in_linec2(unsigned int _x, unsigned int _y) {
  int x = _x;
  int y = _y;
  int l = 1;
  if (x < 15 && y > 3) {
    while (l < 5 && v[x][y] == v[x + 1][y - 1]) {
      l++;
      x++;
      y--;
    }
  }
  return (l >= 5);
}

bool Game::is_won() {
  bool won = false;
  for (unsigned int i = 0; i < v.size(); i++) {
    for (unsigned int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == 'X' || v[i][j] == 'O') {
        if ((is_5in_lineh(i, j)) || (is_5in_linev(i, j)) || (is_5in_linec1(i, j)) || (is_5in_linec2(i, j))) {
          won = true;
        }
      }
    }
  }
  return won;
}

bool Game::get_next() {
  return x_next;
}

void Game::set_next() {
  x_next = !x_next;
}

void Game::is_danger_h(unsigned int _x, unsigned int _y) {
  if (x_next && _x < 14) {
    if (v[_y][_x] == '_' &&
        v[_y][_x+1] == 'O' &&
        v[_y][_x+2] == 'O' &&
        v[_y][_x+3] == '_' &&
        v[_y][_x+4] == 'O' &&
        v[_y][_x+5] == '_') {
      this->set_cell(_x+3, _y);
    } else if (v[_y][_x] == '_' &&
        v[_y][_x+1] == 'O' &&
        v[_y][_x+2] == '_' &&
        v[_y][_x+3] == 'O' &&
        v[_y][_x+4] == 'O' &&
        v[_y][_x+5] == '_') {
      this->set_cell(_x+2, _y);
    }
  }
  if (x_next && _x < 15) {
    if (v[_y][_x] == 'O' &&
        v[_y][_x+1] == 'O' &&
        v[_y][_x+2] == 'O' &&
        v[_y][_x+3] == 'O' &&
        v[_y][_x+4] == '_') {
      this->set_cell(_x+4, _y);
    } else if (v[_y][_x] == 'O' &&
        v[_y][_x+1] == 'O' &&
        v[_y][_x+2] == 'O' &&
        v[_y][_x+3] == '_' &&
        v[_y][_x+4] == 'O') {
      this->set_cell(_x+3, _y);
    } else if (v[_y][_x] == 'O' &&
        v[_y][_x+1] == '_' &&
        v[_y][_x+2] == 'O' &&
        v[_y][_x+3] == 'O' &&
        v[_y][_x+4] == 'O') {
      this->set_cell(_x+1, _y);
    } else if (v[_y][_x] == 'O' &&
        v[_y][_x+1] == 'O' &&
        v[_y][_x+2] == '_' &&
        v[_y][_x+3] == 'O' &&
        v[_y][_x+4] == 'O') {
      this->set_cell(_x+2, _y);
    } else if (v[_y][_x] == '_' &&
        v[_y][_x+1] == 'O' &&
        v[_y][_x+2] == 'O' &&
        v[_y][_x+3] == 'O' &&
        v[_y][_x+4] == 'O') {
      this->set_cell(_x, _y);
    } else if (v[_y][_x] == '_' &&
        v[_y][_x+1] == 'O' &&
        v[_y][_x+2] == 'O' &&
        v[_y][_x+3] == 'O' &&
        v[_y][_x+4] == '_') {
      this->set_cell(_x, _y);
    }
  }
}

void Game::is_danger_v(unsigned int _x, unsigned int _y) {
  if (x_next && _y < 14) {
    if (v[_y][_x] == '_' &&
        v[_y+1][_x] == 'O' &&
        v[_y+2][_x] == 'O' &&
        v[_y+3][_x] == '_' &&
        v[_y+4][_x] == 'O' &&
        v[_y+5][_x] == '_') {
      this->set_cell(_x, _y+3);
    } else if (v[_y][_x] == '_' &&
        v[_y+1][_x] == 'O' &&
        v[_y+2][_x] == '_' &&
        v[_y+3][_x] == 'O' &&
        v[_y+4][_x] == 'O' &&
        v[_y+5][_x] == '_') {
      this->set_cell(_x, _y+2);
    }
  }
  if (x_next && _y < 15) {
    if (v[_y][_x] == 'O' &&
        v[_y+1][_x] == 'O' &&
        v[_y+2][_x] == 'O' &&
        v[_y+3][_x] == 'O' &&
        v[_y+4][_x] == '_') {
      this->set_cell(_x, _y+4);
    } else if (v[_y][_x] == 'O' &&
        v[_y+1][_x] == 'O' &&
        v[_y+2][_x] == 'O' &&
        v[_y+3][_x] == '_' &&
        v[_y+4][_x] == 'O') {
      this->set_cell(_x, _y+3);
    } else if (v[_y][_x] == 'O' &&
        v[_y+1][_x] == '_' &&
        v[_y+2][_x] == 'O' &&
        v[_y+3][_x] == 'O' &&
        v[_y+4][_x] == 'O') {
      this->set_cell(_x, _y+1);
    } else if (v[_y][_x] == 'O' &&
        v[_y+1][_x] == 'O' &&
        v[_y+2][_x] == '_' &&
        v[_y+3][_x] == 'O' &&
        v[_y+4][_x] == 'O') {
      this->set_cell(_x, _y+2);
    } else if (v[_y][_x] == '_' &&
        v[_y+1][_x] == 'O' &&
        v[_y+2][_x] == 'O' &&
        v[_y+3][_x] == 'O' &&
        v[_y+4][_x] == 'O') {
      this->set_cell(_x, _y);
    } else if (v[_y][_x] == '_' &&
        v[_y+1][_x] == 'O' &&
        v[_y+2][_x] == 'O' &&
        v[_y+3][_x] == 'O' &&
        v[_y+4][_x] == '_') {
      this->set_cell(_x, _y);
    }
  }
}

void Game::is_danger_c1(unsigned int _x, unsigned int _y) {
  if (x_next && _y < 14 && _x < 14) {
    if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'O' &&
        v[_y+2][_x+2] == 'O' &&
        v[_y+3][_x+3] == '_' &&
        v[_y+4][_x+4] == 'O' &&
        v[_y+5][_x+5] == '_') {
      this->set_cell(_x+3, _y+3);
    } else if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'O' &&
        v[_y+2][_x+2] == '_' &&
        v[_y+3][_x+3] == 'O' &&
        v[_y+4][_x+4] == 'O' &&
        v[_y+5][_x+5] == '_') {
      this->set_cell(_x+2, _y+2);
    }
  }
  if (x_next && _y < 15 && _x < 15) {
    if (v[_y][_x] == 'O' &&
        v[_y+1][_x+1] == 'O' &&
        v[_y+2][_x+2] == 'O' &&
        v[_y+3][_x+3] == 'O' &&
        v[_y+4][_x+4] == '_') {
      this->set_cell(_x+4, _y+4);
    } else if (v[_y][_x] == 'O' &&
        v[_y+1][_x+1] == 'O' &&
        v[_y+2][_x+2] == 'O' &&
        v[_y+3][_x+3] == '_' &&
        v[_y+4][_x+4] == 'O') {
      this->set_cell(_x+3, _y+3);
    } else if (v[_y][_x] == 'O' &&
        v[_y+1][_x+1] == '_' &&
        v[_y+2][_x+2] == 'O' &&
        v[_y+3][_x+3] == 'O' &&
        v[_y+4][_x+4] == 'O') {
      this->set_cell(_x+1, _y+1);
    } else if (v[_y][_x] == 'O' &&
        v[_y+1][_x+1] == 'O' &&
        v[_y+2][_x+2] == '_' &&
        v[_y+3][_x+3] == 'O' &&
        v[_y+4][_x+4] == 'O') {
      this->set_cell(_x+2, _y+2);
    } else if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'O' &&
        v[_y+2][_x+2] == 'O' &&
        v[_y+3][_x+3] == 'O' &&
        v[_y+4][_x+4] == 'O') {
      this->set_cell(_x, _y);
    } else if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'O' &&
        v[_y+2][_x+2] == 'O' &&
        v[_y+3][_x+3] == 'O' &&
        v[_y+4][_x+4] == '_') {
      this->set_cell(_x, _y);
    }
  }
}

void Game::is_danger_c2(unsigned int _x, unsigned int _y) {
  if (x_next && _y > 4 && _x < 14) {
    if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'O' &&
        v[_y-2][_x+2] == 'O' &&
        v[_y-3][_x+3] == '_' &&
        v[_y-4][_x+4] == 'O' &&
        v[_y-5][_x+5] == '_') {
      this->set_cell(_x+3, _y-3);
    } else if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'O' &&
        v[_y-2][_x+2] == '_' &&
        v[_y-3][_x+3] == 'O' &&
        v[_y-4][_x+4] == 'O' &&
        v[_y-5][_x+5] == '_') {
      this->set_cell(_x+2, _y-2);
    }
  }
  if (x_next && _y > 3 && _x < 15) {
    if (v[_y][_x] == 'O' &&
        v[_y-1][_x+1] == 'O' &&
        v[_y-2][_x+2] == 'O' &&
        v[_y-3][_x+3] == 'O' &&
        v[_y-4][_x+4] == '_') {
      this->set_cell(_x+4, _y-4);
    } else if (v[_y][_x] == 'O' &&
        v[_y-1][_x+1] == 'O' &&
        v[_y-2][_x+2] == 'O' &&
        v[_y-3][_x+3] == '_' &&
        v[_y-4][_x+4] == 'O') {
      this->set_cell(_x+3, _y-3);
    } else if (v[_y][_x] == 'O' &&
        v[_y-1][_x+1] == '_' &&
        v[_y-2][_x+2] == 'O' &&
        v[_y-3][_x+3] == 'O' &&
        v[_y-4][_x+4] == 'O') {
      this->set_cell(_x+1, _y-1);
    } else if (v[_y][_x] == 'O' &&
        v[_y-1][_x+1] == 'O' &&
        v[_y-2][_x+2] == '_' &&
        v[_y-3][_x+3] == 'O' &&
        v[_y-4][_x+4] == 'O') {
      this->set_cell(_x+2, _y-2);
    } else if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'O' &&
        v[_y-2][_x+2] == 'O' &&
        v[_y-3][_x+3] == 'O' &&
        v[_y-4][_x+4] == 'O') {
      this->set_cell(_x, _y);
    } else if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'O' &&
        v[_y-2][_x+2] == 'O' &&
        v[_y-3][_x+3] == 'O' &&
        v[_y-4][_x+4] == '_') {
      this->set_cell(_x, _y);
    }
  }
}

bool Game::can_be_danger() {
  for (int _x = 0; _x < v.size(); _x++) {
    for (int _y = 0; _y < v[_x].size(); _y++) {
      if (_x < 14) {
        if (v[_y][_x] == '_' &&
            v[_y][_x+1] == 'O' &&
            v[_y][_x+2] == 'O' &&
            v[_y][_x+3] == '_' &&
            v[_y][_x+4] == 'O' &&
            v[_y][_x+5] == '_') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y][_x+1] == 'O' &&
            v[_y][_x+2] == '_' &&
            v[_y][_x+3] == 'O' &&
            v[_y][_x+4] == 'O' &&
            v[_y][_x+5] == '_') {
          return true;
        }
      }
      if (_x < 15) {
        if (v[_y][_x] == 'O' &&
            v[_y][_x+1] == 'O' &&
            v[_y][_x+2] == 'O' &&
            v[_y][_x+3] == 'O' &&
            v[_y][_x+4] == '_') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y][_x+1] == 'O' &&
            v[_y][_x+2] == 'O' &&
            v[_y][_x+3] == '_' &&
            v[_y][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y][_x+1] == '_' &&
            v[_y][_x+2] == 'O' &&
            v[_y][_x+3] == 'O' &&
            v[_y][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y][_x+1] == 'O' &&
            v[_y][_x+2] == '_' &&
            v[_y][_x+3] == 'O' &&
            v[_y][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y][_x+1] == 'O' &&
            v[_y][_x+2] == 'O' &&
            v[_y][_x+3] == 'O' &&
            v[_y][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y][_x+1] == 'O' &&
            v[_y][_x+2] == 'O' &&
            v[_y][_x+3] == 'O' &&
            v[_y][_x+4] == '_') {
          return true;
        }
      }
      if (_y < 14) {
        if (v[_y][_x] == '_' &&
            v[_y+1][_x] == 'O' &&
            v[_y+2][_x] == 'O' &&
            v[_y+3][_x] == '_' &&
            v[_y+4][_x] == 'O' &&
            v[_y+5][_x] == '_') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y+1][_x] == 'O' &&
            v[_y+2][_x] == '_' &&
            v[_y+3][_x] == 'O' &&
            v[_y+4][_x] == 'O' &&
            v[_y+5][_x] == '_') {
          return true;
        }
      }
      if (_y < 15) {
        if (v[_y][_x] == 'O' &&
            v[_y+1][_x] == 'O' &&
            v[_y+2][_x] == 'O' &&
            v[_y+3][_x] == 'O' &&
            v[_y+4][_x] == '_') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y+1][_x] == 'O' &&
            v[_y+2][_x] == 'O' &&
            v[_y+3][_x] == '_' &&
            v[_y+4][_x] == 'O') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y+1][_x] == '_' &&
            v[_y+2][_x] == 'O' &&
            v[_y+3][_x] == 'O' &&
            v[_y+4][_x] == 'O') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y+1][_x] == 'O' &&
            v[_y+2][_x] == '_' &&
            v[_y+3][_x] == 'O' &&
            v[_y+4][_x] == 'O') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y+1][_x] == 'O' &&
            v[_y+2][_x] == 'O' &&
            v[_y+3][_x] == 'O' &&
            v[_y+4][_x] == 'O') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y+1][_x] == 'O' &&
            v[_y+2][_x] == 'O' &&
            v[_y+3][_x] == 'O' &&
            v[_y+4][_x] == '_') {
          return true;
        }
      }
      if (_y < 14 && _x < 14) {
        if (v[_y][_x] == '_' &&
            v[_y+1][_x+1] == 'O' &&
            v[_y+2][_x+2] == 'O' &&
            v[_y+3][_x+3] == '_' &&
            v[_y+4][_x+4] == 'O' &&
            v[_y+5][_x+5] == '_') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y+1][_x+1] == 'O' &&
            v[_y+2][_x+2] == '_' &&
            v[_y+3][_x+3] == 'O' &&
            v[_y+4][_x+4] == 'O' &&
            v[_y+5][_x+5] == '_') {
          return true;
        }
      }
      if (_y < 15 && _x < 15) {
        if (v[_y][_x] == 'O' &&
            v[_y+1][_x+1] == 'O' &&
            v[_y+2][_x+2] == 'O' &&
            v[_y+3][_x+3] == 'O' &&
            v[_y+4][_x+4] == '_') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y+1][_x+1] == 'O' &&
            v[_y+2][_x+2] == 'O' &&
            v[_y+3][_x+3] == '_' &&
            v[_y+4][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y+1][_x+1] == '_' &&
            v[_y+2][_x+2] == 'O' &&
            v[_y+3][_x+3] == 'O' &&
            v[_y+4][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y+1][_x+1] == 'O' &&
            v[_y+2][_x+2] == '_' &&
            v[_y+3][_x+3] == 'O' &&
            v[_y+4][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y+1][_x+1] == 'O' &&
            v[_y+2][_x+2] == 'O' &&
            v[_y+3][_x+3] == 'O' &&
            v[_y+4][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y+1][_x+1] == 'O' &&
            v[_y+2][_x+2] == 'O' &&
            v[_y+3][_x+3] == 'O' &&
            v[_y+4][_x+4] == '_') {
          return true;
        }
      }
      if (_y > 4 && _x < 14) {
        if (v[_y][_x] == '_' &&
            v[_y-1][_x+1] == 'O' &&
            v[_y-2][_x+2] == 'O' &&
            v[_y-3][_x+3] == '_' &&
            v[_y-4][_x+4] == 'O' &&
            v[_y-5][_x+5] == '_') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y-1][_x+1] == 'O' &&
            v[_y-2][_x+2] == '_' &&
            v[_y-3][_x+3] == 'O' &&
            v[_y-4][_x+4] == 'O' &&
            v[_y-5][_x+5] == '_') {
          return true;
        }
      }
      if (_y > 3 && _x < 15) {
        if (v[_y][_x] == 'O' &&
            v[_y-1][_x+1] == 'O' &&
            v[_y-2][_x+2] == 'O' &&
            v[_y-3][_x+3] == 'O' &&
            v[_y-4][_x+4] == '_') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y-1][_x+1] == 'O' &&
            v[_y-2][_x+2] == 'O' &&
            v[_y-3][_x+3] == '_' &&
            v[_y-4][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y-1][_x+1] == '_' &&
            v[_y-2][_x+2] == 'O' &&
            v[_y-3][_x+3] == 'O' &&
            v[_y-4][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == 'O' &&
            v[_y-1][_x+1] == 'O' &&
            v[_y-2][_x+2] == '_' &&
            v[_y-3][_x+3] == 'O' &&
            v[_y-4][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y-1][_x+1] == 'O' &&
            v[_y-2][_x+2] == 'O' &&
            v[_y-3][_x+3] == 'O' &&
            v[_y-4][_x+4] == 'O') {
          return true;
        } else if (v[_y][_x] == '_' &&
            v[_y-1][_x+1] == 'O' &&
            v[_y-2][_x+2] == 'O' &&
            v[_y-3][_x+3] == 'O' &&
            v[_y-4][_x+4] == '_') {
          return true;
        }
      }
    }
  }
}

void Game::can_i_win(unsigned int _x, unsigned int _y) {
  if (x_next && _x < 15) {
    if (v[_y][_x] == '_' &&
        v[_y][_x+1] == 'X' &&
        v[_y][_x+2] == 'X' &&
        v[_y][_x+3] == 'X' &&
        v[_y][_x+4] == 'X') {
      this->set_cell(_x, _y);
    } else if (v[_y][_x] == 'X' &&
        v[_y][_x+1] == 'X' &&
        v[_y][_x+2] == 'X' &&
        v[_y][_x+3] == 'X' &&
        v[_y][_x+4] == '_') {
      this->set_cell(_x+4, _y);
    } else if (v[_y][_x] == 'X' &&
        v[_y][_x+1] == '_' &&
        v[_y][_x+2] == 'X' &&
        v[_y][_x+3] == 'X' &&
        v[_y][_x+4] == 'X') {
      this->set_cell(_x+1, _y);
    } else if (v[_y][_x] == 'X' &&
        v[_y][_x+1] == 'X' &&
        v[_y][_x+2] == '_' &&
        v[_y][_x+3] == 'X' &&
        v[_y][_x+4] == 'X') {
      this->set_cell(_x+2, _y);
    } else if (v[_y][_x] == 'X' &&
        v[_y][_x+1] == 'X' &&
        v[_y][_x+2] == 'X' &&
        v[_y][_x+3] == '_' &&
        v[_y][_x+4] == 'X') {
      this->set_cell(_x+3, _y);
    }
  }
  if (x_next && _y < 15) {
    if (v[_y][_x] == '_' &&
        v[_y+1][_x] == 'X' &&
        v[_y+2][_x] == 'X' &&
        v[_y+3][_x] == 'X' &&
        v[_y+4][_x] == 'X') {
      this->set_cell(_x, _y);
    } else if (v[_y][_x] == 'X' &&
        v[_y+1][_x] == 'X' &&
        v[_y+2][_x] == 'X' &&
        v[_y+3][_x] == 'X' &&
        v[_y+4][_x] == '_') {
      this->set_cell(_x, _y+4);
    } else if (v[_y][_x] == 'X' &&
        v[_y+1][_x] == '_' &&
        v[_y+2][_x] == 'X' &&
        v[_y+3][_x] == 'X' &&
        v[_y+4][_x] == 'X') {
      this->set_cell(_x, _y+1);
    } else if (v[_y][_x] == 'X' &&
        v[_y+1][_x] == 'X' &&
        v[_y+2][_x] == '_' &&
        v[_y+3][_x] == 'X' &&
        v[_y+4][_x] == 'X') {
      this->set_cell(_x, _y+2);
    } else if (v[_y][_x] == 'X' &&
        v[_y+1][_x] == 'X' &&
        v[_y+2][_x] == 'X' &&
        v[_y+3][_x] == '_' &&
        v[_y+4][_x] == 'X') {
      this->set_cell(_x, _y+3);
    }
  }
  if (x_next && _y < 15 && _x < 15) {
    if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'X' &&
        v[_y+2][_x+2] == 'X' &&
        v[_y+3][_x+3] == 'X' &&
        v[_y+4][_x+4] == 'X') {
      this->set_cell(_x, _y);
    } else if (v[_y][_x] == 'X' &&
        v[_y+1][_x+1] == 'X' &&
        v[_y+2][_x+2] == 'X' &&
        v[_y+3][_x+3] == 'X' &&
        v[_y+4][_x+4] == '_') {
      this->set_cell(_x+4, _y+4);
    } else if (v[_y][_x] == 'X' &&
        v[_y+1][_x+1] == '_' &&
        v[_y+2][_x+2] == 'X' &&
        v[_y+3][_x+3] == 'X' &&
        v[_y+4][_x+4] == 'X') {
      this->set_cell(_x+1, _y+1);
    } else if (v[_y][_x] == 'X' &&
        v[_y+1][_x+1] == 'X' &&
        v[_y+2][_x+2] == '_' &&
        v[_y+3][_x+3] == 'X' &&
        v[_y+4][_x+4] == 'X') {
      this->set_cell(_x+2, _y+2);
    } else if (v[_y][_x] == 'X' &&
        v[_y+1][_x+1] == 'X' &&
        v[_y+2][_x+2] == 'X' &&
        v[_y+3][_x+3] == '_' &&
        v[_y+4][_x+4] == 'X') {
      this->set_cell(_x+3, _y+3);
    }
  }
  if (x_next && _y > 3 && _x < 15) {
    if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'X' &&
        v[_y-2][_x+2] == 'X' &&
        v[_y-3][_x+3] == 'X' &&
        v[_y-4][_x+4] == 'X') {
      this->set_cell(_x, _y);
    } else if (v[_y][_x] == 'X' &&
        v[_y-1][_x+1] == 'X' &&
        v[_y-2][_x+2] == 'X' &&
        v[_y-3][_x+3] == 'X' &&
        v[_y-4][_x+4] == '_') {
      this->set_cell(_x+4, _y-4);
    } else if (v[_y][_x] == 'X' &&
        v[_y-1][_x+1] == '_' &&
        v[_y-2][_x+2] == 'X' &&
        v[_y-3][_x+3] == 'X' &&
        v[_y-4][_x+4] == 'X') {
      this->set_cell(_x+1, _y-1);
    } else if (v[_y][_x] == 'X' &&
        v[_y-1][_x+1] == 'X' &&
        v[_y-2][_x+2] == '_' &&
        v[_y-3][_x+3] == 'X' &&
        v[_y-4][_x+4] == 'X') {
      this->set_cell(_x+2, _y-2);
    } else if (v[_y][_x] == 'X' &&
        v[_y-1][_x+1] == 'X' &&
        v[_y-2][_x+2] == 'X' &&
        v[_y-3][_x+3] == '_' &&
        v[_y-4][_x+4] == 'X') {
      this->set_cell(_x+3, _y-3);
    }
  }
}

void Game::make_4(unsigned int _x, unsigned int _y) {
  if (x_next && _y > 4 && _x < 14) {
    if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'X' &&
        v[_y-2][_x+2] == 'X' &&
        v[_y-3][_x+3] == '_' &&
        v[_y-4][_x+4] == 'X' &&
        v[_y-5][_x+5] == '_') {
      this->set_cell(_x+3, _y-3);
    } else if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'X' &&
        v[_y-2][_x+2] == '_' &&
        v[_y-3][_x+3] == 'X' &&
        v[_y-4][_x+4] == 'X' &&
        v[_y-5][_x+5] == '_') {
      this->set_cell(_x+2, _y-2);
    } else if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'X' &&
        v[_y-2][_x+2] == 'X' &&
        v[_y-3][_x+3] == 'X' &&
        v[_y-4][_x+4] == '_' &&
        v[_y-5][_x+5] == '_') {
      this->set_cell(_x+4, _y-4);
    } else if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == '_' &&
        v[_y-2][_x+2] == 'X' &&
        v[_y-3][_x+3] == 'X' &&
        v[_y-4][_x+4] == 'X' &&
        v[_y-5][_x+5] == '_') {
      this->set_cell(_x+1, _y-1);
    }
  }
  if (x_next && _y < 14 && _x < 14) {
    if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'X' &&
        v[_y+2][_x+2] == 'X' &&
        v[_y+3][_x+3] == '_' &&
        v[_y+4][_x+4] == 'X' &&
        v[_y+5][_x+5] == '_') {
      this->set_cell(_x+3, _y+3);
    } else if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'X' &&
        v[_y+2][_x+2] == '_' &&
        v[_y+3][_x+3] == 'X' &&
        v[_y+4][_x+4] == 'X' &&
        v[_y+5][_x+5] == '_') {
      this->set_cell(_x+2, _y+2);
    } else if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'X' &&
        v[_y+2][_x+2] == 'X' &&
        v[_y+3][_x+3] == 'X' &&
        v[_y+4][_x+4] == '_' &&
        v[_y+5][_x+5] == '_') {
      this->set_cell(_x+4, _y+4);
    } else if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == '_' &&
        v[_y+2][_x+2] == 'X' &&
        v[_y+3][_x+3] == 'X' &&
        v[_y+4][_x+4] == 'X' &&
        v[_y+5][_x+5] == '_') {
      this->set_cell(_x+1, _y+1);
    }
    if (x_next && _x < 14) {
      if (v[_y][_x] == '_' &&
          v[_y][_x+1] == 'X' &&
          v[_y][_x+2] == 'X' &&
          v[_y][_x+3] == '_' &&
          v[_y][_x+4] == 'X' &&
          v[_y][_x+5] == '_') {
        this->set_cell(_x+3, _y);
      } else if (v[_y][_x] == '_' &&
          v[_y][_x+1] == 'X' &&
          v[_y][_x+2] == '_' &&
          v[_y][_x+3] == 'X' &&
          v[_y][_x+4] == 'X' &&
          v[_y][_x+5] == '_') {
        this->set_cell(_x+2, _y);
      } else if (v[_y][_x] == '_' &&
          v[_y][_x+1] == 'X' &&
          v[_y][_x+2] == 'X' &&
          v[_y][_x+3] == 'X' &&
          v[_y][_x+4] == '_' &&
          v[_y][_x+5] == '_') {
        this->set_cell(_x+4, _y);
      } else if (v[_y][_x] == '_' &&
          v[_y][_x+1] == '_' &&
          v[_y][_x+2] == 'X' &&
          v[_y][_x+3] == 'X' &&
          v[_y][_x+4] == 'X' &&
          v[_y][_x+5] == '_') {
        this->set_cell(_x+1, _y);
      }
    }
    if (x_next && _y < 14) {
      if (v[_y][_x] == '_' &&
          v[_y+1][_x] == 'X' &&
          v[_y+2][_x] == 'X' &&
          v[_y+3][_x] == '_' &&
          v[_y+4][_x] == 'X' &&
          v[_y+5][_x] == '_') {
        this->set_cell(_x, _y+3);
      } else if (v[_y][_x] == '_' &&
          v[_y+1][_x] == 'X' &&
          v[_y+2][_x] == '_' &&
          v[_y+3][_x] == 'X' &&
          v[_y+4][_x] == 'X' &&
          v[_y+5][_x] == '_') {
        this->set_cell(_x, _y+2);
      } else if (v[_y][_x] == '_' &&
          v[_y+1][_x] == 'X' &&
          v[_y+2][_x] == 'X' &&
          v[_y+3][_x] == 'X' &&
          v[_y+4][_x] == '_' &&
          v[_y+5][_x] == '_') {
        this->set_cell(_x, _y+4);
      } else if (v[_y][_x] == '_' &&
          v[_y+1][_x] == '_' &&
          v[_y+2][_x] == 'X' &&
          v[_y+3][_x] == 'X' &&
          v[_y+4][_x] == 'X' &&
          v[_y+5][_x] == '_') {
        this->set_cell(_x, _y+1);
      }
    }
  }
}

void Game::make_3(unsigned int _x, unsigned int _y) {
  if (x_next && _y > 3 && _x < 15) {
    if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'X' &&
        v[_y-2][_x+2] == '_' &&
        v[_y-3][_x+3] == 'X' &&
        v[_y-4][_x+4] == '_') {
      this->set_cell(_x+2, _y-2);
    } else     if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == 'X' &&
        v[_y-2][_x+2] == 'X' &&
        v[_y-3][_x+3] == '_' &&
        v[_y-4][_x+4] == '_') {
      this->set_cell(_x+3, _y-3);
    } else    if (v[_y][_x] == '_' &&
        v[_y-1][_x+1] == '_' &&
        v[_y-2][_x+2] == 'X' &&
        v[_y-3][_x+3] == 'X' &&
        v[_y-4][_x+4] == '_') {
      this->set_cell(_x+1, _y-1);
    }
  }
  if (x_next && _y < 15 && _x < 15) {
    if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'X' &&
        v[_y+2][_x+2] == '_' &&
        v[_y+3][_x+3] == 'X' &&
        v[_y+4][_x+4] == '_') {
      this->set_cell(_x+2, _y+2);
    } else     if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == 'X' &&
        v[_y+2][_x+2] == 'X' &&
        v[_y+3][_x+3] == '_' &&
        v[_y+4][_x+4] == '_') {
      this->set_cell(_x+3, _y+3);
    } else     if (v[_y][_x] == '_' &&
        v[_y+1][_x+1] == '_' &&
        v[_y+2][_x+2] == 'X' &&
        v[_y+3][_x+3] == 'X' &&
        v[_y+4][_x+4] == '_') {
      this->set_cell(_x+1, _y+1);
    }
  }
  if (x_next && _x < 15) {
    if (v[_y][_x] == '_' &&
        v[_y][_x+1] == 'X' &&
        v[_y][_x+2] == '_' &&
        v[_y][_x+3] == 'X' &&
        v[_y][_x+4] == '_') {
      this->set_cell(_x+2, _y);
    } else     if (v[_y][_x] == '_' &&
        v[_y][_x+1] == 'X' &&
        v[_y][_x+2] == 'X' &&
        v[_y][_x+3] == '_' &&
        v[_y][_x+4] == '_') {
      this->set_cell(_x+3, _y);
    } else     if (v[_y][_x] == '_' &&
        v[_y][_x+1] == '_' &&
        v[_y][_x+2] == 'X' &&
        v[_y][_x+3] == 'X' &&
        v[_y][_x+4] == '_') {
      this->set_cell(_x+1, _y);
    }
  }
  if (x_next && _y < 15) {
    if (v[_y][_x] == '_' &&
        v[_y+1][_x] == 'X' &&
        v[_y+2][_x] == '_' &&
        v[_y+3][_x] == 'X' &&
        v[_y+4][_x] == '_') {
      this->set_cell(_x, _y+2);
    } else     if (v[_y][_x] == '_' &&
        v[_y+1][_x] == 'X' &&
        v[_y+2][_x] == 'X' &&
        v[_y+3][_x] == '_' &&
        v[_y+4][_x] == '_') {
      this->set_cell(_x, _y+3);
    } else     if (v[_y][_x] == '_' &&
        v[_y+1][_x] == '_' &&
        v[_y+2][_x] == 'X' &&
        v[_y+3][_x] == 'X' &&
        v[_y+4][_x] == '_') {
      this->set_cell(_x, _y+1);
    }
  }
}
