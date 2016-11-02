#include <iostream>

using namespace std;

/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */

int* resize(int* old_array, int old_size, int new_size) {
  int* new_array = new int[new_size];
  for (int i = 0; i < new_size; i++) {
	if (i < old_size) {
      new_array[i] = old_array[i];
	} else {
	  new_array[i] = i;
	}
  }
  delete[] old_array;
  return new_array;
}

int main() {
  int* array = new int[5];
  for (int i = 0; i < 5; i++) {
    array[i] = i;
  }
  cout << "Original array: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << array[i] << endl;
  }
  int* new_array = new int[8];
  new_array = resize(array, 5, 8);
  cout << "New array: " << endl;
  for (int i = 0; i < 8; i++) {
    cout << new_array[i] << endl;
  }
  delete[] new_array;
  cout << "Original array now: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << array[i] << endl;
  }
return 0;
}
