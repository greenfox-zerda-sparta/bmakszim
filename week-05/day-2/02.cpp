#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // Open a file called "second-exercise.txt"
  // Read the content of the file and print it to the terminal window
  ifstream file;
  file.open("second-exercise.txt");
  string file_content;
  file >> file_content;
  file.close();
  cout << file_content;
  return 0;
}
