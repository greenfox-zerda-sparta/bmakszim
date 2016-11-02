#include <iostream>

using namespace std;

int main() {
  int* pointer = new int[5];

  // Please allocate a 10 long array and fill it with numbers from 0 to 9, then print the whole array
  // Please delete the array before the program exits

  int* pointer2 = new int[10];
  for (int i = 0; i < 10; i++) {
    pointer2[i] = i;
  }
  for (int i = 0; i < 10; i++) {
    cout << pointer2[i] << endl;
  }
  delete[] pointer;
  delete[] pointer2;
  pointer = nullptr;
  pointer2 = nullptr;
  return 0;
}
