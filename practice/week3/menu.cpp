#include <iostream>
using namespace std;

int main() {
	int choice;
	//cout���� 1,2,3�� �ش��ϴ� ��� �˷��ֱ�
	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	//cin���� choice �Է¹ޱ�
	cin >> choice;

	//switch���� ����Ͽ� choice�� ���� ��� �˷��ֱ�
	switch (choice) {
	case 1:		//choice�� 1�϶� 1�� �Է��Ͽ�����
		cout << "���� ������ �����߽��ϴ�." << endl;
		break;
	case 2:
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
		break;
	case 3:
		cout << "���α׷��� �����մϴ�." << endl;
		break;
	default:	//choice�� ���� ������ �Ͽ�����
		cout << "�߸��� �����Դϴ�." << endl;
		break;
	}

	return 0;
}