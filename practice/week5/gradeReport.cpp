#include <iostream>
#include <string>
using namespace std;

int main() {
	//��� �����ϱ� �л����� 5��, ������ 3��
	const int STUDENT = 5;
	const int SUBJECT = 3;
	//2���� �迭 ����� ������ �࿭ �л��� ��������
	int scores[STUDENT][SUBJECT];
	//�迭 �̸� �����ϱ� student,subject
	string studentNames[STUDENT]
		= { "����","����","ö��","�̹�","����" };
	string subjectNames[SUBJECT]
		= { "����","����","CPP" };
	//2���� �迭 ä���ֱ� �л� 5�� ����
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ������ �ϳ��� �Է��ϼ���." << endl;
		//���� 3�� �ֱ� (cin �� ����Ͽ�)
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}
	//��� ���ϱ� �л� ��������
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ��� ������ ";
		double sum = 0;
		double average = 0;
		//�� ���� �л����� ���� �� ���ϱ�
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "�Դϴ�" << endl;
	}
	return 0;
}