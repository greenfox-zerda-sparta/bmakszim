#include "stdafx.h"
#include <iostream>
#include <vector>

bool binary_search(std::vector<int>, int);

int main()
{
  std::vector<int> v {0,2,4,6,8,10,12,14,16,18};
  for (int i = -5; i < 25; i++) {
    std::cout << binary_search(v, i) << std::endl;
  }
  return 0;
}

bool binary_search(std::vector<int> v, int n) {
  int min = 0;
  int max = v.size() - 1;
  do {
    int guess = (min + max) / 2;
    if (v[guess] == n) {
      return true;
    } else if (v[guess] < n) {
      min = guess + 1;
    } else if (v[guess] > n) {
      max = guess - 1;
    }
  } while (min < max);
  if (min == max) {
    if (v[min] == n) {
      return true;
    }
  }
  return false;
}