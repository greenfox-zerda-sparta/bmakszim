#include <iostream>
#include <list>

using namespace std;

list<unsigned int> my_function(string _string, char _char);

int main() {
  return 0;
}

list<unsigned int> my_function(string _string, char _char) {
  list<unsigned int> _list;
  for (unsigned int i = 0; i < _string.length(); i++) {
    if (tolower(_string[i]) == tolower(_char)) {
      _list.push_back(i);
    }
  }
  return _list;
}