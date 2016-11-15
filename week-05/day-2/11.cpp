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
  unsigned int rows = 0;
  while (getline(my_file, buffer)) {
    rows++;
  }
  my_file.close();
  ifstream my_file2;
  my_file2.open("try.txt");
  string array[rows];
  int i = 0;
  while (getline(my_file2, array[i])) {
    i++;
  }
  for (int j = (rows-1); j >= 0; j--) {
    cout << array[j] << endl;
  }
  my_file2.close();
  return 0;
}
