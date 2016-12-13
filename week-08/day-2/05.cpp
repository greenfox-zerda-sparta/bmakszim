#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <time.h>

using namespace std;

// Write a simple program that creates secret santa pairs
// It should read names till the character q is typed to the standard output,
// than it should print the names as secret santa pairs like:
// Clair - Mike
// Joe - Ron
// Cloe - Clair
// Ron - Cloe
// Mike - Joe

map<string, string> my_function (vector<string>& v) {
  map<string, string> m;
  vector<string> temp = v;
  int n;
  for (unsigned int i = 0; i < v.size(); i++) {
    do {
      n = rand() % temp.size();
    } while (v[i] == temp[n]);
    m[v[i]] = temp[n];
    temp.erase(temp.begin() + n);
  }
  return m;
}

int main() {
  srand(time(NULL));
  string name;
  vector<string> names;
  do {
    cin >> name;
    if (name != "q") {
      names.push_back(name);
    }
  } while (name != "q");
  for (auto it : my_function(names)) {
    cout << it.first << " -> " << it.second << ';';
    cout << endl;
  }
  return 0;
}
