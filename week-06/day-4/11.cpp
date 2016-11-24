#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

vector<vector<int>> v(5, vector<int>(5, 0));

void increase(int a) {
  for (unsigned int i = 0; i < v[a].size(); i++) {
    v[a][i]++;
  }
}

int main() {
  //create a vector of vector of integers
  //the inner vectors have 5 integers, all of them 0
  //the outer vector is holding 5 vector
  //create a function which increase the given inner vector elements by 1 (one inside vector, holding five 0)
  for (unsigned int i = 0; i < v[3].size(); i++) {
    cout << v[3][i] << endl;
  }
  increase(3);
  for (unsigned int i = 0; i < v[3].size(); i++) {
    cout << v[3][i] << endl;
  }
  return 0;
}
