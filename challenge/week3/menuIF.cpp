#include <iostream>
using namespace std;

int main() {
	int choice;
	//cout���� 1,2,3�� �ش��ϴ� ��� �˷��ֱ�
	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;

	//if ������ choice ����� �� �����ϱ�
	if (choice == 1)
		cout << "���� ������ �����߽��ϴ�." << endl;
	else if (choice == 2)
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
	else if (choice == 3)
		cout << "���α׷��� �����մϴ�." << endl;
	else            //1,2,3�� �ƴϰ� �ٸ��� �Է��ߴٸ�
		cout << "�߸��� �����Դϴ�." << endl;

	return 0;
}