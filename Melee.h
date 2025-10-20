#ifndef MELEE_H
#define MELEE_H

#include <iostream>
#include "Player.h" // Melee is a subclass of Player

class Melee : public Player{
    protected:
        int stamina; // stamina only for Melee class
    private:
        // Melee constructor
        Melee(string name, int hp, int strength, int defense, int stamina);
        // getter and setter for stamina
        int get_stamina();
        void set_stamina(int stamina);
};

#endif