#include "Red.h"

Red::Red(int r, int c, Clr _clr, Board* _b)
    :Piece(r, c, _clr, _b)
{
}

void Red::draw(sf::RenderWindow& window, int r, int c)
{
    sf::Texture temp;
    if (!temp.loadFromFile("redToken.jpg"))
        throw("Unable to load Red token");

    sf::Sprite s(temp);
    s.setScale(0.14, 0.14); 
    s.setPosition(r ,c);
    window.draw(s);
}