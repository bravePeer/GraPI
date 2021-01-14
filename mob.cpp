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
	if (return_map == 1)
	{
		mob.armor = 5 + rand() % (10 - 5 + 1);
		mob.life = 60 + rand() % (140 - 60 + 1);
		mob.mob_lvl = mob.Lvl_mob( level);
		mob.money_from_mob = 100 + rand() % (100 - 20 + 1);
		mob.exp_after_win = mob.Exp_to_player( level);
	}
	else if (return_map == 2)
	{
		mob.armor = 10 + rand() % (20 - 10 + 1);
		mob.life = 80 + rand() % (160 - 80 + 1);
		mob.mob_lvl = mob.Lvl_mob( level);
		mob.money_from_mob = 40 + rand() % (120 - 40 + 1);
		mob.exp_after_win = mob.Exp_to_player( level);
	}
	else if (return_map == 3)
	{
		mob.armor = 15 + rand() % (25 - 15 + 1);
		mob.life = 100 + rand() % (180 - 60 + 1);
		mob.mob_lvl = mob.Lvl_mob( level);
		mob.money_from_mob = 60 + rand() % (140 - 60 + 1);
		mob.exp_after_win = mob.Exp_to_player( level);
	}
	/*{
	case 1:
		mob.life = player.life * 0.4;
		mob.armor = player.armor * 0.1;
		  pom1 = player.dmg_output * 0.4;
		mob.dmg = 5 + rand() % ((pom1)-5 + 1);
		mob.mob_lvl = mob.Lvl_mob(player.level);
		mob.exp_after_win = mob.Exp_to_player( player.level);
		mob.money_from_mob = 20;
		break;
	case 2:
		mob.life = player.life * 0.5;
		mob.armor = player.armor * 0.3;
		  pom2 = player.dmg_output * 0.5;
		mob.dmg = 6 + rand() % ((pom2)-6 + 1);
		mob.mob_lvl = mob.Lvl_mob(player.level);
		mob.exp_after_win = mob.Exp_to_player( player.level);
		mob.money_from_mob = 20;
		break;
	case 3:
		mob.life = player.life * 0.6;
		mob.armor = player.armor * 0.4;
		  pom3 = player.dmg_output * 0.65;
		mob.dmg = 7 + rand() % ((pom3)-7 + 1);
		mob.mob_lvl = mob.Lvl_mob(player.level);
		mob.exp_after_win = mob.Exp_to_player( player.level);
		mob.money_from_mob = 20;
		break;
	case 4:
		mob.life = player.life * 0.7;
		mob.armor = player.armor * 0.6;
		pom4 = player.dmg_output * 0.75;
		mob.dmg = 8 + rand() % ((pom4)-8 + 1);
		mob.mob_lvl = mob.Lvl_mob(player.level);
		mob.exp_after_win = mob.Exp_to_player( player.level);
		mob.money_from_mob = 20;
	case 5:
		mob.life = player.life * 0.8;
		mob.armor = player.armor * 0.7;
		pom5 = player.dmg_output * 1.1;
		mob.dmg = 11 + rand() % ((pom5)-11 + 1);
		mob.mob_lvl = mob.Lvl_mob(player.level);
		mob.exp_after_win = mob.Exp_to_player( player.level);
		mob.money_from_mob = 30;
		break;
	}*/
	return mob;
}


