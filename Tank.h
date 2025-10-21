#ifndef TANK_H
#define TANK_H
#include "Player.h"
using namespace std;

class Tank : public Player {
private:
int stamina_; // Current stamina
int max_stamina_; // Maximum stamina capacity
bool shield_active_;// True if shield ability is active

public:
Tank(string name) : Player(name, 120, 10, 12), stamina_(25), max_stamina_(25), shield_active_(false) {}

// Tank-specific abilities
bool abilityA(Player* opponent); // Charge
bool abilityB(Player* opponent); // Shield

// Overridden damage handling (applies shield reduction)
void takeDamage(int dmg);

// Show stamina & shield state
void printState(ostream& os);

// Getters for stamina
int getStamina() { return stamina_; }
int getMaxStamina() { return max_stamina_; }
void setStamina(int s) { stamina_ = clamp(s, 0, max_stamina_); }

private:
bool spendStamina(int cost); // Helper to check stamina cost
};
#endif