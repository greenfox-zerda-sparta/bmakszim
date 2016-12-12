// Create a function like macro. The Macro should take one parameter and
// print out the parameter to the console after printing out in which file
// and at which line it has been called at.

#include <iostream>
#include <time.h>
using namespace std;

#define prt(a) cout << "In: " << __FILE__ << " at: " << __LINE__ << ", " << a << " has been called." << endl

int main() {
  prt(44);

  return 0;
}
