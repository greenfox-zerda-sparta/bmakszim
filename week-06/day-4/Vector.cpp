#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v; //
  v.reserve(1); // vector<int> v(10)
  v.push_back(123);
  v.resize(10, 124);
  cout << v.at(0) << endl;
  cout << v.at(1) << endl;
  cout << v.at(2) << endl;
  //int x = v[10];
  //int y = v.at(10);
  unsigned int x = v.size();
  for (unsigned int i = 0; i < x; i++) {

  }
  cout << v.capacity() << endl;
  v.resize(5);
  cout << v.capacity() << endl;
  v.reserve(11);
  cout << v.capacity() << endl;
  return 0;
}
