#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int maxPeople;
    cout << "총 고객의 수를 입력하라: ";
    cin >> maxPeople;

    vector<string> names(maxPeople);  
    vector<int> ages(maxPeople);     

    // 이름하고 나이 입력받기
    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    // 특정 나이 이상 찾기 코드
    int ageThreshold;
    cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
    cin >> ageThreshold;

    cout << ageThreshold << "세 이상인 고객들:\n";

    int correctAgePeople = 0;
    //나이 많은 사람 출력하기
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] >= ageThreshold) { 
            cout << names[i] << " (" << ages[i] << "세)\n";
            correctAgePeople++;
        }
    }

    //만약 나이에 맞는 사람이 없다면
    if (correctAgePeople == 0) 
        cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";

    return 0;
}
