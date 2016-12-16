#include <iostream>
#include <string>

using namespace std;

string fun(string s) {
  if (s.length() > 0) {
    char n;
    if (s[0] == 'x') {
      return fun(s.erase(0, 1));
    } else {
      n = s[0];
    }
    return n + fun(s.erase(0, 1));
  } else {
    return "";
  }
}

int main() {
  // Given a string, compute recursively a new string where all the 'x' chars have been removed.
  cout << fun("xoxoyoy");
  return 0;
}
