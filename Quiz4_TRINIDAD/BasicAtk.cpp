#include "BasicAtk.h"
#include "Stats.h"

BasicAtk::BasicAtk(string name, int damageCoefficient, int mpCost)
    : Skill(name, mpCost)
{
    mDamageCoefficient = damageCoefficient;
}

BasicAtk::~BasicAtk()
{
}

void BasicAtk::activate(Unit* target)
{
    // Append the implementation of the parent class by manually calling its function
    Skill::activate(target);

    // Get base damage
    double baseDamage = ((rand() % 20 + getActor()->getPow()) * mDamageCoefficient);

    // Calculate damage in general
    int damage = static_cast<int>(round(baseDamage - target->getVit()));

    // Clamp damage
    if (damage <= 0)
    {
        damage = 1;
    }

    // Calculate hit chance
    int hitRate = (getActor()->getDex()) / (target->getAgi()) * 100;

    // Clamp hit rate
    if (hitRate < 20)
    {
        hitRate = 20;
    }
    else if (hitRate > 80)
    {
        hitRate = 80;
    }

    int rate = 100 - hitRate;

    // Randomize hit chance
    int hitChance = rand() % rate;
    if (hitChance == 2)
    {
        // Calculate crit chance
        int critChance = rand() % 5;
        if (critChance == 2)
        {
            damage = static_cast<int>(damage * 1.2);
            cout << "Critical Hit! " << endl;
        }

        target->setHp(target->getCurrentHp() - damage);
        cout << getActor()->getName() << " inflicted " << damage << " damage on " << target->getName() << "!" << endl;

        if (target->getCurrentHp() == 0)
        {
            cout << target->getName() << " died!" << endl;
        }
    }
    else
    {
        cout << getActor()->getName() << " missed!" << endl;
    }
}
