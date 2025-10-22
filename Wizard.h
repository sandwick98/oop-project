#ifndef WIZARD_H
#define WIZARD_H
#include "Player.h"
using namespace std;

class Wizard : public Player {
private:
int mana_; // Current mana points
int max_mana_; // Maximum mana capacity

public:
Wizard(string name) : Player(name, 80, 8, 5), mana_(30), max_mana_(30) {}

// Implemented magical abilities
bool abilityA(Player* opponent); // Fireball
bool abilityB(Player* opponent); // Lightning

// Show players mana along with stats
void printState(ostream& os);

// Getters and setters 
int getMana() { return mana_; }
int getMaxMana() { return max_mana_; }
void setMana(int m) { mana_ = clamp(m, 0, max_mana_); }

// class type
string type();

private:
bool spendMana(int cost); // Helper to check & deduct mana cost
};
#endif