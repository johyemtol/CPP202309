#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "���";
	string s2;
	//s2=s1+" "+10+"��" �� ����������? to_string���� �������� �ʾƼ� 
	s2 = s1 + " " + to_string(10) + "��";		//s2�� �����Ҷ� to_string�� ���� ���� ������
	cout << s2 << endl;							//����ϸ� ��� 10����� ���� ������ ��
}