#include <iostream>
#include <string>

using namespace std;

int fun(int base, int p) {
  if (p > 1) {
    return base * fun(base, p - 1);
  } else {
    return base;
  }
}

int main() {
// Given base and n that are both 1 or more, compute recursively (no loops)
// the value of base to the n power, so powerN(3, 2) is 9 (3 squared).
  cout << fun(2, 10);
  return 0;
}
