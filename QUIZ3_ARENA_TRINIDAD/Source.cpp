#include <iostream>
#include <string>
#include "warrior.h"
#include "assasin.h"
#include "mage.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main()
{
	srand(time(NULL));

	cout << "State your name!" << endl;
	cout << "______________________________________" << endl << endl;

	warrior* player = new warrior();

	cin >> player->mName;

	system("PAUSE");
	system("CLS");

	int role = 0;

	delete player;

	cout << "Choose your class: " << endl << endl;
	cout << "[1] Warrior" << endl;
	cout << "[2] Assasin" << endl;
	cout << "[3] Mage" << endl;

	while (role < 1 || role > 3)
		cin >> role;

	if (role == 1)
		warrior* player = new warrior();


	if (role == 2)
		assasin* player = new assasin();


	if (role == 3)
		mage* player = new mage();


	system("PAUSE");
	system("CLS");

	cout << " YOUR CHOSEN CLASS IS: " << player->mClass << endl;

	system("PAUSE");
	system("CLS");

	string aName[3] = { "Jograt", "Bogart", "Maxim" };
	string aClass[3] = {"Warrior", "Assasin", "Mage"};


		for (int i = 0; i < 13; i++)
		{
			enemy* Enemy = new enemy();

			Enemy->mName = aName[rand() % 2];
			Enemy->mClass = aClass[rand() % 2];
			Enemy->mHP = rand() % 20 + 5;
			Enemy->mPOW = rand() % 9;
			Enemy->mVit = rand() % 1;
			Enemy->mDex = rand() % 8;
			Enemy->mAgi = rand() % 5;

			Enemy->mHP += i;
			Enemy->mPOW += i;
			Enemy->mVit += i;
			Enemy->mDex += i;
			Enemy->mAgi += i;

			cout << "STAGE " << i+1 << endl << endl;
			cout << "BATTLE COMMENCE!" << endl;

			cout << "Name: " << Enemy->mName << endl;
			cout << "Class: " << Enemy->mClass << endl;
			cout << "HP: " << Enemy->mHP << endl;
			cout << "Power: " << Enemy->mPOW << endl;
			cout << "Vitality: " << Enemy->mVit << endl;
			cout << "Dexterity: " << Enemy->mDex << endl;
			cout << "Agility: " << Enemy->mAgi << endl;

			cout << endl << endl;

			cout << "Name: " << player->mName << endl;
			cout << "HP: " << player->mHP << endl;
			cout << "Power: " << player->mPOW << endl;
			cout << "Vitality: " << player->mVit << endl;
			cout << "Dexterity: " << player->mDex << endl;
			cout << "Agility: " << player->mAgi << endl;
			while (player->mHP > 0 && Enemy->mHP > 0)

			{

				player->Attack(Enemy);

				system("PAUSE");
				system("CLS");

				Enemy->Attack();


				if (player->mHP < 1)

					cout << "YOU HAVE BEEN SLAIN!" << endl << endl;

				if (Enemy->mHP < 1)
					cout << "VICTORY!" << endl << endl;

			}

			delete Enemy;

			system("PAUSE");
			system("CLS");

			

			


		}
			
		
}