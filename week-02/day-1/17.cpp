#include <iostream>
#include <string>

using namespace std;

int main() {
	float w = 24;
	int w_int = static_cast<int>(w);
	int out = 0;
	if (w == w_int) {
		if ((w_int%2) == 0) {
			out++;
		}
	}
	cout << out << endl;
	// if w is even increment out by one
	return 0;
}
