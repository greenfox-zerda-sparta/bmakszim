#include <iostream>
#include <string>

using namespace std;

int fun(int n) {
  if (n > 10) {
    return (n % 10) + (fun(n / 10));
  } else {
    return n;
  }
}

int main() {
// Given a non-negative int n,
// return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6),
// while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
  cout << fun(12345);
  return 0;
}
