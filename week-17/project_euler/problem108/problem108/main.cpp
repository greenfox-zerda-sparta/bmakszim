#include <iostream>

using namespace std;

unsigned long long int count_soloutions(unsigned long long int _n);

int main() {
  unsigned long long int i = 0;
  unsigned long long int n;
  do {
    i++;
    n = count_soloutions(i);
    //cout << "For " << i << " the number of disctinc solutions: " << n << endl;
    if (n > 1000) {
      break;
    }
  } while (1);
  cout << i << endl;
  //cout << count_soloutions(180180) << endl;
  return 0;
}

unsigned long long int count_soloutions(unsigned long long int _n) {
  unsigned long long int count = 0;
  unsigned long long int y_numerator;
  unsigned long long int y_denominator;
  long double y;
  for (unsigned long long int i = _n + 1; i <= (_n * 2); i++) {
    y_denominator = i * _n;
    y_numerator = i - _n;
    y = long double(y_denominator) / long double(y_numerator);
    //if (i > 65770) {
    //  cout << y << "=" << y_denominator << "/" << y_numerator << endl;
    //}
    if (y == unsigned long long int(y)) {
      //if (((i - _n) * ((y_denominator/y_numerator) - _n)) == (_n * _n)) {
        count++;
        //cout << "    y  = " << y << endl;
        //cout << "int(y) = " << int(y) << endl;
        //cout << "1/" << i << " + 1/" << (y_denominator / y_numerator) << " = 1/" << _n << endl;
     //}
    }
  }
  return count;
}