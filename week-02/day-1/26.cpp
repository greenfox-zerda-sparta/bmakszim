#include <iostream>
#include <string>

using namespace std;

int main() {
	// Write a program that prints the numbers from 1 to 100.
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".

	int b = 1;
	do {
		if ((b%3 == 0) && (b%5 == 0)) {
			cout << "FizzBuzz" << endl;
			b++;
		} else if (b%3 == 0) {
			cout << "Fizz" << endl;
			b++;
		} else if (b%5 == 0) {
			cout << "Buzz" << endl;
			b++;
		} else {
			cout << b++ << endl;
		}
	} while (b <=100);

	int a = 1;
	while (a <= 100) {
		if ((a%3 == 0) && (a%5 == 0)) {
			cout << "FizzBuzz" << endl;
			a++;
		} else if (a%3 == 0) {
			cout << "Fizz" << endl;
			a++;
		} else if (a%5 == 0) {
			cout << "Buzz" << endl;
			a++;
		} else {
			cout << a++ << endl;
		}
	}

	for (int c = 1; c <= 100; c++) {
			if ((c%3 == 0) && (c%5 == 0)) {
				cout << "FizzBuzz" << endl;
			} else if (c%3 == 0) {
				cout << "Fizz" << endl;
			} else if (c%5 == 0) {
				cout << "Buzz" << endl;
			} else {
				cout << c << endl;
			}
		}

	return 0;
}
