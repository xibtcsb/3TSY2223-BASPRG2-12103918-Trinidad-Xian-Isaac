#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string kaijiSide;

void playRound(int round, int& mmLeft, int& moneyEarned, int wager) {
    string kaijiSide;
    if (round <= 3 || round == 7 || round == 8 || round == 9) {
        kaijiSide = "Emperor";
    }
    else {
        kaijiSide = "Slave";
    }

    string opponentCard;
    if (round <= 3 || (round >= 10 && round <= 12)) {
        opponentCard = "Citizen";
    }
    else if (round >= 4 && round <= 6) {
        opponentCard = "Emperor";
    }
    else if (round >= 7 && round <= 9) {
        opponentCard = "Citizen";
    }
    else {
        // Generate random opponent card
        int randomNum = rand() % 100 + 1; // Generate a random number between 1 and 100

        if (kaijiSide == "Emperor") {
            if (randomNum <= 80) {
                opponentCard = "Citizen";
            }
            else {
                opponentCard = "Slave";
            }
        }
        else if (kaijiSide == "Slave") {
            if (randomNum <= 20) {
                opponentCard = "Emperor";
            }
            else {
                opponentCard = "Citizen";
            }
        }
    }

    if (kaijiSide == "Emperor") {
        if (opponentCard == "Citizen") {
            moneyEarned += wager * 100000;
            cout << "You win! You earned " << wager * 100000 << " yen!" << endl;
        }
        else if (opponentCard == "Slave") {
            mmLeft -= wager; // Deduct the amount wagered on loss
            cout << "You lost! The pin will now move by " << wager << "mm." << endl;
            cout << "DRILLING.... DRILLING...." << endl;
            cout << "KAIJI: RAGGGGGHHHHHHHHHH" << endl;
        }
        else if (opponentCard == "Emperor") {
            cout << "It's a draw! No money earned." << endl;
        }
    }
    else if (kaijiSide == "Slave") {
        if (opponentCard == "Citizen") {
            cout << "It's a draw! No money earned." << endl;
        }
        else if (opponentCard == "Emperor") {
            mmLeft -= wager; // Deduct the amount wagered on loss
            cout << "You lost! The pin will now move by " << wager << "mm." << endl;
            cout << "DRILLING.... DRILLING...." << endl;
            cout << "KAIJI: RAGGGGGHHHHHHHHHH" << endl;
        }
    }

    // Output the result of the round
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

    // Set the seed for random number generation
    srand(static_cast<unsigned>(time(nullptr)));

    while (!shouldEndGame(round, mmLeft, moneyEarned)) {
        system("cls");
        cout << "Cash: " << moneyEarned << endl;
        cout << "Distance Left (mm): " << mmLeft << endl;
        cout << "Round " << round << "/12" << endl;
        cout << "Side: ";
        if (round <= 3 || round == 7 || round == 8 || round == 9) {
            cout << "Emperor";
            kaijiSide = "Emperor";
        }
        else {
            cout << "Slave";
            kaijiSide = "Slave";
        }
        cout << endl << endl;

        cout << "How many mm would you like to wager, Kaiji? ";
        int wager;
        cin >> wager;
        system("cls");
        cout << endl;

        if (wager >= 1 && wager <= mmLeft) {
            cout << "Pick a card to play..." << endl;
            if (kaijiSide == "Emperor") {
                cout << "[1] Emperor" << endl;
            }
            else if (kaijiSide == "Slave") {
                cout << "[1] Slave" << endl;
            }
            cout << "[2] Citizen" << endl;
            cout << "[3] Citizen" << endl;
            cout << "[4] Citizen" << endl;
            cout << "[5] Citizen" << endl;
            cout << endl;

            int cardChoice;
            cin >> cardChoice;
            system("cls");
            cout << endl;

            if (cardChoice >= 1 && cardChoice <= 5) {
                if (cardChoice == 1) {
                    kaijiSide = "Emperor";
                }
                else {
                    kaijiSide = "Slave";
                }

                playRound(round, mmLeft, moneyEarned, wager);

                // Deduct the wagered amount from mmLeft on a loss
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