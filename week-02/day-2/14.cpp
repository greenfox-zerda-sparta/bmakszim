#include <iostream>
#include <string>

using namespace std;

int min (int a[], int len) {
	int m = a[0];
	for (int i = 1; i < len; i++) {
		if (a[i] < m){
			m = a[i];
		}
	}
	return m;
}

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  // Write a function that takes ana array and its length returns the minimal element
  // in the array (your own min function)
  cout << min(numbers, 5) << '\n';
  return 0;
}
