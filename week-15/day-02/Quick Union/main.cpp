#include "stdafx.h"
#include <iostream>
#include "quick_union.h"

void draw(vector<vector<int>>v);

int main()
{
  Quick_union m_union(10);
  m_union.unite(3, 4);
  draw(m_union.get_groups());
  m_union.unite(4, 9);
  draw(m_union.get_groups());
  m_union.unite(8, 0);
  draw(m_union.get_groups());
  m_union.unite(2, 3);
  draw(m_union.get_groups());
  m_union.unite(5, 6);
  draw(m_union.get_groups());
  m_union.unite(5, 9);
  draw(m_union.get_groups());
  m_union.unite(7, 3);
  draw(m_union.get_groups());
  m_union.unite(4, 8);
  draw(m_union.get_groups());
  m_union.unite(6, 1);
  draw(m_union.get_groups());
  return 0;
}

void draw(vector<vector<int>>v) {
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
  std::cout << std::endl;
}