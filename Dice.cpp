#include "Dice.h"
using namespace std;

void Dice::Diceprint(sf::RenderWindow& window, int r, int c,int &diceNumber)
{
    string S[6] = { "Dice 1.jpeg" ,"Dice 2.jpeg","Dice 3.jpeg","Dice 4.jpeg","Dice 5.jpeg","Dice 6.jpeg" };
    diceNumber = rand() % 6 + 1;
    sf::Texture temp;
    temp.loadFromFile(S[diceNumber - 1]);
    sf::Sprite s;
    s.setTexture(temp, true);
    s.setScale(1.38, 1.38);
    s.setPosition(r + 117, c + 115);
    window.draw(s);
}