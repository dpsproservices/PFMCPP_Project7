#include "Paladin.h"
#include "Character.h"

Paladin::Paladin
(
    std::string& name_, 
    int hitPoints_, 
    int armor_, 
    int attackDamage_ 
) : name(name_), Character(hitPoints_, armor_, attackDamage_) {}

//Paladin::~Paladin() {}

const std::string& Paladin::getName()
{
    return name;
}

std::string Paladin::getStats()
{
    return "Stats: ";
}
