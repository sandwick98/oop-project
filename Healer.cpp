#include "Healer.h"

Healer::Healer(string name, int hp, int strength, int defense, int mana){
    Mage(name,hp,strength,defense,mana);
}
void Healer::zap(Player* opponent){
    attack(opponent);
}
void Healer::heal(){
    this->hp += 20;
}