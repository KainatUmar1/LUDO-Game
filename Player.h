#pragma once
#include<string>
#include"Utility.h"
using namespace std;
class Player
{
	string name;
	Clr clr;
public:
	Player(string, Clr);
	string getName();
	Clr getClr();
};