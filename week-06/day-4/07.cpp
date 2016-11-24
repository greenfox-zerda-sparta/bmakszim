#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  //create a vector of integers with the size of 20
  //fill this vector with random numbers from 0 to 10
  //print the items of the vector
  //remove the even numbers, then print the items again
  srand(time(NULL));
  vector<int> v(20);
  int unsigned s = v.size();
  for (unsigned int i = 0; i < s; i++) {
    v.at(i) = rand() % 11;
  }
  for (unsigned int i = 0; i < s; i++) {
    cout << v.at(i);
    if (i != s-1) {
      cout << '|';
    }
  }
  cout << endl;
  for (unsigned int i = 0; i < v.size(); i++) {
    if (v.at(i) % 2 == 0) {
      v.erase(v.begin() + i);
      i--;
    }
  }
  for (unsigned int i = 0; i < v.size(); i++) {
    cout << v.at(i);
    if (i != s-1) {
      cout << '|';
    }
  }
  return 0;
}
