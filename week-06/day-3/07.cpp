#include <iostream>
#include <string>

using namespace std;

template <class T>

class Simple {
private:
  T item;
public:
  Simple();
  void set_item(T i);
  T get_item();
};

template <class T>
Simple<T>::Simple() {
  item = T ();
}

template <class T>
void Simple<T>::set_item(T i) {
  item = i;
}

template <class T>
T Simple<T>::get_item() {
  return item;
}

int main() {
	//Create a simple class template which contains 2 item and has both a get and a set method for these!

  Simple <char>a;
  a.set_item('a');
  cout << a.get_item();
  return 0;
}
