#ifndef TANK_H
#define TANK_H
#include "player.h"
using namespace std;


class Tank : public Player {
private:
int stamina_;
int max_stamina_;
bool shield_active_ = false;

public:
Tank(const string& name)
: Player(name, 120, 10, 12), stamina_(25), max_stamina_(25) {}

bool abilityA(Player* opponent) override;
bool abilityB(Player* opponent) override;
void takeDamage(int dmg) override;

int getStamina() const {return stamina_;}
int getMaxStamina() const {return max_stamina_;}
void setStamina(int s) {stamina_ = clamp(s, 0, max_stamina_);}

private:
bool spendStamina(int cost);
};


#endif