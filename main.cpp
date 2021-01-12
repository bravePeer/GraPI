#include <iostream>
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

using namespace std;

void console_clean()
{
	cout << "(wcisnij dowolny klawisz)" << endl;
	int a;
	a = _getch();
	system("cls");
}

Mob MobStats(Player &player)
{
	Mob mob;
	int pom1 = 1 + rand() % (5 - 1 + 1);
	int pom2 = 1 + rand() % (5 - 1 + 1);
	int pom3 = 1 + rand() % (5 - 1 + 1);
	int pom4 = 1 + rand() % (5 - 1 + 1);
	int pom5 = 1 + rand() % (5 - 1 + 1);
	switch (rand()%5+1)
	{
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
	}
	return mob;
}

/*void Mob_stats(Player &player, Mob mob1_1, Mob &mob1_2, Mob &mob1_3, Mob &mob1_4, Mob &mob1_5,
	Mob &mob2_1, Mob &mob2_2, Mob &mob2_3, Mob &mob2_4, Mob &mob2_5,
	Mob &mob3_1, Mob &mob3_2, Mob &mob3_3, Mob &mob3_4, Mob &mob3_5, Mob &boss)
{
	mob1_1.life = player.life * 0.4;
	mob1_1.armor = player.armor * 0.1;
	int pom1 = player.dmg_output * 0.4;
	mob1_1.dmg = 5 + rand() % ((pom1)-5 + 1);
	mob1_1.mob_lvl = mob1_1.Lvl_mob(player.level);
	mob1_1.exp_after_win = mob1_1.Exp_to_player(mob1_1.mob_lvl, player.level);
	mob1_1.money_from_mob = 20;


	boss.life = 300;						//do wyliczenia 
	boss.armor = 40;
	boss.dmg = 40 + rand() % (90-40+1);
}*/

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
			map.mobs.push_back(new Mob(MobStats(player)));
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

int Fight(Player& player, Mob& mobek)
{
	system("cls");
	int tura = 1;
	int mana = 4;
	int pom=0;
	
	player.Dmg_formula();
	while (player.life > 0 || mobek.life > 0)
	{
		cout << "Tura: " << tura << endl;
		cout << "p:" << pom << endl;
		cout << "HP twojego bohatera: " << player.life << endl;
		cout << "HP przeciwnika: " << mobek.life << endl;
		cout << "Mana: " << mana << " /4" << endl;
		cout << endl;
		cout << "Wybierz atak!" << endl;
		cout << endl;
		

		for (int i = 0; i < 1; i++)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			vector<string> s;
			s.push_back("Zwykły atak\n");
			s.push_back("Umiejętność specjalna (potrzeba 4pkt many)\n");
			switch (DrawMenu(s, { 0,6 }))
			{
			case 0:
				mobek.life = mobek.life - (player.dmg_output - mobek.armor);
				cout << "Zadajesz: " << player.dmg_output - mobek.armor << " pkt obrażeń" << endl;
				continue;
			case 1:
				if (player.profession == 2 && player.life == player.lifeMax)
				{
					cout << "Masz pełne zdrowie." << endl;
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

				else if (player.profession == 1 && mana ==4) 
				{
					pom = 3;
					cout << "Aktywujesz wokół siebie aurę która osłabi przyjmowane przez ciebie ciosy!" << endl << endl;
					mobek.dmg=player.Spell(mobek.dmg);
					mana = 0;

				}

				else if (player.profession == 3 && mana == 4) 
				{
					
					cout << "Wypuszczasz deszcz strzał..." << endl << endl;
					cout << "Zadajesz: " << player.Spell(mobek.dmg) << " pkt obrażeń" << endl;
					mana = 0;
				}

				 else if (mana != 4)
				{
					cout << "Nie masz many aby wykonać ten atak." << endl;
					i--;
				}
				
			}
		
		}

		if (pom >0 && player.profession==1)
		{
			pom--;
			if (pom == 0) mobek.dmg *= 2;
		}


		if (mana < 4) mana++;
		cout << endl;

		if (mobek.life <= 0)
		{
			cout << endl;
			cout << "Brawo wygrałeś tę walkę!" << endl;
			cout << "Zdobywasz: " <<mobek.exp_after_win<<" pkt doświadczenia."<< endl;
			cout << "Za wygraną walkę zyskujesz: " <<mobek.money_from_mob<<" złota."<< endl;
			mobek.dead = true;
			player.money += mobek.money_from_mob;
			player.xp += mobek.exp_after_win;
			//  break;
			return 1;	//wygra
		}

		cout << endl;
		cout << "Twój przeciwnik uderza..." << endl;

		// Sleep(1000);
		player.life = player.life - (mobek.dmg - player.armor);
		cout << "Zadaje ci: " << mobek.dmg - player.armor << " pkt obrażeń" << endl;

		if (player.life <= 0)
		{
			cout << endl;
			cout << "Niestety przegrałeś walkę..." << endl;
			player.life = 1;
			break;
			return 0;	//przegra
		}

		tura++;
		console_clean();
	}
	return 1;
}

