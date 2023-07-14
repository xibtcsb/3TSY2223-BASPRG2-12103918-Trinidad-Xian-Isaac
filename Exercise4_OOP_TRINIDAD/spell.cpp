#include "wizard.h"
// Include any forward-declared types in the header file here
#include "spell.h"

// 'wizard::' means the function is owned by the 'wizard' class
// This can be auto-generated from the header file
void spell::activate(wizard* caster, wizard* target)
{
	int dmg = rand() % this->sMaxDamage + this->sMinDamage;

	cout << caster->mName << " activated " << this->sName;
	cout << "(" << dmg << "damage)" << endl;
	target->mHP -= dmg;
	caster->mMP -= this->sCost;
}