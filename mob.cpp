#include "mob.h"

Mob::Mob() //konstruktor domyslny, wykonuje sie gdy tworzy sie obiekt
{

}

Mob::Mob(Point p)
{
	position = p;
}

Mob::~Mob()	//destruktor
{

}

int Mob::Lvl_mob(int lvl_gracza)
{
	if (lvl_gracza > 3)
	{
		mob_lvl = (lvl_gracza - 2) + rand() % ((lvl_gracza + 2) - (lvl_gracza - 2) + 1);
	}
	else mob_lvl = lvl_gracza + rand() % ((lvl_gracza + 2) - lvl_gracza + 1);

	return mob_lvl;
}

int Mob::Exp_to_player(int mob_lvl, int lvl_gracza)
{
	int exp_after_win;
	if ((lvl_gracza - mob_lvl) == 2)	exp_after_win = 50 - (50 * 0.4);
	if ((lvl_gracza - mob_lvl) == 1)	exp_after_win = 50 - (50 * 0.2);
	if ((lvl_gracza - mob_lvl) == 0)	exp_after_win = 50;
	if ((lvl_gracza - mob_lvl) == -1)	exp_after_win = 50 + (50 * 0.15);
	if ((lvl_gracza - mob_lvl) == -2)	exp_after_win = 50 + (50 * 0.25);
	return exp_after_win;
}
