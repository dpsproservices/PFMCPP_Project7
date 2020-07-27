#include "DefensiveItem.h"
#include "Utility.h"

DefensiveItem::DefensiveItem() : Item("defensive item", 3) {}

void DefensiveItem::use(Character* character)
{
    useDefensiveItem(character, *this);
}
