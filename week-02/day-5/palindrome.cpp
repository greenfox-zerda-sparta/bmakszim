#include <iostream>
#include <string>

using namespace std;

void parts(string& a);
void palindrome(string& input);
void remove_end(string& b);

int main() {
  //string output = "dog goat dad duck doodle never";
  string output;
  getline (cin, output);
  parts(output);
  remove_end(output);
  cout << output << endl;
  return 0;
}

void parts(string& a) {
  int length = a.length();
  string temp = "";
  string temp2 = "";
  string temp3 = "";
  for (int i = 3; i <= length; i++){
	for (int j = 0; j <= length-i; j++){
	  temp = temp + a[j] + a[j+1];
	  for (int k = j+2; k < i+j; k++) {
	    temp = temp + a[k];
	  }
	  temp2 = temp;
      palindrome(temp2);
	  if (temp == temp2) {
	    if (temp3 == "") {
	      temp3 = temp3 + '\'' + temp + '\'';
	    } else {
	      temp3 = temp3 + ", " + '\'' + temp + '\'';
	    }
	  }
	  temp = "";
	}
  }
  a = temp3;
}

void palindrome(string& input) {
  int length = input.length();
  string temp = "";
  for (int i = (length-1); i >= 0; i--) {
    temp = temp + input[i];
  }
  input = temp;
}

void remove_end(string& b) {
  b = '[' + b + ']';
}
