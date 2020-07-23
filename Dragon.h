#pragma once

#include <string>
#include "Character.h"

struct Dragon : Character
{   
    Dragon
    (
        std::string name_, 
        int hitPoints_, 
        int armor_, 
        int attackDamage_ 
    );

    const std::string& getName() override;

    std::string getStats() override;

    void attack( Character& other ) override;

    private:

        const std::string name;
};
