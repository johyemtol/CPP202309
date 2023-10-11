#include <iostream>
using namespace std;

int main() {
	const int numCell = 3;
	//3x3배열
	char board[numCell][numCell]{};	
	//사용자에게 입력받는 x,y 좌표 저장할 변수
	int x, y;						

	//보드판 초기화
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}
	//게임 코드
	//차례정하기 위한 변수
	int k = 0;					
	//유저 돌 이름 x로 나타나기위해
	char currentUser = 'X';			
	while (true) {
		//누구 차례인지 출력
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 ->";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "번 유저(0)의 차례입니다 ->";
			currentUser = '0';
			break;
		}

		//좌표 입력받기
		cout << "(x,y) 좌표를 입력하세요: ";
		cin >> x >> y;

		//cin 좌표의 유효성 검사(틀 벗어난것,틀 이미 채워져있는것)
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": 이미 돌이 차있습니다."<<endl;
			continue;
		}
		

		//돌 놓기
		board[x][y] = currentUser;

	
		//현재 보드 판 출력
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				//보드판 출력
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
		
		//모든 칸 찼는지 확인
		int check = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					check++;
				}
			}
		}
		//check된게 0이라면 모든 칸이 다 찬거
		if (check == 0) {
			cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
			break;
		}

		//승패 확인 코드
		bool win = false;
		//가로 세로 빙고
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "가로에 모두 돌이 놓였습니다!: ";
				win = true;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "세로에 모두 돌이 놓였습니다!: ";
				win = true;
			}
		}
		//대각선 빙고
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓여있습니다!: ";
			win = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓여있습니다!: ";
			win = true;
		}
		//승자 출력
		if (win == true) {
			cout << k % 2 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			cout << "종료합니다" << endl;
			break;
		}
	}

	
	
	return 0;
}
