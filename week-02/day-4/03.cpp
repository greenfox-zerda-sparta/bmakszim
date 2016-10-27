#include <iostream>

using namespace std;

void swap (int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}

int main() {
  int first = 12;
  int second = 54;
  swap (first, second);
  cout << first << endl << second << endl;

  // Write a function that takes two int pointers and swaps the values where the pointers point

  return 0;
}
