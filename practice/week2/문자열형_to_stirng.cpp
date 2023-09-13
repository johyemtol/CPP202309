#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "사과";
	string s2;
	//s2=s1+" "+10+"개" 왜 오류가날까? to_string으로 진행하지 않아서 
	s2 = s1 + " " + to_string(10) + "개";		//s2를 정의할때 to_string을 통해 값을 정의함
	cout << s2 << endl;							//출력하면 사과 10개라는 값을 가지게 됨
}