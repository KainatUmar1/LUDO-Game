#pragma once
#include<SFML/Graphics.hpp>
class Piece;
class Board
{
	int dim;
	int dice();
public:
	Board();
	Piece*** Ps;
	Piece* getPiece(int, int);
	void move(int, int, int, int);
	void drawBoard(sf::RenderWindow& window);
};