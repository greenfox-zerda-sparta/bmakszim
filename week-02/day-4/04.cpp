#include <iostream>

using namespace std;

void reverser (int *array, int len) {
  for (int i = 0; i < len; i++) {
    if (i < len/2) {
	  int temp = array[i];
	  array[i] = array[(len - 1) - i];
	  array[(len - 1) - i] = temp;
    }
    cout << array[i] << endl;
  }
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
  reverser (array, 8);

  // Write a function that takes an array and its length than reverses the array

  return 0;
}
