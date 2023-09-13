#include <iostream>
using namespace std;

int main() {
    int my_money;       //현재 가지고 있는돈
    int candy;          //candy가격

    cout << "현재 가지고 있는 돈 : ";
    cin >> my_money;

    cout << "캔디의 가격 : ";
    cin >> candy;

    int money_max = my_money / candy;               //캔디 구입할 수 있는 값 계산 몫으로
    int change = my_money - (money_max * candy); // 캔디 구입 후 남은 돈 계산

    cout << "최대로 살 수 있는 캔디 = " << money_max << endl;
    cout << "캔디 구입 후 남은 돈 = " << change << endl;

    return 0;
}
