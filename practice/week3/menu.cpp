#include <iostream>
using namespace std;

int main() {
	int choice;
	//cout으로 1,2,3에 해당하는 결과 알려주기
	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료!" << endl;
	//cin으로 choice 입력받기
	cin >> choice;

	//switch문을 사용하여 choice에 따른 결과 알려주기
	switch (choice) {
	case 1:		//choice가 1일때 1을 입력하였을때
		cout << "파일 저장을 선택했습니다." << endl;
		break;
	case 2:
		cout << "파일 닫기를 선택했습니다." << endl;
		break;
	case 3:
		cout << "프로그램을 종료합니다." << endl;
		break;
	default:	//choice에 없는 선택을 하였을때
		cout << "잘못된 선택입니다." << endl;
		break;
	}

	return 0;
}