int SellItem(Player &player)
{
	vector<string> itNames;
	for (int i = 0; i < player.inventory.size(); i++)
	{
		itNames.push_back(player.inventory[i]->name + " " + to_string(player.inventory[i]->weight) + "Kg " + to_string(player.inventory[i]->price) + "PLN");
	}
	itNames.push_back("Powrót");

	return DrawMenu(itNames);
}

int BuyItem( vector<Item*> &sellersItems)
{
	vector<string> itNames;
	for (int i = 0; i < sellersItems.size(); i++)
	{
		itNames.push_back(sellersItems[i]->name + " " + to_string(sellersItems[i]->weight) + "Kg " + to_string(sellersItems[i]->price) + "PLN");
	}
	itNames.push_back("Powrót");

	return  DrawMenu(itNames);
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

	switch (DrawMenu(s))
	{
	case 0:
		it = BuyItem( sellersItems);
		if (it < sellersItems.size())
		{
			if (sellersItems[it]->price < player.money)
			{
				player.money -= sellersItems[it]->price;
				player.inventory.push_back(sellersItems[it]);
				CDrawText("Kupiłeś " + player.inventory[player.inventory.size() - 1]->name, { 5,5 }, 0x0003);
			}
			else
			{
				it = sellersItems.size();
				CDrawText("Nie stać Cię!", { 5,5 }, 0x000c);
			}
			_getch();
		}
		break;
	case 1:
		it = SellItem(player);
		if (it < player.inventory.size())
		{
			CDrawText("Sprzedałeś: " + player.inventory[it]->name + " za: " + to_string(player.inventory[it]->price), { 5,5 }, 0x000c);

			player.money += player.inventory[it]->price;
			player.inventory[it] = NULL;
			player.inventory.erase(player.inventory.begin() + it);
			_getch();
		}
		it = sellersItems.size();
		break;
	case 2:
		break;
	}

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
	player.CreateCharacter();
	/*missje?*/
	player.quest = new Mission("Quest", {5,5});

	int x = 0, y = 0;
	int return_map = map.Load1map();

	map_generator(player, map);
	map.ShowMap(player.positon);

	vector<Food> allFood;
	vector<Weapon> allWeapons;
	vector<Armor> allArmor;

	ReadGameAssets(allFood, allWeapons, allArmor);

	while (1)	//głowna petla gry
	{
		system("cls");
		//DrawBorder();
		map.ShowMap(player.positon);

		//Osługa klawiatury
		int a = _getch();
		switch (a)
		{
		case 'w':
			player.positon.y -= 1;
			if(player.positon.y < 1)
				player.positon.y += 1;
			break;
		case 's':
			player.positon.y += 1;
			if (player.positon.y > map.mapSize.y - 1)
				player.positon.y -= 1;
			break;
		case 'a':
			player.positon.x -= 1;
			if (player.positon.x < 1)
				player.positon.x += 1;
			break;
		case 'd':
			player.positon.x += 1;
			if (player.positon.x > map.mapSize.x - 1)
				player.positon.x -= 1;
			break;
		case 'i':
			player.ShowInventory();
			break;
		case 'k':
			player.ShowStats();
			break;
		case 'j':
			player.ShowQuests();
			break;
		}
		
		y = player.positon.x;
		x = player.positon.y;
		
		if (int buf = map.IsFight(player.positon))		//walka
		{
			cout << "Na swojej drodze spotkałeś potwora, musisz stanąć z nim do walki!" << endl;

			if (Fight(player, *map.mobs[buf-1]))
			{
				map.KillMob(buf - 1);
			}

			_getch();

			/*int pom1, pom2, pom3;
			pom1 = 1 + rand() % (5 - 1 + 1);
			pom2 = 1 + rand() % (5 - 1 + 1);
			pom3 = 1 + rand() % (5 - 1 + 1);
			if (pom1 == 1 && return_map == 1) {
				Fight(player, mob1_1);
				if (mob1_1.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 2 && return_map == 1) {
				Fight(player, mob1_2);
				if (mob1_2.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 3 && return_map == 1) {
				Fight(player, mob1_3);
				if (mob1_3.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 4 && return_map == 1) {
				Fight(player, mob1_4);
				if (mob1_4.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 5 && return_map == 1) {
				Fight(player, mob1_5);
				if (mob1_5.dead == true) map.map[x][y] = '.';
			}

			else if (pom2 == 1 && return_map == 2) {
				Fight(player, mob2_1);
				if (mob2_1.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 2 && return_map == 2) {
				Fight(player, mob2_2);
				if (mob2_2.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 3 && return_map == 2) {
				Fight(player, mob2_3);
				if (mob2_3.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 4 && return_map == 2) {
				Fight(player, mob2_4);
				if (mob2_4.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 5 && return_map == 2) {
				Fight(player, mob2_5);
				if (mob2_5.dead == true) map.map[x][y] = '.';
			}

			else if (pom2 == 1 && return_map == 3) {
				Fight(player, mob3_1);
				if (mob3_1.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 2 && return_map == 3) {
				Fight(player, mob3_2);
				if (mob3_2.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 3 && return_map == 3) {
				Fight(player, mob3_3);
				if (mob3_3.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 4 && return_map == 3) {
				Fight(player, mob3_4);
				if (mob3_4.dead == true) map.map[x][y] = '.';
			}
			else if (pom1 == 5 && return_map == 3) {
				Fight(player, mob3_5);
				if (mob3_5.dead == true) map.map[x][y] = '.';
			}
			else if (map.map[x][y] == 'B' && return_map == 3) {
				Fight(player, boss);
				if (boss.dead == true);
			}
			else if (boss.dead == true)
				break; //pokonanie bossa, wyjscie z glownej petli gry*/
		}
		
		if (map.map[x][y] == 'H')		//baza
		{

		}
		else if (map.map[x][y] == 'N')		//npc
		{

		}
		else if (map.map[x][y] == '-' || map.map[x][y] == '|' || map.map[x][y] == '+' || map.map[x][y] == '_')
		{
			if (a == 'w')	x = x - 1;
			if (a == 'a')	y = y + 1;
			if (a == 's')	x = x + 1;
			if (a == 'd')	y = y - 1;
		}
		else if (map.map[x][y] == 'S')		//sklep
		{
			Shop(player, allFood, allWeapons, allArmor);
		}
		else if (map.map[x][y] == 'P')		//przejście
		{

		}
		else if (player.xp >= player.xpToNextLvl)	//lvl up
		{
			player.xp -= player.xpToNextLvl;
			player.xpToNextLvl = (int)player.xpToNextLvl * 1.5;
		}

		if (player.quest->IsOnMissionPoint(player.positon))
		{
			//player.quest->ShowMessege();
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
			player.inventory.push_back(new Item("Sztabka stali", "Ciężka", 2.0f, 10));
			player.inventory.push_back(new Weapon("Miecz jednoręczny", "", 1.5f, 1000, 5, 3, 0.1, 1));
			player.inventory.push_back(new Armor("Zbroja", "", 3.0f, 1000, 1, 1));
			player.inventory.push_back(new Food("Ciasteczko", "Można zjeść, przywróci troche zdrowia", 0.2f, 200, 20));
			Game(player, map);
			break;
		case 1:	//wczytanie zapisu
			Game(player, map);
			break;
		case 2:	//wyjscie
			return 0;
			break;
		}
	}

	return 0;
}