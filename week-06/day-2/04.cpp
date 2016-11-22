#include <iostream>
#include <string>
using namespace std;

// Write a function that receives a string and an unsigned integer.
// The function should return an array of strings, with two string in it.
// The first string should be the first part of the original string
// Characters in range [0,index-1].
// The second part should be the rest of the string characters range [index,length-1]
// Example: split("Rebarbara", 2)
// Result: {"Re", "barbara"}
// If the index is out of bounds, throw an exception.
//
// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.

string* function (string a, unsigned int b) throw (const char*) {
  unsigned int len = a.length();
  if (len < b) {
    throw "Index out of bound.";
  }
  string* array = new string[2];
  for (unsigned int i = 0; i < b; i++) {
    array[0] += a[i];
  }
  for (unsigned int i = b; i < len; i++) {
    array[1] += a[i];
  }
  return array;
}

int main () {
  try {
	string* array;
    array = function ("szelet", 6);
    cout << *array << endl << *(array+1);
    delete[] array;
  } catch (const char* excp) {
    cout << excp;
  }
  return 0;
}
