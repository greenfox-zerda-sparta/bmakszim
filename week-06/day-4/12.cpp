#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

vector<vector<int>> v(5, vector<int>(5, 0));

void increase(int a, int b) {
  v[a][b]++;
}

int main() {
  //create a vector of vector of integers
  //the inner vectors have 5 integers, all of them 0
  //the outer vector is holding 5 vector
  //create a function which increase a specific element of an inner vector by 1
  cout << v[3][3] << endl;
  increase(3, 3);
  cout << v[3][3] << endl;
  return 0;
}
