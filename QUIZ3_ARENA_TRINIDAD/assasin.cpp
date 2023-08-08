#include <iostream>
#include <string>
#include "warrior.h"
#include "assasin.h"
#include "mage.h"
#include "enemy.h"

using namespace std;

void assasin::Attack(enemy* target)

{
	int dmg = mPOW - target->mVit;

	int hit = rand() % 100;

	int hitPer = (mDex / mAgi) * 10;

	if (hitPer < 20)

		hitPer = 20;

	if (hitPer > 80)

		hitPer = 80;

	if (hit > hitPer)
	{

		cout << "Player miss" << endl;

	}

	if (hit < hitPer)
	{


		cout << "you attacked " << target->mName << endl << endl;

		cout << "Enemy HP left: " << target->mHP << " HP" << endl << endl;

		cout << "Player HP left: " << this->mHP << " HP" << endl << endl;

		if (target->mClass == "Mage")

			dmg * 1.5;

		if (target->mClass == "Warrior")

			dmg * .5;

		target->mHP -= dmg;
	}

	if (target->mHP < 1)

	{

		mAgi += 3;
		mDex += 3;

	}

}