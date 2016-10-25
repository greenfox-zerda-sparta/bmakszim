#include <iostream>
#include <string>

using namespace std;

int fact (int a) {
	int r = 1;
	for (int i = 1; i <= a; i++) {
		r = r * i;
	}
	return r;
}

int main() {
  // create a function that returns its input factorial
	cout << fact(5) << '\n';
  return 0;
}
