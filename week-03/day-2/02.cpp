#include <string>
#include <iostream>

using namespace std;

struct RectangularCuboid {
  double a;
  double b;
  double c;
};

// Write a function called "get_surface" that takes a RectangularCuboid
// and returns it's surface

// Write a function called "get_volume" that takes a RectangularCuboid
// and returns it's volume

int get_surface(RectangularCuboid* s){
  return 2*(s->a * s->b + s->a * s->c + s->b * s->c);
}

int get_volume(RectangularCuboid* v) {
  return v->a * v->b * v->c;
}

int main() {
  RectangularCuboid* ptr = new RectangularCuboid{1, 1, 1};
  cout << get_surface(ptr) << endl << get_volume(ptr) << endl;
  delete ptr;
  return 0;
}
