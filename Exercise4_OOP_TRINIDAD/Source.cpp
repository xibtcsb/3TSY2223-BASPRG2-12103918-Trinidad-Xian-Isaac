#include <iostream>
#include <string>
#include "spell.h"
#include "wizard.h"

using namespace std;

int main()
{
	cout << "Name your wizard" << endl;
	cout << "________________________________" << endl;



	wizard* player1 = new wizard();
	cin >> player1->mName;

	wizard* harry = new wizard();
	harry->mName = "Harry";

	spell* stupify = new spell();
	stupify->sName = "Stupify";

	spell* episkey = new spell();
	episkey->sName = "Episkey";

	//archer->attack(killerBunny);

	while (player1->mHP > 0 && harry->mHP > 0)
	{
		if (player1->mMP < 50)
			player1->Attack(harry);

		else if (player1->mMP > 49)
			stupify->activate(player1, harry);

		if (harry->mMP < 50)
			harry->Attack(player1);

		else if (harry->mMP > 49)
			stupify->activate(harry, player1);

		cout << endl << player1->mName << "HP: " << player1->mHP << endl;
		cout << player1->mName << "MP: " << player1->mMP << endl;
		cout << endl << harry->mName << "HP: " << harry->mHP << endl;
		cout << harry->mName << "MP: " << harry->mMP << endl;

		system("PAUSE");
		system("CLS");
	}

	if (player1->mHP < 0)
		cout << "You lost!";
	if (harry->mHP < 0)
		cout << "You won!";
}