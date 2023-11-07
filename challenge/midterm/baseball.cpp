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
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum = 0; // 정답의 첫번째 자리수
	int secondNum = 0; // 정답의 두번째 자리수
	int thirdNum = 0; // 정답의 세번째 자리수

	while (1) {
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		//firstNum = randomNum / 100;
		//thirdNum = randomNum % 10;
		//secondNum = (randomNum - firstNum * 100) / 10;

		//세개의 숫자가 중복된게 있다면 다시 while 처음 문으로 가기
		//if (firstNum == secondNum || firstNum == thirdNum || secondNum == thirdNum) {
		//	continue;
		//}
		//중복된 숫자가 없다면 넘어가기
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
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst=0; // 추측한 숫자의 첫번째 자리수
		int guessSecond=0; // 추측한 숫자의 두번째 자리수
		int guessThird=0; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
			//guessFirst = userNumber / 100;
			//guessThird = userNumber % 10;
			//guessSecond = (userNumber - guessFirst * 100) / 10;

			//입력된 숫자들 중에 중복 숫자가 있는지 확인하기
			//if (guessFirst == guessSecond || guessFirst == guessThird || guessSecond == guessThird) {
			//	cout << "입력된 숫자에 중복된 숫자가 있습니다. 다시 입력하세요\n";
			//	continue;
			//}
			if (!checkNumber(userNumber)) {
				continue;
			}
			//입력된 숫자의 길이가 3이 아닐때
			if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}
			//입력된 숫자의 길이가 3이고 중복된 숫자가 없을 때 while문 빠져나오기
			else {
				guessFirst = userNumber / 100;
				guessThird = userNumber % 10;
				guessSecond = (userNumber - guessFirst * 100) / 10;
				break;
			}

		}


		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
		//strike 개수 증가 시키기
		if (firstNum == guessFirst) {
			strike +=1;
		}
		if (secondNum == guessSecond) {
			strike += 1;
		}
		if (thirdNum == guessThird) {
			strike += 1;
		}
		//ball 개수 증가시키기
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

		//스트라이크와 볼 개수 출력하기
		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;

		//strike 전부 다 맞춘다면 멈춤
		if (strike == 3) {

			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}
		//횟수 증가시키기
		turn += 1;
	}

	return 0;
}
