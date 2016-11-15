#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string read_file(string _file);

int main() {
  // Write a function that reads the content of a file and returns it as a string
  // It should take the filename as a string parameter
  cout << read_file("fourth-exercise.txt");
  return 0;
}

string read_file(string _file) {
  ifstream mFile;
  mFile.open(_file);
  if (!mFile.is_open()) {
    cerr << "Could not open the file.";
    return "";
  }
  string temp = "";
  string buffer;
  while (mFile >> buffer) {
    temp += buffer + '\n';
  }
  mFile.close();
  return temp;
}
