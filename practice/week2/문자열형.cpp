#include <iostream>
#include <string>
using namespace std;

int main() {
	//string을 정의 함
	string s1 = "Good";
	string s2 = "Morning";
	string s3 = s1 + " " + s2 + "!";  //s3은 string으로 만들어 다른 string과 합쳐줌
	cout << s3 << endl;				//s3 출력
	return 0;
}