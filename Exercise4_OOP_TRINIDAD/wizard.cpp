#include "wizard.h"
// Include any forward-declared types in the header file here
#include "spell.h"

// 'wizard::' means the function is owned by the 'wizard' class
// This can be auto-generated from the header file
void wizard::Attack(wizard* target)
{
	int dmg = rand() % this->mMaxDamage + this->mMinDamage;
	cout << this->mName << " attacked " << target->mName;
	cout << "(" << dmg << "damage)" << endl;
	target->mHP -= dmg;
	this->mMP += rand() % 20 + 10;
}