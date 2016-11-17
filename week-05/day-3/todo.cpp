#include <iostream>
#include <string>
#include <stdlib.h>
#include "file_handler.hpp"
#include "lists.hpp"
#include "add.hpp"
#include "remove.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  string l = "-l";
  string a = "-a";
  string r = "-r";
  if (argc == 1) {
    cout << "CLI Todo application" << endl << "====================" << endl << endl <<
    "Command line arguments:" << endl << " -l   Lists all the tasks" << endl <<
	" -a   Adds a new task" << endl << " -r   Removes a task" << endl <<
	" -c   Completes a task" << endl;
  } else if (argv[1] == l) {
    Lists list;
  } else if (argv[1] == a) {
    if (argc != 3) {
      cerr << "Unable to add: No task is provided" << endl;
    } else {
      Add add(argv[2]);
    }
  } else if (argv[1] == r) {
    if (argc != 3) {
      cerr << "Unable to remove: No index is provided" << endl;
    } else {
	  int a = atoi(argv[2]);
	  if (a == 0) {
        cerr << "Unable to remove: Index is not a number." << endl;
        return 0;
	  }
      Remove remove(a);
    }
  }

  return 0;
}
