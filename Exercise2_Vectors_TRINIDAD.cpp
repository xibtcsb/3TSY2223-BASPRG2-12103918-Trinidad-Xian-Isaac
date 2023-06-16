#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void getRandomItems(vector<string>& items)
{
	for (int i = 0; i < 10; i++)
	{

		int randomNum = rand() % 4;
		if (randomNum == 0)
		{

			items.push_back("RedPotion");

		}
		if (randomNum == 1)
		{

			items.push_back("Elixir");

		}
		if (randomNum == 2)
		{

			items.push_back("EmptyBottle");

		}
		if (randomNum == 3)
		{

			items.push_back("BluePotion");

		}

	}

}

void printVector(vector<string>& items)
{
	for (int i = 0; i < items.size(); i++)
	{
		cout << items[i] << endl;

	}

}

void countItem(vector<string>& items)
{
	int RedPotion = 0;
	int Elixir = 0;
	int EmptyBottle = 0;
	int BluePotion = 0;

	for (int i = 0; i < items.size(); i++)
	{

		if (items[i] == "RedPotion")
		{
			RedPotion++;

		}
		if (items[i] == "Elixir")
		{

			Elixir++;

		}
		if (items[i] == "EmptyBottle")
		{

			EmptyBottle++;


		}
		if (items[i] == "BluePotion")
		{

			BluePotion++;


		}


	}
	cout << endl << endl;
	cout << "Amount of Red Potion: " << RedPotion << endl << endl;
	cout << "Amount of Elixir: " << Elixir << endl << endl;
	cout << "Amount of Empty Bottle: " << EmptyBottle << endl << endl;
	cout << "Amount of Blue Potion: " << BluePotion << endl << endl;
}



void removeItem(vector<string>& items)
{

	cout << "Removing element at index 2..." << endl << endl;

	items.erase(items.begin() + 2);


}

int main()

{
	srand(time(NULL));

	vector<string> items;

	getRandomItems(items);

	printVector(items);

	countItem(items);

	removeItem(items);

	printVector(items);

	return 0;

}