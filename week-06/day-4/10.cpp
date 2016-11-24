#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main() {
  //find how much integer divisor 2400 has
  //create a vector of doubles, reserve place for the divisors of 2400
  //fill this places with random numbers from 0 to 2400
  //sort them in ascending order
  srand(time(NULL));
  int number = 2400;
  int counter = 1;
  for (int i = 1; i <= (number/2); i++) {
    if (number % i == 0) {
      counter++;
    }
  }
  cout << counter << endl;
  vector<double> vd;
  vd.reserve(counter);
  for (int i = 0; i < counter; i++) {
    vd.push_back(rand() % 2401);
  }
  sort(vd.begin(), vd.end());
  for (int i = 0; i < counter; i++) {
    cout << vd.at(i) << '|';
  }
  return 0;
}
