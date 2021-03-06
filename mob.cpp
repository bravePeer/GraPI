#include "mob.h"
#include "player.h"
#include "gfx.h"

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

int Mob::Exp_to_player( int lvl_gracza)
{
	int exp_after_win;
	if ((lvl_gracza - mob_lvl) == 2)	exp_after_win = 50 - (50 * 0.4);
	if ((lvl_gracza - mob_lvl) == 1)	exp_after_win = 50 - (50 * 0.2);
	if ((lvl_gracza - mob_lvl) == 0)	exp_after_win = 50;
	if ((lvl_gracza - mob_lvl) == -1)	exp_after_win = 50 + (50 * 0.15);
	if ((lvl_gracza - mob_lvl) == -2)	exp_after_win = 50 + (50 * 0.25);
	return exp_after_win;
}

Mob  Mob::MobStats(int level, int return_map)
{
	Mob mob;
	Mob boss;
	int pom_name = 1 + rand() % (6-1+1);
	if (pom_name == 1)
	{
		mob.name = "Wilk";
		mob.gfxID = 502;
		//ShowGfx_Mobs(502, { 20,50 });
	}
	else if (pom_name == 2)
	{
		mob.name = "Wied�ma";
		mob.gfxID = 501;
	}
	else if (pom_name == 3)
	{
		mob.name = "Szkielet";
		mob.gfxID = 500;
	}
	else if (pom_name == 4)
	{
		mob.name = "Ghul";
		mob.gfxID = 504;
	}
	else if (pom_name == 5)
	{
		mob.name = "Drzewiec";
		mob.gfxID = 503;
	}
	else if (pom_name == 6)
	{
		mob.name = "Goblin";
		mob.gfxID = 505;
	}
	if (return_map == 1)
	{
		//mob.name=pom_name;
		mob.armor = 5 + rand() % (10 - 5 + 1);
		mob.life = 60 + rand() % (110 - 60 + 1);
		mob.mob_lvl = mob.Lvl_mob( level);
		mob.money_from_mob = 100 + rand() % (100 - 20 + 1);
		mob.exp_after_win = mob.Exp_to_player( level);
		return mob;
	}
	else if(return_map == 2)
	{
		//mob.name=pom_name;
		mob.armor = 10 + rand() % (20 - 15 + 1);
		mob.life = 110 + rand() % (150 - 110 + 1);
		mob.mob_lvl = mob.Lvl_mob( level);
		mob.money_from_mob = 40 + rand() % (120 - 40 + 1);
		mob.exp_after_win = mob.Exp_to_player( level);
		return mob;
	}
	else if (return_map == 3)
	{
		//mob.name=pom_name;
		mob.armor = 20 + rand() % (30 - 20 + 1);
		mob.life = 150 + rand() % (200 - 150 + 1);
		mob.mob_lvl = mob.Lvl_mob( level);
		mob.money_from_mob = 60 + rand() % (140 - 60 + 1);
		mob.exp_after_win = mob.Exp_to_player( level);
		return mob;
	}
	if (return_map ==1)
	{
		boss.name="Golem";
		boss.armor = 20;
		boss.life = 150;
		boss.mob_lvl = mob.Lvl_mob( level);
		boss.money_from_mob = 500;
		boss.exp_after_win = mob.Exp_to_player( level);
		return boss;
		
	}
	else if (return_map ==2)
	{
		boss.name="Wilko�ak";
		boss.armor = 25;
		boss.life = 200;
		boss.mob_lvl = mob.Lvl_mob( level);
		boss.money_from_mob = 750;
		boss.exp_after_win = mob.Exp_to_player( level);
		return boss;

	}
	else if (return_map ==3)
	{
		boss.name="Nieumar�y Smok";
		boss.armor = 30;
		boss.life = 250;
		boss.mob_lvl = mob.Lvl_mob( level);
		boss.money_from_mob = 1000;
		boss.exp_after_win = mob.Exp_to_player( level);
		return boss;
	}
}


