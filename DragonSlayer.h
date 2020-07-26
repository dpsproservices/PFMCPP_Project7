#pragma once

//#include <string>
#include "Character.h"
#include "AttackItem.h"

struct DragonSlayer : Character
{
    DragonSlayer( std::string name_, int hitPoints_, int armor );

    const std::string& getName() override;

    std::string getStats() override;

    void attack( Character& other ) override;

private:

    const std::string name;

    // only DragonSlayer has an attack item the sword named Excalibur!
    std::unique_ptr<AttackItem> attackItem { new AttackItem() };
    
};
