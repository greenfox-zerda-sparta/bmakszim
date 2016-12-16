#include <iostream>
#include <string>

using namespace std;

string fun(string s) {
  if (s.length() > 1) {
    string n;
      n = s[0];
    return n + '*' + fun(s.erase(0, 1));
  } else if (s.length() > 0 && s.length() < 2) {
    string n;
      n = s[0];
    return n + fun(s.erase(0, 1));
  } else {
    return "";
  }
}

int main() {
  // Given a string, compute recursively a new string where all the
  // adjacent chars are now separated by a "*"
  cout << fun("abcd");
  return 0;
}
