#include <iostream>
#include <string>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception. The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segmetn in a new try-catch block.

const char* sentence[6] = {"What", "a", "pleasant", "surprie", "this", "is."};

string get_word(int a) throw(int, const char*) {
  if (a > 5) {
    throw (a - 5);
  }
  if (a < 0) {
    throw "It is a negative number.";
  }
  return sentence[a];
}

int main() {
  for (int i = -1; i < 7; i++) {
    try {
      cout << get_word(i) << endl;
    } catch (int diff) {
      cout << "It is higher than 5 by " << diff << '.' << endl;
    } catch (const char* err) {
      cout << err << endl;
    }
  }
  return 0;
}
