#ifndef STACK_HPP_
#define STACK_HPP_

#include <iostream>
#include <string>
using namespace std;

enum Exception {full, empty};

class Stack {
private:
  int* array;
  int length;
public:
  Stack();
  ~Stack();
  void push(int _number) throw(Exception);
  int pop() throw(Exception);
  int get_last();
};

#endif
