#include <iostream>
using namespace std;

int main() {
	int Fahrenheit;
	double Celsius;
	cout << "화씨 온도 : ";					//cin으로 받아들이기
	cin >> Fahrenheit;
	Celsius = (5.0 / 9.0) * (Fahrenheit - 32);		//온도 계산
	cout << "섭씨온도 = " << Celsius;
}
