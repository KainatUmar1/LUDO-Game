#pragma once
#include<string>
#include"Board.h"
#include"Player.h"
#include"Utility.h"
using namespace std;
class Team
{
protected:
	int score;
	Clr clr;
	string name;
	Player p;
	Board b;
	bool isWin();
	bool isLose();
	void scoreInc();
};

