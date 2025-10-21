#ifndef WARRIOR_H
#define WARRIOR_H

#include "Melee.h"
#include <string>
#include <vector>
using namespace std;

class Warrior: public Melee{
    public:
    // building a Warrior with a name and initial stats (hp, strength, defense, stamina)
    Warrior(const string& name, int hp, int strength, int defense, int stamina);
    // ability A: tries a sword strike against the opponent
    // denies the action if stamina is too low
    void sword(Player* opponent);

    // ability B: heavier mace hit, costs more stamina
    void mace(Player* opponent);
    ;
};

#endif
    
