#include "Character.h"
#include <iostream>
#include <vector>

#include "DefensiveItem.h"
#include "HelpfulItem.h"

Character::Character(int hp, int armor_, int attackDamage_ ) :
    hitPoints(hp),
    armor(armor_),
    attackDamage(attackDamage_)
{
    initialHitPoints.reset( new int(hitPoints) );
    initialArmorLevel.reset( new int( armor) );
    initialAttackDamage.reset( new int( attackDamage) );
}

int Character::getHP() const { return hitPoints; }

int Character::getArmorLevel() const { return armor; }

int Character::getAttackDamage() const { return attackDamage; }

bool Character::getIsDefending() const { return isDefending; }

const std::vector<std::unique_ptr<Item>>& Character::getHelpfulItems() const { return helpfulItems; }

const std::vector<std::unique_ptr<Item>>& Character::getDefensiveItems() const { return defensiveItems; }

void Character::attack( Character& other )
{
    if( hitPoints <= 0 )
    {
        std::cout << getName() << " can't attack. " << getName() << " is dead." << std::endl;
        std::cout << "make another party member use an item to revive them" << std::endl << std::endl;
        return;
    }
        
    isDefending = false;
    std::cout << getName() << " has attacked " << other.getName() << std::endl;
    //subtract attackDamage from other->hitPoints
    if( other.takeDamage(attackDamage) <= 0 )
    {
        //if you kill other, you get a boost in hit points and armor.
        attackInternal(other);
    }
}

void Character::defend()
{
    std::cout << getName() << " is defending!!" << std::endl;
    for( auto& item : defensiveItems )
    {
        if( auto* defensiveItem = dynamic_cast<DefensiveItem*>(item.get()) )
        {
            defensiveItem->use(this);
            item.reset(); //can only be used once!
            break;
        }
    }
    isDefending = true;
}

void Character::help(Character& other)
{
    std::cout << getName() << " is going to help " << other.getName() << std::endl;
    for( auto& item : helpfulItems )
    {
        if( auto* helpfulItem = dynamic_cast<HelpfulItem*>(item.get()) )
        {
            helpfulItem->use(&other);
            item.reset(); //can only be used once!
            break;
        }
    }
}

int Character::takeDamage(int damage)
{
    std::cout << getName() << " is taking " << damage << " damage!" << std::endl;
    if( damage < armor )
    {
        armor -= damage;
    }
    else
    {
        damage -= armor;
        armor = 0;
        
        hitPoints -= damage;
        if( hitPoints < 0 )
        {
            std::cout << getName() << " has died in battle!" << std::endl;
            hitPoints = 0;
        }
    }
    printStats();
    return hitPoints;
}

void Character::levelUpHitPoints()
{
    if(*initialHitPoints.get())
    {
        // stats are restored to their initial value if they are lower than it
        if(hitPoints < *initialHitPoints.get() )
        {
            hitPoints = *initialHitPoints.get();
        }
    }

    // Hit Points boosted by 10% which means multiply by factor of 1.1 
    hitPoints *= 1.1;

    // Initial value of Hit Points becomes this boosted Hit Points
    *initialHitPoints = hitPoints;
}

void Character::levelUpArmor()
{
    if(*initialArmorLevel.get())
    {
        // stats are restored to their initial value if they are lower than it
        if(armor < *initialArmorLevel.get() )
        {
            armor = *initialArmorLevel.get();
        }
    }

    // Hit Points boosted by 10% which means multiply by factor of 1.1 
    armor *= 1.1;

    // Initial value of Hit Points becomes this boosted Hit Points
    *initialArmorLevel = armor;
}

void Character::levelUpAttackDamage()
{
    if(*initialAttackDamage.get())
    {
        // stats are restored to their initial value if they are lower than it
        if(attackDamage < *initialAttackDamage.get() )
        {
            attackDamage = *initialAttackDamage.get();
        }
    }

    // Hit Points boosted by 10% which means multiply by factor of 1.1 
    attackDamage *= 1.1;

    // Initial value of Hit Points becomes this boosted Hit Points
    *initialAttackDamage = attackDamage;
}

void Character::attackInternal(Character& other)
{
    if( other.hitPoints <= 0 )
    {
        /*
        When you defeat another Character: 
            a) your stats are restored to their initial value if they are lower than it.
            b) your stats are boosted 10%
            c) the initial value of your stats is updated to reflect this boosted stat for the next time you defeat another character.
        */

        levelUpHitPoints();
        levelUpArmor();
        levelUpAttackDamage();

        std::cout << getName() << " defeated " << other.getName() << " and leveled up!" << std::endl;        
    }
}
