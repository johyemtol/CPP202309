#include <iostream>
#define PI 3.14159265359		//PI���� 3.14159265359�� ��������
using namespace std;

int main() {
	int income = 1000;
	const double TAX_RATE = 0.25;  //��������� TAX_RATE�� ��������
	income = income - TAX_RATE*income;		//income���� �ٽ� �������
	double x = 100;
	x = x * PI;

	cout << x << endl;
	return 0;
}