#pragma once
#include <iostream>
#include <string>
using namespace std;
//hp 멤버변수 접근 지정자는 모두 private로 변경
class User
{
private:
	int hp;
public:
	User():hp(20){}
	int GetHp();
	void DecreaseHp(int dec_hp);
	void IncreaseHp(int inc_hp);
};

