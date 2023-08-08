#pragma once
#include "warrior.h"
#include "assasin.h"
#include <string>
#include <iostream>
#include "enemy.h"

using namespace std;

class enemy;

class mage
{
public:
	string mName= "Mage";
	string mClass = "Mage";
	int mHP = 9;
	int mPOW = 5;
	int mVit = 5;
	int mDex = 9;
	int mAgi = 6;

	void Attack(enemy* target);
};