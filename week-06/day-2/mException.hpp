#ifndef MEXCEPTION_HPP_
#define MEXCEPTION_HPP_

#include "Stack.hpp"

class mException {
private:
  Exception exc;
  int element;

public:
  mException(Exception a, int b);
  Exception get_exc();
  int get_element();
  string toString();
};



#endif
