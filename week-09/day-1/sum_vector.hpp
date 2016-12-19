#ifndef SUM_VECTOR_HPP_
#define SUM_VECTOR_HPP_

#include <vector>
using namespace std;

class Sum_class {
public:
  int sum_vector(vector<int>& v) {
    int s = 0;
    for (int i = 0; i < v.size(); i++) {
      s += v[i];
    }
    return s;
  }
};



#endif
