#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  //create a vector of integers with the size of 10, fill them with random numbers
  //create a vector of doubles and reserve place for 10 items
  //push and item to the end of the vector with the double places
  //print which vectors size is higher (and why?)
  srand (time(NULL));
  vector<int> vi(10);
  int s = vi.size();
  for (int i = 0; i < s; i++) {
    vi.at(i) = (rand() % 10);
  }
  vector<double> vd;
  vd.reserve(10);
  vd.push_back(10);
  cout << "Size of int: "<< vi.size() << endl;
  cout << "Size of double: "<< vd.size() << endl;

  return 0;
}
