#include <iostream>
using namespace std;

int main() {
	int x = 1;
	//계산 정리하기 ++x,x++구분하기
	cout << "x = " << x++ << endl;
	cout << "x = " << x++ << endl;
	cout << "x = " << ++x << endl;
	cout << "x = " << x-- << endl;
	cout << "x = " << x-- << endl;
	cout << "x = " << --x << endl;

	return 0;
}
