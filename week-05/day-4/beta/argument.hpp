#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP

#include "task.hpp"

const string l = "-l";
const string a = "-a";
const string r = "-r";
const string c = "-c";

class Argument {
private:
  int argc;
  char** argv;
public:
  Argument(int c, char** v);
  void decide();
};

#endif
