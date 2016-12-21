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
