#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));		//random �Լ� ���� ����

	int answer = rand() % 100;		//����
	int tries = 0;			//�õ� Ƚ�� �����ϴ� ����

	int guess;					//����� �Է� �����ϱ� ���� ����

	while (true) {
		cout << "������ �����Ͽ� ���ÿ�: ";
		cin >> guess;
		tries++;		//Ƚ�� ����
		if (guess < answer)		//������ �� ũ�ٸ�
			cout << "������ ������ �����ϴ�" << endl;
		else if (guess > answer)		//������ �� �۴ٸ�
			cout << "������ ������ �����ϴ�"<<endl;
		else if (guess == answer) {		//����ٸ�
			cout << "�����մϴ�. �õ�Ƚ��=" << tries;
			break;
		}
	}

}