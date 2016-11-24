#include <iostream>
#include <string>
#include "Bouble.hpp"

using namespace std;

class Handler {
private:
  Bouble** boubles;
  int bouble_counter;
  int round;
  int hit_counter;
public:
  Handler();
  ~Handler();
  void add_bouble(Bouble& bouble);
  int go();
};

Handler::Handler() {
  round = 10;
  boubles = NULL;
  bouble_counter = 0;
}

Handler::~Handler() {
  delete[] boubles;
  boubles = NULL;
}

void Handler::add_bouble(Bouble& bouble) {
  Bouble** temp = new Bouble*[bouble_counter + 1];
  if (boubles != NULL) {
    for (int i = 0; i < bouble_counter; i++) {
      temp[i] = boubles[i];
    }
  }
  temp[bouble_counter] = &bouble;
  delete[] boubles;
  boubles = temp;
  bouble_counter++;
}

int Handler::go() {
  for (int i = 0; i < round; i++) {
    boubles[0]->move();
  }
  return boubles[0]->get_hit_counter();
}

int main() {
  Bouble a(0, 0, 3, 2);
  cout << "X: " << a.get_pos_x() << " Y: " << a.get_pos_y() << endl;
  cout << a.get_hit_counter() << endl;
  a.move();
  cout << "X: " << a.get_pos_x() << " Y: " << a.get_pos_y() << endl;
  cout << a.get_hit_counter() << endl;
  Handler h;
  h.add_bouble(a);
  cout << h.go();

  return 0;
}

