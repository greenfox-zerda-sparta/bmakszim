#include "Stack.hpp"

Stack::Stack() {
  length = 0;
  array = new int[5];
}

Stack::~Stack() {
  delete[] array;
  array = NULL;
}

void Stack::push(int _number) throw(Exception) {
  if (length > 4) {
    throw full;
  }
  array[length] = _number;
  length++;
}

int Stack::pop() throw(Exception) {
  if (length < 1) {
    throw empty;
  }
  length--;
  return array[length];
}

int Stack::get_last() {
  return array[length-1];
}

