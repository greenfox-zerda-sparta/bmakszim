#include <iostream>
#include <string>

using namespace std;

int my_function(int n) {
  if (n > 0) {
    return n + my_function(n - 1);
  } else {
    return n;
  }
}

int main() {
// write a recursive function
// that takes one parameter: n
// and adds numbers from 1 to n
  cout << my_function(5);
  return 0;
}
