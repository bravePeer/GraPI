﻿#include <iostream>
#include <fstream>
#include <cwchar>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <list>
#include "person.h"
#include "player.h"
#include "item.h"
#include "map.h"
#include "mob.h"
#include "something.h"
#include "point.h"
#include "gfx.h"

using namespace std;

void console_clean()
{
	cout << "(wcisnij dowolny klawisz)" << endl;
	int a;
	a = _getch();
	system("cls");
}

Mob MobStats(Player &player, int return_map)
{
	Mob mob;
	if(return_map == 1)
	{
	mob.armor = 5 + rand() % (10 - 5 + 1);
	mob.life = 60 + rand() % (140 - 60 + 1);
	mob.mob_lvl = mob.Lvl_mob(player.level);
	mob.money_from_mob= 100 + rand() % (100 - 20 + 1);
	mob.exp_after_win = mob.Exp_to_player(player.level);
	}
	else if(return_map == 2)
	{
		mob.armor = 10 + rand() % (20 - 10 + 1);
	mob.life = 80 + rand() % (160 - 80 + 1);
	mob.mob_lvl = mob.Lvl_mob(player.level);
	mob.money_from_mob = 40 + rand() % (120 - 40 + 1);
	mob.exp_after_win = mob.Exp_to_player(player.level);
	}
	else if(return_map == 3)
	{
	mob.armor = 15 + rand() % (25 - 15 + 1);
	mob.life = 100 + rand() % (180 - 60 + 1);
	mob.mob_lvl = mob.Lvl_mob(player.level);
	mob.money_from_mob = 60 + rand() % (140 - 60 + 1);
	mob.exp_after_win = mob.Exp_to_player(player.level);
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

void map_generator(Player &player, Map& map)
{
	int x, y;
	for (int i = 0; i < 5;i++)
	{
		x = 1 + rand() % (10 - 1 + 1);
		y = 1 + rand() % (20 - 1 + 1);
		if (map.map[x][y] == 'H' || map.map[x][y] == 'S' || map.map[x][y] == 'N'
			|| map.map[x][y] == 'P' || map.map[x][y] == '|' || map.map[x][y] == 'B'
			|| map.map[x][y] == '-' || map.map[x][y] == '_')
		{
			i--;
			continue;
		}
		else
		{
			map.mobs.push_back(new Mob(MobStats(player,1)));
			//map.map[x][y] = 'X';
			if (map.mobs.size() > 0)
			{
				map.mobs[map.mobs.size()-1]->position = { y,x };
			}
			
			x = 0;
			y = 0;
		}
	}
}

/*
Mob Mob_generator1(Mob &mob,Player &player)
{
	mob.armor = 5 + rand() % (10 - 5 + 1);
	mob.life = 60 + rand() % (140 - 60 + 1);
	mob.mob_lvl = mob.Lvl_mob(player.level);
	mob.money_from_mob= 100 + rand() % (100 - 20 + 1);
	mob.exp_after_win = mob.Exp_to_player(player.level);
	return mob;
}
Mob Mob_generator2(Mob& mob, Player& player)
{
	mob.armor = 10 + rand() % (20 - 10 + 1);
	mob.life = 80 + rand() % (160 - 80 + 1);
	mob.mob_lvl = mob.Lvl_mob(player.level);
	mob.money_from_mob = 40 + rand() % (120 - 40 + 1);
	mob.exp_after_win = mob.Exp_to_player(player.level);
	return mob;
}
Mob Mob_generator3(Mob& mob, Player& player)
{
	mob.armor = 15 + rand() % (25 - 15 + 1);
	mob.life = 100 + rand() % (180 - 60 + 1);
	mob.mob_lvl = mob.Lvl_mob(player.level);
	mob.money_from_mob = 60 + rand() % (140 - 60 + 1);
	mob.exp_after_win = mob.Exp_to_player(player.level);
	return mob;
}*/

int Fight(Player& player, Mob& mobek, int return_map)
{
	//system("cls");
	int tura = 1;
	int mana = 4;
	int pom=0;
	bool crit = false;

	player.Dmg_formula();

	while (player.life > 0 || mobek.life > 0)
	{
		/*cout << "Tura: " << tura << endl;
		cout << "p:" << pom << endl;
		cout << "HP twojego bohatera: " << player.life << endl;
		cout << "HP przeciwnika: " << mobek.life << endl;
		cout << "Mana: " << mana << " /4" << endl;
		cout << endl;
		cout << "Wybierz atak!" << endl;
		cout << endl;*/

		CDrawText("Tura: "+to_string(tura), { 107,1 }, 0x0003);
		CDrawText("p: " + to_string(pom), { 107,2 }, 0x0003);
		CDrawText("HP twojego bohatera: " + to_string(player.life), { 107,3 }, 0x0003);
		CDrawText("HP przeciwnika: " + to_string(mobek.life), { 107,4 }, 0x0003);
		CDrawText("Mana: " + to_string(mana), { 107,5 }, 0x0003);
		CDrawText("Wybierz atak! ", { 107,7 }, 0x0003);

		for (int i = 0; i < 1; i++)
		{
			//cout << endl;
			//cout << endl;
			//cout << endl;
			vector<string> s;
			s.push_back("Zwykły atak\n");
			s.push_back("Umiejętność specjalna \n");
			CDrawText("(potrzeba 4pkt many)", { 107,10}, 0x0003);

			switch (DrawMenu(s, { 107,9 }))
			{
			case 0:
				crit = player.CritIs();
				if(crit)
				{
					player.dmg_output*=1.5;
				}
				mobek.life = mobek.life - (player.dmg_output - mobek.armor);
				//cout << "Zadajesz: " << player.dmg_output - mobek.armor << " pkt obrażeń" << endl;
				CDrawText("Zadajesz: " + to_string(player.dmg_output - mobek.armor) + " pkt obrażeń", { 107,12 }, 0x000b);
				if(crit)
				{
					player.dmg_output=player.dmg_output/1.5;
				}
				continue;
			case 1:
				if (player.profession == 2 && player.life == player.lifeMax)
				{
					//cout << "Masz pełne zdrowie." << endl;
					CDrawText("Masz pełne zdrowie. " , { 107,12 }, 0x000b);

					//mobek.life = mobek.life - (player.dmg_output - mobek.armor);
					//cout << "Zadajesz: " << player.dmg_output - mobek.armor << " pkt obrażeń" << endl;
					i--;
					break;
				}
				else if (player.profession == 2 && mana == 4) 
				{
					mobek.life -= player.Spell(mobek.dmg);
					mana = 0;
				}
				else if (player.profession == 1 && mana == 4) 
				{
					pom = 3;
					//cout << "Aktywujesz wokół siebie aurę która osłabi przyjmowane przez ciebie ciosy!" << endl << endl;
					CDrawText("Aktywujesz wokół siebie aurę,", { 107,12 }, 0x000b);
					CDrawText("która zwiększy pancerz", { 107,13 }, 0x000b);

					mobek.dmg=(int)player.Spell(mobek.dmg);
					mana = 0;

				}
				else if (player.profession == 3 && mana == 4) 
				{
					
					//cout << "Wypuszczasz deszcz strzał..." << endl << endl;
					//cout << "Zadajesz: " << player.Spell(mobek.dmg) << " pkt obrażeń" << endl;
					CDrawText("Wypuszczasz deszcz strzał...", { 107,12 }, 0x000b);
					CDrawText("Zadajesz: " +to_string( player.Spell(mobek.dmg)) + " pkt obrażeń", { 107,12 }, 0x000b);

					mana = 0;
				}
				 else if (mana != 4)
				{
					//cout << "Nie masz many aby wykonać ten atak." << endl;
					CDrawText("Nie masz many!", { 107,12 }, 0x000b);
					i--;
				}
			}
		}

		if (pom >0 && player.profession==1) pom--;
		if (pom == 0) mobek.dmg *= 2;

		if (mana < 4) mana++;
		//cout << endl;

		if (mobek.life <= 0)
		{
		//	cout << endl;
		//	cout << "Brawo wygrałeś tę walkę!" << endl;
		//	cout << "Zdobywasz: " <<mobek.exp_after_win<<" pkt doświadczenia."<< endl;
		//	cout << "Za wygraną walkę zyskujesz: " <<mobek.money_from_mob<<" złota."<< endl;
			ClearInfoPlace();
			CDrawText("Brawo wygrałeś tę walkę!", { 107,1   }, 0x000b);
			CDrawText("Zdobywasz: " +to_string( mobek.money_from_mob) + "G", { 107,2 }, 0x000b);

			mobek.dead = true;
			player.money += mobek.money_from_mob;
			player.xp += mobek.exp_after_win;
			//  break;
			return 1;	//wygra
		}

		//cout << endl;
		//cout << "Twój przeciwnik uderza..." << endl;
		GetKey();
		CDrawText("Twój przeciwnik uderza...", { 107,12 }, 0x000b);
		if (return_map == 1)
		{
			mobek.dmg= 20 + rand() % (30 - 20 + 1);
		}
		else if (return_map == 2)
		{
			mobek.dmg = 30 + rand() % (45 - 30 + 1);
		}
		else if (return_map == 3)
		{
			mobek.dmg = 40 + rand() % (55 - 40 + 1);
		}
		if (player.profession == 1 && pom > 0)
		{
			//cout << "Aura zablokowała:" <<(int)mobek.dmg*0.5<<" pkt obrażeń."<< endl;
			CDrawText("Aura zablokowała : " + to_string((int)mobek.dmg * 0.5) + " pkt obrażeń.", { 107,14 }, 0x000b);
		}

		player.life = player.life - (mobek.dmg - player.armor);
		//cout << "Zadaje ci: " << mobek.dmg - player.armor << " pkt obrażeń" << endl;
		CDrawText("Zadaje ci: : " + to_string(mobek.dmg - player.armor) + " pkt obrażeń.", { 107,14 }, 0x000b);

		if (player.life <= 0)
		{
			//cout << endl;
			//cout << "Poległeś na polu bitwy..." << endl;
			CDrawText("Poległeś na polu bitwy...", { 107,14 }, 0x000b);
			player.dead = true;
			break;
			
			return 0;	//przegra
		}

		tura++;
		GetKey();
		ClearInfoPlace();
		//console_clean();
	}
	return 1;
}

int SellItem(Player &player)
{
	vector<string> itNames;
	for (int i = 0; i < player.inventory.size(); i++)
	{
		itNames.push_back(player.inventory[i]->name + " " + [](string s)->string { s.erase(s.end() - 4, s.end()); return s; }(to_string(player.inventory[i]->weight)) + "Kg " + to_string(player.inventory[i]->price) + "G");
	}
	itNames.push_back("Powrót");

	ClearInfoPlace();
	return DrawMenu(itNames, {107,1});
}

int BuyItem( vector<Item*> &sellersItems)
{
	vector<string> itNames;
	for (int i = 0; i < sellersItems.size(); i++)
	{
		itNames.push_back(sellersItems[i]->name + " " + [](string s)->string { s.erase(s.end() - 4, s.end()); return s; }(to_string(sellersItems[i]->weight)) + "Kg " + to_string(sellersItems[i]->price) + "G");
	}
	itNames.push_back("Powrót");
	
	ClearInfoPlace();
	return  DrawMenu(itNames, {107,1});
}

void Shop(Player& player, vector<Food>& allFood, vector<Weapon>& allWeapons, vector<Armor>& allArmor)
{
	vector<Item *> sellersItems;
	vector<string> s;
	s.push_back("Kup");
	s.push_back("Sprzedaj");
	s.push_back("Odejdź");

	int it = 0;

	for (int i = 0; i < 5; i++)
	{
		switch (rand()%3 + 1)
		{
		case 1:	//jedzonko
			sellersItems.push_back(new Food(allFood[rand() % (allFood.size() - 1)]));
			break;
		case 2:	//bron
			sellersItems.push_back(new Weapon(allWeapons[rand() % (allWeapons.size() - 1)]));
			break;
		case 3:	//armor
			sellersItems.push_back(new Armor(allArmor[rand() % (allArmor.size() - 1)]));
			break;
		}
		//sellersItems.push_back(new Item("Tak", "To jest opis", 3 + i, 99 + i * 1));
	}

	ClearInfoPlace();

	switch (DrawMenu(s, {107, 1}))
	{
	case 0:
		it = BuyItem( sellersItems);
		if (it < sellersItems.size())
		{
			if (sellersItems[it]->price < player.money)
			{
				player.money -= sellersItems[it]->price;
				player.inventory.push_back(sellersItems[it]);
				CDrawText("Kupiłeś " + player.inventory[player.inventory.size() - 1]->name, { 107,30 }, 0x0003);
			}
			else
			{
				it = sellersItems.size();
				CDrawText("Nie stać Cię!", { 107, 30 }, 0x000c);
			}
		}
		break;
	case 1:
		it = SellItem(player);
		if (it < player.inventory.size())
		{
			CDrawText("Sprzedałeś: " + player.inventory[it]->name + " za: " + to_string(player.inventory[it]->price), {107,30 }, 0x000c);

			player.money += player.inventory[it]->price;
			player.inventory[it] = NULL;
			player.inventory.erase(player.inventory.begin() + it);
		}
		it = sellersItems.size();
		break;
	case 2:
		break;
	}

	//GetKey();

	//Czyszczenie ekwipunku sprzedawcy
	s.clear();
	for (int i = 0; i < sellersItems.size(); i++)
	{
		if(i != it)
			sellersItems[i] = NULL;
	}
	sellersItems.clear();
}

void ReadGameAssets(vector<Food>& allFood, vector<Weapon>& allWeapons, vector<Armor>& allArmor)
{
	allFood.push_back(Food("Bułka", "Można zjeść", 0.05f, 30, 2));
	allFood.push_back(Food("Chleb", "Można zjeść", 0.05f, 30, 2));
	allFood.push_back(Food("Ciasteczka", "Ze stron ;)", 0.01f, 200, 3));
	allFood.push_back(Food("Soczek Jagodowy", "Do picia", 0.3f, 500, 10));
	allFood.push_back(Food("XXX", "Jak nie piłeś lepiej nie pij", 0.5f, 2000, -1));
	
	allWeapons.push_back(Weapon("Srebrny miecz", "", 2.81f, 767, 5, 30, 0.5f, 1));
	allWeapons.push_back(Weapon("Stalowy miecz", "", 2.81f, 767, 30, 10, 0.3f, 1));
	allWeapons.push_back(Weapon("Siekiera", "", 1.76f, 500, 10, 10, 0.8f, 1));


	allArmor.push_back(Armor("Zbroja stalowa", "", 5.0f, 2000, 10, 1));
	allArmor.push_back(Armor("Skurzane ubranko", "", 1.0f, 500, 7, 2));
}

void Game(Player &player, Map &map)
{
	system("cls");
	
	/*missje?*/
	player.quest = new Mission("Quest", {5,5});

	int x = 0, y = 0;
	int return_map = map.Load1map();

	map_generator(player, map);
	map.ShowMap(player.positon);

	vector<Food> allFood;
	vector<Weapon> allWeapons;
	vector<Armor> allArmor;

	Mob mob;
	ReadGameAssets(allFood, allWeapons, allArmor);
	
	map.ShowMap();
	DrawBorder();

	//int a = 0;

	while (1)	//głowna petla gry
	{
		
		//system("cls");
		map.ShowMap(player.positon);

		//Osługa klawiatury
		switch (GetKey())
		{
		case 'w':
			player.positon.y -= 1;
			if (player.positon.y < 1 || !map.CanMove(player.positon))
				player.positon.y += 1;
			break;
		case 's':
			player.positon.y += 1;
			if (player.positon.y > map.mapSize.y - 1 || !map.CanMove(player.positon))
				player.positon.y -= 1;
			break;
		case 'a':
			player.positon.x -= 1;
			if (player.positon.x < 1 || !map.CanMove(player.positon))
				player.positon.x += 1;
			break;
		case 'd':
			player.positon.x += 1;
			if (player.positon.x > map.mapSize.x - 1 || !map.CanMove(player.positon))
				player.positon.x -= 1;
			break;
		case 'i':
			ClearInfoPlace();
			player.ShowInventory();
			ClearInfoPlace();
			break;
		case 'k':
			ClearInfoPlace();
			player.ShowStats();
			ClearInfoPlace();
			break;
		case 'j':
			ClearInfoPlace();
			player.ShowQuests();
			ClearInfoPlace();
			break;
		}
		
		y = player.positon.x;
		x = player.positon.y;
		
		if (int buf = map.IsFight(player.positon))		//walka
		{
			//cout << "Na swojej drodze spotkałeś potwora, musisz stanąć z nim do walki!" << endl;
			X(1, 0x000c ,"Na swojej drodze spotkałeś potwora, musisz stanąć z nim do walki!");
			if (Fight(player, *map.mobs[buf-1],return_map))
			{
				map.KillMob(buf - 1);
			}
			//map.ShowMap();
		}
		
		
		if (map.map[x][y] == 'S')		//sklep
		{
			Shop(player, allFood, allWeapons, allArmor);
		}
		else if (map.map[x][y] == 'P')		//przejście
		{
			if (return_map == 1)
			{
				//delete map.map;
				map.Load2map();
				map_generator(player, map);
			}
			else if (return_map == 2)
			{
				//delete map.map;
				map.Load3map();
				map_generator(player, map);
			}/**/
		}
		
		if (player.xp >= player.xpToNextLvl)	//lvl up
		{
			player.xp -= player.xpToNextLvl;
			player.xpToNextLvl = (int)player.xpToNextLvl * 1.5;
			player.level++;
			player.Bonus_stats_per_lvl();
		}

		if (player.quest->IsOnMissionPoint(player.positon))
		{
			//player.quest->ShowMessege();
		}
		if(player.dead)
		{
			//cout << "Koniec gry." << endl;
			X(1, 0x0004, "Koniec gry");
			break;
		}
	}
	
	allArmor.clear();
	allWeapons.clear();
	allFood.clear();
}

int main()
{
	srand(time(NULL));
	GenerateWindow();
	
//	ShowGfx_NPC(102);


	//_getch();

	Player player;
	vector<string> s;
	s.push_back("1 Rozpocznij nowa grę");
	s.push_back("2 Wczytaj zapis");
	s.push_back("3 wyjdź");

	//TU ZACZYNA SIE GRA

	Map map;
	map.Load1map();

	while (1)//główna 
	{
		switch (DrawMenu(s))
		{
		case 0: //poczatek gry
			player.CreateCharacter();
			player.inventory.push_back(new Item("Sztabka stali", "Ciężka", 2.0f, 10));
			player.inventory.push_back(new Weapon("Miecz jednoręczny", "", 1.5f, 1000, 5, 3, 0.1, 1));
			player.inventory.push_back(new Armor("Zbroja", "", 3.0f, 1000, 1, 1));
			player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
			Game(player, map);
			break;
		case 1:	//wczytanie zapisu
			player.UsePreset();
			Game(player, map);
			break;
		case 2:	//wyjscie
			return 0;
			break;
		}
	}

	return 0;
}