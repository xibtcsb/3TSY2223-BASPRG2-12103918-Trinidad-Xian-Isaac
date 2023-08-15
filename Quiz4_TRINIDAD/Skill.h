#pragma once
#include <string>
#include "Unit.h"
#include <iostream>
#include <cmath>

using namespace std;

class Unit;

class Skill
{
public:
	Skill(string name, int mpCost);
	~Skill();
	int getMpCost();
	string getName();

	Unit* getActor();
	void setActor(Unit* actor);

	virtual void activate(Unit* target);

private:
	string mName;
	Unit* mActor;
	int mMpCost;
};


