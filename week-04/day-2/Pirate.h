#ifndef PIRATE_H_
#define PIRATE_H_
#include <string>

using namespace std;

class Pirate {
  private:
    unsigned int rum_drunk;
  public:
    Pirate();
    void drink_rum();
    string hows_goin_mate();
};

#endif /* PIRATE_H_ */
