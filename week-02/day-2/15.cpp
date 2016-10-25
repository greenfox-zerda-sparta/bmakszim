#include <iostream>
#include <string>

using namespace std;

int srch (int a[], int len, int e) {
	int index = (-1);
	for (int i = 0; i < len; i++) {
		if (e == a[i]) {
			index = index + 1 +i;
		}
	}
	return index;
}

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  // Write a function that takes an array, its length and a number
  // and it returns the index of the given number in the array.
  // It should return -1 if did not find it. (linear search)
  cout << srch(numbers, 5, 7) << '\n';
  return 0;
}
