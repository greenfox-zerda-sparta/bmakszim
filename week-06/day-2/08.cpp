#include <iostream>
#include <string>
using namespace std;

// Create a fixed size stack. The stack can contain only 5 elements.
// You can push on the stack and pop from the stack.
// Write the push and pop methods so, that each throws an integer value if there is an error.
// Like when the stack is empty or full. Just make sure those are different values.
// Write a method called string interpretException(int exception) that returns the error message string for the integer.
//
// Illustrate in the main function both when it works fine and when exceptions occur.

class Stack {
private:
  int* array;
  int length;
public:
  Stack();
  ~Stack();
  void push(int _number) throw(int);
  int pop() throw(int);
  int get_last();
  string interpretException(int exception);
};

Stack::Stack() {
  length = 0;
  array = new int[5];
}

Stack::~Stack() {
  delete[] array;
  array = NULL;
}

void Stack::push(int _number) throw(int) {
  if (length > 4) {
    throw 1;
  }
  array[length] = _number;
  length++;
}

int Stack::pop() throw(int) {
  if (length < 1) {
    throw 2;
  }
  length--;
  return array[length];
}

int Stack::get_last() {
  return array[length-1];
}

string Stack::interpretException(int exception) {
  switch (exception) {
  case 1:
    return "Stack is full.";
  case 2:
    return "Stack is empty.";
  }
}

int main () {
  Stack* a = new Stack;
  for(int i = 0; i < 8; i++) {
    try {
      a->push(i);
    } catch (int err) {
      cout << a->interpretException(err) << endl;
    }
  }
  for(int i = 0; i < 8; i++) {
    try {
      a->pop();
    } catch (int err) {
      cout << a->interpretException(err) << endl;
    }
  }
  delete a;
  return 0;
}
