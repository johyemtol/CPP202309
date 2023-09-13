#include <iostream>
#define PI 3.14159265359		//PI값을 3.14159265359로 정의해줌
using namespace std;

int main() {
	int income = 1000;
	const double TAX_RATE = 0.25;  //상수변수로 TAX_RATE로 정의해줌
	income = income - TAX_RATE*income;		//income값을 다시 계산해줌
	double x = 100;
	x = x * PI;

	cout << x << endl;
	return 0;
}