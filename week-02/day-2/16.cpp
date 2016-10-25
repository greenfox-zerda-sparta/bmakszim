#include <iostream>
using namespace std;

int main(){
	int m[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
	//This is an array of arrays. Print it out as a 3x3 matrix. Using each inner array as
	//a.) a row
	//b.) a column
	//c.) all in one line separated by the character '|'
	//d.) all in one column
	for (int i = 0; i < 3; i++) {           //inner array in a row
		for (int j = 0; j < 3; j++) {
			cout << m[i][j];
		}
		cout << '\n';
	}
	cout << '\n';

	for (int i = 0; i < 3; i++) {           //inner array in a column
		for (int j = 0; j < 3; j++) {
			cout << m[j][i];
		}
		cout << '\n';
	}
	cout << '\n';

	for (int i = 0; i < 3; i++) {           //all in one row separated by |
		for (int j = 0; j < 3; j++) {
			cout << m[i][j];
			if (i == 2 && j == 2) {
				cout << '\n';
				break;
			}
			cout << '|';
		}
	}
	cout << '\n';

	for (int i = 0; i < 3; i++) {           //all in one column
		for (int j = 0; j < 3; j++) {
			cout << m[i][j] << '\n';
		}
	}
	return 0;
}
