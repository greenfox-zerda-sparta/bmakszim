#include "Triangle.h"
#include <iostream>
#include <string>

using namespace std;

Triangle::Triangle(unsigned int length){
  this->length = length;
  string a = "";
  for (int i = 0; i < this->length; i++) {
    a += "*";
    cout << a << endl;
  }
}
