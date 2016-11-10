#include <iostream>
#include <string>
using namespace std;

// Create a class called ParentClass. It should have two public functions. Both return a string. One virtual, the other not.
// Each should return a unique string.
// Create a ChildClass which inherits from the ParentClass publicly.
// This should override both functions. The virtual and the nonvirtual one both.
// These should return unique string again.
//
// Create a main() function. In this function, create a ParentClass* pointer and instanciate a ChildClass member for that pointer.
// Hint: This should look something like this: ParentClass* a = new ChildClass();
// Print out the result of both functions on this a ponter.
// Print out the result of both functions if You first cast pointer a to be interpreted as of type ChildClass*
//

class ParentClass {
  public:
    string a();
    virtual string b();
};

string ParentClass::a() {
  return string ("Unique string a.");
}

string ParentClass::b() {
  return string ("Unique string b.");
}

class ChildClass: public ParentClass {
  public:
    string a();
    string b();
};

string ChildClass::a() {
  return string ("Unique child string a.");
}

string ChildClass::b() {
  return string ("Unique child string b.");
}

int main() {
  ParentClass* a = new ChildClass();
  cout << a->a() << endl << a->b() << endl;
  cout << ((ChildClass*)a)->a() << endl << ((ChildClass*)a)->b() << endl;


  return 0;
}
