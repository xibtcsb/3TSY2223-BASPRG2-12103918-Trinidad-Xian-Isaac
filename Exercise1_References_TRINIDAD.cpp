#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void minusBet(int& money, int& wager) 
{
	money -= wager;
}

void diceRoll(int& a, int& b, int& sum) 
{
	a = rand() % 6 + 1;
	b = rand() % 6 + 1;
	sum = a + b;
}

void payOut(int& money, int& wager, int& result) 
{
	if (result == 1)
	{
		money += wager * 2;
		cout << wager << endl << endl;
	}

	if (result == 2)
	{
		money += wager;
		cout << "0" << endl << endl;
	}

	if (result == 3)
	{
		money += wager * 4;
		cout << wager * 3 << endl << endl;
	}

	if (result == 4)
	{
		money -= wager * 2;
		cout << "-" << wager * 2 << endl << endl;
	}
}

void playRound(int& playerSum, int& dealerSum, int& result) 
{
	if (playerSum < dealerSum) 
	{
		result = 0;
		cout << "You lost" << endl;
		
	}

	if (playerSum > dealerSum) 
	{
		result = 1;
		cout << "You won" << endl;
		
	}

	if (playerSum == dealerSum) 
	{
		result = 2;
		cout << "Draw" << endl;
		
	}

	if ((playerSum == 2) && playerSum != dealerSum) 
	{
		result = 3;
		cout << "You won (Snake Eyes)" << endl;
		
	}

	if ((dealerSum == 2) && playerSum != dealerSum) 
	{
		result = 4;
		cout << "You lost (Snake Eyes)" << endl;
		
	}
}

int main()
{
	srand(time(0)); 
	
	int cash = 1000;
	int round = 1;
	int bet, pSum, dSum, result;


	while (cash > 0) 
	{
		cout << "ROUND: " << round << endl << endl; 
		cout << "Your money: " << cash << endl;

		do
		{
			cout << "How much are you betting?: ";
			cin >> bet;
		} while ((bet < 1) || (bet > cash));

		minusBet(cash, bet);

		system("CLS");

		int pDie1, pDie2, dDie1, dDie2;

		cout << "Dealer rolls: " << endl;
		diceRoll(dDie1, dDie2, dSum);
		cout << "Dice 1: " << dDie1 << endl;
		cout << "Dice 2: " << dDie2 << endl;
		

		system("PAUSE");
		system("CLS");

		cout << "Player rolls: " << endl;
		diceRoll(pDie1, pDie2, pSum);
		cout << "Dice 1: " << pDie1 << endl;
		cout << "Dice 2: " << pDie2 << endl;
		

		system("PAUSE");
		system("CLS");

		playRound(pSum, dSum, result);
		payOut(cash, bet, result);

		cout << "cash: " << cash << endl << endl;
		round++;

		system("PAUSE");
		system("CLS");
	}

	cout << "GAME OVER";

}