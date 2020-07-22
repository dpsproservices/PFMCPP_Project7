#pragma once

#include <string>

struct Character;
struct DragonSlayer : Character
{
    public:

        DragonSlayer
        (
            std::string& name_, 
            int hitPoints_, 
            int armor_, 
            int attackDamage_ 
        );

        //~DragonSlayer();

        const std::string& getName() override;

        std::string getStats() override;

        void attack( Character& other ) override;

    private:

        const std::string name;
    
};
