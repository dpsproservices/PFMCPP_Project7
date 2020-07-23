#pragma once

#include "Item.h"

struct Character;
struct DefensiveItem : Item
{
    DefensiveItem();

    void use(Character* character) override;
};
