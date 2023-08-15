
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Unit.h"
#include "SingleTarget.h"
#include "MultiTarget.h"
#include "BasicAtk.h"
#include "Heal.h"

using namespace std;


int main()
{
	srand(time(0));

	//create skills
	Skill* attack = new BasicAtk("Basic Attack", 1, 0);
	Skill* multi = new MultiTarget("Multi Target", 0.9, 4);
	Skill* single = new SingleTarget("Single Target", 2.2, 5);
	Skill* heal = new Heal("Heal", 3);

	//create units
	Unit* etc = new Unit("E.T.C", (rand() % 16) + 30, (rand() % 11) + 10, (rand() % 6) + 8, (rand() % 6) + 3, (rand() % 6) + 15, (rand() % 6) + 15);
	// insert skills
	etc->addSkill(attack);
	etc->addSkill(multi);

	Unit* ill = new Unit("Illidan", (rand() % 16) + 30, (rand() % 11) + 10, (rand() % 6) + 8, (rand() % 6) + 3, (rand() % 6) + 15, (rand() % 6) + 15);
	//insert skills
	ill->addSkill(attack);
	ill->addSkill(single);

	Unit* lili = new Unit("LiLi", (rand() % 16) + 30, (rand() % 11) + 10, (rand() % 6) + 8, (rand() % 6) + 3, (rand() % 6) + 15, (rand() % 6) + 15);
	// insert skills
	lili->addSkill(attack);
	lili->addSkill(heal);

	Unit* jo = new Unit("Johanna", (rand() % 16) + 30, (rand() % 11) + 10, (rand() % 6) + 8, (rand() % 6) + 3, (rand() % 6) + 15, (rand() % 6) + 15);
	// insert skills
	jo->addSkill(attack);
	jo->addSkill(multi);

	Unit* val = new Unit("Valla", (rand() % 16) + 30, (rand() % 11) + 10, (rand() % 6) + 8, (rand() % 6) + 3, (rand() % 6) + 15, (rand() % 6) + 15);
	// insert skills
	val->addSkill(attack);
	val->addSkill(single);

	Unit* kha = new Unit("Kharazim", (rand() % 16) + 30, (rand() % 11) + 10, (rand() % 6) + 8, (rand() % 6) + 3, (rand() % 6) + 15, (rand() % 6) + 15);
	// insert skills
	kha->addSkill(attack);
	kha->addSkill(heal);

	//make team 1
	vector<Unit*> Warcraft;
	Warcraft.push_back(etc);
	Warcraft.push_back(ill);
	Warcraft.push_back(lili);

	//make team 2
	vector<Unit*> Diablo;
	Diablo.push_back(jo);
	Diablo.push_back(val);
	Diablo.push_back(kha);

	//vector for everyone
	vector<Unit*> everyone;
	everyone.push_back(etc);
	everyone.push_back(ill);
	everyone.push_back(lili);
	everyone.push_back(jo);
	everyone.push_back(val);
	everyone.push_back(kha);

	//vector for turnorder
	vector<Unit*> turnOrder;
	//how many people are alive
	int aliveNumber = 6;

	//loop to find the turnorder
	for (int x = 0; x < aliveNumber; x++)
	{
		int b = 0;
		Unit* greater = everyone[b];
		int toErase = 0;

		for (int n = 0; n < everyone.size(); n++)
		{

			for (int y = 1; y < everyone.size(); y++)
			{
				if (everyone[n]->getAgi() > everyone[y]->getAgi())
				{
					greater = everyone[n];
					toErase = n;
				}
				else if (everyone[n]->getAgi() < everyone[y]->getAgi())
				{
					greater = everyone[y];
					toErase = y;
				}
			}
		}
		turnOrder.push_back(greater);
		everyone.erase(everyone.begin() + toErase);
	}

	// loop for game!!!!!

	int curTurn = 0;
	while (Warcraft.size() != 0 && Diablo.size() != 0)
	{
		//Show teams and hp
		cout << "==================================" << endl;
		cout << "Team: Warcraft" << endl;
		cout << "==================================" << endl;
		for (int n = 0; n < Warcraft.size(); n++)
		{
			cout << Warcraft[n]->getName() << " [ HP: " << Warcraft[n]->getCurrentHp() << "]" << endl;
		}
		cout << endl;
		cout << "==================================" << endl;
		cout << "Team: Diablo" << endl;
		cout << "==================================" << endl;
		for (int n = 0; n < Diablo.size(); n++)
		{
			cout << Diablo[n]->getName() << " [ HP: " << Diablo[n]->getCurrentHp() << "]" << endl;
		}
		cout << endl;
		cout << "=========== TURN ORDER ===========" << endl;
		int turnNum = 1;
		for (int n = 0; n < turnOrder.size(); n++)
		{
			cout << "[" << turnNum << "]" << turnOrder[n]->getName() << endl;
			turnNum++;
		}
		cout << "=========== TURN ORDER ===========" << endl;
		cout << endl;

		//show who's turn it is
		cout << "Current Turn: " << turnOrder[curTurn]->getName() << endl;
		cout << endl;
		system("pause");
		system("cls");

		//loop to find player (player team)
		for (int n = 0; n < Warcraft.size(); n++)
		{
			//if player team they can choose & display stats
			if (turnOrder[curTurn]->getName() == Warcraft[n]->getName())
			{
				int randomEnemy = rand() % Diablo.size();
				int choice = 0;
				Warcraft[n]->displayStatus();
				cout << endl;
				cout << "Choose an action..." << endl;
				cout << "==================================" << endl;
				//print skills and mp cost
				Warcraft[n]->printSkills();
				//set actor to whoever it is
				for (int v = 0; v < 2; v++)
				{
					Warcraft[n]->getSkills()[v]->setActor(Warcraft[n]);
				}
				cin >> choice;
				while (choice != 2 && choice != 1)
				{
					cout << "Invalid Input! Please choose 1 or 2." << endl;
					cin >> choice;
				}
				if (Warcraft[n]->getSkills()[choice - 1]->getMpCost() > Warcraft[n]->getCurrentMp())
				{
					cout << "You do not have enough MP for this skill." << endl;
					choice = 1;
				}
				if (choice == 2)
				{
					if (Warcraft[n]->getSkills()[choice - 1]->getName() == "Heal")
					{
						int d = 0;
						Unit* lesser = Warcraft[d];
						for (int a = 0; a < Warcraft.size(); a++)
						{

							for (int b = 1; b < Warcraft.size(); b++)
							{
								if (Warcraft[a]->getCurrentHp() > Warcraft[b]->getCurrentHp())
								{
									lesser = Warcraft[b];
								}
								else if (Warcraft[a]->getCurrentHp() < Warcraft[b]->getCurrentHp())
								{
									lesser = Warcraft[a];

								}
							}
						}
						Warcraft[n]->getSkills()[choice - 1]->activate(lesser);
					}
					else if (Warcraft[n]->getSkills()[choice - 1]->getName() == "Multi Target")
					{
						Warcraft[n]->setCurrentMp(Warcraft[n]->getCurrentMp() - 4);
						for (int y = 0; y < Diablo.size(); y++)
						{
							Warcraft[n]->getSkills()[choice - 1]->activate(Diablo[y]);
						}
					}
					else if (Warcraft[n]->getSkills()[choice - 1]->getName() == "Single Target")
					{
						int d = 0;
						Unit* lesser = Diablo[d];
						for (int a = 0; a < Diablo.size(); a++)
						{

							for (int b = 1; b < Diablo.size(); b++)
							{
								if (Diablo[a]->getCurrentHp() > Diablo[b]->getCurrentHp())
								{
									lesser = Diablo[b];
								}
								else if (Diablo[a]->getCurrentHp() < Diablo[b]->getCurrentHp())
								{
									lesser = Diablo[a];

								}

							}
						}
						Warcraft[n]->getSkills()[choice - 1]->activate(lesser);
					}
				}
				//basic attack
				else if (choice == 1)
				{
					Warcraft[n]->getSkills()[choice - 1]->activate(Diablo[randomEnemy]);

				}
			}
		}

		//loop to find player (enemy team)
		for (int n = 0; n < Diablo.size(); n++)
		{
			if (turnOrder[curTurn]->getName() == Diablo[n]->getName())
			{
				int choice = rand() % 2;
				int randomEnemy = rand() % Warcraft.size();
				//set actor to whoever it is
				for (int v = 0; v < 2; v++)
				{
					Diablo[n]->getSkills()[v]->setActor(Diablo[n]);
				}
				//special attack attack
				//check MP cost first
				if (Diablo[n]->getSkills()[choice]->getMpCost() > Diablo[n]->getCurrentMp())
				{
					choice = 0;
				}
				else
				{
					if (choice == 1)
					{
						if (Diablo[n]->getSkills()[choice]->getName() == "Heal")
						{
							int d = 0;
							Unit* lesser = Diablo[d];
							for (int a = 0; a < Diablo.size(); a++)
							{

								for (int b = 1; b < Diablo.size(); b++)
								{
									if (Diablo[a]->getCurrentHp() > Diablo[b]->getCurrentHp())
									{
										lesser = Diablo[b];
									}
									else if (Diablo[a]->getCurrentHp() < Diablo[b]->getCurrentHp())
									{
										lesser = Diablo[a];

									}
								}
							}
							Diablo[n]->getSkills()[choice]->activate(lesser);
						}
						else if (Diablo[n]->getSkills()[choice]->getName() == "Multi Target")
						{
							//remove mp
							Diablo[n]->setCurrentMp(Diablo[n]->getCurrentMp() - 4);
							for (int y = 0; y < Warcraft.size(); y++)
							{
								Diablo[n]->getSkills()[choice]->activate(Warcraft[y]);
							}
						}
						else if (Diablo[n]->getSkills()[choice]->getName() == "Single Target")
						{
							int d = 0;
							Unit* lesser = Warcraft[d];
							for (int a = 0; a < Warcraft.size(); a++)
							{

								for (int b = 1; b < Warcraft.size(); b++)
								{
									if (Warcraft[a]->getCurrentHp() > Warcraft[b]->getCurrentHp())
									{
										lesser = Warcraft[b];
									}
									else if (Warcraft[a]->getCurrentHp() < Warcraft[b]->getCurrentHp())
									{
										lesser = Warcraft[a];

									}

								}
							}
							Diablo[n]->getSkills()[choice]->activate(lesser);
						}
					}
				}
				//basic attack
				if (choice == 0)
				{
					Diablo[n]->getSkills()[choice]->activate(Warcraft[randomEnemy]);

				}

			}
		}
		Unit* putBack = turnOrder[curTurn];

		//when done with turn remove and put at back of turn order
		turnOrder.erase(turnOrder.begin() + curTurn);
		turnOrder.push_back(putBack);

		//loop through everyone to check if dead
		for (int x = 0; x < turnOrder.size(); x++)
		{
			if (turnOrder[x]->getCurrentHp() == 0)
			{
				//find in warcraft
				for (int z = 0; z < Warcraft.size(); z++)
				{
					if (Warcraft[z]->getName() == turnOrder[x]->getName())
					{
						Warcraft.erase(Warcraft.begin() + z);

					}
				}
				//find in diablo
				for (int w = 0; w < Diablo.size(); w++)
				{
					if (Diablo[w]->getName() == turnOrder[x]->getName())
					{
						Diablo.erase(Diablo.begin() + w);
					}
				}
				//delete from turnOrder
				turnOrder.erase(turnOrder.begin() + x);
			}
		}
		system("pause");
		system("cls");

	}

	//show who won
	if (Warcraft.size() > 0)
	{
		cout << "Team Warcraft wins!" << endl;
	}
	else
	{
		cout << "Team Diablo wins!" << endl;
	}


	//clear all vectors
	Diablo.clear();
	Warcraft.clear();
	everyone.clear();
	turnOrder.clear();

	delete attack;
	delete heal;
	delete single;
	delete multi;

	system("pause");
	return 0;
}