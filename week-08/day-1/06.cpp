// In Your main function create an array of integers. 5 long.
// Fill it up with random numbers.
// For each number treat it as the radius of a circle.
// Calculate the circumference and the area of the circle with such a radius.
// Use preprocessor to define the MY_PI constant. Use this in th calculations.

#include <iostream>
#include <time.h>
using namespace std;

#define MY_PI 3.14f

int main() {
  int array[5];
  for (int i = 0; i < 5; i++) {
    array[i] = rand() % 40 + 10;
    cout << "Radius: " << array[i] << " | " << "Circumference: " << 2 * array[i] * MY_PI
         << " | " << "Area: " << array[i] * array[i] * MY_PI << endl;
  }
  return 0;
}
