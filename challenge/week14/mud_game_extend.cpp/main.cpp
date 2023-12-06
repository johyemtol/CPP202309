#include "user.h"
using namespace std;
const int mapX = 5;
const int mapY = 5;
void checkState(int map[][mapX], int user_x, int user_y, User& my_user);
bool checkGoal(int map[][mapX], int user_x, int user_y);
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool CheckUser(User user);
void readMap(int map[][mapX], const string& filename);

int main()
{
	User my_user;
	Magician M;
	Warrior W;


	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX];
	readMap(map, "map.txt");


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ

	int k = 0;
	char currentUser = 'W';

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����
		switch (k % 2) {
		case 0:  // 0�� �� M�� ����
			cout << (k % 2 + 1) << "�� ����(M)�� ����:";
			currentUser = 'M';
			break;
		case 1:  // 1�� �� W�� ����
			cout << (k % 2 + 1) << "�� ����(W)�� ����:";
			currentUser = 'W';
			break;
		}

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "���� HP: " << my_user.GetHp() << " ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		//���� �ö󰡱� ��
		try {
			if (user_input == "��") {
				user_y -= 1;
				//�Լ� ���� �� ���� �����ϴ� �� üũ
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				//�� �� ���� ���Ѵٸ�
				if (inMap == false) {
					throw inMap;
					user_y += 1;
				}
				//�� �� �����Ѵٸ� ��ĭ �ö󰡰� ���� �Լ� ��°� checkState �Լ� �ϱ�
				else {
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
					displayMap(map, user_x, user_y);
					my_user.DecreaseHp(1);
					checkState(map, user_x, user_y, my_user);
				}
			}
			else if (user_input == "��") {
				// TODO: �Ʒ��� �� ĭ ��������
				user_y += 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				if (inMap == false) {
					throw inMap;
					user_y -= 1;
				}
				else {
					cout << "���� �� ĭ �������ϴ�." << endl;
					displayMap(map, user_x, user_y);
					my_user.DecreaseHp(1);
					checkState(map, user_x, user_y, my_user);

				}
			}
			else if (user_input == "��") {
				// TODO: �������� �̵��ϱ�
				user_x -= 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);

				if (inMap == false) {
					throw inMap;
					user_x += 1;
				}
				else {
					cout << "�������� �̵��մϴ�." << endl;
					displayMap(map, user_x, user_y);
					my_user.DecreaseHp(1);
					checkState(map, user_x, user_y, my_user);

				}
			}
			else if (user_input == "��") {
				// TODO: ���������� �̵��ϱ�
				user_x += 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				if (inMap == false) {
					throw inMap;
					user_x -= 1;
				}
				else {
					cout << "���������� �̵��մϴ�." << endl;
					displayMap(map, user_x, user_y);
					my_user.DecreaseHp(1);
					checkState(map, user_x, user_y, my_user);

				}
			}
			else if (user_input == "����") {
				// TODO: ���� �����ֱ� �Լ� ȣ��
				displayMap(map, user_x, user_y);
			}
			else if (user_input == "����") {
				cout << "�����մϴ�.";
				break;
			}
			else {
				cout << "�߸��� �Է��Դϴ�." << endl;
				continue;
			}
		}
		catch (...) {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

		if ((user_x == 1 && user_y == 3) || (user_x == 4 && user_y == 4) || (user_x == 3 && user_y == 1)) {
			if (currentUser == 'M') {
				M.doAttack(); // Magician�� doAttack ȣ��
			}
			else if (currentUser == 'W') {
				W.doAttack(); // Warrior�� doAttack ȣ��
			}
			my_user.DecreaseHp(2);
		}

		bool check = CheckUser(my_user);
		if (check == false) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
			cout << "������ �����մϴ�." << endl;
			break;

		}

		k++;
	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

//����/����,����,���� �������� hp ������ �Լ�
void checkState(int map[][mapX], int user_x, int user_y, User& my_user) {
	if (user_x == 0 && user_y == 1) {
		cout << "�������� �ֽ��ϴ�." << endl;
	}
	else if (user_x == 1 && user_y == 0) {
		cout << "�������� �ֽ��ϴ�." << endl;
	}
	else if (user_x == 0 && user_y == 4) {
		cout << "������ �ֽ��ϴ�. HP�� 2 ����մϴ�." << endl;
		my_user.IncreaseHp(2);
	}
	else if (user_x == 2 && user_y == 3) {
		cout << "������ �ֽ��ϴ�. HP�� 2 ����մϴ�." << endl;
		my_user.IncreaseHp(2);
	}
	else if (user_x == 1 && user_y == 3) {
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		my_user.DecreaseHp(2);
	}
	else if (user_x == 4 && user_y == 4) {
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		my_user.DecreaseHp(2);
	}
	else if (user_x == 3 && user_y == 1) {
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		my_user.DecreaseHp(2);
	}
}

bool CheckUser(User user) {
	if (user.GetHp() <= 0) {
		return false;
	}
	return true;
}

void readMap(int map[][mapX], const string& filename) {
	ifstream is(filename);

	if (!is) {
		cerr << "���� �߻�: " << filename << endl;
		exit(1);
	}

	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			char cell;
			is >> cell;
			map[i][j] = cell - '0'; 
		}
	}
}
