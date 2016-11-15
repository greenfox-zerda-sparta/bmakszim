#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Create a program that decrypts the file called "reversed-lines.txt",
  // and pritns the decrypred text to the terminal window.
  char my_char = 'a';
  ifstream my_file;
  my_file.open("try.txt");
  string buffer;
  while (getline(my_file, buffer)) {
    for (unsigned int i = 0; i < buffer.length(); i++) {
      my_char = buffer[i];
      if (my_char == ' ') {
        cout << my_char;
      } else {
      cout << char(int(my_char)-1);
      }
    }
    cout << endl;
  }
  my_file.close();
  return 0;
}
