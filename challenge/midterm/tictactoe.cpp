#include <iostream>
using namespace std;
//numCell�ٲٰ������ �ٲ������
bool isValid(int x, int y, int numCell, char board[][4]);
bool checkWin(char board[][4], char currentUser, int numCell);
const int numCell = 4;

int main() {

    // �迭
    char board[numCell][numCell]{};
    // ����ڿ��� �Է¹޴� x,y ��ǥ ������ ����
    int x, y;

    // ������ �ʱ�ȭ
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // ���� �ڵ�
    // �������ϱ� ���� ����
    int k = 0;
    // ���� �� �̸� x�� ��Ÿ��������
    char currentUser = 'X';

    while (true) {
        // ���� �������� ���
        switch (k % 3) {
        case 0:
            cout << k % 3 + 1 << "�� ����(X)�� �����Դϴ� ->";
            currentUser = 'X';
            break;
        case 1:
            cout << k % 3 + 1 << "�� ����(0)�� �����Դϴ� ->";
            currentUser = '0';
            break;
        case 2:
            cout << k % 3 + 1 << "�� ����(K)�� �����Դϴ� ->";
            currentUser = 'K';
            break;
        }

        // ��ǥ �Է¹ޱ�
        cout << "(x,y) ��ǥ�� �Է��ϼ���: ";
        cin >> x >> y;

        // �Լ�ȭ ��ȿ�� 
        if (!isValid(x, y, numCell, board)) {
            continue;
        }

        // �� ����
        board[x][y] = currentUser;

        // ���� ���� �� ���
        for (int i = 0; i < numCell; i++) {
            cout << "----";
        }
        cout << endl;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (j == 0) {
                    cout << "| ";
                }
                cout << board[i][j] << " | ";
            }
            cout << endl;
            if (i < numCell - 1) {
                for (int j = 0; j < numCell * 4 + 1; ++j) {
                    cout << "-";
                }
                cout << endl;
            }
        }

        for (int i = 0; i < numCell; i++) {
            cout << "----";
        }
        cout << endl;
        k++;

        // ��� ĭ á���� Ȯ��
        int check = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    check++;
                }
            }
        }
        // check�Ȱ� 0�̶�� ��� ĭ�� �� ����
        if (check == 0) {
            cout << "��� ĭ�� �� á���ϴ�. �����մϴ�" << endl;
            break;
        }

        // ���� Ȯ�� �ڵ�
        bool win = false;

        // �밢�� ����
        bool diabingo1 = true;
        bool diabingo2 = true;
        for (int i = 0; i < numCell; i++) {
            if (board[i][i] != currentUser) {
                diabingo1 = false;
            }
            if (board[i][numCell - 1 - i] != currentUser) {
                diabingo2 = false;
            }
        }
        if (diabingo1) {
            cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �����ֽ��ϴ�!: ";
            win = true;
        }

        if (diabingo2) {
            cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �����ֽ��ϴ�!: ";
            win = true;
        }
        // ���� ���
        if (checkWin(board, currentUser, numCell)) {
            cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
            cout << "�����մϴ�" << endl;
            break;
        }

    }
    return 0;
}

bool isValid(int x, int y, int numCell, char board[][4]) {
    // cin ��ǥ�� ��ȿ�� �˻�(Ʋ �����,Ʋ �̹� ä�����ִ°�)
    if (x >= numCell || y >= numCell) {
        cout << x << ", " << y << ": ";
        cout << "x �� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
        return false;
    }
    if (board[x][y] != ' ') {
        cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
        return false;
    }
    return true;
}

//checkWin�Լ�
bool checkWin(char board[][4], char currentUser, int numCell) {
    //���μ��� �Ǻ�
    for (int i = 0; i < numCell; i++) {
        bool rowWin = true;
        bool colWin = true;

        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) {
                rowWin = false;
            }
            if (board[j][i] != currentUser) {
                colWin = false;
            }
        }

        if (rowWin || colWin) {
            cout << (rowWin ? "����" : "����") << "�� ��� ���� �������ϴ�!: ";
            return true;
        }
    }

    // �밢�� ����
    bool diabingo1 = true;
    bool diabingo2 = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] != currentUser) {
            diabingo1 = false;
        }
        if (board[i][numCell - 1 - i] != currentUser) {
            diabingo2 = false;
        }
    }
    if (diabingo1 || diabingo2) {
        cout << (diabingo1 ? "���� ������ ������ �Ʒ�" : "������ ������ ���� �Ʒ�") << " �밢������ ��� ���� �����ֽ��ϴ�!: ";
        return true;
    }

    return false;
}
