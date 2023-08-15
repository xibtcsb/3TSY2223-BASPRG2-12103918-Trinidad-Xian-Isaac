#include "Skill.h"


Skill::Skill(std::string name, int mpCost)
{
	mName = name;
	mMpCost = mpCost;
}

Skill::~Skill()
{
}

int Skill::getMpCost()
{
	return mMpCost;
}

std::string Skill::getName()
{
	return mName;
}

Unit* Skill::getActor()
{
	return mActor;
}

void Skill::setActor(Unit* actor)
{
	mActor = actor;
}

void Skill::activate(Unit* target)
{
	if (mActor == NULL || target == NULL) throw exception("Actor or target cannot be null");
	cout << mActor->getName() << " is casting " << mName << " on " << target->getName() << endl;
}

