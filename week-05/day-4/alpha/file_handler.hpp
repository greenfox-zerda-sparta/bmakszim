#ifndef FILE_HANDLER_HPP_
#define FILE_HANDLER_HPP_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File_handler {
private:

protected:
  string todo[100];
  unsigned int number_of_todo;
public:
  File_handler();
  ~File_handler();
  void write(string _to_write);

};




#endif
