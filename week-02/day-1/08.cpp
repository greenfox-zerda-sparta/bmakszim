#include <iostream>
#include <string>

using namespace std;

int main() {
	int h1 = 350;
	int h2 = 200;
	bool a = (h2*=2) > h1;
	cout << a << endl;
	// tell if the double of h2 is bigger than h1
	return 0;
}
