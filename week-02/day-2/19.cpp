#include <iostream>
using namespace std;

int ifPrime (int number) {
  bool a;
  for (int i = 2; i <= (number / 2); i++) {
    a = (number % i) != 0;
    if (a != 1) {
	  break;
	}
  }
  return a;
}

int main(){
  int number = 523;
  // create a function that decides if a number is a prime number.
  // It should take a number as an argument and return true if it is prime and
  // false otherwise.
  cout << ifPrime(number) << endl;
	return 0;
}
