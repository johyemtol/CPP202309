#include <iostream>
using namespace std;

int main() {
	int a, b, c, largest;
	cout << "3���� ������ �Է��Ͻÿ�: ";
	cin >> a >> b >> c;					//3���� ���� �ޱ�
	
	if (a > b && a > c)					//a�� ���� Ŭ ���
		largest = a;
	else if (b > a && b > c)			//b�� ���� Ŭ ���
		largest = b;
	else                               //c�� ���� Ŭ ���
		largest = c;
	cout << "���� ū ������ " << largest << endl;
	return 0;
}