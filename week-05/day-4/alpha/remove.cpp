#include "file_handler.hpp"
#include "remove.hpp"

Remove::Remove(int _idx) {
  if (_idx > number_of_todo) {
    cerr << "Unable to remove: Index is out of bound." << endl;
    return;
  }
  ofstream file;
  file.open("todo.csv");
  for (unsigned int i = 0; i < number_of_todo; i++) {
    if (i == (_idx - 1)) {
      continue;
    }
    file << todo[i] << '\n';
  }
  number_of_todo--;
}
