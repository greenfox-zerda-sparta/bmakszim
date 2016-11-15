#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write_file(string _file, string _content);

int main() {
  // Write a function that writes a string to a file
  // It should take the filename and the content as a string parameter
  write_file("try.txt", "elso sor\nmasodik sor\nharmadik sor");
  return 0;
}

void write_file(string _file, string _content) {
  ofstream mFile;
  mFile.open(_file);
  mFile << _content;
  mFile.close();
}
