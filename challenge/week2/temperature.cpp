#include <iostream>
using namespace std;

int main() {
	int Fahrenheit;
	double Celsius;
	cout << "È­¾¾ ¿Âµµ : ";
	cin >> Fahrenheit;
	Celsius = (5.0 / 9.0) * (Fahrenheit - 32);
	cout << "¼·¾¾¿Âµµ = " << Celsius;
}