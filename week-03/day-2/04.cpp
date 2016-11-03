#include <string>
#include <iostream>

using namespace std;

struct Pirate {
  string name;
  bool has_wooden_leg;
  short int gold_count;
};

int sum(Pirate array[], int length);

float avrg(Pirate array[], int length);

string richest(Pirate array[], int length);

// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates

// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate

// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg

int main() {
  Pirate pirates[] = {
    {"Jack", false, 18},
    {"Uwe", true, 8},
    {"Hook", true, 12},
    {"Halloween kid", false, 0},
    {"Sea Wolf", true, 14},
    {"Morgan", false, 1}
  };

  cout << sum(pirates, 6) << endl;
  cout << avrg(pirates, 6) << endl;
  cout << richest(pirates, 6) << endl;

  return 0;
}

int sum(Pirate array[], int length) {
  int counter = 0;
  for (int i = 0; i < length; i++) {
    counter = counter + array[i].gold_count;
  }
  return counter;
}

float avrg(Pirate array[], int length) {
  return float((sum(array, length)))/length;
}

string richest(Pirate array[], int length) {
  string richest;
  int counter = 0;
  for (int i = 0; i < length; i++) {
    if (array[i].has_wooden_leg == true && array[i].gold_count > counter) {
      counter = array[i].gold_count;
      richest = array[i].name;
    }
  }
  return richest;
}
