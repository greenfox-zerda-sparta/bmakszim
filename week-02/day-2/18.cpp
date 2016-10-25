#include <iostream>
using namespace std;

int evennumbers (int array[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (array[i]%2 == 0) {
			count++;
		}
	}
	return count;
}

int main(){
  int numbers[] = {4, 5, 6, 2, 3, 8, 6, 5};
  // create a function that takes an array and it's length as an agrument
  // and returns a number that states how many even numbers are in the array
  cout << evennumbers(numbers, 8) << endl;
	return 0;
}
