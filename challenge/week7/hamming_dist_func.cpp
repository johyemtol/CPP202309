#include <iostream>
#include <string>
using namespace std;

//함수 원형 정의
string toLowerStr(string str);
string toUpperStr(string str);
int calcHammingDist(string s1, string s2);

int main() {
	string s1, s2;

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	calcHammingDist(s1, s2);
	return 0;
}

//toLowerStr 함수
string toLowerStr(string str) {
	string newStr = str;
	for (char& c : newStr) {
		c = tolower(c);
	}
	return newStr;
}

//toUpperrStr 함수

string toUpperStr(string str) {
	string newStr = str;
	for (char& c : str) {
		c = toupper(c);
	}
	return newStr;
}
//허밍거리 계산 함수 짜기
int calcHammingDist(string s1, string s2) {
	s1=toLowerStr(s1);
	s2=toLowerStr(s2);
	int count = 0;
	//반복문
	//while (s1.length() != s2.length()) {
	//	cout << "오류: 길이가 다름 다시 입력하세요" << endl;
	//	cout << "DNA1: ";
	//	cin >> s1;
	//	cout << "DNA2: ";
	//	cin >> s2;
	// }
	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;
	//길이가 같다면 해밍거리 틀린거에 따라 +1씩 하기
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "해밍 거리는 " << count << endl;
	}
	return count;
}