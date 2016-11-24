#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<char> v(8);

int i = 0;

void ask_char() {
  cout << "Give char no. " << i << ':' << endl;
  cin >> v.at(i);
}

bool check_char() {
  char a;
  switch (i) {
    case 0:
      a = 'G';
      break;
    case 1:
      a = 'R';
      break;
    case 2:
      a = 'E';
      break;
    case 3:
      a = 'E';
      break;
    case 4:
      a = 'N';
      break;
    case 5:
      a = 'F';
      break;
    case 6:
      a = 'O';
      break;
    case 7:
      a = 'X';
      break;
  }
return (v.at(i) == a);
}

int main() {
	//create a vector of characters with the size of 8
	//ask the user to fill this vector with characters one by one
	//at the end make sure the vector holds the letters of "GREENFOX"
	//so correct the user if he/she gives a different letter from the one we want them to give :)
  do {
    ask_char();
    if (check_char() == 1) {
      i++;
    } else {
      cout << "Given char is wrong." << endl;
    }
  } while (i != 8);
  for (unsigned int i = 0; i < v.size(); i++) {
    cout << v.at(i);
  }
  return 0;
}
