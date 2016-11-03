#include <string>
#include <iostream>

using namespace std;

// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
//
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a refrence to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
//
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
//
// Create a function that takes an array of houses (and it's length),
// then it creates a new array that consists new houses with the calculated price,
// but all the other properties are the same.

struct House {
  string address;
  int price;
  int rooms;
  int area;
};

bool is_worth(House &house);
int count_worth(House* array, int length);
House* new_prices(House* array, int length);

int main() {
  House* array = new House[5];
  array[0] = {"a", 50000, 3, 100};
  array[1] = {"b", 40000, 3, 110};
  array[2] = {"c", 80000, 3, 150};
  array[3] = {"d", 30000, 2, 60};
  array[4] = {"e", 60000, 2, 150};

  cout << is_worth(array[4]) << endl;

  cout << count_worth(array, 5) << endl << endl;

  House* new_array = new_prices(array, 5);

  for (int i = 0; i < 5; i++) {
    cout << (new_array+i)->address << endl
         << (new_array+i)->price << endl
		 << (new_array+i)->rooms << endl
		 << (new_array+i)->area << endl << endl;
  }

  delete[] new_array;
  delete[] array;
  return 0;
}

bool is_worth(House &house) {
  bool worth;
  if ((house.price / house.area) <= 400) {
    worth = true;
  } else {
    worth = false;
  }
  return worth;
}

int count_worth(House* array, int length) {
  int counter = 0;
    for (int i = 0; i < length; i++) {
      if (is_worth(array[i]) == 1) {
        counter+=1;
      }
    }
  return counter;
}

House* new_prices(House* array, int length) {
  House* new_array = new House[length];
  for (int i = 0; i < length; i++) {
    new_array[i] = {array[i].address, 400*array[i].area, array[i].rooms, array[i].area};
  }
  return new_array;
}
