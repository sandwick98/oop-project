#include "Wizard.h"
#include <iostream>
using namespace std;


// Spend mana for casting abilities
bool Wizard::spendMana(int cost) {
if (mana_ >= cost) { mana_ -= cost; return true;} // Returns false if insufficient mana
cout << getName() << " lacks mana!\n";
return false;
}

// Fireball: Medium power spell, moderate mana cost
bool Wizard::abilityA(Player* opponent) {
if (!opponent) return false;
if (!spendMana(5)) return false;
opponent->takeDamage(15);
cout << getName() << " casts Fireball (15 dmg). Mana:" << mana_ << "\n";
return true;
}

// Lightning: Strong spell, higher mana cost
bool Wizard::abilityB(Player* opponent) {
if (!opponent) return false;
if (!spendMana(8)) return false;
opponent->takeDamage(20);
cout << getName() << " casts Lightning (20 dmg). Mana:" << mana_ << "\n";
return true;
}

// Display Wizards current mana as part of overall stats
void Wizard::printState(ostream& os) {
Player::printState(os);
os << " MANA:" << getMana() << "/" << getMaxMana();
}

// return class type
string Wizard::type(){
    return "Wizard";
}