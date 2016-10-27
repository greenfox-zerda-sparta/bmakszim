#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void squares (int *array, int len) {
  for (int i = 0; i < len; i++) {
    array[i] = pow (array[i], 2);
	cout << array [i] << endl;
  }
}

int main() {
  // Write a function that takes an array and squares all the elements in the array
  int array[] = {1, 2, 3, 4, 5, 6, 7};
  squares (array, 7);

  return 0;
}
