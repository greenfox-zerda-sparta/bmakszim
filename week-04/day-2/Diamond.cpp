#include <iostream>
#include <string>
#include "Diamond.h"

using namespace std;

Diamond::Diamond(unsigned int length){
  this->length = length;
  int temp = (this->length/2);
  for (int i = 1; i <= this->length; i+=2) {
    for (int k = temp; k > 0; k--) {
      cout << " ";
    }
    temp--;
    for (int j = 1; j <= i; j++) {
      cout << '*';
    }
    cout << endl;
  }
  temp = 0;
  for (int i = this->length/2*2-1 /*(/2*2): in order to work with even numbers, too*/ ; i >= 1; i-=2) {
    for (int k = 0; k <= temp; k++) {
      cout << " ";
    }
    temp++;
    for (int j = i; j >= 1; j--) {
      cout << '*';
    }
    cout << endl;
  }
}
