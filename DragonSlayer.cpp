#include "DragonSlayer.h"
#include "Dragon.h"
#include "Character.h"
#include "Utility.h"
#include "AttackItem.h"

DragonSlayer::DragonSlayer
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

const std::string& DragonSlayer::getName()
{
    return name;
}

std::string DragonSlayer::getStats()
{
    return getCharacterStats(this);
}

void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;

    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        //assert(false);
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so they should USE their attack item before attacking the dragon... 
        //note that items are single-use only, so you need to reset it after use. 
        
        if (attackItem == nullptr)
        {
            std::cout << getName() << "'s attack item has already been used." << std::endl;
        }
        else
        {
            attackItem->use(this);
            attackItem.reset();
        }

        //look in the Character class for how the other item types are reset after use.
        while( dragon->getHP() > 0 )
        {
            dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
        
}
