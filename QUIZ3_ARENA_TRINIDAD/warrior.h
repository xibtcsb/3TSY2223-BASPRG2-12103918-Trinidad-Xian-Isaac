#pragma once
#include "assasin.h"
#include "mage.h"
#include <string>
#include <iostream>
#include "enemy.h"

using namespace std;

class enemy;

class warrior
{
public:
	string mName = "Warrior";
	string mClass = "Warrior";
	int mHP = 15;
	int mPOW = 4;
	int mVit = 6;
	int mDex = 8;
	int mAgi = 4;
		
	void Attack(enemy* target);
};