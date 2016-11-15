#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Create a program that decrypts the file called "reversed-lines.txt",
  // and pritns the decrypred text to the terminal window.
  ifstream my_file;
  my_file.open("try.txt");
  string buffer;
  while (getline(my_file, buffer)) {
    for (int i = (buffer.length()-1); i >= 0; i--) {
      cout << buffer[i];
    }
    cout << endl;
  }
  my_file.close();
  return 0;
}
