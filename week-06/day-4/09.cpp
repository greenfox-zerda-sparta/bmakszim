#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<vector<int>> outer(5, vector<int>(5, 0));

void add_vector() {
  vector<int> a(5, 1);
  outer.push_back(a);
}

int main() {
  //create a vector of vector of integers, yeah a vector that holds vectors of integers
  //the inner vectors have 5 integers, all of them 0
  //the outer vector is holding 5 vector at the beginning
  //create a function that will add a new vector of integers to the end of our outer vector
  add_vector();
 return 0;
}
