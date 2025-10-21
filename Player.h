#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;


class Player {
private:
string name_;
int hp_{};
int max_hp_{};
int strength_{};
int defense_{};

public:
Player(const string& name, int hp, int strength, int defense) : name_(name), hp_(hp), max_hp_(hp), strength_(strength), defense_(defense) {}
virtual ~Player() = default;

// Core combat
virtual void attack(Player* opponent); // Basic attack
virtual void takeDamage(int dmg); // Apply damage

// Abstract abilities
virtual bool abilityA(Player* opponent) = 0; // Pure virtual
virtual bool abilityB(Player* opponent) = 0; // Pure virtual

// Optional defend hook
virtual void defend() {}
virtual void printState(ostream& os); // Readable HUD line
virtual string type() = 0; // e.g., "Wizard", "Tank"
virtual void save(ostream& out); // Writes common fields; subclass writes its own tail

// Utility
bool isKO()  {return hp_ <= 0;}

// Getters and Setters
string getName()  {return name_;}
void setName(string& n) {name_ = n;}

int getHP() {return hp_;}
void setHP(int val) { hp_ = clamp(val, 0, max_hp_); }

int getMaxHP() {return max_hp_;}

int getStrength()  {return strength_;}
void setStrength(int s) {strength_ = max(0, s);}

int getDefense() {return defense_;}
void setDefense(int d) { defense_ = max(0, d); }
};

#endif

