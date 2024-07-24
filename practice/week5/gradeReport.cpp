#include <iostream>
#include <string>
using namespace std;

int main() {
	//상수 지정하기 학생수는 5명, 과목은 3개
	const int STUDENT = 5;
	const int SUBJECT = 3;
	//2차원 배열 만들기 점수로 행열 학생과 과목으로
	int scores[STUDENT][SUBJECT];
	//배열 이름 지정하기 student,subject
	string studentNames[STUDENT]
		= { "영수","영희","철수","미미" };
	string subjectNames[SUBJECT]
		= { "수학","영어" };
	//2차원 배열 채워넣기 학생 5명 동안
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 성적을 하나씩 입력하세요." << endl;
		//과목 3개 넣기 (cin 을 사용하여)
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}
	//평균 구하기 학생 각각마다
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 평균 점수는 ";
		double sum = 0;
		double average = 0;
		//각 과목 학생들의 성적 다 더하기
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "입니다" << endl;
	}
	return 0;
}
