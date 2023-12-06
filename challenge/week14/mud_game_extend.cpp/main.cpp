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


	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX];
	readMap(map, "map.txt");


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	int k = 0;
	char currentUser = 'W';

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		switch (k % 2) {
		case 0:  // 0일 때 M의 차례
			cout << (k % 2 + 1) << "번 유저(M)의 차례:";
			currentUser = 'M';
			break;
		case 1:  // 1일 때 W의 차례
			cout << (k % 2 + 1) << "번 유저(W)의 차례:";
			currentUser = 'W';
			break;
		}

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP: " << my_user.GetHp() << " 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		//위로 올라가기 상
		try {
			if (user_input == "상") {
				user_y -= 1;
				//함수 통해 맵 내에 존재하는 지 체크
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				//맵 내 존재 안한다면
				if (inMap == false) {
					throw inMap;
					user_y += 1;
				}
				//맵 내 존재한다면 한칸 올라가고 지도 함수 출력과 checkState 함수 하기
				else {
					cout << "위로 한 칸 올라갑니다." << endl;
					displayMap(map, user_x, user_y);
					my_user.DecreaseHp(1);
					checkState(map, user_x, user_y, my_user);
				}
			}
			else if (user_input == "하") {
				// TODO: 아래로 한 칸 내려가기
				user_y += 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				if (inMap == false) {
					throw inMap;
					user_y -= 1;
				}
				else {
					cout << "위로 한 칸 내려갑니다." << endl;
					displayMap(map, user_x, user_y);
					my_user.DecreaseHp(1);
					checkState(map, user_x, user_y, my_user);

				}
			}
			else if (user_input == "좌") {
				// TODO: 왼쪽으로 이동하기
				user_x -= 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);

				if (inMap == false) {
					throw inMap;
					user_x += 1;
				}
				else {
					cout << "왼쪽으로 이동합니다." << endl;
					displayMap(map, user_x, user_y);
					my_user.DecreaseHp(1);
					checkState(map, user_x, user_y, my_user);

				}
			}
			else if (user_input == "우") {
				// TODO: 오른쪽으로 이동하기
				user_x += 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				if (inMap == false) {
					throw inMap;
					user_x -= 1;
				}
				else {
					cout << "오른쪽으로 이동합니다." << endl;
					displayMap(map, user_x, user_y);
					my_user.DecreaseHp(1);
					checkState(map, user_x, user_y, my_user);

				}
			}
			else if (user_input == "지도") {
				// TODO: 지도 보여주기 함수 호출
				displayMap(map, user_x, user_y);
			}
			else if (user_input == "종료") {
				cout << "종료합니다.";
				break;
			}
			else {
				cout << "잘못된 입력입니다." << endl;
				continue;
			}
		}
		catch (...) {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		if ((user_x == 1 && user_y == 3) || (user_x == 4 && user_y == 4) || (user_x == 3 && user_y == 1)) {
			if (currentUser == 'M') {
				M.doAttack(); // Magician의 doAttack 호출
			}
			else if (currentUser == 'W') {
				W.doAttack(); // Warrior의 doAttack 호출
			}
			my_user.DecreaseHp(2);
		}

		bool check = CheckUser(my_user);
		if (check == false) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;

		}

		k++;
	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

//무기/갑옷,포션,적을 만났을때 hp 증감소 함수
void checkState(int map[][mapX], int user_x, int user_y, User& my_user) {
	if (user_x == 0 && user_y == 1) {
		cout << "아이템이 있습니다." << endl;
	}
	else if (user_x == 1 && user_y == 0) {
		cout << "아이템이 있습니다." << endl;
	}
	else if (user_x == 0 && user_y == 4) {
		cout << "포션이 있습니다. HP가 2 상승합니다." << endl;
		my_user.IncreaseHp(2);
	}
	else if (user_x == 2 && user_y == 3) {
		cout << "포션이 있습니다. HP가 2 상승합니다." << endl;
		my_user.IncreaseHp(2);
	}
	else if (user_x == 1 && user_y == 3) {
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		my_user.DecreaseHp(2);
	}
	else if (user_x == 4 && user_y == 4) {
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		my_user.DecreaseHp(2);
	}
	else if (user_x == 3 && user_y == 1) {
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
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
		cerr << "에러 발생: " << filename << endl;
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
