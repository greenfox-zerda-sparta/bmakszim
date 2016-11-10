#include "IntList.hpp"

IntList::IntList() {
  mLength = 0;
}

void IntList::set_mLength() {
  mLength++;
}

int IntList::get_mLength() {
  return mLength;
}

IntList::~IntList() {
  ;
}


