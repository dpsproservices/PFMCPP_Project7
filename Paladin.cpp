#include "Paladin.h"
#include "Utility.h"

Paladin::Paladin( std::string name_, int hitPoints_, int armor_ ) : 
Character(hitPoints_, armor_, 10), 
name(name_) 
{
    // int randomNumber = (rand() % 4);
    // helpfulItems = makeHelpfulItems(randomNumber);
    
    // randomNumber = (rand() % 4);
    // defensiveItems = makeDefensiveItems(randomNumber);

    helpfulItems = makeHelpfulItems(2);
    defensiveItems = makeDefensiveItems(6);
}

const std::string& Paladin::getName()
{
    return name;
}

std::string Paladin::getStats()
{
    return getCharacterStats(this);
}
