#include "argument.hpp"

Argument::Argument(int c, char** v) {
  argc = c;
  argv = v;
}

void Argument::decide() {
  Task* task = new Task;
  if (argc == 1) {
    task->usage();
  } else if (argc == 2 && argv[1] == l) {
    task->list();
  } else if (argv[1] == a) {
    if (argc < 3) {
      cerr << "Unable to add: No task is provided." << endl;
    } else if (argc > 3) {
      task->unsupported();
      task->usage();
    } else {
      task->add(argv[2]);
    }
  } else if (argv[1] == r) {
    if (argc < 3) {
      cerr << "Unable to remove: No index is provided." << endl;
    } else if (argc > 3) {
      task->unsupported();
      task->usage();
    } else {
      int arg = atoi(argv[2]);
      if (arg == 0) {
        cerr << "Unable to remove: Index is not a number." << endl;
      } else {
        task->remove(arg);
      }
    }
  } else if (argv[1] == c) {
    if (argc != 3) {
      cerr << "Unable to check: No index is provided." << endl;
    } else {
      int arg = atoi(argv[2]);
      if (arg == 0) {
    	char zero[10];
    	string temp = argv[2];
    	itoa(arg, zero, 10);
    	if (zero == temp) {
          cout << "Unable to remove: Index is out of bound." << endl;
        } else {
          cerr << "Unable to check: Index is not a number." << endl;
        }
      } else {
        task->check(arg);
      }
    }
  } else {
    task->unsupported();
    task->usage();
  }
  delete task;
}
