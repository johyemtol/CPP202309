#include <iostream>
using namespace std;

//add��� �̸����� �Լ� ����� add(x,y)�� �ϸ� x�� y���Ѱ��� ����
auto add(int x, int y)
{
	return x + y;
}

int main() {
	auto sum = add(5, 6);  //add �Լ��� ���� 5�� 6�� ���Ѱ��� sum�� ����
	cout << sum;		  //sum ���� �����
	return 0;
}