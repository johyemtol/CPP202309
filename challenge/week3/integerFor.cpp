#include <iostream>
using namespace std;

int main() {
	int userInput;

	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";
	for (int i = 0; i < 10;i++) {				//int ���� ����
		cin >> userInput;
		if (userInput == 0) {						//0�� �Է��ϸ� ����
			break;
		}
		cout << "�Է°�: " << userInput << " Ƚ�� :" << i << endl;

		if (i == 10) {						//10�� �ԷµǾ��ٸ� ����
			break;
		}
	}
	cout << "����Ǿ����ϴ�";					//���� �ȳ�

	return 0;
}