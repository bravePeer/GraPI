#include <iostream>
#include <fstream>
#include <cwchar>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string>
#include "person.h"
#include "player.h"
#include "item.h"
#include "map.h"
#include "mob.h"
#include "something.h"

using namespace std;

void map_generator(Map &map)
{
	int x,y;
	for (int i = 0; i < 5;i++)
	{
		x = 1 + rand() % (10 - 1 + 1);
		y = 1 + rand() % (20 - 1 + 1);
		if(map.map[x][y] == 'H' || map.map[x][y] == 'S' || map.map[x][y] == 'N' 
		|| map.map[x][y] == 'P' || map.map[x][y] == '|' || map.map[x][y] == 'B'
		|| map.map[x][y] == '-' || map.map[x][y] == '_')
		{
			i--;
			continue;
		}
		else{
		map.map[x][y] = 'X';
		x = 0;
		y = 0;
		}
	}
	map.ShowMap();
}

void Mob_stats(Player &player, Mob mob1_1, Mob &mob1_2, Mob &mob1_3, Mob &mob1_4, Mob &mob1_5,
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

	mob1_2.life = player.life * 0.5;
	mob1_2.armor = player.armor * 0.3;
	int pom2 = player.dmg_output * 0.5;
	mob1_2.dmg = 6 + rand() % ((pom2)-6 + 1);
	mob1_2.mob_lvl = mob1_2.Lvl_mob(player.level);
	mob1_2.exp_after_win = mob1_2.Exp_to_player(mob1_2.mob_lvl, player.level);
	mob1_2.money_from_mob = 20;

	mob1_3.life = player.life * 0.6;
	mob1_3.armor = player.armor * 0.4;
	int pom3 = player.dmg_output * 0.65;
	mob1_3.dmg = 7 + rand() % ((pom3)-7 + 1);
	mob1_3.mob_lvl = mob1_3.Lvl_mob(player.level);
	mob1_3.exp_after_win = mob1_3.Exp_to_player(mob1_3.mob_lvl, player.level);
	mob1_3.money_from_mob = 20;

	mob1_4.life = player.life * 0.7;
	mob1_4.armor = player.armor * 0.6;
	int pom4 = player.dmg_output * 0.75;
	mob1_4.dmg = 8 + rand() % ((pom4)-8 + 1);
	mob1_4.mob_lvl = mob1_4.Lvl_mob(player.level);
	mob1_4.exp_after_win = mob1_4.Exp_to_player(mob1_4.mob_lvl, player.level);
	mob1_4.money_from_mob = 20;

	mob1_5.life = player.life * 0.8;
	mob1_5.armor = player.armor * 0.7;
	int pom5 = player.dmg_output * 1.1;
	mob1_5.dmg = 11 + rand() % ((pom5)-11 + 1);
	mob1_5.mob_lvl = mob1_5.Lvl_mob(player.level);
	mob1_5.exp_after_win = mob1_5.Exp_to_player(mob1_5.mob_lvl, player.level);
	mob1_5.money_from_mob = 30;

	mob2_1.life = player.life * 0.65;
	mob2_1.armor = player.armor * 0.55;
	int pom2_1 = player.dmg_output*0.9;
	mob2_1.dmg = 9 + rand() % ((pom2_1)-9 + 1);
	mob2_1.mob_lvl = mob2_1.Lvl_mob(player.level);
	mob2_1.exp_after_win = mob2_1.Exp_to_player(mob2_1.mob_lvl, player.level);
	mob2_1.money_from_mob = 20;

	mob2_2.life = player.life * 0.7;
	mob2_2.armor = player.armor * 0.7;
	int pom2_2 = player.dmg_output;
	mob2_2.dmg = 11 + rand() % ((pom2_2)-11 + 1);
	mob2_2.mob_lvl = mob2_2.Lvl_mob(player.level);
	mob2_2.exp_after_win = mob2_2.Exp_to_player(mob2_2.mob_lvl, player.level);
	mob2_2.money_from_mob = 20;

	mob2_3.life = player.life * 0.8;
	mob2_3.armor = player.armor * 0.7;
	int pom2_3 = player.dmg_output * 1.15;
	mob2_3.dmg = 12 + rand() % ((pom2_3)-12 + 1);
	mob2_3.mob_lvl = mob2_3.Lvl_mob(player.level);
	mob2_3.exp_after_win = mob2_3.Exp_to_player(mob2_3.mob_lvl, player.level);
	mob2_3.money_from_mob = 20;

	mob2_4.life = player.life * 0.5;
	mob2_4.armor = player.armor * 0.3;
	int pom2_4 = player.dmg_output * 1.5;
	mob2_4.dmg = 14 + rand() % ((pom2_4)-14 + 1);
	mob2_4.mob_lvl = mob2_4.Lvl_mob(player.level);
	mob2_4.exp_after_win = mob2_4.Exp_to_player(mob2_4.mob_lvl, player.level);
	mob2_3.money_from_mob = 20;

	mob2_5.life = player.life * 1.2;
	mob2_5.armor = player.armor * 0.5;
	int pom2_5 = player.dmg_output * 0.7;
	mob2_5.dmg = 12 + rand() % ((pom2_5)-12 + 1);
	mob2_5.mob_lvl = mob2_5.Lvl_mob(player.level);
	mob2_5.exp_after_win = mob2_5.Exp_to_player(mob2_4.mob_lvl, player.level);
	mob2_5.money_from_mob = 40;

	mob3_1.life = player.life * 0.8;
	mob3_1.armor = player.armor * 0.6;
	int pom3_1 = player.dmg_output;
	mob3_1.dmg = 13 + rand() % ((pom3_1)-13 + 1);
	mob3_1.mob_lvl = mob3_1.Lvl_mob(player.level);
	mob3_1.exp_after_win = mob3_1.Exp_to_player(mob3_1.mob_lvl, player.level);
	mob3_1.money_from_mob = 20;

	mob3_2.life = player.life * 0.85;
	mob3_2.armor = player.armor * 0.75;
	int pom3_2 = player.dmg_output*1.2;
	mob3_2.dmg = 14 + rand() % ((pom3_2)-14 + 1);
	mob3_2.mob_lvl = mob3_2.Lvl_mob(player.level);
	mob3_2.exp_after_win = mob3_2.Exp_to_player(mob3_2.mob_lvl, player.level);
	mob3_2.money_from_mob = 20;

	mob3_3.life = player.life * 0.9;
	mob3_3.armor = player.armor * 0.7;
	int pom3_3 = player.dmg_output * 1.4;
	mob3_3.dmg = 12+ rand() % ((pom3_3)-12 + 1);
	mob3_3.mob_lvl = mob3_3.Lvl_mob(player.level);
	mob3_3.exp_after_win = mob3_3.Exp_to_player(mob3_3.mob_lvl, player.level);
	mob3_3.money_from_mob = 20;

	mob3_4.life = player.life * 0.80;
	mob3_4.armor = player.armor;
	int pom3_4 = player.dmg_output * 0.9;
	mob3_4.dmg = 13 + rand() % ((pom3_4)-13 + 1);
	mob3_4.mob_lvl = mob3_4.Lvl_mob(player.level);
	mob3_4.exp_after_win = mob3_4.Exp_to_player(mob3_4.mob_lvl, player.level);
	mob3_4.money_from_mob = 20;

	mob3_5.life = player.life;
	mob3_5.armor = player.armor * 0.70;
	int pom3_5 = player.dmg_output * 1.3;
	mob3_5.dmg = 15 + rand() % ((pom3_5)-15 + 1);
	mob3_5.mob_lvl = mob3_5.Lvl_mob(player.level);
	mob3_5.exp_after_win = mob3_5.Exp_to_player(mob3_5.mob_lvl, player.level);
	mob3_5.money_from_mob = 50;

	boss.life = 300;						//do wyliczenia 
	boss.armor = 40;
	boss.dmg = 40 + rand() % (90-40+1);
}

