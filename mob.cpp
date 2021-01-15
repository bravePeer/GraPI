#include "mob.h"
#include "player.h"

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
	mob.name = "BLEEE";
	int pom_name = 1 + rand() % (6-1+1);
	if (pom_name == 1) mob.name = "Wilk";
	else if(pom_name == 2) mob.name = "WiedŸma";
	else if(pom_name == 3) mob.name = "Licho";
	else if(pom_name == 4) mob.name = "Ghul";
	else if(pom_name == 5) mob.name = "Leœnica";
	else if(pom_name == 6) mob.name = "Troll skalny";

	if (return_map == 1)
	{
		mob.name=pom_name;
		mob.armor = 5 + rand() % (30 - 5 + 1);
		mob.life = 60 + rand() % (140 - 60 + 1);
		mob.mob_lvl = mob.Lvl_mob( level);
		mob.money_from_mob = 100 + rand() % (100 - 20 + 1);
		mob.exp_after_win = mob.Exp_to_player( level);
		return mob;
	}
	else if(return_map == 2)
	{
		mob.name=pom_name;
		mob.armor = 15 + rand() % (35 - 15 + 1);
		mob.life = 90 + rand() % (180 - 90 + 1);
		mob.mob_lvl = mob.Lvl_mob( level);
		mob.money_from_mob = 40 + rand() % (120 - 40 + 1);
		mob.exp_after_win = mob.Exp_to_player( level);
		return mob;
	}
	else if (return_map == 3)
	{
		mob.name=pom_name;
		mob.armor = 25 + rand() % (50 - 25 + 1);
		mob.life = 110 + rand() % (220 - 110 + 1);
		mob.mob_lvl = mob.Lvl_mob( level);
		mob.money_from_mob = 60 + rand() % (140 - 60 + 1);
		mob.exp_after_win = mob.Exp_to_player( level);
		return mob;
	}
	else if (return_map ==1)
	{
		boss.name="Wilko³ak";
		boss.armor = 20;
		boss.life = 180;
		boss.mob_lvl = mob.Lvl_mob( level);
		boss.money_from_mob = 500;
		boss.exp_after_win = mob.Exp_to_player( level);
		return boss;
		
	}
	else if (return_map ==2)
	{
		boss.name="Golem";
		boss.armor = 40;
		boss.life = 260;
		boss.mob_lvl = mob.Lvl_mob( level);
		boss.money_from_mob = 750;
		boss.exp_after_win = mob.Exp_to_player( level);
		return boss;

	}
	else if (return_map ==3)
	{
		boss.name="Smok dzikiego wzgórza";
		boss.armor = 70;
		boss.life = 300;
		boss.mob_lvl = mob.Lvl_mob( level);
		boss.money_from_mob = 1000;
		boss.exp_after_win = mob.Exp_to_player( level);
		return boss;
	}
}


