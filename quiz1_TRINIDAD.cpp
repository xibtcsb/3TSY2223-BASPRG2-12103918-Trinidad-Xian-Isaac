#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playRound(int round, int& mmLeft, int& moneyEarned, int wager, string kaijiSide) {
    string opponentCard;
    if (kaijiSide == "Emperor") {
        int randomNum = rand() % 100;
        if (randomNum < 80) {
            opponentCard = "Citizen";
        }
        else {
            opponentCard = "Emperor";
        }
    }
    else if (kaijiSide == "Slave") {
        int randomNum = rand() % 100;
        if (randomNum < 20) {
            opponentCard = "Emperor";
        }
        else {
            opponentCard = "Citizen";
        }
    }

    if (kaijiSide == "Emperor") {
        if (opponentCard == "Citizen") {
            moneyEarned += wager * 100000;
            cout << "You win! You earned " << wager * 100000 << " yen!" << endl;
        }
        else if (opponentCard == "Emperor") {
            cout << "It's a draw! No money earned." << endl;
        }
    }
    else if (kaijiSide == "Slave") {
        if (opponentCard == "Emperor") {
            moneyEarned += wager * 500000;
            cout << "You win! You earned " << wager * 500000 << " yen!" << endl;
        }
        else if (opponentCard == "Citizen") {
            mmLeft -= wager;
            cout << "You lost! The pin will now move by " << wager << "mm." << endl;
            cout << "DRILLING.... DRILLING...." << endl;
            cout << "KAIJI: RAGGGGGHHHHHHHHHH" << endl;
        }
    }

    cout << "Round " << round << ": Kaiji's Side - " << kaijiSide << ", Opponent's Card - " << opponentCard << endl;
    system("pause");
}

bool shouldEndGame(int round, int mmLeft, int moneyEarned) {
    if (mmLeft <= 0) {
        cout << "Bad Ending. You wagered a total of 30mm and lost on the last round." << endl;
        return true;
    }
    else if (round == 12) {
        if (moneyEarned >= 20000000) {
            cout << "Best Ending achieved! Congratulations!" << endl;
        }
        else {
            cout << "Meh Ending. You still have millimeters to spare, but didn't reach 20 million yen." << endl;
        }
        return true;
    }
    return false;
}

int main() {
    int round = 1;
    int mmLeft = 30;
    int moneyEarned = 0;

    srand(static_cast<unsigned>(time(nullptr)));

    while (!shouldEndGame(round, mmLeft, moneyEarned)) {
        system("cls");
        cout << "Cash: " << moneyEarned << endl;
        cout << "Distance Left (mm): " << mmLeft << endl;
        cout << "Round " << round << "/12" << endl;

        string kaijiSide;
        if (round <= 3 || round == 7 || round == 8 || round == 9) {
            cout << "Side: Emperor" << endl;
            kaijiSide = "Emperor";
        }
        else {
            cout << "Side: Slave" << endl;
            kaijiSide = "Slave";
        }
        cout << endl;

        cout << "How many mm would you like to wager, Kaiji? ";
        int wager;
        cin >> wager;
        system("cls");
        cout << endl;

        if (wager >= 1 && wager <= mmLeft) {
            cout << "Pick a card to play..." << endl;
            cout << "===============================" << endl;
            if (kaijiSide == "Emperor") {
                cout << "[1] Emperor" << endl;
                cout << "[2] Citizen" << endl;
                cout << "[3] Citizen" << endl;
                cout << "[4] Citizen" << endl;
                cout << "[5] Citizen" << endl;
            }
            else if (kaijiSide == "Slave") {
                cout << "[1] Slave" << endl;
                cout << "[2] Citizen" << endl;
                cout << "[3] Citizen" << endl;
                cout << "[4] Citizen" << endl;
                cout << "[5] Citizen" << endl;
            }
            cout << endl;

            int cardChoice;
            cin >> cardChoice;
            system("cls");
            cout << endl;

            if (cardChoice >= 1 && cardChoice <= 5) {
                if (kaijiSide == "Emperor") {
                    if (cardChoice == 1) {
                        kaijiSide = "Emperor";
                    }
                    else {
                        kaijiSide = "Citizen";
                    }
                }
                else if (kaijiSide == "Slave") {
                    if (cardChoice == 1) {
                        kaijiSide = "Slave";
                    }
                    else {
                        kaijiSide = "Citizen";
                    }
                }

                playRound(round, mmLeft, moneyEarned, wager, kaijiSide);

                if (mmLeft < 0) {
                    mmLeft = 0;
                }
            }
            else {
                cout << "Invalid card choice. Please enter a value between 1 and 5." << endl << endl;
                system("pause");
            }
        }
        else {
            cout << "Invalid wager. Please enter a value between 1 and " << mmLeft << "." << endl << endl;
            system("pause");
        }

        round++;
    }

    return 0;
}
