#include <iostream>
#include <string>

using namespace std;

int main() {
	int v = 426;
	if (v%4==0) {
		cout << "Yeah!" << endl;
	} else {
		cout << "End of program" << endl;
	}
	// print 'Yeah!' if dividable by 4 but print 'End of program' after regardless
	return 0;
}
