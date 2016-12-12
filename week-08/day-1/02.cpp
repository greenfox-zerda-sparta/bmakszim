// Create a constatn using a prepocesor directive.
// Print it out to the console.
// Undefine it. And then redefine it with a new value.
// Print it out again.

#include <iostream>
using namespace std;

#define ASD 10

int main() {
  cout << ASD << endl;
#undef ASD
#define ASD 20
  cout << ASD << endl;
  return 0;
}
