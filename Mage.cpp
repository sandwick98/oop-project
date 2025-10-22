#include "Mage.h" // include Mage header file

// Mage constructor: name, hp, strength, defense, mana
Mage::Mage(string name, int hp, int strength, int defense, int mana)
    : Player(name, hp, strength, defense), mana(mana) {}

// getters and setters for mana
int Mage::get_mana(){
    return this->mana;
}
void Mage::set_mana(int mana){
    this->mana = mana;
}