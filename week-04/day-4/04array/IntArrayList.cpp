#include "IntList.hpp"
#include "IntArrayList.hpp"

IntArrayList::IntArrayList() : IntList() {
  mSize = 2;
  int* new_array = new int[2];
  array = new_array;
}

int IntArrayList::get_index(int _i) {
  return *(array + _i);
}

void IntArrayList::append(int _a) {
  if (get_mLength() < 0.8 * mSize) {
    *(array + get_mLength()) = _a;
    set_mLength();
  } else {
    mSize *= 2;
    int* new_array = new int[mSize];
    for (int i = 0; i < get_mLength(); i++) {
      new_array[i] = *(array+i);
    }
    new_array[get_mLength()] = _a;
    set_mLength();
    delete[] array;
    array = new_array;
  }
}

void IntArrayList::insert(int _idx, int _a) {
  if (get_mLength() > 0.8 * mSize) {
    mSize *= 2;
  }
  int* new_array = new int[mSize];
  for (int i = 0; i < _idx; i++) {
    new_array[i] = *(array+i);
  }
  new_array[_idx] = _a;
  for (int i = _idx+1; i <= get_mLength(); i++) {
    new_array[i] = *(array+i-1);
  }
  set_mLength();
  delete[] array;
  array = new_array;
}

int IntArrayList::getFirst() {
  return *array;
}

int IntArrayList::getLast() {
  return *(array+(get_mLength()-1));
}

bool IntArrayList::isEmpty() {
    return get_mLength() == 0;
}

IntArrayList::~IntArrayList() {
  delete[] array;
}
