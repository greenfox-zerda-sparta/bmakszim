#include <iostream>
#include <string>

using namespace std;

int main() {
	string x = "cheese";
	bool a = x.length()%2 == 0;
	if (a == 1) {
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}
	// Tell if the x has even or odd number of
	// characters with a True for even and
	// false False output otherwise
	return 0;
}
