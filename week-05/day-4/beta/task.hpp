#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Task {
private:
  string* todo;
  unsigned int number_of_todo;
public:
  Task();
  ~Task();
  string usage();
  void list();
  void add(string _new_task);
  void remove(int _idx);
  void check(int _idx);
};
#endif
