#pragma once

#include "Item.h"

struct Character;
struct AttackItem : Item
{
    AttackItem();

    void use(Character* character) override;
};