int Fight(Player &player, Mob &mobek)
{
    int tura=1;
    char help;
	int mana = 4;
	player.Dmg_formula();
    while(player.life > 0 || mobek.life)
    {
        cout<<"Tura: "<<tura<<endl;
        cout<<"HP twojego bohatera: "<<player.life<<endl;
        cout<<"HP przeciwnika: "<<mobek.life<<endl;
        cout<<endl;
        cout<<"Wybierz atak!"<<endl;
        cout<<"1 - zwykły atak"<<endl;
        cout<<"2 - umiejętność specjalna"<<" (potrzeba 4pkt many) " << mana << "/4"<<endl;
        cout<<":";
        cin>>help;
        cout<<endl;

        for(int i=0; i < 1; i++)
        {
           switch(help)
            {
            case'1':
				mobek.life = mobek.life - (player.dmg_output - mobek.armor);
                cout<<"Zadajesz: "<<player.dmg_output - mobek.armor<<" pkt obrażeń"<<endl;
                continue;

            case'2':
                mobek.life-=player.Spell();
                if(mana!=4)
                {
                    cout<<"nie masz many aby wykonać ten atak, zamiast tego atakujesz podstawowym atakiem"<<endl;
                }
                cout<<"Zadajesz: "<< player.Spell()<<" pkt obrażeń"<<endl;
                cout<<endl;
                mana=0;
            }
        }

        if(mana<4) mana++;
        cout<<endl;

        if(mobek.life<=0)
        {
            cout<<"Brawo wygrałeś tę walkę!"<<endl;
			mobek.dead = true;
			player.money += mobek.money_from_mob;
            break;
        }

        cout<<endl;
        cout<<"Twój przeciwnik uderza..."<<endl;
		
        cout<<endl;
       // Sleep(1000);
        player.life=player.life-(mobek.dmg-player.armor);
        cout<<"Zadaje ci: "<< mobek.dmg - player.armor <<" pkt obrażeń"<<endl;

        if(player.life<=0)
        {
            cout<<"Niestety przegrałeś walkę..."<<endl;
			player.life = 1;

            break;
        }

        tura++;
       // console_clean();
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

	return 0;
}

int BuyItem(vector<Item*> &sellersItems)
{
	vector<string> itNames;
	for (int i = 0; i < sellersItems.size(); i++)
	{
		itNames.push_back(sellersItems[i]->name + " " + to_string(sellersItems[i]->weight) + "Kg " + to_string(sellersItems[i]->price) + "PLN");
	}
	itNames.push_back("Powrót");
	
	return DrawMenu(itNames);
}

void Shop(Player& player)
{
	vector<Item *> sellersItems;
	vector<string> s;
	s.push_back("Kup");
	s.push_back("Sprzedaj");
	s.push_back("Odejdź");

	int it = 0;

	for (int i = 0; i < 3; i++)
	{
		sellersItems.push_back(new Item("Tak", "To jest opis", 3 + i, 400 + i * 10));
	}

	switch (DrawMenu(s))
	{
	case 0:
		it = BuyItem(sellersItems);
		if (it <= sellersItems.size())
		{
			player.money -= sellersItems[it]->price;
			player.inventory.push_back(sellersItems[it]);
		}
		break;
	case 1:
		it = SellItem(player);
		if (it <= player.inventory.size())
		{
			player.money += player.inventory[it]->price;
			player.inventory[it] = NULL;
			player.inventory.erase(player.inventory.begin() + it);
		}
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

void Game(Player &player, Map &map)
{
	//moby  mob[nr mapy]_[numer moba]
	Mob mob1_1;
	Mob mob1_2;
	Mob mob1_3;
	Mob mob1_4;
	Mob mob1_5;
	Mob mob2_1;
	Mob mob2_2;
	Mob mob2_3;
	Mob mob2_4;
	Mob mob2_5;
	Mob mob3_1;
	Mob mob3_2;
	Mob mob3_3;
	Mob mob3_4;
	Mob mob3_5;
	Mob boss;
	// koniec mobow

	int x = 0, y = 0;
	int return_map = map.Load1map();

	map_generator(map);
	map.ShowMap();

	while (1)	//głowna petla gry
	{
		system("cls");
		map.ShowMap();

		//Osługa klawiatury
		int a = _getch();
		switch (a)
		{
		case 'w':
			map.playerPos = Point(map.playerPos.x, map.playerPos.y - 1);
			if(map.playerPos.y < 1)
				map.playerPos = Point(map.playerPos.x, 1);
			break;
		case 's':
			map.playerPos = Point(map.playerPos.x, map.playerPos.y + 1);
			if (map.playerPos.y > map.mapSize.y - 1)
				map.playerPos = Point(map.playerPos.x, map.mapSize.y - 1);
			break;
		case 'a':
			map.playerPos = Point(map.playerPos.x - 1, map.playerPos.y);
			if (map.playerPos.x < 1)
				map.playerPos = Point(1, map.mapSize.y);
			break;
		case 'd':
			map.playerPos = Point(map.playerPos.x + 1, map.playerPos.y);
			if (map.playerPos.x > map.mapSize.x - 1)
				map.playerPos = Point(map.playerPos.x - 1, map.mapSize.y);
			break;
		case 'i':
			player.ShowInventory();
			break;
		case 'j':
			player.ShowStats();
			break;
		}
		
		

		y = map.playerPos.x;
		x = map.playerPos.y;

		Mob_stats(player, mob1_1, mob1_2, mob1_3, mob1_4, mob1_5,	//aktualizowanie statow mobow
			mob2_1, mob2_2, mob2_3, mob2_4, mob2_5,
			mob3_1, mob3_2, mob3_3, mob3_4, mob3_5, boss);
		
		cout<<endl << map.map[x][y] << endl;
		if (map.map[x][y] == '.')			//puste pole
		{
			// możliwość otwarcia eq
			// wyświetlenie mapy z oznaczeniem gdzie jest postać
		}
		if (map.map[x][y] == 'X')		//walka
		{
			cout << "Na swojej drodze spotkałeś potwora, musisz stanąć z nim do walki!" << endl;
			int pom1, pom2, pom3;
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
				break; //pokonanie bossa, wyjscie z glownej petli gry
		}
		
		if (map.map[x][y] == 'H')		//baza
		{

		}
		else if (map.map[x][y] == 'N')		//npc
		{

		}
		else if (map.map[x][y] == 'S')		//sklep
		{
			Shop(player);
		}
		else if (map.map[x][y] == 'P')		//przejście
		{

		}
		else if (player.xp >= player.xpToNextLvl)	//lvl up
		{
			player.xp -= player.xpToNextLvl;
			player.xpToNextLvl = (int)player.xpToNextLvl * 1.5;
		}
		//cout << "Brawo, udało ci się ukończyć grę!" << endl;
	}
}


int main()
{
	srand(time(NULL));

	GenerateWindow();
	Font(); //zmiana rodzaju oraz wielkosci czcionki
	
	Player player;
	
	vector<string> s;
	s.push_back("1 Rozpocznij nowa gre");
	s.push_back("2 Wczytaj zapis");
	s.push_back("3 wyjdz");

	//TU ZACZYNA SIE GRA

	Map map;
	map.Load1map();
	
	while (1)//główna 
	{
		switch (DrawMenu(s))
		{
		case 0: //poczatek gry
			player.inventory.push_back(new Item("PRzedmiot", "Przedmiot Testpwy", 0.1f, 1));
			player.inventory.push_back(new Weapon("Miecz jednoręczny", "", 1.5f, 3000, 5, 3, 0.1, 1));
			player.inventory.push_back(new Armor("Zbroja", "", 3.0f, 5000, 5, 1));
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