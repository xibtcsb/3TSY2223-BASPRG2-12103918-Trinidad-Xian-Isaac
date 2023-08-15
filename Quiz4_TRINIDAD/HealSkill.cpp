#include "HealSkill.h"

HealSkill::HealSkill(string name, int healValue)
    : Skill(name, 0), mHealValue(healValue) {
}

HealSkill::~HealSkill() {
}

void HealSkill::activate(Unit* target) {
    // Append the implementation of the parent class by manually calling its function
    Skill::activate(target);

    target->heal(mHealValue);
    cout << target->getName() << " is healed for " << mHealValue << " HP" << endl;
}
