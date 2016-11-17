#include <iostream>
#include <string>
#include <fstream>
#include "task.hpp"
#include "argument.hpp"

using namespace std;

int main(int argc, char** argv) {
  Argument a(argc, argv);
  a.decide();
  return 0;
}
