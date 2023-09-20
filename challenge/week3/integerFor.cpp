#include <iostream>
using namespace std;

int main() {
	int userInput;

	cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";
	for (int i = 0; i < 10;i++) {				//int 범위 지정
		cin >> userInput;
		if (userInput == 0) {						//0을 입력하면 종료
			break;
		}
		cout << "입력값: " << userInput << " 횟수 :" << i << endl;

		if (i == 10) {						//10번 입력되었다면 종료
			break;
		}
	}
	cout << "종료되었습니다";					//종료 안내

	return 0;
}