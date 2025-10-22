#include "Mage.h" // include Mage header file

Mage::Mage(string name, int hp, int strength, int defense, int mana)
    : Player(name, hp, strength, defense), mana(mana) {}

int Mage::get_mana(){
    return this->mana;
}
void Mage::set_mana(int mana){
    this->mana = mana;
}