#pragma once
#include <iostream>
#include <string>
using namespace std;
//hp ������� ���� �����ڴ� ��� private�� ����
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

