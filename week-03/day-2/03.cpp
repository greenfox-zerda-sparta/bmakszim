#include <string>
#include <iostream>

using namespace std;

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  CarType type;
  double km;
  double gas;
};

// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

void stat(Car* car) {
  string car_names[4] = {"Volvo", "Toyota", "Land Rover", "Tesla"};
  if (car->type == TESLA) {
    cout << car_names[car->type] << endl << car->km << endl;
  } else {
	cout << car_names[car->type] << endl << car->km << endl << car->gas << endl;
  }
}

int main() {
  Car* volvo = new Car{VOLVO, 100, 100};
  Car* toyota = new Car{TOYOTA, 200, 200};
  Car* land_rover = new Car{LAND_ROVER, 300, 300};
  Car* tesla = new Car{TESLA, 400, 0};

  stat(tesla);

  delete volvo;
  delete toyota;
  delete land_rover;
  delete tesla;

  return 0;
}
