#include <iostream>
#include <string>

using namespace std;

template <class T>

double sum_of_elements(T array[], int length) {
  T sum = T();
  for (int i = 0; i < length; i++) {
    sum += array[i];
  }
  return sum;
}

template<>
double sum_of_elements<char> (char array[], int length) {
  double sum = 0;
  for (int i = 0; i < length; i++) {
    if (array[i] - 96 > 0) {
      sum += (array[i] - 96);
    } else {
    	sum += (array[i] - 64);
    }
  }
  return sum;
}

int main() {
  // Create a function template that takes an array, and its length and return the sum of his elements
  // Create a template specialization for char types, that it returns the sum of the characters integer position in the alphabet

  int arrayi[] = {1, 2, 3, 4, 5};
  double arrayd[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  char arrayc[] = {'a', 'B', 'c', 'D', 'E'};
  cout << sum_of_elements(arrayi, 5) << endl;
  cout << sum_of_elements(arrayd, 5) << endl;
  cout << sum_of_elements(arrayc, 5) << endl;

  return 0;
}
