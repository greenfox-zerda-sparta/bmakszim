// Take the function like macro from the previous exercise.
// Make it so, that it's defined like the way You wrote it
// when __DEBUG is defined.
// It's defined to be nothing otherwise.

#include <iostream>
#include <time.h>
using namespace std;

#if defined __DEBUG
#define magic(a) if (!a) cout << "Expression in the argument: " << a << ", in: " << __FILE__ << ", at: " << __LINE__ << endl;
#else
#define magic(a)
#endif

int main() {
  bool arg = false;
  magic(arg);

  return 0;
}
