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
	int life;
	int armor;
	int dmg;
	int mob_lvl;
	int money_from_mob;
	int Exp_to_player(int mob_lvl, int lvl_gracza);
	int exp_after_win;
	int Lvl_mob(int lvlGracza);
};

