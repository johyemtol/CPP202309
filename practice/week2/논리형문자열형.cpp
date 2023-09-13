#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "Good";	
	string s2 = "Bad";
	bool b = (s1 == s2);		//s1과 s2가 같은지에 대해 true false를 진행함 false임
	cout << b << endl;			//b를 출력하는데 false값이므로 0이 나오게 됨

	s2 = "Good";				//s2를 Good으로 바꿈
	b = (s1 == s2);				//s1과 s2과 같으므로 true가 나옴
	cout << b << endl;			//true 이므로 1값이 나옴
}