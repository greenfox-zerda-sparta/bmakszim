#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // Open a file called "first-exercise.txt"
  // Write your name in it as a single line
  ofstream file;
  file.open("first-exercise.txt");
  file << "Makszim Balazs\n";
  file.close();

  return 0;
}
