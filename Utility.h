#pragma once

#include <string>
#include <vector>
#include <memory>

struct Item;
std::vector<std::unique_ptr<Item>> makeHelpfulItems(int num);

std::vector<std::unique_ptr<Item>> makeDefensiveItems(int num);

std::vector<std::unique_ptr<Item>> makeAttackItems(int num);

struct Character;
std::string getCharacterStats(Character* ch);

void useDefensiveItem(Character*, Item&);
void useHelpfulItem(Character*, Item*);
void useAttackItem(Character*, Item*);
