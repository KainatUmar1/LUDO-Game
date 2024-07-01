#pragma once
#include"Board.h"
#include"Utility.h"
class Board;
class Piece
{
	int ri, ci;
	static bool isDiagonalPathClrL2R(Board B, int, int, int, int);
	static bool isDiagonalPathClrR2L(Board B, int, int, int, int);
protected:
	Clr clr;
	Board *B;
	static bool isHorizontal(int sr, int er);
	static bool isVertical(int sc, int ec);
	static bool isDiagonal(int sr, int sc, int er, int ec);
	static bool isHorizontalPathClr(Board b, int sr, int sc, int ec);
	static bool isVerticalPathClr(Board b, int sr, int sc, int er);
	static bool isDiagonalPathClr(Board B, int, int, int, int);
public:
	Piece(int r, int c, Clr clr, Board* _b);
	virtual void draw(sf::RenderWindow& window,int, int) = 0;
	void move(int r, int c);
	Clr getClr();
};
