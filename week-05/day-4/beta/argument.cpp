#include "argument.hpp"

Argument::Argument(int c, char** v) {
  argc = c;
  argv = v;
}

void Argument::decide() {
  if (argc == 1) {
    Task* a = new Task;
    cout << a->usage();
    delete a;
  } else if (argc > 1 && argv[1] != l && argv[1] != a && argv[1] != r && argv[1] != c) {
    Task* a = new Task;
    cerr << endl << "Unsupported argument!" << endl << endl;
    cout << a->usage();
    delete a;
  } else if (argv[1] == l) {
    Task* a = new Task;
    a->list();
    delete a;
  } else if (argv[1] == a) {
    if (argc != 3) {
      cerr << "Unable to add: No task is provided." << endl;
    } else {
      Task* a = new Task;
      a->add(argv[2]);
      delete a;
    }
  } else if (argv[1] == r) {
    if (argc != 3) {
      cerr << "Unable to remove: No index is provided." << endl;
    } else {
      int arg = atoi(argv[2]);
      if (arg == 0) {
        cerr << "Unable to remove: Index is not a number." << endl;
      } else {
        Task* a = new Task;
        a->remove(arg);
        delete a;
      }
    }
  } else if (argv[1] == c) {
    if (argc != 3) {
      cerr << "Unable to remove: No index is provided." << endl;
    } else {
      int arg = atoi(argv[2]);
      if (arg == 0) {
        cerr << "Unable to remove: Index is not a number." << endl;
      } else {
        Task* a = new Task;
        a->check(arg);
        delete a;
      }
    }
  }
}
