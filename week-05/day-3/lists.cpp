#include "file_handler.hpp"
#include "lists.hpp"

Lists::Lists() {
  if (number_of_todo == 0) {
    cout << "No todos for today! :)" << endl;
  } else {
    for (unsigned int i = 0; i < number_of_todo; i++) {
      cout << i+1 << " - " << todo[i] << endl;
    }
  }
}

