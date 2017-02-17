#include <iostream>
#include <list>

using namespace std;

list<unsigned int> my_function(string _string, char _char);

int main() {
  list<unsigned int> my_list = my_function("Greenfox Academy", 'E');
  for (list<unsigned int>::iterator it = my_list.begin(); it != my_list.end(); it++) {
    cout << *it << ' ';
  }
  cout << endl;
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