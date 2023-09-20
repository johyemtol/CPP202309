#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	int ans;
	int n=0;
	cout << "산수 문제를 자동으로 출제합니다. " << endl;

	while (true) {
		//time함수를 통해 랜덤 숫자 형성
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;
		//정답 계산하기
		ans = firstNum + secondNum;
		cout << firstNum << "+" << secondNum << "=";
		cin >> i;
		if (ans == i) {					//정답이랑 일치할때
			cout << "맞았습니다." << endl;
			n++;
		}
		else
			cout << "틀렸습니다."<<endl;
		if (n == 5)					//맞춘횟수가 5회라면 멈추게 하기
			break;
	}
}