#include <iostream>
#include <string>
#include "warrior.h"
#include "assasin.h"
#include "mage.h"
#include "enemy.h"

using namespace std;

void enemy::Attack()

{
	int dmg = mPOW - mVit;

	int hit = rand() % 100;


	int hitPer = (mDex / mAgi) * 10;

	if (hitPer < 20)

		hitPer = 20;

	if (hitPer > 80)

		hitPer = 80;

	if (hit > hitPer)
	{

		cout << "Enemy miss" << endl;

	}

	if (hit < hitPer)
	{


		cout << "Enemy attacked " << "Player" << endl << endl;


	}
}