#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main() {
    // Create a `Stack` class that stores elements
    // It should have a `size` method that returns number of elements it has
    // It should have a `push` method that adds an element to the stack
    // It should have a `pop` method that returns the last element form the stack and also deletes it from it
  Stack numbers;
  numbers.push(1);
  numbers.push(2);
  numbers.push(3);
  numbers.push(4);
  numbers.push(5);
  cout << "Size of stack: " << numbers.size() << endl;
  cout << "Popped: " << numbers.pop() << endl;
  cout << "Size of stack: " << numbers.size() << endl;
  cout << "Popped: " << numbers.pop() << endl;
  cout << "Size of stack: " << numbers.size() << endl;
  return 0;
}
