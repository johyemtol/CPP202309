#include <iostream>
using namespace std;

int main() {
	int number;
	
	cout << "숫자를 입력하시오:";
	//cin으로 number 받기
	cin >> number;

	if (number == 0)	//number 0을 입력했다면
		cout << "zero\n";
	else if (number == 1)
		cout << "one\n";
	else               //number에 0,1을 입력안했다면?
 		cout << "many\n";

	return 0;
}