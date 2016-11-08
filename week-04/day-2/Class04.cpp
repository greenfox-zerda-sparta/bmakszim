#include <iostream>
#include <string>

using namespace std;

class Student {
  private:
    string name;
    unsigned int age;
  public:
    Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }

    string greet() {
      return "Hello my name is: " + this->name;
    }

    void change_name(string new_name) {
      this->name = new_name;
    }
};

int main() {
  // Create a method on student that takes a string as an argument and
  // changes it's name property
  Student john("John", 21);
  john.change_name("Alf");
  cout << john.greet();
  return 0;
}
