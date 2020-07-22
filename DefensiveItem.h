#pragma once

#include "Item.h"

struct Character;
struct DefensiveItem : Item
{
    DefensiveItem();
    
    //~DefensiveItem();

    void use(Character* character) override;
};
