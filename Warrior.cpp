#include "Warrior.h"
#include <algorithm>
#include <iostream>
using namespace std;

#include "Warrior.h"
#include <algorithm>
#include <iostream>
using namespace std;

Warrior::Warrior(const string& name, int hp, int strength, int defense, int stamina)
    : Melee(name, hp, strength, defense, stamina) {}

void Warrior::sword(Player* opponent) {
    if (!opponent) return;
    if (get_stamina() < 5) {
        cout << getName() << " doesn't have enough Stamina (needs 5) for Sword.\n";
        return; // denied: turn will stay with the same player
    }
    set_stamina(get_stamina() - 5);             // pay stamina
    int damage = max(1, getStrength() + 3);    // light consistent damage
    cout << getName() << " used Sword for " << damage << " damage on "
         << opponent->getName() << ".\n";
    opponent->takeDamage(damage);
}

void Warrior::mace(Player* opponent) {
    if (!opponent) return;
    if (get_stamina() < 8) {
        cout << getName() << " doesn't have enough Stamina (needs 8) for Mace.\n";
        return; // denied: turn will stay with the same player
    }
    set_stamina(get_stamina() - 8);             // pay stamina
    int damage = max(1, getStrength() * 2 - 2);// heavy, costly hit
    cout << getName() << " used Mace for " << damage << " damage on "
         << opponent->getName() << ".\n";
    opponent->takeDamage(damage);
}

bool Warrior::abilityA(Player* opponent) {
    if (get_stamina() < 5) return false; // not enough stamina
    sword(opponent);
    return true;
}

bool Warrior::abilityB(Player* opponent) {
    if (get_stamina() < 5) return false; // not enough stamina
    mace(opponent);
    return true;
}

string Warrior::type(){
    return "Warrior";
}