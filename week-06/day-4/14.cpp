#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

vector<string> car_types = {"Moszkvics", "Volga", "ZISZ", "Tatra", "Zbrojovka", "Hotchkiss", "DAF", "Warszawa",
  "Puli", "Balaton", "Benz", "Marauder", "Zsiguli" , "IFA", "Fjord", "Trabant", "Wartburg", "Martini"};
vector<string> colours = {"Piros", "Narancssárga", "Zöld", "Kék", "Türkiz", "Barna", "Lila", "Sárga", "Fekete", "Fehér"};

char random_char() {
  int temp = rand() % 26 + 65;
  char c = temp;
  return c;
}

string random_plate() {
  int temp = (rand() % 801 + 100) + (rand() % 81 + 10) + (rand() % 10);
  string str_temp = to_string(temp);
  string str(1, random_char());
  return str + random_char() + random_char() + '-' + str_temp;
}

class Car {
private:
  string name;
  string colour;
  string plate;
public:
  Car();
  string get_name();
  string get_colour();
  string get_plate();
  void set_name();
  void set_colour();
  void set_plate();
};

vector<vector<vector<Car>>> parking_house(8, vector<vector<Car>> (4, vector<Car> (4, Car())));


void fill_parking_house() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        parking_house[i][j][k].set_colour();
        parking_house[i][j][k].set_name();
        parking_house[i][j][k].set_plate();
      }
    }
  }
}

Car::Car() {
  name = "";
  colour = "";
  plate = "";
}

string Car::get_name() {
  return name;
}

string Car::get_colour() {
  return colour;
}

string Car::get_plate() {
  return plate;
}

void Car::set_name() {
  name = car_types.at(rand() % car_types.size());
}

void Car::set_colour() {
  colour = colours.at(rand() % colours.size());
}

void Car::set_plate() {
  plate = random_plate();
}

int main() {
	//Create a vector of string, for the following car types:
	//"Moszkvics", "Volga", "ZISZ", "Tatra", "Zbrojovka", "Hotchkiss", "DAF", "Warszawa", "Puli", "Balaton",
	//"Benz", "Marauder", "Zsiguli" , "IFA", "Fjord", "Trabant", "Wartburg", "Martini"
	//Create a vector of strings, for the following colors:
	//"Piros", "Narancssárga", "Zöld", "Kék", "Türkiz", "Barna", "Lila", "Sárga", "Fekete", "Fehér"
	//Create a Car class, which holds 3 strings, the name of a car, the color of it, and the platenumber in a format like "AAA"-"000"
	//Create a 3 dimensional vector of our car class, that will represent a "parking house"
		//1 dimension: row of cars
		//2 dimension: cars on a platform like a table game
		//3 dimension: "parking house"
	//Make this parking house 4*4*8 (4*4 platform on 8 floors), then fill it with cars! :)
	//Give these cars a random type from our car type vector!
	//Give these cars a random color from our color vector!
	//Give these cars a random plate number!
	//Make sure there are no duplicates in car plates!
	//Print out how much "Sárga"-"Zsiguli" we have, with their position and platenumber in the parking house!
	//At the end empty the parking house!
  srand(time(NULL));
  fill_parking_house();
  int counter = 0;
  vector<Car> temp;
  vector<string> pos;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (parking_house[i][j][k].get_colour() == colours.at(7) && parking_house[i][j][k].get_name() == car_types.at(12)) {
          counter++;
          temp.push_back(parking_house[i][j][k]);
          pos.push_back(to_string(i+1) + "-" + to_string(j+1) + "-" + to_string(k+1));
        }
      }
    }
  }
  cout << counter << " db sárga Zsiguli van." << endl;
  for (unsigned int i = 0; i < temp.size(); i++) {
    cout << temp[i].get_plate();
    cout << ' ' << pos[i] << " pozícioban" << endl;
  }

//  cout << parking_house[0][0][0].get_plate() << endl << parking_house[0][0][0].get_name() << endl << parking_house[0][0][0].get_colour() << endl;
//  cout << parking_house[0][0][1].get_plate() << endl << parking_house[0][0][1].get_name() << endl << parking_house[0][0][1].get_colour() << endl;
  return 0;
}
