#include "Green.h"

Green::Green(int r, int c, Clr _clr, Board* _b)
    :Piece(r, c, _clr, _b)
{
}

void Green::draw(sf::RenderWindow& window, int r, int c)
{
    sf::Texture temp;
    if (!temp.loadFromFile("greenToken.jpg"))
        throw("Unable to load Green token");

    sf::Sprite s(temp);
    s.setScale(0.14, 0.14);

    s.setPosition(r , c); 
    window.draw(s);
}