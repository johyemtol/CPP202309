#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople=3;					//maxPeople�� 3���� ����
	//cout << "�� ���� ���� �Է��϶�: ";
	//cin >> maxPeople;
	string names[maxPeople];				//string Ÿ���� �迭 �����
	int ages[maxPeople];					//int Ÿ���� �迭 �����
	//�̸��ϰ� ���� �Է¹ޱ�
	for (int i = 0; i < maxPeople; i++) {
		cout << "��� " << i + 1 << "�� �̸�: ";
		cin >> names[i];
		cout << "���" << i + 1 << "�� ����: ";
		cin >> ages[i];
	}
	//Ư�� ���� �̻� ã�� �ڵ�
	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;

	cout << ageThreshold << "�� �̻��� ����:\n";
	
	int correctagePeople = 0;
	for (int i = 0; i < maxPeople;i++) {
	
		if (ages[i] >= ageThreshold) {							//���̿� �´� �̻��� ������ �ִٸ� ���
			cout << names[i] << " (" << ages[i] << "��)\n";
			correctagePeople++;
		}

		
	}
	if (correctagePeople == 0)						//���̿� �´� ���� ���ٸ�
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
}