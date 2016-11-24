#include <iostream>
#include <string>

using namespace std;

template <class T>

void print_first(T& array) {
  cout << array[0] << endl;
}

int main() {
	// create a function template the takes in a fix long array and prints the 1st element of it
  int array[] = {1, 2, 3, 4, 5};
  float arrayf[] = {1.1, 2.2, 3.3, 4.4};
  char arrayc[] = {'a', 'b', 'c'};
  string arrays[] = {"abc", "def", "ghi"};
  print_first(array);
  print_first(arrayf);
  print_first(arrayc);
  print_first(arrays);
  return 0;
}
