#include "tank.h"
#include <iostream>
using namespace std;


bool Tank::spendStamina(int cost) {
if (stamina_ >= cost) { stamina_ -= cost; return true; }
cout << getName() << " lacks stamina!\n";
return false;
}

bool Tank::abilityA(Player* opponent) {
if (!spendStamina(6)) return false;
opponent->takeDamage(12);
cout << getName() << " charges for 12 damage! (Stamina: " << stamina_ << ")\n";
return true;
}

bool Tank::abilityB(Player* opponent) {
(void)opponent;
if (!spendStamina(4)) return false;
shield_active_ = true;
cout << getName() << " raises a shield for next hit.\n";
return true;
}

void Tank::takeDamage(int dmg) {
int eff_def = getDefense() + (shield_active_ ? 5 : 0);
int final_dmg = max(1, dmg - eff_def);
setHP(getHP() - final_dmg);
if (shield_active_) {
shield_active_ = false;
cout << getName() << "'s shield absorbed damage!\n";
}
cout << getName() << " takes " << final_dmg << " damage (HP: " << getHP() << ")\n";
}