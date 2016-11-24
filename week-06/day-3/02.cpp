#include <iostream>
#include <string>

using namespace std;

template <class T>

T add(T array[]) {
  return array[0] + array[2];
}

int main() {
	// create a function template that takes 3 long array
	// and add the 1st element of it to the third
  int arrayi[] = {1, 2, 3};
  float arrayf[] = {1.1, 2.2, 3.3};
  cout << add(arrayi) << endl;
  cout << add(arrayf);
  return 0;
}
