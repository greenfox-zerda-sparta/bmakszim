// Define 3 constants using a macro directive.
// One integer, one float and one string of characters.
// Print them out to the console in Your main funciton.

#include <iostream>
using namespace std;

#define CONST1 10
#define CONST2 2.3f
#define CONST3 "preprocessor"

int main() {
  cout << CONST1 << endl;
  cout << CONST2 << endl;
  cout << CONST3 << endl;
  return 0;
}
