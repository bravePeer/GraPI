#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "person.h"
#include "player.h"

using namespace std;

class Mob
{
public:
	Mob();
	Mob(Point p);
	~Mob();

	bool dead = false;
	int life =1;
	int armor =0;
	int dmg =10;
	int mob_lvl=1;
	int money_from_mob =1;
	int Exp_to_player(int lvl_gracza);
	int exp_after_win =1;
	int Lvl_mob(int lvlGracza);
	Point position = { 0,0 };

	
};

