#include <iostream>
using namespace std;

int main() {
	const int numCell = 3;
	//3x3�迭
	char board[numCell][numCell]{};	
	//����ڿ��� �Է¹޴� x,y ��ǥ ������ ����
	int x, y;						

	//������ �ʱ�ȭ
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}
	//���� �ڵ�
	//�������ϱ� ���� ����
	int k = 0;					
	//���� �� �̸� x�� ��Ÿ��������
	char currentUser = 'X';			
	while (true) {
		//���� �������� ���
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� ->";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "�� ����(0)�� �����Դϴ� ->";
			currentUser = '0';
			break;
		}

		//��ǥ �Է¹ޱ�
		cout << "(x,y) ��ǥ�� �Է��ϼ���: ";
		cin >> x >> y;

		//cin ��ǥ�� ��ȿ�� �˻�(Ʋ �����,Ʋ �̹� ä�����ִ°�)
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x �� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�."<<endl;
			continue;
		}
		

		//�� ����
		board[x][y] = currentUser;

	
		//���� ���� �� ���
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				//������ ���
				cout << board[i][j];			
				if (j == numCell - 1) {
					break;
				}
				cout <<"  |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl;
		k++;
		
		//��� ĭ á���� Ȯ��
		int check = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					check++;
				}
			}
		}
		//check�Ȱ� 0�̶�� ��� ĭ�� �� ����
		if (check == 0) {
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�" << endl;
			break;
		}

		//���� Ȯ�� �ڵ�
		bool win = false;
		//���� ���� ����
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ�!: ";
				win = true;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ�!: ";
				win = true;
			}
		}
		//�밢�� ����
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �����ֽ��ϴ�!: ";
			win = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �����ֽ��ϴ�!: ";
			win = true;
		}
		//���� ���
		if (win == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "�����մϴ�" << endl;
			break;
		}
	}

	
	
	return 0;
}