#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

// Write a program that creates a text file named alice_words.txt
// containing an alphabetical listing of all the words,
// and the number of times each occurs, in the text version of
// Alice’s Adventures in Wonderland.
// (You can obtain a free plain text version of the book,
// along with many others, from http://www.gutenberg.org.)
//
// The first 10 lines of your output file should look something like this:
//
// Word              Count
// =======================
// a                 631
// a-piece           1
// abide             1
// able              1
// about             94
// above             3
// absence           1
// absurd            2
//
// How many times does the word alice occur in the book?
// What is the longest word in Alice in Wonderland?
// How many characters does it have?

bool is_letter(char c) {
  return ((c > 64  && c < 91) || (c > 96 && c < 123));
}

int main() {
  map<string, int> m;
  ifstream file;
  file.open("alice.txt");
  string buffer;
  while (file >> buffer) {
    string cache = "";
    int itemp;
    char ctemp;
    for (unsigned int i = 0; i < buffer.length(); i++) {
      itemp = buffer[i];
      if (itemp == 39 || itemp == 45 || (itemp > 64
          && itemp < 91) || (itemp > 96 && itemp < 123)) {
        if (itemp > 64 && itemp < 91) {
          itemp += 32;
          ctemp = itemp;
          cache += ctemp;
        } else if ( itemp == 45) {
          if (is_letter(buffer[i+1]) && is_letter(buffer[i-1])) {
            ctemp = itemp;
            cache += ctemp;
          } else {
            if (cache != "") {
              m[cache] ++;
            }
            //cout << cache << "itt" << endl; //////
            cache = "";
          }
        } else {
          ctemp = itemp;
          cache += ctemp;
        }
      }
    }
    if (cache != "") {
      m[cache] ++;
    }
    //cout << cache << "ott" << endl; /////
  }
  file.close();
  for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " -> " << it->second << ';';
    cout << endl;
  }
  return 0;
}
