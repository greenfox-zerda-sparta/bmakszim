#include <iostream>
#include "colour.hpp"

using namespace std;

int main() {
  Colour first(200, 150, 200);
  /*Colour second(150, 250, 150);
  Colour copied(first);
  cout << copied.get_rgb() << endl;
  Colour blended = second.blend(copied);
  try {
    blended.darken(0.5);
  } catch (const char* s) {
    cerr << s << endl;
  }
  cout << blended.get_rgb() << endl;
  try {
    blended.lighten(0.97);
  } catch (const char* s) {
    cerr << s << endl;
  }
  cout << blended.get_rgb() << endl;
  cout << (blended + first).get_rgb() << endl;*/
  cout << (first--).get_rgb() << endl;
  cout << first.get_rgb() << endl;
  return 0;
}
