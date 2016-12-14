#include "colour.hpp"

Colour::Colour() {
  red = 0;
  green = 0;
  blue = 0;
}

Colour::~Colour() {

}

Colour::Colour(uint8_t r, uint8_t g, uint8_t b) {
  red = r;
  green = g;
  blue = b;
}

uint8_t Colour::get_red() const {
  return red;
}

uint8_t Colour::get_green() const {
  return green;
}

uint8_t Colour::get_blue() const {
  return blue;
}

string Colour::get_rgb() {
  return to_string(red) + ',' + to_string(green) + ',' +  to_string(blue);
}

Colour::Colour(const Colour& other) {
  red = other.red;
  green = other.green;
  blue = other.blue;
}

Colour Colour::blend(const Colour& other) {
  uint8_t _r = (this->get_red() + other.get_red()) / 2;
  uint8_t _g = (this->get_green() + other.get_green()) / 2;
  uint8_t _b = (this->get_blue() + other.get_blue()) / 2;
  Colour c(_r, _g, _b);
  return c;
}

void Colour::darken(float amount) throw (const char*) {
  if (amount >= 0.0 && amount <= 1.0) {
    this->red *= amount;
    this->green *= amount;
    this->blue *= amount;
  } else {
    throw "Amount should be between 0.0 and 1.0!";
  }
}

void Colour::lighten(float amount) throw (const char*) {
  if (amount >= 0.0 && amount <= 1.0) {
    this->red += ((255 - this->red) * amount);
    this->green += ((255 - this->green) * amount);
    this->blue += ((255 - this->blue) * amount);
  } else {
    throw "Amount should be between 0.0 and 1.0!";
  }
}

Colour Colour::operator+(const Colour& other) {
  return this->blend(other);
}

Colour Colour::operator++ (int) {
  Colour c(red, green, blue);
  this->lighten(0.1);
  return c;
}

Colour& Colour::operator++ () {
  this->lighten(0.1);
  return *this;
}

Colour Colour::operator-- (int) {
  Colour c(red, green, blue);
  this->darken(0.9);
  return c;
}

Colour& Colour::operator-- () {
  this->darken(0.9);
  return *this;
}
