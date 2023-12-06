#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class User
{
private:
	int hp;
public:
	User() :hp(20) {}
	int GetHp();
	void DecreaseHp(int dec_hp);
	void IncreaseHp(int inc_hp);
	virtual void doAttack();
};

class Magician :public User {
public:
	void doAttack() override;
};

class Warrior :public User {
public:
	void doAttack() override;
};