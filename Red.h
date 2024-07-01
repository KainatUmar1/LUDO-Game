#pragma once
#include "Piece.h"
class Red :
    public Piece
{
public:
    Red(int r, int c, Clr _clr, Board* _b);
    virtual  void draw(sf::RenderWindow& window,int r, int c);
};

