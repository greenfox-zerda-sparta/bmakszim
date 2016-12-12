// Create a function like macro that takes one argument.
// If the argument is false, it should print out the following:
// The expression in the argument. And the file name and the line in the file.

#include <iostream>
#include <time.h>
using namespace std;

#define magic(a) if (!a) cout << "Expression in the argument: " << a << ", in: " << __FILE__ << ", at: " << __LINE__ << endl;

int main() {
  bool arg = false;
  magic(arg);

  return 0;
}
