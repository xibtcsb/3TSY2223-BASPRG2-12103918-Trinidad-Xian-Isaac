#pragma once
#include <string>
#include <iostream>
using namespace std;

class wizard;

class spell
{
public:
	string sName;
	int sMinDamage = 40;
	int sMaxDamage = 60;
	int sCost = 50;

	void activate(wizard* caster, wizard* target);
};