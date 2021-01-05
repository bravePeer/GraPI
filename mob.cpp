#include "mob.h"

Mob::Mob() //konstruktor domyslny, wykonuje sie gdy tworzy sie obiekt
{

}

Mob::~Mob()	//destruktor
{

}

void Mob::Lvl_mob(int lvl_gracza)
{
	mob_lvl = lvl_gracza - 3 + rand() % ((lvl_gracza+3)-;

}

void Mob::Exp_to_player()
{

}