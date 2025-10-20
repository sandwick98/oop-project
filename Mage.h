#ifndef MAGE_H
#define MAGE_H

#include <iostream>
#include "Player.h" // Melee is a subclass of Player

class Mage : public Player{
    protected:
        int mana; // mana only for Mage class
    private:
        // Mage constructor
        Mage(string name, int hp, int strength, int defense, int mana);
        // getter and setter for mana
        int get_mana();
        void set_mana(int mana);
};

#endif