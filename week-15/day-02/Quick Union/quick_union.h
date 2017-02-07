#pragma once
#include <vector>
#include <set>
using namespace std;

class Quick_union {
private:
  vector<int> v;
  int root(int);
public:
  Quick_union(int);
  ~Quick_union();
  void unite(int, int);
  bool find(int, int);
  vector<vector<int>> get_groups();
};