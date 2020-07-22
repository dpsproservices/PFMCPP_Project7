#pragma once

#include "Item.h"

struct Character;
struct HelpfulItem : Item
{
    public:
    
        HelpfulItem();

        //~HelpfulItem();

        void use(Character* character) override;
};
