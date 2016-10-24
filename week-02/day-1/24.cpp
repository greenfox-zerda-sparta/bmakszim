#include <iostream>
#include <string>

using namespace std;

int main() {
	int ae = 4;
	string text = "Gold";
	// print content of the text variable ae times
	int a = 0;
	while (a < ae) {
		a++;
		cout << text << " with while" << endl;
	}

	int b = 0;
	do {
		b++;
		cout << text << " with do_while" << endl;
	} while (b < ae);

	for (int c = 0; c < ae; c++) {
		cout << text << " with for loop" << endl;
	}

	return 0;
}
