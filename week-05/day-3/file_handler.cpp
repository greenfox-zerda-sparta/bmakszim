#include "file_handler.hpp"

File_handler::File_handler() {
  ifstream file;
  file.open("todo.txt");
  number_of_todo = 0;
  if (!file.is_open()) {
    ofstream newfile;
    newfile.open("todo.txt");
    newfile.close();
  }
  string buffer;
  while (getline(file, buffer)) {
    number_of_todo++;
  }
  file.close();
  ifstream file2;
  file2.open("todo.txt");
  unsigned int i = 0;
  while (getline(file2, todo[i])) {
    i++;
  }
  file2.close();
}

File_handler::~File_handler() {

}

void File_handler::write(string _to_write) {
  ofstream file;
  file.open("todo.txt");
  for (unsigned int i = 0; i < number_of_todo; i++) {
    file << todo[i] << '\n';
  }
  file << _to_write;
  file.close();
}
