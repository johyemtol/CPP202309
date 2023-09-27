#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople=3;					//maxPeople을 3으로 지정
	//cout << "총 고객의 수를 입력하라: ";
	//cin >> maxPeople;
	string names[maxPeople];				//string 타입의 배열 만들기
	int ages[maxPeople];					//int 타입의 배열 만들기
	//이름하고 나이 입력받기
	for (int i = 0; i < maxPeople; i++) {
		cout << "사람 " << i + 1 << "의 이름: ";
		cin >> names[i];
		cout << "사람" << i + 1 << "의 나이: ";
		cin >> ages[i];
	}
	//특정 나이 이상 찾기 코드
	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold;

	cout << ageThreshold << "세 이상인 고객들:\n";
	
	int correctagePeople = 0;
	for (int i = 0; i < maxPeople;i++) {
	
		if (ages[i] >= ageThreshold) {							//나이에 맞는 이상의 고객들이 있다면 출력
			cout << names[i] << " (" << ages[i] << "세)\n";
			correctagePeople++;
		}

		
	}
	if (correctagePeople == 0)						//나이에 맞는 고객이 없다면
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";
}