#include "Paladin.h"
#include "Character.h"
#include "Utility.h"

Paladin::Paladin
(
    std::string name_, 
    int hitPoints_, 
    int armor_, 
    int attackDamage_ 
) : Character(hitPoints_, armor_, attackDamage_), name(name_) {}

//Paladin::~Paladin() {}

const std::string& Paladin::getName()
{
    return name;
}

std::string Paladin::getStats()
{
    return getCharacterStats(this);
}
