#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

vector<int> row(4);
vector<vector<int>> matrix (4, row);

void print_vector() {
  cout << endl;
  for (unsigned int i = 0; i < matrix.size(); i++) {
    for (unsigned int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i].at(j) << ' ';
    }
    cout << endl;
  }
}

int main() {
  //Create a 2 dimensional vector with matrix!
  // 1 0 0 0
  // 0 1 0 0
  // 0 0 1 0
  // 0 0 0 1
  // Extend it to the following format:
  // 1 1 1 1 1
  // 0 1 0 0 1
  // 0 0 1 0 1
  // 0 0 0 1 1
  // 0 0 0 0 1
  // Mirror it horizontaly!
  // Mirror it verticaly!

//2 dimensional matrix
  for (unsigned int i = 0; i < matrix.size(); i++) {
    matrix[i][i] = 1;
  }

  print_vector();

//Extended
  matrix.push_back(row);
  for (unsigned int i = 0; i < matrix.size(); i++) {
    matrix[i].push_back(1);
    matrix[0].at(i) = 1;
  }

  print_vector();

//Mirrored horizontally
  for (unsigned int i = 0; i < (matrix.size() / 2); i++) {
    swap(matrix[i], matrix[(matrix.size()-i)-1]);
  }

  print_vector();

//Mirrored vertically
  for (unsigned int i = 0; i < matrix.size(); i++) {
    for (unsigned int j = 0; j < (matrix[i].size() / 2); j++) {
      swap(matrix[i][j], matrix[i][(matrix[i].size()-j)-1]);
    }
  }

  print_vector();
  return 0;
}
