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
        cout << name << " doesn't have enough Stamina (needs 5) for Sword.\n";
        return; // denied: turn will stay with the same player
    }
    set_stamina(get_stamina() - 5);             // pay stamina
    int damage = max(1, get_strength() + 3);    // light consistent damage
    cout << name << " used Sword for " << damage << " damage on "
         << opponent->get_name() << ".\n";
    opponent->takeDamage(damage);
}

void Warrior::mace(Player* opponent) {
    if (!opponent) return;
    if (get_stamina() < 8) {
        cout << name << " doesn't have enough Stamina (needs 8) for Mace.\n";
        return; // denied: turn will stay with the same player
    }
    set_stamina(get_stamina() - 8);             // pay stamina
    int damage = max(1, get_strength() * 2 - 2);// heavy, costly hit
    cout << name << " used Mace for " << damage << " damage on "
         << opponent->get_name() << ".\n";
    opponent->takeDamage(damage);
}