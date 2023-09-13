#include <iostream>
using namespace std;

int main() {
    int my_money;
    int candy;

    cout << "현재 가지고 있는 돈 : ";
    cin >> my_money;

    cout << "캔디의 가격 : ";
    cin >> candy;

    int money_max = my_money / candy;
    int change = my_money - (money_max * candy); // 캔디 구입 후 남은 돈 계산

    cout << "최대로 살 수 있는 캔디 = " << money_max << endl;
    cout << "캔디 구입 후 남은 돈 = " << change << endl;

    return 0;
}
