#include <iostream>
#include "battleSystem.h"
using namespace std;

// Function that starts the battle and alternates turns between players
void startBattle(Player* p1, Player* p2) {
    int turn = 0;  // 0 = Player 1's turn, 1 = Player 2's turn
    cout << "\n=== Battle Start! ===\n";

    while (!p1->isKO() && !p2->isKO()) {
        Player* me = (turn % 2 == 0) ? p1 : p2; // Determines current player
        Player* foe = (turn % 2 == 0) ? p2 : p1;

        cout << "\nIt's " << me->getName() << "'s turn.\n";
        cout << "1. Attack\n2. Ability A\n3. Ability B\n4. Defend\n> ";

        int choice;
        cin >> choice;

        // Prevent crashes if input fails
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Try again.\n";
            continue;
        }

        bool acted = false;

        if (choice == 1) {
            me->attack(foe);
            acted = true;
        }
        else if (choice == 2) {
            acted = me->abilityA(foe);
        }
        else if (choice == 3) {
            acted = me->abilityB(foe);
        }
        else if (choice == 4) {
            me->defend();
            acted = true;
        }
        else {
            cout << "Invalid option. Try again.\n";
        }

        // Show updated stats
        cout << "\n--- Current Status ---\n";
        p1->printState(cout); cout << "\n";
        p2->printState(cout); cout << "\n";

        // Check if someone has been defeated
        if (foe->isKO()) {
            cout << foe->getName() << " has been defeated!\n";
            cout << me->getName() << " wins the battle!\n";
            break;
        }

        // Alternate turns only if a valid action was taken
        if (acted) turn++;
    }
}