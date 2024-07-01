#include "Board.h"
#include"Piece.h"
#include"Blue.h"
#include"Red.h"
#include"Green.h"
#include"Yellow.h"
#include<time.h>
#include"Utility.h"

Board::Board()
{
	dim = 15;
	Ps = new Piece * *[dim];
	for (int ri = 0; ri < dim; ri++)
	{
		Ps[ri] = new Piece * [dim];
		for (int ci = 0; ci < dim; ci++)
		{
			if ((ri == 2 || ri == 3) && (ci == 2 || ci == 3))
				Ps[ri][ci] = new Red(ri, ci, R, this);
			else if ((ri == 11 || ri == 12) && (ci == 2 || ci == 3))
				Ps[ri][ci] = new Blue(ri, ci, B, this);
			else if ((ri == 2 || ri == 3) && (ci == 11 || ci == 12))
				Ps[ri][ci] = new Green(ri, ci, G, this);
			else if ((ri == 11 || ri == 12) && (ci == 11 || ci == 12))
				Ps[ri][ci] = new Yellow(ri, ci, Y, this);
			else
				Ps[ri][ci] = nullptr;
		}
	}
}

int Board::dice()
{
	return rand() % 6;
}

Piece* Board::getPiece(int r, int c)
{
	return Ps[r][c];
}

void Board::move(int sri, int sci, int dri, int dci)
{
	Ps[dri][dci] = Ps[sri][sci];
	Ps[sri][sci] = nullptr;
}

void Board::drawBoard(sf::RenderWindow& window)
{
	sf::Texture temp;
	if (!temp.loadFromFile("Ludo.png"))
		throw("Unable to load img");

	sf::Sprite s(temp);
	s.setScale(2, 1.88);

	s.setPosition(1, 1);
	window.draw(s);
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			if (Ps[i][j] != nullptr)
				Ps[i][j]->draw(window, i * 70, j * 67);
}