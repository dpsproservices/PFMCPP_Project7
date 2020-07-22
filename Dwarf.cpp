#include "Dwarf.h"
#include "Character.h"
#include "Utility.h"

Dwarf::Dwarf
(
    std::string name_, 
    int hitPoints_, 
    int armor_, 
    int attackDamage_ 
) : Character(hitPoints_, armor_, attackDamage_), name(name_) 
{
    int randomNumber = (rand() % 4);
    helpfulItems = makeHelpfulItems(randomNumber);
    randomNumber = (rand() % 4);
    defensiveItems = makeDefensiveItems(randomNumber);
}

//Dwarf::~Dwarf() {}

const std::string& Dwarf::getName()
{
    return name;
}

std::string Dwarf::getStats()
{
    return getCharacterStats(this);
}

// void Dwarf::attack( Character& other )
// {

// }
