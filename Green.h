#pragma once
#include "Piece.h"
class Green :
    public Piece
{
public:
    Green(int r, int c, Clr _clr, Board* _b);
    virtual void draw(sf::RenderWindow& window,int r, int c);
};

