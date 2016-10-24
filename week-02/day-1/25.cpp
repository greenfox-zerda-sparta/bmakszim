#include <iostream>
#include <string>

using namespace std;

int main() {
	// print the even numbers till 20
	int a = 0;
	while (a <= 20) {
		if (a%2 == 0) {
			cout << a++ << endl;
		} else {
			a++;
		}
	}

	int b = 0;
	do {
		if (b%2 == 0) {
			cout << b++ << endl;
		} else {
			b++;
		}
	} while( b <= 20);

	for (int c = 0; c <= 20; c++) {
		if (c%2 == 0) {
			cout << c << endl;
		}
	}

	return 0;
}

