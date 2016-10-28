#include <iostream>

using namespace std;

void swap (int*a, int* b) {
	int temp = a;
	a = b;
	b = temp;
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

  int a = 7;
  int b = 6;

  swap (a, b);
  cout << a, b << endl;
  return 0;
}
