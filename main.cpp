#include <iostream>
#include "Manager.h"
#include "Player.h"
#include "Healer.h"
#include "Mage.h"
#include "Melee.h"
#include "Tank.h"
#include "Warrior.h"
#include "Wizard.h"

int main() {
    Manager game;

    for (int i = 1; i <= 2; i++) {
        cout << "Choose player " << i << " class:\n";
        cout << "1. Warrior\n2. Tank\n3. Wizard\n4. Healer\n> ";

        int choice;
        cin >> choice;

        string name;
        cout << "Enter player " << i << " name: ";
        cin >> name;

        Player* player = nullptr;

        switch (choice) {
            case 1: player = new Warrior(name, 100, 20, 10, 50); break;
            case 2: player = new Tank(name); break;
            case 3: player = new Wizard(name); break;
            case 4: player = new Healer(name); break;
            default:
                cout << "Invalid choice. Defaulting to Warrior.\n";
                player = new Warrior(name, 100, 20, 10, 50);
        }

        game.addPlayer(player);
    }

    game.runBattle();

    // Clean up dynamically allocated memory
    // (Manager stores raw pointers, so we delete manually)
    delete game.current();
    delete game.other();

    return 0;
}