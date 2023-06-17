#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playRound(int round, int& mmLeft, int& moneyEarned) {
    // Determine Kaiji's side for the current round
    string kaijiSide;
    if (round % 4 == 0 || round % 4 == 1 || round % 4 == 2) {
        kaijiSide = "Emperor";
    }
    else {
        kaijiSide = "Slave";
    }

    // Generate opponent's card randomly
    string opponentCard;
    int randomNum = rand() % 3;
    if (randomNum == 0) {
        opponentCard = "Civilian";
    }
    else if (randomNum == 1) {
        opponentCard = "Slave";
    }
    else {
        opponentCard = "Emperor";
    }

    // Check the outcome of the round
    if (kaijiSide == "Emperor") {
        if (opponentCard == "Civilian") {
            mmLeft -= 1; // Deduct 1mm from contraption
            moneyEarned += 100000; // Earn 100,000 yen
        }
        else if (opponentCard == "Slave") {
            mmLeft += 5; // Add 5mm to contraption
        }
    }
    else if (kaijiSide == "Slave") {
        if (opponentCard == "Civilian") {
            mmLeft -= 3; // Deduct 3mm from contraption
        }
        else if (opponentCard == "Emperor") {
            mmLeft -= 30; // Deduct 30mm from contraption
        }
    }

    // Output the result of the round
    cout << "Round " << round << ": Kaiji's Side - " << kaijiSide << ", Opponent's Card - " << opponentCard << endl;
}

bool shouldEndGame(int round, int mmLeft, int moneyEarned) {
    if (round == 12) {
        if (mmLeft > 0 && moneyEarned >= 20000000) {
            cout << "Best Ending achieved! Congratulations!" << endl;
        }
        else if (mmLeft > 0 && moneyEarned < 20000000) {
            cout << "Meh Ending. You still have millimeters to spare, but didn't reach 20 million yen." << endl;
        }
        else if (mmLeft <= 0 && moneyEarned < 20000000) {
            cout << "Bad Ending. You wagered a total of 30mm and lost on the last round." << endl;
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

    // Play each round until the game ends
    while (!shouldEndGame(round, mmLeft, moneyEarned)) {
        cout << "Round " << round << endl;
        cout << "Enter the number of millimeters you want to wager (remaining: " << mmLeft << "mm): ";
        int wager;
        cin >> wager;

        playRound(round, mmLeft, moneyEarned);

        if (mmLeft >= wager) {
            mmLeft -= wager;
            if (wager > 0) {
                if (moneyEarned >= 20000000) {
                    cout << "Congratulations! You have already reached 20 million yen!" << endl;
                }
                else {
                    if (round % 4 == 0 || round % 4 == 1 || round % 4 == 2) {
                        moneyEarned += wager * 100000;
                    }
                    else {
                        moneyEarned += wager * 500000;
                    }
                }
            }
        }
        else {
            cout << "Invalid wager. You do not have enough millimeters left." << endl;
        }

        round++;
    }

    return 0;
}
