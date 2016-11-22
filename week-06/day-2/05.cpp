#include <iostream>
#include <string>
using namespace std;

// Write a function that receives a string and a character.
// The function should return an array of strings.
// The function should split the string at the character it receives as the second argument.
// The character it uses to split should not be in any of the new strings.
// Example: split("What a nice day", ' ');
// Result: {"What", "a", "nice",  "day"}
// If the character is not in the string throw an exception.
//
// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.

string* split (string a, char b) throw (const char*) {
  unsigned int counter = 1;
  unsigned int len = a.length();
  for (unsigned int i = 0; i < len; i++) {
    if (a[i] == b) {
      counter++;
    }
  }
  if (counter < 2) {
    throw "Character is not in the string.";
  }
  string* array = new string[counter];
  unsigned j = 0;
  for (unsigned int i = 0; i < len; i++) {
    if (a[i] == b) {
      j++;
    } else {
      array[j] += a[i];
    }
  }
  return array;
}

int main () {
  try {
    string* array = NULL;
    array = split("What a nice day", ' ');
    for (int i = 0; i < 4; i++) {
      cout << *(array+i) << endl;
    }
    array = split("What a nice day", 's');
    delete[] array;
  } catch (const char* err) {
    cout << err;
  }
  return 0;
}
