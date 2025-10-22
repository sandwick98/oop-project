#include "Healer.h"
#include <iostream>
using namespace std;

// Helper to check mana and spend it
bool Healer::spendMana(int cost) {
    if (mana_ >= cost) {
        mana_ -= cost;
        return true;
    }
    cout << getName() << " lacks mana!\n";
    return false;
}

// Zap: low damage, low mana cost
bool Healer::abilityA(Player* opponent) {
    if (!opponent) return false;
    if (!spendMana(3)) return false; // cheap spell
    int dmg = 8;
    opponent->takeDamage(dmg);
    cout << getName() << " casts Zap for " << dmg << " damage. Mana: " << mana_ << "\n";
    return true;
}

// Heal: restores some of own HP
bool Healer::abilityB(Player* opponent) {
    (void)opponent; // heal doesn't need target
    if (!spendMana(5)) return false;
    int heal_amount = 15;
    setHP(getHP() + heal_amount);
    cout << getName() << " casts Heal and restores " << heal_amount << " HP. Current HP: " << getHP() << "\n";
    return true;
}

// Display Healer stats
void Healer::printState(ostream& os) {
    Player::printState(os);
    os << " MANA:" << getMana() << "/" << getMaxMana();
}

// Class type
string Healer::type() {
    return "Healer";
}
