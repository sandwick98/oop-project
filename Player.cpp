#include "Player.h"
using namespace std;

// Standard attack
void Player::attack(Player* opponent) {
if (!opponent) return;
int dmg = max(1, getStrength() - opponent->getDefense());
opponent->takeDamage(dmg);
cout << getName() << " attacks for " << dmg << " damage.\n";
}

// Reduce HP by given amount and ensure that HP doesn't fall below zero
void Player::takeDamage(int dmg) {
setHP(getHP() - max(0, dmg));
}

// Prints current stats
void Player::printState(ostream& os) {
os << "Name:" << getName()
<< " HP:" << getHP() << "/" << getMaxHP()
<< " STR:" << getStrength()
<< " DEF:" << getDefense();
}