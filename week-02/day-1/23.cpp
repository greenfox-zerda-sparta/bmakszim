#include <iostream>
#include <string>

using namespace std;

int main() {
	int ad = 6;

	int a = 0;
	while (a <= ad) {
		cout << a++ << endl;
	}

	int b = 0;
	do {
		cout << b++ << endl;
	} while (b <= ad);

	for (int c = 0; c <= ad; c++) {
		cout << c << endl;
	}

	// print the numbers till ad from 0
	return 0;
}
