#pragma once
#include <string>
#include "Stats.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Skill.h"

class Skill;

using namespace std;

class Unit
{
public:
	Unit(string name, int hp, int pow, int vit, int agi, int dex, int mp);
	~Unit();

	// Getters
	string getName();
	//get stats
	int getMaxHp();
	int getCurrentHp();
	int getPow();
	int getVit();
	int getAgi();
	int getDex();
	int getMaxMp();
	int getCurrentMp();

	//set stats
	void setMaxHp(int value);
	void setHp(int value);
	void setPow(int value);
	void setVit(int value);
	void setDex(int value);
	void setAgi(int value);
	void setMaxMp(int value);
	void setCurrentMp(int value);
	void heal(int amount);

	// This allows us to expose the vector without allowing the user to change the contents of the vector. However, they can still use the Skill's function freely.
	const vector<Skill*>& getSkills();

	// We want to control how the vector is modified so we expose this function instead
	void addSkill(Skill* skill);
	//for player
	void printSkills();

	bool alive();
	void displayStatus();

	// I did not add a UseSkill function since the Skill already has an actor (Unit) attached to it. To activate a skill, you must get the skill from the vector first (getSkills()) then call activate.

private:
	string mName;
	int mMaxHp;
	int mCurrentHp;
	int mPow;
	int mVit;
	int mAgi;
	int mDex;
	int mMaxMp;
	int mCurrentMp;
	vector<Skill*> mSkills;
};

