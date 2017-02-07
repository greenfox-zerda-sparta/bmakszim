#include "stdafx.h"
#include <iostream>
#include "quick_union.h"

int main()
{
  Quick_union m_union(10);
  m_union.unite(0, 1);
  m_union.unite(9, 3);
  m_union.unite(8, 9);
  m_union.unite(6, 7);
  vector<vector<int>>v = m_union.get_groups();
  for (int i = 0; i < v.size(); i++) {
    std::cout << "{";
    for (int j = 0; j < v[i].size(); j++) {
      std::cout << v[i][j];
      if (j != v[i].size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "}";
    if (i != v.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
  return 0;
}

