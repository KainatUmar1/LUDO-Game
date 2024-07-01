#include "Ludo_game.h"
#include<iostream>
#include"Utility.h"
#include"Player.h"
#include"Dice.h"
#include"Piece.h"
#include"Board.h"
#include<time.h>
using namespace std;

void static getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window)
{
	sf::Event eve;
	while (true)
	{
		while (window.pollEvent(eve))
		{
			if (eve.type == eve.MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				sf::Vector2i p = sf::Mouse::getPosition(window);
				cpos = p.x;
				rpos = p.y;

				while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					sf::Vector2i m = sf::Mouse::getPosition(window);
				return;
			}
		}
	}
}

Ludo_game::Ludo_game()
{
	Ps[0] = new Player("Jack", R);
	Ps[1] = new Player("Steward", G);
	Ps[2] = new Player("Micheal", Y);
	Ps[3] = new Player("Anna", B);
	b = Board();
	srand(time(0));
	turn = rand() % 4;
	sr = 0, sc = 0, dr = 0, dc = 0;
}

void Ludo_game::title(sf::Text t, sf::RenderWindow& window)
{
	t.setCharacterSize(100);
	t.setOutlineThickness(1.5);
	t.setOutlineColor(sf::Color::White);

	t.setPosition(1158, 50);
	t.setString("L");
	t.setFillColor(sf::Color::Red);
	window.draw(t);

	t.setPosition(1220, 50);
	t.setString("u");
	t.setFillColor(sf::Color::Green);
	window.draw(t);

	t.setPosition(1275, 50);
	t.setString("d");
	t.setFillColor(sf::Color::Yellow);
	window.draw(t);

	t.setPosition(1330, 50);
	t.setString("o");
	t.setFillColor(sf::Color::Blue);
	window.draw(t);

	t.setCharacterSize(38);
	t.setPosition(1175, 160);
	t.setLetterSpacing(1.5);
	t.setString("by Kainat");
	t.setFillColor(sf::Color::Magenta);
	window.draw(t);
}

void Ludo_game::playerTitle(sf::Text t, sf::RenderWindow& window, Player* A)
{
	t.setCharacterSize(45);
	t.setPosition(1145, 450);
	t.setString(A->getName() + " `s Turn");

	if (A->getClr() == R)
		t.setFillColor(sf::Color::Red);
	else if (A->getClr() == G)
		t.setFillColor(sf::Color::Green);
	else if (A->getClr() == Y)
		t.setFillColor(sf::Color::Yellow);
	else if (A->getClr() == B)
		t.setFillColor(sf::Color::Cyan);
	window.draw(t);
}

void displayTurnMsg(Player* A)
{
	cout << endl << endl << A->getName() + "'s Turn";
}

void Ludo_game::selectPiece(int &rpos,int &cpos, sf::RenderWindow&window)
{
	int r = 0, c = 0;
	getRowColbyLeftClick(r, c, window);
	rpos = (c / 67);
	cpos = (r / 65);
	cout << rpos + 1 << "  " << cpos + 1;
}

bool Ludo_game::validSrc(Player* A, int r, int c)
{
	if (r < 0 || r > 14 || c < 0 || c > 14 )
		return false;
	Piece* P = b.getPiece(r, c);
	return P != nullptr && P->getClr() == A->getClr();
}

bool Ludo_game::validDes(Player* A, int r, int c)
{
	if (r < 0 || r > 14 || c < 0 || c > 14 || (r < 6 && c < 6) || (r > 8 && c < 6) ||
		(r < 6 && c > 8) || (c > 8 && r > 8) || ((r >= 6 && r <= 8) && (c >= 6 && c <= 8)))
		return false;
	return true;
}

void Ludo_game::changeTurn(Player* A)
{
	if (A->getClr() == R)
		turn = 1;
	else if (A->getClr() == G)
		turn = 2;
	else if (A->getClr() == Y)
		turn = 3;
	else if (A->getClr() == B)
		turn = 0;
}

void Ludo_game::isFirstMove(int dice, int sr, int sc, int& dr, int& dc)
{
	if (dice == 6)
	{
		if (((sr == 2 || sr == 3) && (sc == 2 || sc == 3)))
			dr = 1, dc = 6;
		else if (((sr == 11 || sr == 12) && (sc == 11 || sc == 12)))
			dr = 13, dc = 8;
		else if (((sr == 2 || sr == 3) && (sc == 12 || sc == 11)))
			dr = 6, dc = 13;
		else if (((sr == 11 || sr == 12) && (sc == 2 || sc == 3)))
			dr = 8, dc = 1;
	}
}

bool safeSpot(int sr, int sc, int dr, int dc)
{
	if ((dr == 1 || dr == 2 || dr == 6 || dr == 8 || dr == 12 || dr == 13) &&
		(dc == 1 || dc == 6 || dc == 8 || dc == 2 || dc == 13 || dc == 12))
		return true;
	return false;
}

void Ludo_game::isLegalMove(Board b, int sr, int sc, int dr, int dc)
{

}

void Ludo_game::play()
{
	int dice_no = 0;
	Dice d;
	sf::RenderWindow window(sf::VideoMode(1550, 980), "LUDO by Kainat");
	sf::Font f;
	sf::Text t;
	f.loadFromFile("FontForLudo.ttf");
	t.setFont(f);

	while (window.isOpen())
	{
		do
		{
			b.drawBoard(window);
			displayTurnMsg(Ps[turn]);

			title(t, window);
			playerTitle(t, window, Ps[turn]);

			d.Diceprint(window, 347, 320, dice_no);
			cout << endl << endl << dice_no;
			window.display();
			do
			{
				do
				{
					cout << "\nSrc: ";
					selectPiece(sr, sc, window); //src selection
				} while (!validSrc(Ps[turn], sr, sc));
				cout << "\nDest: ";
				selectPiece(dr, dc, window);     //dc selection
			} while (!validDes(Ps[turn], dr, dc));
			isFirstMove(dice_no, sr, sc, dr, dc);
			if (safeSpot(sr, sc, dr, dc))
				cout << "\nsafe spot";
			b.move(sr, sc, dr, dc);
			window.clear();
		} while (dice_no == 6);
		changeTurn(Ps[turn]);
	}
}