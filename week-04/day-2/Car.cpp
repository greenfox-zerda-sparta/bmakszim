#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

Car::Car(string type, unsigned int km) {
  this->type = type;
  this->km = km;
}

void Car::run(unsigned int km_run) {
  this->km += km_run;
}

unsigned int Car::get_km() {
  return this->km;
}
