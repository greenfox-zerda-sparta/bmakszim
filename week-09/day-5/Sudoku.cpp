#include <iostream>
#include <vector>
#include <string>

////////Sudoku solver////////////

using namespace std;

unsigned int a = 0;

void draw_v(vector<vector<int>>& v);

vector<vector<int>> create_v();

bool is_line_unique(unsigned int l, vector<vector<int>>& v);

bool is_column_unique(unsigned int c, vector<vector<int>>& v);

bool is_area_unique(unsigned int x, unsigned int y, vector<vector<int>>& v);

void solve(unsigned int x, unsigned int y, vector<vector<int>> v) {
  vector<vector<int>> temp = v;
  bool finished = true;
  for (int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if (temp[i][j] == 0) {
        finished = false;
      }
    }
  }
  if (finished == true) {
    draw_v(temp);
    a++;
  } else {
    if (temp[y][x] == 0) {
      for (int i = 1; i < 10; i++) {
        temp[y][x] = i;
        if (is_line_unique(y, temp) && is_column_unique(x, temp) && is_area_unique(x, y, temp)) {
          if (x == 8 && y == 8) {
            if (a <= 10) {
             solve (x, y, temp);
            }
          } else {
            if (x < 8) {
              if (a <= 10) {
                solve(x+1, y, temp);
              }
            } else {
              if (a <= 10) {
                solve(0, y+1, temp);
              }
            }
          }
        }
      }
    } else {
      if (x == 8 && y == 8) {
        if (a <= 10) {
          solve (x, y, temp);
        }
      } else {
        if (x < 8) {
          if (a <= 10) {
            solve(x+1, y, temp);
          }
        } else {
          solve(0, y+1, temp);
        }
      }
    }
  }
}

int main() {
  vector<vector<int>> v = create_v();
  unsigned int n;
  string s;
  cout << "Add rows of the given sudoku puzzle in a format like: 123456789" << endl
       << "Use 0 for empty cells. e.g. '001002003'" << endl
       << "Hit Enter after each row." << endl;
  for (int i = 0; i < 9; i++) {
    cin >> s;
    for (unsigned int j = 0; j < s.length(); j++) {
      n = s[j] - 48;
      if (n > 0 && n < 10) {
        v[i][j] = n;
      } else {
        v[i][j] = 0;
      }
    }
  }
  cout << "Puzzle to solve:" << endl;
  draw_v(v);
  solve(0, 0, v);
  if (a <= 10) {
    cout << a << " solution(s) found." << endl;
  } else {
    cout << "More than 10 possible solution." << endl;
  }
  return 0;
}

bool is_line_unique(unsigned int _l, vector<vector<int>>& v) {
  vector<int> temp;
  for (int i = 0; i < 9; i++) {
    if (v[_l][i] != 0) {
      temp.push_back(v[_l][i]);
    }
  }
  for (unsigned int i = 1; i < temp.size(); i++) {
    for (unsigned int j = 0; j < i; j++) {
      if (temp[i] == temp[j]) {
        return false;
      }
    }
  }
  return true;
}

bool is_column_unique(unsigned int _c, vector<vector<int>>& v) {
  vector<int> temp;
  for (int i = 0; i < 9; i++) {
    if (v[i][_c] != 0) {
      temp.push_back(v[i][_c]);
    }
  }
  for (unsigned int i = 1; i < temp.size(); i++) {
    for (unsigned int j = 0; j < i; j++) {
      if (temp[i] == temp[j]) {
        return false;
      }
    }
  }
  return true;
}

bool is_area_unique(unsigned int x, unsigned int y, vector<vector<int>>& v) {
  vector<int> temp;
  for (unsigned int i = (y / 3) * 3; i < 3 +((y / 3) * 3); i++) {
    for (unsigned int j = (x / 3) * 3; j < 3 +((x / 3) * 3); j++) {
      if (v[i][j] != 0) {
        temp.push_back(v[i][j]);
      }
    }
  }
  for (unsigned int i = 1; i < temp.size(); i++) {
    for (unsigned int j = 0; j < i; j++) {
      if (temp[i] == temp[j]) {
        return false;
      }
    }
  }
  return true;
}

void draw_v(vector<vector<int>>& v) {
  cout << "-------------------------" << endl;
  for (int i = 0; i < 9; i++) {
    if (i % 3 == 0 && i != 0) {
      cout << "-------------------------" << endl;
    }
    for (int j = 0; j < 9; j++) {
      if (j % 3 == 0) {
        cout << "| ";
      }
      cout << v[i][j] << " ";
    }
    cout << "|";
    cout << endl;
  }
  cout << "-------------------------" << endl;
  cout << endl;
}

vector<vector<int>> create_v() {
  vector<vector<int>> v;
  for (int i = 0; i < 9; i++) {
    vector<int> row;
    for (int j = 0; j < 9; j++) {
      row.push_back(0);
    }
    v.push_back(row);
  }
  return v;
}
