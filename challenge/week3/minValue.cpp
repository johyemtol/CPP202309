#include <iostream>
using namespace std;

int main() {
	int a, b, c, smallest;
	cout << "3개의 정수를 입력하시오: ";
	cin >> a >> b >> c;					//3개의 정수 받기

	if (a < b && a < c)					//a가 가장 작은 경우
		smallest = a;
	else if (b < a && b < c)			//b가 가장 작은 경우
		smallest = b;
	else                               //c가 가장 작은 경우
		smallest = c;
	cout << "가장 작은 정수는 " << smallest << endl;
	return 0;
}