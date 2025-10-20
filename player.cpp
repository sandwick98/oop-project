#include "player.h"
using namespace std;


void Player::attack(Player* opponent) {
if (!opponent) return;
int dmg = max(1, strength_ - opponent->getDefense());
opponent->takeDamage(dmg);
cout << name_ << " attacks for " << dmg << " damage.\n";
}


void Player::takeDamage(int dmg) {
hp_ = max(0, hp_ - dmg);
}