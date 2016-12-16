#include <iostream>
#include <string>

using namespace std;

int fun(int n) {
  if (n > 0) {
    return 2 + fun(n - 1);
  } else {
    return 0;
  }
}

int main() {
// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies
// recursively (without loops or multiplication).
  cout << fun(5);
  return 0;
}
