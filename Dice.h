#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"

class Dice 
{
public:
    int dice_roll;
    Dice() 
    {
        dice_roll = 0;
    }

    void Diceprint(sf::RenderWindow& window, int r, int c,int &n);
};

