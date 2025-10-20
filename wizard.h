#ifndef WIZARD_H
#define WIZARD_H
#include "player.h"
using namespace std;


class Wizard : public Player {
private:
int mana_;
int max_mana_;

public:
Wizard(const string& name)
: Player(name, 80, 8, 5), mana_(30), max_mana_(30) {}

bool abilityA(Player* opponent) override;
bool abilityB(Player* opponent) override;

int getMana() const { return mana_; }
int getMaxMana() const { return max_mana_; }
void setMana(int m) { mana_ = clamp(m, 0, max_mana_); }

private:
bool spendMana(int cost);
};
#endif