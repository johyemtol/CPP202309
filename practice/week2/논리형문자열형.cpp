#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "Good";	
	string s2 = "Bad";
	bool b = (s1 == s2);		//s1�� s2�� �������� ���� true false�� ������ false��
	cout << b << endl;			//b�� ����ϴµ� false���̹Ƿ� 0�� ������ ��

	s2 = "Good";				//s2�� Good���� �ٲ�
	b = (s1 == s2);				//s1�� s2�� �����Ƿ� true�� ����
	cout << b << endl;			//true �̹Ƿ� 1���� ����
}