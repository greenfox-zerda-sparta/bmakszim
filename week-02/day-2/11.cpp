#include <iostream>
#include <string>

using namespace std;

string add (string a) {
	return a + "a";
}

int main() {
  string k = "kuty";
  // write a function that gets a string as an input
  // and appends an 'a' character to its end
  cout << add(k) << '\n';
  return 0;
}
