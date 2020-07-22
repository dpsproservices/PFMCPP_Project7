#pragma once

#include <string>

struct Character;
struct Dragon : Character
{
    public:
    
        Dragon
        (
            std::string& name_, 
            int hitPoints_, 
            int armor_, 
            int attackDamage_ 
        );

        //~Dragon();

        const std::string& getName() override;

        std::string getStats() override;

        void attack( Character& other ) override;

    private:

        const std::string name;

};
