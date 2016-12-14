#ifndef COLOUR_HPP_
#define COLOUR_HPP_

#include <cstdint>
#include <string>

using namespace std;

class Colour {
private:
  uint8_t red;
  uint8_t green;
  uint8_t blue;
public:
  Colour();
  ~Colour();
  Colour(uint8_t r, uint8_t g, uint8_t b);
  string get_rgb();
  uint8_t get_red() const;
  uint8_t get_green() const;
  uint8_t get_blue() const;
  Colour(const Colour& other);
  Colour blend(const Colour& other);
  void darken(float amount) throw (const char*);
  void lighten(float amount) throw (const char*);
  Colour operator+(const Colour& other);
  Colour operator++(int);
  Colour& operator++();
  Colour operator--(int);
  Colour& operator--();
};



#endif
