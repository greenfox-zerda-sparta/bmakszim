#include <iostream>
#include <string>
using namespace std;

// Duplicate the Stack class from the previous exercies.
// Rewrite it so, that the push and pop methods don't throw integers.
// Define an enum for te two types of exceptions.
// Adapt the interpretException method to except an argument from that enum type.
// Adapt the main function so that the try and catch blocks except an exception of that enum type.

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
  string interpretException(Exception a);
};

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

string Stack::interpretException(Exception a) {
  switch (a) {
  case full:
    return "Stack is full.";
  case empty:
    return "Stack is empty.";
  }
}

int main () {
  Stack* a = new Stack;
  for(int i = 0; i < 8; i++) {
    try {
      a->push(i);
    } catch (Exception& err) {
      cout << a->interpretException(err) << endl;
    }
  }
  for(int i = 0; i < 8; i++) {
    try {
      a->pop();
    } catch (Exception& err) {
      cout << a->interpretException(err) << endl;
    }
  }
  delete a;
  return 0;
}
