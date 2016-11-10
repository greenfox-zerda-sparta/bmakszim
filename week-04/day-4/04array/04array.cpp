#include <iostream>
#include <string>
#include "IntList.hpp"
#include "IntArrayList.hpp"
using namespace std;

// Take the attached hpp and cpp files. Read them trough.
// Choose either IntArrayList or IntLinkedList and implement it.
// Write code here in a main function that uses it and tests it in edge cases as well.

int main() {
  IntArrayList* theList = new IntArrayList();//Your code starts here!
  cout << "Is empty? " << theList->isEmpty() << endl;
  theList->append(1);
  theList->append(2);
  theList->append(3);
  theList->append(4);
  theList->insert(3, 88);
  theList->insert(4, 88);
  theList->insert(4, 88);
  theList->insert(4, 88);
  theList->insert(4, 88);
  theList->insert(4, 88);
  theList->insert(4, 88);
  theList->insert(4, 88);
  theList->insert(4, 88);
  theList->insert(4, 88);
  cout << "Length of the array: " << theList->get_mLength() << endl << endl;
  for (int i = 0; i < theList->get_mLength(); i++) {
  cout << theList->get_index(i) << endl;
  }
  cout << endl << "First element: " << theList->getFirst() << endl;
  cout << endl << "Last element: " << theList->getLast() << endl;
  cout << endl << "Is empty? " << theList->isEmpty() << endl;
  delete theList;
  return 0;
}
