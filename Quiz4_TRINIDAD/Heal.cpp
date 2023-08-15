#include "Heal.h"

Heal::Heal(string name, int mpCost)
	: Skill(name, mpCost)
{
}

Heal::~Heal()
{
}

void Heal::activate(Unit* target)
{
	//remove mp
	getActor()->setCurrentMp(getActor()->getCurrentMp() - 3);

	// Append the implementation of the parent class by manually calling its function
	Skill::activate(target);

	//heal them
	int healValue = (target->getCurrentHp() + round(target->getMaxHp() * 0.3));
	target->setHp(healValue);
	cout << getActor()->getName() << " healed " << target->getName() << " for " << round(target->getMaxHp() * 0.3) << " HP!" << endl;
}
