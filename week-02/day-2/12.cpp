#include <iostream>
#include <string>

using namespace std;

int sum (int a[], int len) {
	int s = 0;
	for (int i = 0; i < len; i++) {
		s = s + a[i];
	}
	return s;
}

int main() {
  int numbers[] = {4, 5, 6, 7, 8, 9, 10};
  // write your own sum function
  // it should take an array and its length
  cout << sum(numbers, 7) << '\n';
  return 0;
}
