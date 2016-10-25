#include <iostream>
#include <string>

using namespace std;

int main() {
  char g1 = 'a';
  double g2 = 12.345;
  // Tell if g1 is stored in more bytes than g2
  bool a = sizeof(g1) > sizeof(g2);
  cout << a << '\n';
  return 0;
}
