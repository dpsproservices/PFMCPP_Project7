#pragma once
#include <string>

struct Character;
struct Dwarf : Character
{
    public:

        Dwarf
        (
            std::string name_, 
            int hitPoints_, 
            int armor_, 
            int attackDamage_ 
        );
        
        //~Dwarf();

        const std::string& getName() override;

        std::string getStats() override;

        void attack( Character& other ) override;

    private:

        const std::string name;
};
