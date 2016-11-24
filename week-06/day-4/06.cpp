#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<double> v(30, 1.5);

void shorten() {
  int s = v.size();
  v.at(rand() % (s-1)) += v.at(s - 1);
  v.resize(s - 1);
}

int main() {
  //create a vector of doubles with the size of 30, with every element equal of 1.5
  //create functions that takes this vector, pick the last element of it and adding its value to
  //an other item from the vector(this item place is random) and remove the last element at the end
  //run this function 20 times, then print every element of the vector
  srand (time(NULL));
  for (int i = 0; i < 20; i++) {
    shorten();
  }
  for (unsigned int i = 0; i < v.size(); i++) {
    cout << v.at(i) << endl;
  }
  return 0;
}

