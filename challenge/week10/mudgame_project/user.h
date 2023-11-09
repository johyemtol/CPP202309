#pragma once
#include <iostream>
#include <string>
using namespace std;
class User
{
public:
	int hp;
	int GetHp(int hp);
	void DecreaseHp(int dec_hp); 
	void IncreaseHp(int inc_hp);
};
