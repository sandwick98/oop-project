#ifndef HEALER_H
#define HEALER_H

#include "Player.h"
#include <algorithm>
#include <iostream>
using namespace std;

class Healer : public Player {
private:
    int mana_;
    int max_mana_;

    // Helper to check & spend mana
    bool spendMana(int cost);

public:
    // Constructor: name, HP, strength, defense, starting mana
    explicit Healer(const string& name)
        : Player(name, 90, 6, 8), mana_(40), max_mana_(40) {}

    // Abilities
    bool abilityA(Player* opponent) override; // Zap (low damage)
    bool abilityB(Player* opponent) override; // Heal self

    // Display stats
    void printState(ostream& os) override;

    // Mana getters/setters
    int getMana() { return mana_; }
    int getMaxMana() { return max_mana_; }
    void setMana(int m) { mana_ = clamp(m, 0, max_mana_); }

    // Class type
    string type() override;
};

#endif