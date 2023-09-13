#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	cout << "이름을 입력하시오: ";
	cin >> name;							//name이라는 string을 넣을 수 있게됨
	cout << name << "을 환영합니다.";		//입력받은값과 함께 출력됨
	return 0;
}