// Create a function like macro that takes an argumnet.
// It should print the the code of the argument and the value of the argument too.
// E.g.:
//
// #define FunctionLikeMacro(a) //here comes magic
// int Main() {
// 	int a = 23;
// 	FunctionLikeMacro(a);
//
// }
//
// Should have the output:
// Variable a = 23;
// Where both 'a' and '23' are set by teh macro.

#include <iostream>
#include <time.h>
using namespace std;

#define magic(a) cout << "Variable " << #a << " = " << a << ';' << endl;

int main() {
int arsenal = 1;
magic(arsenal);

  return 0;
}
