#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int j1 = 10;
	int j2 = 3;
	bool a = j1 > sqrt (j2) && j1 < pow (j2, 2);
	cout << a << endl;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed
	return 0;
}
