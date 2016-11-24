#include <iostream>
#include <string>

using namespace std;

template <class T>

void print_all(T array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {
	// create a function template which takes in an array, and the size of it
	// print all the elements of the array
  float arrayf[] = {1.1, 2.2, 3.3, 4.4};
  char arrayc[] = {'a', 'b', 'c', 'd'};
  print_all(arrayf, 4);
  print_all(arrayc, 4);
  return 0;
}
