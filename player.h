#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class Player {
private:
string name_;
int hp_{};
int max_hp_{};
int strength_{};
int defense_{};

public:
Player(const string& name, int hp, int strength, int defense)
: name_(name), hp_(hp), max_hp_(hp), strength_(strength), defense_(defense) {}

virtual ~Player() = default;

virtual void attack(Player* opponent);
virtual void takeDamage(int dmg);
virtual bool abilityA(Player* opponent) {return false;}
virtual bool abilityB(Player* opponent) {return false;}
virtual void defend() {}

bool isKO() const {return hp_ <= 0;}

string getName() const {return name_;}
void setName(const string& n) {name_ = n;}

int getHP() const { return hp_; }
void setHP(int val) {hp_ = clamp(val, 0, max_hp_);}

int getMaxHP() const {return max_hp_;}

int getStrength() const {return strength_;}
void setStrength(int s) {strength_ = max(0, s);}

int getDefense() const {return defense_;}
void setDefense(int d) {defense_ = max(0, d);}
};

#endif