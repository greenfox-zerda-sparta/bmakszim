#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

Stack::Stack(){
  this->number_of_elements = 0;
  this->length = 2;
  double* array = new double[this->length];
  this->elements = array;
}

unsigned int Stack::size() {
  return this->number_of_elements;
}

void Stack::push(double new_element) {
  if ((this->number_of_elements)+1 > 0.8 * this->length) {
    this->length *= 2;
    double* new_array = new double[(this->length)];
    for (unsigned int i = 0; i < this->length; i++) {
      new_array[i] = *(this->elements+i);
    }
    new_array[this->number_of_elements] = new_element;
    ++this->number_of_elements;
    delete[] this->elements;
    this->elements = new_array;
  } else {
    *(this->elements+this->number_of_elements) = new_element;
    this->number_of_elements++;
  }
}

double Stack::pop() {
  this->number_of_elements--;
  return *(this->elements+this->number_of_elements);
}
