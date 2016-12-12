// Create a function like macro, that gets an expression as it's input.
// If the expression is false, it should print out some error message.

#include <iostream>
#include <time.h>
using namespace std;

#define if_false(expression) if (!expression) cout << "ERROR" << endl

int main() {
  bool arsenal = 1;
  bool chelsea = 0;
  if_false(arsenal);
  if_false(chelsea);

  return 0;
}
