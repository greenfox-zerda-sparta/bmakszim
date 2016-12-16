#include <iostream>
#include <string>

using namespace std;

string my_function(int n) {
  if (n > 0) {
    return to_string(n) + ", " +  my_function(n - 1);
  } else {
    return to_string(n);
  }
}

int main() {
// write a recursive function
// that takes one parameter: n
// and counts down from n
  cout << my_function(5);
  return 0;
}
