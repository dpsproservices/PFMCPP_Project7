#include "Dwarf.h"
#include "Character.h"

Dwarf::Dwarf
(
    std::string& name_, 
    int hitPoints_, 
    int armor_, 
    int attackDamage_ 
) : name(name_), Character(hitPoints_, armor_, attackDamage_) {}

//Dwarf::~Dwarf() {}

const std::string& Dwarf::getName()
{
    return name;
}

std::string Dwarf::getStats()
{
    return "Stats: ";
}
