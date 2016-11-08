#include "Pirate.h"
#include <iostream>
#include <string>

using namespace std;

Pirate::Pirate(){
  this->rum_drunk = 0;
}

void Pirate::drink_rum() {
  ++this->rum_drunk;
}

string Pirate::hows_goin_mate() {
  return this->rum_drunk >= 5 ? "Arrrr!" : "Nothin\'";
}
