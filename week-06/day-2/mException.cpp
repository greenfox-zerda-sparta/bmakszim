#include "mException.hpp"

mException::mException(Exception a, int b) {
  exc = a;
  element = b;
}

Exception mException::get_exc() {
  return exc;
}

int mException::get_element() {
  return element;
}

string mException::toString() {
  string str;
  switch (exc) {
    case full:
      str = "Problem with item " + to_string(element) + ". Stack is already full.";
      return str;
    case empty:
      str = "Stack is empty.";
      return str;
  }
}
