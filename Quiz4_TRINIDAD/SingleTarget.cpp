#include "SingleTarget.h"

SingleTarget::SingleTarget(string name, int damageCoefficient, int mpCost)
	: Skill(name, mpCost)
{
	mDamageCoefficient = damageCoefficient;
}

SingleTarget::~SingleTarget()
{
}

void SingleTarget::activate(Unit* target)
{
	//remove mp
	getActor()->setCurrentMp(getActor()->getCurrentMp() - 5);

	// Append the implementation of the parent class by manually calling its function
	Skill::activate(target);

	//get base damage
	int baseDamage = ((rand() % 20 + getActor()->getPow()) * mDamageCoefficient);

	//damage in general
	int damage = round(baseDamage - target->getVit());

	//clamp damage
	if (damage <= 0)
	{
		damage = 1;
	}

	target->setHp(target->getCurrentHp() - damage);
	cout << getActor()->getName() << " inflicted " << damage << " damage on " << target->getName() << "!" << endl;
	if (target->getCurrentHp() == 0)
	{
		cout << target->getName() << " died!" << endl;
	}

}
