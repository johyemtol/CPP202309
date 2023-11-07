#include <iostream>
#include <string>
using namespace std;

bool checkNumber(int number) {
	int first = number / 100;
	int third = number % 10;
	int second = (number - first * 100) / 10;

	if (first == second || first == third || second == third) {
		return false;
	}
	return true;
}

int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	int firstNum = 0; // ������ ù��° �ڸ���
	int secondNum = 0; // ������ �ι�° �ڸ���
	int thirdNum = 0; // ������ ����° �ڸ���

	while (1) {
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		//firstNum = randomNum / 100;
		//thirdNum = randomNum % 10;
		//secondNum = (randomNum - firstNum * 100) / 10;

		//������ ���ڰ� �ߺ��Ȱ� �ִٸ� �ٽ� while ó�� ������ ����
		//if (firstNum == secondNum || firstNum == thirdNum || secondNum == thirdNum) {
		//	continue;
		//}
		//�ߺ��� ���ڰ� ���ٸ� �Ѿ��
		//else {
		//	break;
		//}

		if (!checkNumber(randomNum)) {
			continue;
		}
		else {
			firstNum = randomNum / 100;
			thirdNum = randomNum % 10;
			secondNum = (randomNum - firstNum * 100) / 10;
			break;
		}


	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		int guessFirst=0; // ������ ������ ù��° �ڸ���
		int guessSecond=0; // ������ ������ �ι�° �ڸ���
		int guessThird=0; // ������ ������ ����° �ڸ���


		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
			//guessFirst = userNumber / 100;
			//guessThird = userNumber % 10;
			//guessSecond = (userNumber - guessFirst * 100) / 10;

			//�Էµ� ���ڵ� �߿� �ߺ� ���ڰ� �ִ��� Ȯ���ϱ�
			//if (guessFirst == guessSecond || guessFirst == guessThird || guessSecond == guessThird) {
			//	cout << "�Էµ� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���\n";
			//	continue;
			//}
			if (!checkNumber(userNumber)) {
				continue;
			}
			//�Էµ� ������ ���̰� 3�� �ƴҶ�
			if (to_string(userNumber).length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}
			//�Էµ� ������ ���̰� 3�̰� �ߺ��� ���ڰ� ���� �� while�� ����������
			else {
				guessFirst = userNumber / 100;
				guessThird = userNumber % 10;
				guessSecond = (userNumber - guessFirst * 100) / 10;
				break;
			}

		}


		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
		//strike ���� ���� ��Ű��
		if (firstNum == guessFirst) {
			strike +=1;
		}
		if (secondNum == guessSecond) {
			strike += 1;
		}
		if (thirdNum == guessThird) {
			strike += 1;
		}
		//ball ���� ������Ű��
		if (firstNum == guessSecond ) {
			ball += 1;
		}
		if (firstNum == guessThird) {
			ball += 1;
		}
		if (secondNum == guessFirst) {
			ball += 1;
		}
		if (secondNum == guessThird) {
			ball += 1;
		}
		if (thirdNum == guessFirst ) {
			ball += 1;
		}
		if (thirdNum == guessSecond) {
			ball+=1;
		}

		//��Ʈ����ũ�� �� ���� ����ϱ�
		cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;

		//strike ���� �� ����ٸ� ����
		if (strike == 3) {

			cout << "������ ������ϴ�. �����մϴ�.";
			break;
		}
		//Ƚ�� ������Ű��
		turn += 1;
	}

	return 0;
}
