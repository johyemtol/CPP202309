#include <iostream>
using namespace std;

int main() {
    int my_money;
    int candy;

    cout << "���� ������ �ִ� �� : ";
    cin >> my_money;

    cout << "ĵ���� ���� : ";
    cin >> candy;

    int money_max = my_money / candy;
    int change = my_money - (money_max * candy); // ĵ�� ���� �� ���� �� ���

    cout << "�ִ�� �� �� �ִ� ĵ�� = " << money_max << endl;
    cout << "ĵ�� ���� �� ���� �� = " << change << endl;

    return 0;
}
