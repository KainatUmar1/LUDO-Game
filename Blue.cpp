#include "Blue.h"

Blue::Blue(int r, int c, Clr _clr, Board* _b)
    :Piece(r, c, _clr, _b)
{
}

void Blue::draw(sf::RenderWindow& window, int r, int c)
{
    sf::Texture temp;
    if (!temp.loadFromFile("blueToken.jpg"))
        throw("Unable to load Blue token");

    sf::Sprite s(temp);
    s.setScale(0.1, 0.1);

    s.setPosition(r , c);
    window.draw(s);
}
