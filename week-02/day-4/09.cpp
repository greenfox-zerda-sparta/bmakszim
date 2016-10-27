#include <iostream>

using namespace std;

void diamond (int number) {
  int temp = (number/2);
  for (int i = 1; i <= number; i+=2) {
    for (int k = temp; k > 0; k--) {
      cout << " ";
    }
    temp--;
    for (int j = 1; j <= i; j++) {
	    cout << '*';
	}
  cout << endl;
  }
  temp = 0;
  for (int i = number/2*2-1 /*(/2*2): in order to work with even numbers, too*/ ; i >= 1; i-=2) {
      for (int k = 0; k <= temp; k++) {
        cout << " ";
      }
      temp++;
      for (int j = i; j >= 1; j--) {
  	    cout << '*';
  	}
    cout << endl;
    }
}

int main() {
  // Create a function that takes a number and prints a diamond like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //  *********
  //   *******
  //    *****
  //     ***
  //      *
  //
  // The diamond should have as many lines as the value in the argument
  diamond(9);
  return 0;
}
