#pragma once
#include "warrior.h"
#include "mage.h"
#include <string>
#include <iostream>
#include "enemy.h"

using namespace std;

class enemy;

class assasin
{
public:
	string mName = "Assasin";
	string mClass = "Assasin";
	int mHP = 12;
	int mPOW = 3;
	int mVit = 8;
	int mDex = 12;
	int mAgi = 8;

	void Attack(enemy* target);
};