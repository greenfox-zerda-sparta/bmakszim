#include <iostream>
#include <string>

using namespace std;

int counter (string word, char letter) {
  int count = 0;
  for (int i = 0; i < sizeof(word) / sizeof(letter); i++) {
    if (letter == word[i]) {
    	count++;
    }
  }
  return count;
}

int main() {
  string word = "makkoshotyka-also";
  char letter = 'o';
  // Write a function that takes a string and a character, and counts how many
  // times the character occures in the string and it should return a number
  cout << counter(word, letter) << endl;
  return 0;
}
