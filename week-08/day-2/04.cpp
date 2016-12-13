#include <iostream>
#include <string>
#include <map>

using namespace std;

// write a function that takes a string and returns a map
// the map should have the letters of the string as keys and
// it should have integers as values that represents how many times the
// letter appeared in the string

map<char, int> my_function (string s) {
  map<char, int> map;
  for (unsigned int i = 0; i < s.length(); i++) {
    map[s[i]] ++;
  }
  return map;
}

int main() {
  for (auto it : my_function("almafa")) {
    cout << it.first << " : " << it.second << ';';
    cout << endl;
  }
  return 0;
}
