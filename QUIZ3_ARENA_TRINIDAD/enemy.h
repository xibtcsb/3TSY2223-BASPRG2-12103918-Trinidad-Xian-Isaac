#pragma once
#include <string>
#include <iostream>
#include "warrior.h"
#include "assasin.h"
#include "mage.h"

using namespace std;

class enemy
{
public:
	
	string mClass;


	string mName;
	int mHP;
	int mPOW;
	int mVit;
	int mDex;
	int mAgi;

	void Attack();

};

