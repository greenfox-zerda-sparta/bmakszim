#include <iostream>
#include <string>

using namespace std;

int main() {
	int k = 1521;
	bool a = (k%3) == 0 || (k%5) == 0;
	// tell if k is dividable by 3 or 5

	cout << a << endl;
	return 0;
}
