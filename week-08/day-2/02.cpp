#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>

void print_vector(vector<T> v) {
  for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it;
    if (it != v.end() - 1) {
      cout << ", ";
    }
  }
  cout << endl;
}

// create a function that prints a vector using iterators

int main() {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  vector<string> s;
  s.push_back("asd");
  s.push_back("fgh");
  s.push_back("jkl");
  print_vector(v);
  print_vector(s);

  return 0;
}
