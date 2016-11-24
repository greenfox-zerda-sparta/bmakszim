#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  //create an integer vector with the size of 5 and print all elements of it
  vector<int> v(5);
  int s = v.size();
  for (int i = 0; i < s; i++) {
    cout << v.at(i) << '|';
  }
  return 0;
}
