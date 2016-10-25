#include <iostream>
#include <string>

using namespace std;

int dub (int a) {
	return a = a * 2;
}

int main() {
  int j = 123;
  // create a function that doubles its input
  // double j with it
  cout << dub(j) << '\n';
  return 0;
}
