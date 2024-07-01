#pragma once
#include "Piece.h"
class Yellow :
    public Piece
{
public:
    Yellow(int r, int c, Clr _clr, Board* _b);
    virtual void draw(sf::RenderWindow& window,int r, int c);
};