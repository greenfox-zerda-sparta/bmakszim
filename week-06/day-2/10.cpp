#include <iostream>
#include <string>
#include "Stack.hpp"
#include "mException.hpp"

using namespace std;

// Duplicate the Stack class from the previous exercies.
// Create a class for Your exception.
// The class should have two private fields:
// 1.) A filed from Your enum type to represent the kind of error.
// 2.) A field of type: int. So You can give back the element or the index which caused the problems.
// Set all the fields in the constructor only.
// Create get... methods for both variables.
// Create an std::string toString() method, which gives back a comprehensive error message.
//
// Demonstrate how this works in the main function. Print the error messages from the main function

int main () {
  Stack* a = new Stack;
  for(int i = 0; i < 8; i++) {
    try {
      a->push(i);
    } catch (Exception& err) {
      mException asd(err, i);
      cout << asd.toString() << endl;
    }
  }
  for (int i = 0; i < 8; i++) {
    try {
      a->pop();
    } catch (Exception& err) {
      mException asd(err, 0);
      cout << asd.toString() << endl;
    }
  }
  delete a;
  return 0;
}
