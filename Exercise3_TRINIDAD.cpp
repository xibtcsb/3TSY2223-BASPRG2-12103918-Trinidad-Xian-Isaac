#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

void itemGenerator(vector<string>& Loot, vector<int>& Prices)
{
    int rng;
    struct {
        string Items[5] = { "Mithril Ore", "Sharp Talon", "Thick Leather", "Jellopy", "Cursed Stone" };
        int Gold[5] = { 100, 50, 25, 5, 0 };
    } a;

    if (Loot.size() < 3) // makes sure the player has at least 1 item before a cursed stone appears
        rng = rand() % 4;
    else
        rng = rand() % 5;

    Loot.push_back(a.Items[rng]);
    Prices.push_back(a.Gold[rng]);

    cout << "    ITEM FOUND!    " << endl;
    cout << Loot.back() << endl; // prints last item in vector
}

void itemDisplay(vector<string>& Loot, vector<int>& Prices) // prints Items and prices
{
    cout << "Here are your items" << endl;
    for (int i = 0; i < Loot.size(); i++)
    {
        cout << "[" << i << "] " << Loot[i] << "- " << Prices[i] << endl;
    }
    system("PAUSE");
    system("CLS");
}

void itemSell(vector<string>& Loot, vector<int>& Prices, int* currentGold)
{
    int potentialReward = 0;
    itemDisplay(Loot, Prices);

    for (int i = 0; i < Loot.size(); i++) // Price multiplier
    {
        if (Loot[i] == "Mithril Ore")
            potentialReward += Prices[i] * i;
        if (Loot[i] == "Sharp Talon")
            potentialReward += Prices[i] * i;
        if (Loot[i] == "Thick Leather")
            potentialReward += Prices[i] * i;
        if (Loot[i] == "Jellopy")
            potentialReward += Prices[i] * i;
        if (Loot[i] == "Cursed Stone")
        {
            potentialReward = 0;
        }
    }

    *currentGold += potentialReward; // combines item total with Gold
}

void enterDungeon(vector<string>& Loot, vector<int>& Prices, int* currentGold)
{
    Loot.reserve(3);    // Reserve space for at least 3 elements
    Prices.reserve(3);  // Reserve space for at least 3 elements

    char a = 'y';
    *currentGold -= 25;

    while ((a == 'y' || a == 'Y') && Loot.back() != "Cursed Stone")
    {
        itemGenerator(Loot, Prices);

        if (Loot.back() != "Cursed Stone")
        {
            cout << "Continue looting? [y/n]" << endl;
            cin >> a;
        }
        else if (Loot.back() == "Cursed Stone")
            system("PAUSE");
        system("CLS");
    }
}

int main()
{
    srand(time(0));
    int Gold = 25;
    char a = 'y';
    vector<string> Loot;
    vector<int> Prices;

    while (Gold >= 25 && Gold < 500)
    {
        Loot.clear();
        Prices.clear();

        Loot.push_back(" "); // Enters blank value to avoid condition errors from an empty vector
        Prices.push_back(0);

        cout << "You have " << Gold << " Gold." << endl;
        cout << "Enter the Dungeon for 25 Gold? [y/n]" << endl;
        cin >> a;
        system("CLS");

        if (a == 'y' || a == 'Y')
            enterDungeon(Loot, Prices, &Gold);

        itemSell(Loot, Prices, &Gold);

        if (Loot.back() == "Cursed Stone")
            cout << "The curse is death!" << endl;

        cout << "Total Gold Collected: " << Gold << endl; // Display total gold collected
    }

    if (Gold >= 500)
        cout << "Congratulations, you won with " << Gold << " Gold!" << endl;
    else
        cout << endl << "You Lost! Gold(" << Gold << ")" << endl;

    return 0;
}
