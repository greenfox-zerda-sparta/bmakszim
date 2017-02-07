#include "stdafx.h"
#include "quick_union.h"
#include <iostream>

Quick_union::Quick_union(int _len) {
  for (int i = 0; i < _len; i++) {
    v.push_back(i);
  }
}

Quick_union::~Quick_union() {}

int Quick_union::root(int i) {
  while (i != v[i]) {
    i = v[i];
  }
  return i;
}

void Quick_union::unite(int a, int b) {
  int root_a = root(a);
  int root_b = root(b);
  if (a <= b) {
    v[root_b] = root_a;
  } else {
    v[root_a] = root_b;
  }
}

bool Quick_union::find(int a, int b) {
  return root(a) == root(b);
}

vector<vector<int>> Quick_union::get_groups() {
  vector<vector<int>>m_v;
  for (unsigned int i = 0; i < v.size(); i++) {
    if (i == v[i]) {
      m_v.push_back(vector<int>(1, i));
    }
  }
  for (unsigned int i = 0; i < v.size(); i++) {
    for (unsigned int j = 0; j < m_v.size(); j++) {
      if (root(i) == root(m_v[j][0]) && i != m_v[j][0]) {
        m_v[j].push_back(i);
      }
    }
  }
  return m_v;
}