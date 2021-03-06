#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "point.h"

using namespace std;

//Mob MobStats(Player& player, int return_map);


class Mob
{
public:
	Mob();
	Mob(Point p);
	~Mob();
	int Exp_to_player(int lvl_gracza);
	int Lvl_mob(int lvlGracza);
	Mob MobStats(int level, int return_map);
	bool dead = false;
	
	string name = "";
	int life = 1;
	int armor = 0;
	int dmg = 10;
	int mob_lvl = 1;
	int money_from_mob = 1;
	int exp_after_win = 1;
	Point position = { 0,0 };
	int gfxID = 0;
	wstring onMap = L"\u00e6";
};

