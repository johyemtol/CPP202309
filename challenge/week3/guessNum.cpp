#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));		//random 함수 관련 설정

	int answer = rand() % 100;		//정답
	int tries = 0;			//시도 횟수 저장하는 변수

	int guess;					//사용자 입력 저장하기 위한 변수

	while (true) {
		cout << "정답을 추측하여 보시오: ";
		cin >> guess;
		tries++;		//횟수 증가
		if (guess < answer)		//정답이 더 크다면
			cout << "제시한 정수가 낮습니다" << endl;
		else if (guess > answer)		//정답이 더 작다면
			cout << "제시한 정수가 높습니다"<<endl;
		else if (guess == answer) {		//맞췄다면
			cout << "축하합니다. 시도횟수=" << tries;
			break;
		}
	}

}