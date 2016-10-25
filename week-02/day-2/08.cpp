#include <iostream>
#include <string>

using namespace std;

int main() {
  int h[] = {3, 4, 5, 6, 7};
	// print the sum of all numbers in h
  int a = 0;
  for (int i = 0; i < (sizeof(h)/sizeof(int)); i++){
	  a = a + h[i];
  }
  cout << a << '\n';
  return 0;
}
