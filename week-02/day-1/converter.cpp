#include <iostream>
#include <string>

using namespace std;

int main() {
	int a = 8797;
	string e = "";

	cout << "Adj meg egy pozitiv egesz szamot: " << endl;
	cin >> a;

	if (a >= 1000) {
		for (int i = 0; i < a/1000; i++) {
			e = e + "M";
		}
		a = a%1000;
	}
	if (a >= 900) {
		e = e + "CM";
		a -=900;
	}
	if (a >= 500) {
		e = e + "D";
		for (int i = 0; i < (a-500)/100; i++) {
			e = e + "C";
		}
		a = a - (500 + ((a-500)/100)*100);
	}
	if (a >= 400) {
		e = e + "CD";
		a-=400;
	}
	if (a >= 100) {
		for (int i = 0; i < a/100; i++) {
			e = e + "C";
		}
		a = a%100;
	}
	if (a >= 90) {
		e = e + "XC";
		a -=90;
	}
	if  (a >= 50) {
		e = e + "L";
		for (int i = 0; i < (a-50)/10; i++){
			e = e + "X";
		}
		a = a - (50 + ((a-50)/10)*10);
	}
	if (a >= 40) {
		e = e + "XL";
		a -= 40;
	}
	if (a >= 10) {
		for (int i = 0; i < a/10; i++){
			e = e + "X";
		}
		a = a%10;
	}
	if (a == 9){
		e = e + "IX";
		a = a - 9;
	}
	if (a >= 5) {
		e = e + "V";
		for (int i = 0; i < (a-5)/1; i++) {
			e = e + "I";
		}
		a = a - (5 + ((a-5)/1)*1);
	}
	if (a == 4) {
		e = e + "IV";
		a = a - 4;
	}
	if (a >= 0) {
		for (int i = 0; i < a; i++) {
			e = e + "I";
		}
	}
	cout << e << endl;

	return 0;
}
