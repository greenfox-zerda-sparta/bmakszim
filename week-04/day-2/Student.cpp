#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student() {
  unsigned int* array = new unsigned int[0];
  this->grades = array;
  this->size = 0;
}

void Student::add_grade(unsigned int grade) {
  unsigned int* new_array = new unsigned int[(this->size)+1];
  for (unsigned int i = 0; i < this->size; i++) {
    new_array[i] = *(this->grades+i);
  }
  new_array[this->size] = grade;
  ++this->size;
  delete[] this->grades;
  this->grades = new_array;
}

float Student::get_average() {
  float sum = 0;
  for (unsigned int i = 0; i < this->size; i++) {
    sum += *(this->grades+i);
  }
  return sum / this->size;
}

void Student::show_grades() {
  for (unsigned int i = 0; i < this->size; i++) {
    cout << *(this->grades+i) << endl;
  }
}
