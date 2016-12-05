#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<int> v(4);
vector<int> r;

int guesses = 0;
int bulls = 0;
int cows = 0;

void random_gen();

bool unique(int u);

string ask_for_guess();

bool is_length_correct(string a);

bool are_they_numbers(string a);

void guess();

void check();

void solution();

int main() {
  string asd;
  srand(time(NULL));
  random_gen();
  //solution();
  while (guesses < 11) {
    if (guesses == 10) {
      cout << "You lose. Winning number is: ";
      solution();
      guesses++;
    } else {
      cout << "You have " << 10 - guesses << " guesses remaining." << endl;
      guess();
      check();
      if (bulls == 4) {
        cout << "Bulls: " << bulls << endl << "You won by " << guesses << " guesses.";
        cin >> asd;
        return 0;
      }
      cout << "Bulls: " << bulls << endl << "Cows: " << cows << endl;
    }
  }
  cin >> asd;
  return 0;
}

bool unique(int u) {
  if (r.size() > 0) {
    for (unsigned int i = 0; i < r.size(); i++) {
      if (u == r[i]) {
        return false;
      }
    }
  }
  return true;
}

void random_gen() {
  int number;
  bool is_unique;
  for (int i = 0; i < 4; i++) {
    do {
      number = (rand() % 10);
	  is_unique = unique(number);
    } while (is_unique == false);
    r.push_back(number);
  }
}

string ask_for_guess() {
  string a;
  cin >> a;
  return a;
}

bool is_length_correct(string a) {
  return (a.length() == 4);
}

bool are_they_numbers(string a) {
  int n;
  for (int i = 0; i < 4; i++) {
    n = a[i] - '0';
    if (n > 9 || n < 0) {
      return false;
    }
  }
  return true;
}

void guess() {
  string str;
  bool correct;
  do {
    correct = 1;
    str = ask_for_guess();
    if (!is_length_correct(str)) {
      correct = 0;
    }
    if (!are_they_numbers(str)) {
      correct = 0;
    }
    if (correct == 0) {
      cout << "Please, provide a 4 digit number!" << endl;
    }

  } while (correct == 0);


  for (int i = 0; i < 4; i++) {
    v[i] = str[i] - '0';
  }
  guesses++;
}

void check() {
  int b = 0;
  int c = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (v[i] == r[j]) {
        if (i == j) {
          b++;
        } else {
          c++;
        }
      }
    }
  }
  bulls = b;
  cows = c;
}

void solution() {
  for (unsigned int i = 0; i < r.size(); i++) {
    cout << r[i];
  }
  cout << endl;
}
