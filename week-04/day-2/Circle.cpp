#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(unsigned int radius) {
  this->radius = radius;
}

float Circle::get_circumference() {
  return this->radius * 2 * 3.14;
}

float Circle::get_area() {
  return this->radius * this->radius * 3.14;
}
