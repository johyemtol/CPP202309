#include <iostream>
using namespace std;
//numCell바꾸고싶으면 바꿔줘야함
bool isValid(int x, int y, int numCell, char board[][4]);
bool checkWin(char board[][4], char currentUser, int numCell);
const int numCell = 4;

int main() {

    // 배열
    char board[numCell][numCell]{};
    // 사용자에게 입력받는 x,y 좌표 저장할 변수
    int x, y;

    // 보드판 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임 코드
    // 차례정하기 위한 변수
    int k = 0;
    // 유저 돌 이름 x로 나타나기위해
    char currentUser = 'X';

    while (true) {
        // 누구 차례인지 출력
        switch (k % 3) {
        case 0:
            cout << k % 3 + 1 << "번 유저(X)의 차례입니다 ->";
            currentUser = 'X';
            break;
        case 1:
            cout << k % 3 + 1 << "번 유저(0)의 차례입니다 ->";
            currentUser = '0';
            break;
        case 2:
            cout << k % 3 + 1 << "번 유저(K)의 차례입니다 ->";
            currentUser = 'K';
            break;
        }

        // 좌표 입력받기
        cout << "(x,y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 함수화 유효성 
        if (!isValid(x, y, numCell, board)) {
            continue;
        }

        // 돌 놓기
        board[x][y] = currentUser;

        // 현재 보드 판 출력
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

        // 모든 칸 찼는지 확인
        int check = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    check++;
                }
            }
        }
        // check된게 0이라면 모든 칸이 다 찬거
        if (check == 0) {
            cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
            break;
        }

        // 승패 확인 코드
        bool win = false;

        // 대각선 빙고
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
            cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓여있습니다!: ";
            win = true;
        }

        if (diabingo2) {
            cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓여있습니다!: ";
            win = true;
        }
        // 승자 출력
        if (checkWin(board, currentUser, numCell)) {
            cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            cout << "종료합니다" << endl;
            break;
        }

    }
    return 0;
}

bool isValid(int x, int y, int numCell, char board[][4]) {
    // cin 좌표의 유효성 검사(틀 벗어난것,틀 이미 채워져있는것)
    if (x >= numCell || y >= numCell) {
        cout << x << ", " << y << ": ";
        cout << "x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return false;
    }
    if (board[x][y] != ' ') {
        cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
        return false;
    }
    return true;
}

//checkWin함수
bool checkWin(char board[][4], char currentUser, int numCell) {
    //가로세로 판별
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
            cout << (rowWin ? "가로" : "세로") << "에 모두 돌이 놓였습니다!: ";
            return true;
        }
    }

    // 대각선 빙고
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
        cout << (diabingo1 ? "왼쪽 위에서 오른쪽 아래" : "오른쪽 위에서 왼쪽 아래") << " 대각선으로 모두 돌이 놓여있습니다!: ";
        return true;
    }

    return false;
}
