#pragma once
#include"Board.h"
class Board;
class Piece;
class Player;
class Ludo_game
{
	int sr, sc, dr, dc;
	int turn;
	Player* Ps[4];
	Board b;
	void title(sf::Text t, sf::RenderWindow& window);
	void playerTitle(sf::Text t, sf::RenderWindow& window, Player* A);
	void selectPiece(int& rpos, int& cpos, sf::RenderWindow& window);
	bool validSrc(Player* A, int r, int c);
	bool validDes(Player* A, int r, int c);
	void changeTurn(Player* A);
	void isLegalMove(Board b, int sr, int sc, int dr, int dc);
	void isFirstMove(int dice_no, int sr, int sc, int& dr, int& dc);
public:
	Ludo_game();
	void play();
};