#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
  public:
    Circle(unsigned int radius);
    float get_circumference();
    float get_area();
  private:
    unsigned int radius;

};

#endif /* CIRCLE_H_ */
