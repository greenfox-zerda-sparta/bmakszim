#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Open a file called "fourth-exercise.txt"
  // Print all of its lines to the terminal window
  ifstream file;
  file.open("fourth-exercise.txt");
  string buffer;
  while (file >> buffer) {
    cout << buffer << endl;
  }
  file.close();
  return 0;
}
