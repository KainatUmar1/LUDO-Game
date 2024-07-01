#pragma once
#include "Piece.h"
class Blue :
    public Piece
{
public:
    Blue(int r, int c, Clr _clr, Board* _b);
    virtual void draw(sf::RenderWindow& window,int r, int c);
};