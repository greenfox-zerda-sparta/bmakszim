#include "wordtoolbox.hpp"
#include <iostream>

WordToolbox::WordToolbox(string _s) : stringHeld(_s) {

}

string WordToolbox::get_stringHeld() {
  return stringHeld;
}

void WordToolbox::set_stringHeld(string _s) {
  stringHeld = _s;
}

bool WordToolbox::isAnAnagram(string _s) {
  string s = convertToLetters(_s);
  string temp = convertToLetters(stringHeld);
  if (s.length() != temp.length()) {
    return false;
  }
  for (unsigned int i = 0; i < s.length(); i++) {
    for (unsigned int j = 0; j < temp.length(); j++) {
      if (s[i] == temp[j]) {
        temp.erase(j, 1);
        break;
      }
    }
  }
  if (temp.length() != 0) {
    return false;
  }
  return true;
}

int WordToolbox::countHowMany(char charToFind) {
  unsigned int n;
  unsigned int ascii = charToFind;
  if (ascii > 64 && ascii < 91) {
    for (unsigned int i = 0; i < stringHeld.length(); i++) {
      if (stringHeld[i] == (charToFind) ||
          stringHeld[i] == (charToFind + 32)) {
        n++;
      }
    }
  } else if (ascii > 96 && ascii < 123) {
    for (unsigned int i = 0; i < stringHeld.length(); i++) {
      if (stringHeld[i] == (charToFind) ||
          stringHeld[i] == (charToFind - 32)) {
        n++;
      }
    }
  } else {
    for (unsigned int i = 0; i < stringHeld.length(); i++) {
      if (stringHeld[i] == charToFind) {
        n++;
      }
    }
  }
  return n;
}

string WordToolbox::convertToLetters(string _s) {
  string temp = "";
  for (unsigned int i = 0; i < _s.length(); i++) {
    if (_s[i] > 64 && _s[i] < 91) {
      temp += (_s[i] + 32);
    } else if (_s[i] > 96 && _s[i] < 123) {
      temp += _s[i];
    }
  }
  return temp;
}
