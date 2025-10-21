#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "Mage.h"

class Healer : public Mage{
    private:
        // healer constructor
        Healer(string name, int hp, int strength, int defense, int mana);
        // zap spell
        void zap(Player* opponent);
        // heal spell
        void heal();
};

#endif