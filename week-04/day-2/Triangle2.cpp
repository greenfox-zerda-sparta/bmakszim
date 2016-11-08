#include <iostream>
#include <string>
#include "Triangle2.h"

using namespace std;

Triangle::Triangle(unsigned int length){
  this->length = length;
  int temp = (this->length);
  for (int i = 1; i <= this->length*2; i+=2) {
    for (int k = temp; k > 0; k--) {
      cout << " ";
    }
    temp--;
    for (int j = 1; j <= i; j++) {
	    cout << '*';
	}
  cout << endl;
  }
}
