#include <iostream>
using namespace std;

int main() {
	int a, b, c, smallest;
	cout << "3���� ������ �Է��Ͻÿ�: ";
	cin >> a >> b >> c;					//3���� ���� �ޱ�

	if (a < b && a < c)					//a�� ���� ���� ���
		smallest = a;
	else if (b < a && b < c)			//b�� ���� ���� ���
		smallest = b;
	else                               //c�� ���� ���� ���
		smallest = c;
	cout << "���� ���� ������ " << smallest << endl;
	return 0;
}