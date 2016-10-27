#include <iostream>

using namespace std;

void triangle (int number) {
  int temp = number-1;
  for (int i = 1; i <= number*2; i+=2) {
    for (int k = temp; k > 0; k--) {
      cout << " ";
    }
    temp--;
    for (int j = 1; j <= i; j++) {
	    cout << '*';
	}
  cout << endl;
  }
}

int main() {
	  // Create a function that takes a number and prints a triangle like this:
	  //
	  //      *
	  //     ***
	  //    *****
	  //   *******
	  //  *********
	  // ***********
	  //
	  // The triangle should have as many lines as the value in the argument

  int number = 7;
  triangle (number);
  return 0;
}
