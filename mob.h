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

	string name;
	bool dead = false;
	int hp;
	int armor;
	int magic_dmg;
	int phi_dmg;
	int mob_lvl;
	void Exp_to_player();
	void Lvl_mob(int lvlGracza);

};