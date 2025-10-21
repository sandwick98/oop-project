#include "Tank.h"
#include <iostream>
using namespace std;

bool Tank::spendStamina(int cost) {
if (stamina_ >= cost) { stamina_ -= cost; return true; }
cout << getName() << " lacks stamina!\n";
return false;
}

// Charge: Heavy strike costing stamina
bool Tank::abilityA(Player* opponent) {
if (!opponent) return false;
if (!spendStamina(6)) return false;
opponent->takeDamage(12);
cout << getName() << " uses Charge (12 dmg). Stamina:" << stamina_ << "\n";
return true;
}

// Shield:  Activate temporary damage reduction buff
bool Tank::abilityB(Player* opponent) {
(void)opponent;
if (!spendStamina(4)) return false;
shield_active_ = true;
cout << getName() << " raises Shield for next attack.\n";
return true;
}

// Modified damage formula when shield is active
void Tank::takeDamage(int dmg) {
int bonus = shield_active_ ? 5 : 0;
int eff = max(1, dmg - (getDefense() + bonus));
setHP(getHP() - eff);

if (shield_active_) {
shield_active_ = false;
cout << getName() << "'s Shield absorbed some damage!\n";
}
cout << getName() << " takes " << eff << " dmg. HP:" << getHP() << "\n";
}

// Show Tank’s stamina and shield status
void Tank::printState(ostream& os) {
Player::printState(os);
os << " STA:" << getStamina() << "/" << getMaxStamina()
<< (shield_active_ ? " [Shield]" : "");
}