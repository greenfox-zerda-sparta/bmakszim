#include <iostream>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main() {
  int* count_ptr = new int();
  cin >> *count_ptr;
  cout << "Give " << *count_ptr << " numbers." << endl;
  int* numbers = new int[*count_ptr];
  for (int i = 0; i < *count_ptr; i++) {
    cin >> numbers[i];
  }
  float average = 0;
  for (int i = 0; i < *count_ptr; i++) {
    average = average + numbers[i];
  }
  average = average / *count_ptr;
  cout << "The average of the above numbers is: " << average << endl;
  delete count_ptr;
  delete[] numbers;
  return 0;
}
