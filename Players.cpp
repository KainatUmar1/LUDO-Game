#include "Player.h"

Player::Player(string n, Clr c)
{
	this->name = n;
	this->clr = c;
}

string Player::getName()
{
	return name;
}

Clr Player::getClr()
{
	return clr;
}