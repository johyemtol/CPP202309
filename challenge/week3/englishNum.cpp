#include <iostream>
using namespace std;

int main() {
	int number;
	
	cout << "���ڸ� �Է��Ͻÿ�:";
	//cin���� number �ޱ�
	cin >> number;

	if (number == 0)	//number 0�� �Է��ߴٸ�
		cout << "zero\n";
	else if (number == 1)
		cout << "one\n";
	else               //number�� 0,1�� �Է¾��ߴٸ�?
 		cout << "many\n";

	return 0;
}