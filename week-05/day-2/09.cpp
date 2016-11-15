#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Create a program that decrypts the file called "duplicated-chars.txt",
  // and pritns the decrypred text to the terminal window.
  ifstream my_file;
  my_file.open("try.txt");
  string buffer;
  while (getline(my_file, buffer)) {
    for (unsigned int i = 0; i < buffer.length(); i+=2) {
      cout << buffer[i];
    }
    cout << endl;
  }
  my_file.close();
  return 0;
}
