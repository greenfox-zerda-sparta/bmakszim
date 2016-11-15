#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool copy(string _from, string _to);

int main() {
  // Write a function that copies a file to an other
  // It should take the filenames as parameters
  // It should return a boolean that shows if the copy was successful
  cout << copy("try.txt", "try2.txt");
  return 0;
}

bool copy(string _from, string _to) {
  ifstream mFile;
  mFile.open(_from);
  if (!mFile.is_open()) {
    cerr << "Could not open the file.";
    return false;
  }
  string temp = "";
  string buffer;
  while (getline(mFile, buffer)) {
    temp += buffer + '\n';
  }
  mFile.close();
  ofstream mFile2;
  mFile2.open(_to);
  mFile2 << temp;
  mFile2.close();
  return true;
}
