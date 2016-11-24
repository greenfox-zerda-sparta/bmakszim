#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> v(0);

void add_char(char a) {
  v.push_back(a);
}

int main() {
  //create a vector of chars with the size of zero;
  //write a function where the user can add characters to the end of this vector
  add_char('t');
  add_char('e');
  add_char('s');
  add_char('t');
  for (unsigned int i = 0; i < v.size(); i++) {
    cout << v.at(i);
  }
  return 0;
}
