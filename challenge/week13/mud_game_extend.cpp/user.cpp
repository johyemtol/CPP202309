#include "user.h"

int User::GetHp() {
    return hp;
}

void User::DecreaseHp(int dec_hp) {
    hp -= dec_hp;
}

void User::IncreaseHp(int inc_hp) {
    hp += inc_hp;
}

void User::doAttack() {
    cout << "�����մϴ�" << endl;
}

void Magician::doAttack() {
    cout << "���� ���" << endl;
}

void Warrior::doAttack() {
    cout << "���� ���" << endl;
}
