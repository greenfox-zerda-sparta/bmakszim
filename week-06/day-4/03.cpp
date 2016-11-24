#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  //Create a vector of integers
  //reserve place for 10 element, then fill those place with random numbers between 0 and 10
  vector<int> v;
  v.reserve(10);
  int c = v.capacity();
  srand (time(NULL));
  for (int i = 0; i < c; i++) {
    v.push_back(rand() % 11);
  }
  for (unsigned int i = 0; i < v.size(); i++) {
    cout << v.at(i) << '|';
  }
  return 0;
}
