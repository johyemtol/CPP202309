#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	int ans;
	int n=0;
	cout << "��� ������ �ڵ����� �����մϴ�. " << endl;

	while (true) {
		//time�Լ��� ���� ���� ���� ����
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;
		//���� ����ϱ�
		ans = firstNum + secondNum;
		cout << firstNum << "+" << secondNum << "=";
		cin >> i;
		if (ans == i) {					//�����̶� ��ġ�Ҷ�
			cout << "�¾ҽ��ϴ�." << endl;
			n++;
		}
		else
			cout << "Ʋ�Ƚ��ϴ�."<<endl;
		if (n == 5)					//����Ƚ���� 5ȸ��� ���߰� �ϱ�
			break;
	}
}