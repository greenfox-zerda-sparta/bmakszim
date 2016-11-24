#include <iostream>
#include <string>

using namespace std;

template <class T>

class Calculator {
private:
  T result;
public:
  Calculator(T init);
  T add(T a);
  T subtract(T s);
  T multiply(T m);
  T divide(T d) throw(const char*);
};

template <class T>
Calculator<T>::Calculator(T init) {
  result = init;
}

template <class T>
T Calculator<T>::add(T a) {
  result += a;
  return result;
}

template <class T>
T Calculator<T>::subtract(T s) {
  result -= s;
  return result;
}

template <class T>
T Calculator<T>::multiply(T m) {
  result *= m;
  return result;
}

template <class T>
T Calculator<T>::divide(T d) throw(const char*) {
  if (d == 0) {
    throw "Dividing by zero.";
  }
  result /= d;
  return result;
}

int main() {
	//Create a class template for a calculator
    //it should have all the basic methods: add, subtract, multiply, divide
    //use exceptions to handle errors in special cases! (find the special cases!)
  Calculator <float>a(1.1);
  cout << a.add(2.2) << endl;
  cout << a.subtract(3.3) << endl;
  cout << a.multiply(2.5) << endl;
  try {
    cout << a.divide(0) << endl;
  } catch (const char* err) {
    cout << err << endl;
  }
  return 0;
}

