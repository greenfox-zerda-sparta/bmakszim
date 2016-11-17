#include "file_handler.hpp"
#include "check.hpp"

Check::Check(int _idx) {
  if (_idx > number_of_todo) {
    cerr << "Unable to remove: Index is out of bound." << endl;
    return;
  }
  char star = '*';
  string buffer;
  buffer = todo[_idx - 1];
  if (buffer[0] == star) {
    //cerr << "Task is already checked." << endl;
    return;
  }
  ofstream file;
  file.open("todo.csv");
  for (unsigned int i = 0; i < number_of_todo; i++) {
    if (i == (_idx - 1)) {
      file << "*" << todo[i] << '\n';
    } else {
      file << todo[i] << '\n';
    }
  }
}
