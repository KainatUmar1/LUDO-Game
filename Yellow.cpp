#include "Yellow.h"

Yellow::Yellow(int r, int c, Clr _clr, Board* _b)
    :Piece(r, c, _clr, _b)
{
}

void Yellow::draw(sf::RenderWindow& window, int r, int c)
{
    sf::Texture temp;
    if (!temp.loadFromFile("yellowToken.jpg"))
        throw("Unable to load Yellow token");

    sf::Sprite s(temp);
    s.setScale(0.14, 0.14);

    s.setPosition(r, c);
    window.draw(s);	
}