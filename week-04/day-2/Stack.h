#ifndef STACK_H_
#define STACK_H_
#include <string>

using namespace std;

class Stack {
  private:
    double* elements;
    unsigned int length;
    unsigned int number_of_elements;
  public:
    Stack();
    unsigned int size();
    void push(double new_element);
    double pop();
};

#endif /* STACK_H_ */
