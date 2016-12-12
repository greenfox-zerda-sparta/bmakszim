// Create a function like macro, that get's one parameter.
// This macro should print out that paramter using cout.
// Illustrate that it works in Your main function.

#include <iostream>
#include <time.h>
using namespace std;

#define prt(parameter) cout << parameter

int main() {
  prt(10);
  return 0;
}
