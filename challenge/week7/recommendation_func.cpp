#include <iostream>
using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;

//사용자 선호도 입력받는 함수
void initializePreferences(int userPreferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; ++i) {
        cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
        cout << NUM_ITEMS << "개의 항목에 대해 ):";
        for (int j = 0; j < NUM_ITEMS; ++j) {
            cin >> userPreferences[i][j];
        }

    }
}

//사용자 별 추천 항목을 찾고 출력하는 함수
void findRecommendedItems(const int userPreferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; ++i) {
        int maxPreferenceIndex = 0;
        for (int j = 1; j < NUM_ITEMS; ++j) {
            if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
                maxPreferenceIndex = j;
            }
        }
        cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
        cout << (maxPreferenceIndex + 1) << endl;
    }
}

//main()함수 실행
int main() {
    int userPreferences[NUM_USERS][NUM_ITEMS];
    initializePreferences(userPreferences);
    findRecommendedItems(userPreferences);
    return 0;
}
