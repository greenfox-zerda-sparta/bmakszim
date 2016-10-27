#include <iostream>

using namespace std;

void triangle (int number) {
  for (int i = 1; i <= number; i++) {
    for (int j = 1; j <= i; j++) {
      cout << '*';
    }
    cout << endl;
  }
}

int main() {
  // create a function that takes a number and prints a triangle like this:
  // *
  // **
  // ***
  // ****
  // *****
  // ******
  //
  // The triangle should have as many lines as the value in the argument
  int number = 8;
  triangle (number);
  return 0;
}
