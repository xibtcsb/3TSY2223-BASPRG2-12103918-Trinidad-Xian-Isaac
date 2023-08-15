#include "Unit.h"

Unit::Unit(string name, int hp, int pow, int vit, int agi, int dex, int mp)
{
	mName = name;
	mMaxHp = hp;
	mCurrentHp = hp;
	mPow = pow;
	mVit = vit;
	mAgi = agi;
	mDex = dex;
	mMaxMp = mp;
	mCurrentMp = mp;
}

Unit::~Unit()
{
	// Delete all skills
	for (int i = 0; i < mSkills.size(); i++)
	{
		delete mSkills[i];
	}
	mSkills.clear();
}

string Unit::getName()
{
	return mName;
}


int Unit::getMaxHp()
{
	return mMaxHp;
}

int Unit::getCurrentHp()
{
	return mCurrentHp;
}

int Unit::getPow()
{
	return mPow;
}

int Unit::getVit()
{
	return mVit;
}

int Unit::getAgi()
{
	return mAgi;
}

int Unit::getDex()
{
	return mDex;
}

int Unit::getMaxMp()
{
	return mMaxMp;
}

int Unit::getCurrentMp()
{
	return mCurrentMp;
}

void Unit::setMaxHp(int value)
{
	mMaxHp = value;
}

void Unit::setHp(int value)
{
	mCurrentHp = value;

	if (mCurrentHp > mMaxHp)
	{
		mCurrentHp = mMaxHp;
	}

	if (mCurrentHp < 0)
	{
		mCurrentHp = 0;
	}


}

void Unit::heal(int amount) {
	mCurrentHp += amount;
	if (mCurrentHp > mMaxHp) {
		mCurrentHp = mMaxHp;
	}
}

void Unit::setPow(int value)
{
	mPow = value;
}

void Unit::setVit(int value)
{
	mVit = value;
}

void Unit::setDex(int value)
{
	mDex = value;
}

void Unit::setAgi(int value)
{
	mAgi = value;
}

void Unit::setMaxMp(int value)
{
	mMaxMp = value;
	//since we'll only set this up once
	mCurrentMp = value;
}

void Unit::setCurrentMp(int value)
{
	mCurrentMp = value;

	if (mCurrentMp > mMaxMp)
	{
		mCurrentMp = mMaxMp;
	}

	if (mCurrentMp < 0)
	{
		mCurrentMp = 0;
	}

}


const vector<Skill*>& Unit::getSkills()
{
	return mSkills;
}

void Unit::addSkill(Skill* skill)
{
	// Set this skill's actor to self
	skill->setActor(this);

	// You may want to check if the skill already exists to prevent duplicates. This depends on how much restriction you need.
	mSkills.push_back(skill);
}

void Unit::printSkills()
{
	int x = 1;
	for (int n = 0; n < mSkills.size(); n++)
	{

		cout << "[" << x << "]" << mSkills[n]->getName() << " (MP Cost: " << mSkills[n]->getMpCost() << ")" << endl;
		x++;
	}
}


bool Unit::alive()
{
	return mCurrentHp > 0;
}

void Unit::displayStatus()
{
	// Name
	cout << "Name: " << mName << endl;
	// HP
	cout << "HP: " << mCurrentHp << "/" << mMaxHp << endl;
	// Stats
	cout << "MP: " << mCurrentMp << "/" << mMaxMp << endl;
	cout << "Pow: " << mPow << endl;
	cout << "Vit: " << mVit << endl;
	cout << "Dex: " << mDex << endl;
	cout << "Agi: " << mAgi << endl;
}
