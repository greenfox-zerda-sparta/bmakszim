#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // Open a file called "third-exercise.txt"
  // Write numbers from 0 to 20 into the file each in a new line
  ofstream file;
  file.open("third-exercise.txt");
  for (int i = 0; i < 21; i++) {
	  file << i << '\n';
  }
  file.close();
  return 0;
}
