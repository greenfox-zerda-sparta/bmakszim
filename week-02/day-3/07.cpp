#include <iostream>

using namespace std;

int main() {
  int high_number = 6655;
  int low_number = 2;

  int* high_number_pointer = &low_number;
  int* low_number_pointer = &high_number;
  // Please fix the problem and swap where the pointers point,
  // without using the "&" operator.
  cout << high_number_pointer << endl << low_number_pointer << endl;

  int *temp = high_number_pointer;
  high_number_pointer = low_number_pointer;
  low_number_pointer = temp;

  cout << high_number_pointer << endl << low_number_pointer << endl;
  return 0;
}
