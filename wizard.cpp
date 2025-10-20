#include "wizard.h"
#include <iostream>
using namespace std;

bool Wizard::spendMana(int cost) {
if (mana_ >= cost) { mana_ -= cost; return true; }
cout << getName() << " lacks mana!\n";
return false;
}

bool Wizard::abilityA(Player* opponent) {
if (!spendMana(5)) return false;
opponent->takeDamage(15);
cout << getName() << " casts Fireball for 15 damage. (Mana: " << mana_ << ")\n";
return true;
}

bool Wizard::abilityB(Player* opponent) {
if (!spendMana(8)) return false;
opponent->takeDamage(20);
cout << getName() << " casts Lightning for 20 damage. (Mana: " << mana_ << ")\n";
return true;
}