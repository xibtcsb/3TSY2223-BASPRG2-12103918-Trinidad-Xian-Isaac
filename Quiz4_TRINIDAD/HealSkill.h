#pragma once
#include "Skill.h"
#include <string>
#include <iostream>
using namespace std;

class HealSkill :
	public Skill
{
public:
	HealSkill(string name, int healValue);
	~HealSkill();

	// Override parent's virtual function. There's no need to set this to virtual since we're not expecting this class to be inherited further.
	void activate(Unit* target);

private:
	int mHealValue;
};


