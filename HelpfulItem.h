#pragma once

#include "Item.h"

struct Character;
struct HelpfulItem : Item
{   
    HelpfulItem();

    void use(Character* character) override;
};
