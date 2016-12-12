// Define a function like macro that prints out the parameter it gets,
// and adds this string before it "DEBUG: " if __DEBUG is defined.
// Otherwise adds "RELEASE: " before the string.
// Use try it out. Illustrate that it works.

#include <iostream>

#if defined __DEBUG
#define prt(a) std::cout << "DEBUG: " <<  a
#else
#define prt(a) std::cout << "RELEASE: " << a
#endif


int main() {
int parameter = 1;
prt(parameter);
	return 0;
}
