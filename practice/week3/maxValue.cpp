#include <iostream>
using namespace std;

int main() {
	int a, b, c, largest;
	cout << "3개의 정수를 입력하시오: ";
	cin >> a >> b >> c;					//3개의 정수 받기
	
	if (a > b && a > c)					//a가 가장 클 경우
		largest = a;
	else if (b > a && b > c)			//b가 가장 클 경우
		largest = b;
	else                               //c가 가장 클 경우
		largest = c;
	cout << "가장 큰 정수는 " << largest << endl;
	return 0;
}