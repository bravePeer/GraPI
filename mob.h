#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "person.h"

using namespace std;

class Mob
{
public:
	Mob();
	~Mob();

	bool dead = false;
	int life =1;
	int armor =0;
	int dmg =1;
	int mob_lvl=1;
	int money_from_mob =1;
	int Exp_to_player(int mob_lvl, int lvl_gracza);
	int exp_after_win =1;
	int Lvl_mob(int lvlGracza);
};

