#include <iostream>
#include <string>

using namespace std;

string fun(string s) {
  if (s.length() > 0) {
    char n;
    if (s[0] == 'x') {
      n = 'y';
    } else {
      n = s[0];
    }
    return n + fun(s.erase(0, 1));
  } else {
    return "";
  }
}

int main() {
// Given a string, compute recursively (no loops) a new string where all the
// lowercase 'x' chars have been changed to 'y' chars.
  cout << fun("xoxo");
  return 0;
}
