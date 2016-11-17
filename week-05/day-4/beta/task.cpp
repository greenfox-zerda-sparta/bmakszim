#include "task.hpp"

Task::Task() {
  number_of_todo = 0;
  todo = NULL;
  ifstream file;
  file.open("todo.txt");
  if (!file.is_open()) {
    ofstream newfile;
    newfile.open("todo.txt");
    newfile.close();
  } else {
    string buffer;
    while (getline(file, buffer)) {
      number_of_todo++;
    }
    file.close();
    todo = new string[number_of_todo];
    ifstream file2;
    file2.open("todo.txt");
    int i = 0;
    string buffer2;
    while (getline(file2, buffer2)) {
      todo[i] = buffer2;
      i++;
    }
    file2.close();
  }
}

Task::~Task() {
  delete[] todo;
}

string Task::usage() {
  return
  "CLI Todo application\n"
  "====================\n"
  "Command line arguments:\n"
  " -l   Lists all the tasks\n"
  " -a   Adds a new task\n"
  " -r   Removes a task\n"
  " -c   Completes a task";
}

void Task::list() {
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

void Task::add(string _new_task) {
  ofstream file;
  file.open("todo.txt");
  for (unsigned int i = 0; i < number_of_todo; i++) {
    file << todo[i] << '\n';
  }
  file << _new_task;
  file.close();
}

void Task::remove(int _idx) {
  if (_idx > number_of_todo) {
    cerr << "Unable to remove: Index is out of bound." << endl;
    return;
  }
  ofstream file;
  file.open("todo.txt");
  for (unsigned int i = 0; i < number_of_todo; i++) {
    if (i == (_idx - 1)) {
      continue;
    }
    file << todo[i] << '\n';
  }
  number_of_todo--;
}

void Task::check(int _idx) {
  if (_idx > number_of_todo) {
    cerr << "Unable to remove: Index is out of bound." << endl;
    return;
  }
  char star = '*';
  string buffer;
  buffer = todo[_idx - 1];
  if (buffer[0] == star) {
    return;
  }
  ofstream file;
  file.open("todo.txt");
  for (unsigned int i = 0; i < number_of_todo; i++) {
    if (i == (_idx - 1)) {
      file << '*' << todo[i] << '\n';
    } else {
      file << todo[i] << '\n';
    }
  }
}
