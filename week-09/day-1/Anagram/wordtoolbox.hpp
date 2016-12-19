#ifndef WORDTOOLBOX_HPP_
#define WORDTOOLBOX_HPP_

#include <string>
using namespace std;

class WordToolbox {
private:
  string stringHeld;
public:
  WordToolbox(string _s);
  string get_stringHeld();
  void set_stringHeld(string _s);
  bool isAnAnagram(string _s);
  int countHowMany(char charToFind);
  string convertToLetters(string _s);
};



#endif
