#include "Melee.h" // include Melee header file

Melee::Melee(string name, int hp, int strength, int defense, int stamina)
    : Player(name, hp, strength, defense), stamina(stamina) {}

int Melee::get_stamina(){
    return this->stamina;
}
void Melee::set_stamina(int stamina){
    this->stamina = stamina;
}