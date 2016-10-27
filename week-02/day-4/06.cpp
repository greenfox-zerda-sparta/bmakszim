#include <iostream>
#include <string>

using namespace std;

void howmany (int *array, int len) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    if ((array[i]%2) == 0 && (array[i+1]%2) == 0) {
      counter+=1;
    }
  }
  cout << counter << endl;
}

int main() {
  int numbers[] = {5, 2, 6, 3, 4, 8, 5, 2, 2, 2};
  howmany(numbers, 10);

  // Write a function that counts how many times is an even number is followed by
  // another even number in an array

  return 0;
}
