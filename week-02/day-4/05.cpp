#include <iostream>

using namespace std;

void ifNegative (int *array, int len) {
  bool ifneg = 0;
  for (int i = 0; i < len; i++) {
    if (array[i] < 0) {
      ifneg = 1;
    }
  }
  if (ifneg == 0) {
    cout << "Nincs negativ szam." << endl;
  } else {
	cout << "Van negativ szam." << endl;
  }
}

int main() {
  int numbers[] = {6, 5, -3, 4, -1, 8, 7};
  ifNegative (numbers, 7);
  // Write a function that decides if an array includes at least one negative number or not

  return 0;
}
