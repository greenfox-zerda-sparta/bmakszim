#include <iostream>
#include <string>

using namespace std;

template <typename T, typename P>

void print_bigger(T a, P b) {
  sizeof a > sizeof b ? cout << a : cout << b;
}

int main() {
  //Create a function template that takes 2 different typenames, and prints out
  //which one is stored in more bytes from then
  int x = 1;
  char y = 'a';
  print_bigger(x, y);
  return 0;
}
