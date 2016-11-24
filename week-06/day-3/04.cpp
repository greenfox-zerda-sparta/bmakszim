#include <iostream>
#include <string>

using namespace std;

template <class T>

void sort_desc(T array[], int size) {
  bool swap = true;
  while (swap == true) {
    swap = false;
    for (int i = 0; i < size - 1; i++) {
      if (array[i] < array[i+1]) {
        T temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
        swap = true;
      }
    }
  }
  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {
	// create a function template that takes an array and sort it in a descending order
  int arrayi[] = {3, 2, 4, 1, 5, 8, 6, 9, 7};
  double arrayd[] = {4.5, 0.54, 6.9, 23.67, 0.02, 2.54};
  sort_desc(arrayd, 6);
  return 0;
}
