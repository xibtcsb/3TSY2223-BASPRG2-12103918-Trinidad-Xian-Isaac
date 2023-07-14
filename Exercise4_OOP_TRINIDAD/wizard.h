#pragma once
#include <string>
#include <iostream>
using namespace std;

class wizard
{
public:
	string mName;
	int mHP = 250;
	int mMP = 0;
	int mMinDamage = 10;
	int mMaxDamage = 15;

	void Attack(wizard* target);
};