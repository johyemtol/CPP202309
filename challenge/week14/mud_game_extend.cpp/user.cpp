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
    cout << "공격합니다" << endl;
}

void Magician::doAttack() {
    cout << "마법 사용" << endl;
}

void Warrior::doAttack() {
    cout << "베기 사용" << endl;
}
