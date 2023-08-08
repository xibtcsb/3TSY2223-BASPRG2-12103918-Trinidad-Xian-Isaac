#include <iostream>
#include <string>
#include "warrior.h"
#include "assasin.h"
#include "mage.h"
#include "enemy.h"

using namespace std;

void warrior::Attack(enemy* target)

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


		if (target->mClass == "Assasin")

			dmg * 1.5;

		if (target->mClass == "Mage")

			dmg * .5;

		target->mHP -= dmg;

	}

	if (target->mHP < 1)

	{
		
		mPOW += 3;
		mVit += 3;

	}
}