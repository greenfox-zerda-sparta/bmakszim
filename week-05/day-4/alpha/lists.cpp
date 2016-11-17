#include "file_handler.hpp"
#include "lists.hpp"

Lists::Lists() {
  if (number_of_todo == 0) {
    cout << "No todos for today! :)" << endl;
  } else {
	char star = '*';
	string buffer;
    for (unsigned int i = 0; i < number_of_todo; i++) {
      buffer = todo[i];
      if (buffer[0] == star) {
        todo[i] = todo[i].substr(1);
        cout << i+1 << " - [x] " << todo[i] << endl;
      } else {
        cout << i+1 << " - [ ] " << todo[i] << endl;
      }
    }
  }
}

