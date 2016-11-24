#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  //create an integer vector with the size of 5 and print the 3rd element of it
  vector<int> v(5);
  cout << v.at(2);
  return 0;
}
