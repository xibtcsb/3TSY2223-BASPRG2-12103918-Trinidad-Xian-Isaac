#include "MultiTarget.h"

MultiTarget::MultiTarget(string name, int damageCoefficient, int mpCost)
	: Skill(name, mpCost)
{
	mDamageCoefficient = damageCoefficient;
}

MultiTarget::~MultiTarget()
{
}

void MultiTarget::activate(Unit* target)
{

	// Append the implementation of the parent class by manually calling its function
	Skill::activate(target);

	//get base damage
	int baseDamage = (getActor()->getPow() + (rand() % 20)) * 0.9;

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
