#include <iostream>
using namespace std;

int main() {
	int choice;
	//cout으로 1,2,3에 해당하는 결과 알려주기
	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;

	//if 문으로 choice 경우의 수 선택하기
	if (choice == 1)
		cout << "파일 저장을 선택했습니다." << endl;
	else if (choice == 2)
		cout << "파일 닫기를 선택했습니다." << endl;
	else if (choice == 3)
		cout << "프로그램을 종료합니다." << endl;
	else            //1,2,3이 아니고 다른걸 입력했다면
		cout << "잘못된 선택입니다." << endl;

	return 0;
}