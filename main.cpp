#include <iostream>
#include <time.h>
#include <conio.h>
#include "person.h"
#include "player.h"
#include "item.h"
#include "map.h"
//tetuje \/
#include "something.h"
using namespace std;

void map_generator(Map& map)
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
		else {
			map.map[x][y] = 'X';
			x = 0;
			y = 0;
		}
	}
}


/*
	bronie.txt
	string [12]
	string[0] = ########################
	#........r..........d..#
	#...................d..#
	#........r..........d..#
	########################
	string buf;

	for ()
	file >> buf;
	cout << buf;
*/

int fight(int player_attack, int player_hp, int enemy_attack, int enemy_hp, int mana)
{
	int tura = 1;
	char help;
	while (player_hp > 0 || enemy_hp)
	{
		cout << "Tura: " << tura << endl;
		cout << "HP twojego bohatera: " << player_hp << endl;
		cout << "HP przeciwnika: " << enemy_hp << endl;
		cout << endl;
		cout << "Wybierz atak!" << endl;
		cout << "1 - zwykły atak" << endl;
		cout << "2 - umiejętność specjalna" << " (potrzeba 4pkt many) " << mana << "/4" << endl;
		cout << ":";
		cin >> help;
		cout << endl;

		for (int i = 0;i < 1;i++)
		{
			switch (help)
			{
			case'1':
				enemy_hp = enemy_hp - player_attack;
				cout << "Zadajesz: " << player_attack << " pkt obrażeń" << endl;
				continue;

			case'2':
				// enemy_hp-=player_skill(mana,player_attack);
				if (mana != 4)
				{
					cout << "nie masz many aby wykonać ten atak, zamiast tego atakujesz podstawowym atakiem" << endl;
				}
				//  cout<<"Zadajesz: "<<player_skill(mana,player_attack)<<" pkt obrażeń"<<endl;
				cout << endl;
				//   player_skill(mana,player_attack);
				mana = 0;
			}
		}
		if (mana < 4) mana++;
		cout << endl;
		if (enemy_hp <= 0)
		{
			cout << "Brawo wygrałeś tę walkę!" << endl;
			break;
		}

		cout << endl;
		cout << "Twój przeciwnik uderza..." << endl;
		cout << endl;
		Sleep(1000);
		player_hp = player_hp - enemy_attack;
		cout << "Zadaje ci: " << enemy_attack << " pkt obrażeń" << endl;

		if (player_hp <= 0)
		{
			cout << "Niestety przegrałeś walkę..." << endl;
			//trzeba dodac zeby resetowalo hp i cofalo do innego spota
			break;
		}

		tura++;
		// console_clean();
	}
	return 1;
}

int main()
{
	srand(time(NULL));

	GenerateWindow();

	Player player;

	player.inventory.push_back(new Item("PRzedmiot", "Przedmiot Testpwy", 0.1f, 1));
	player.inventory.push_back(new Weapon("Miecz jednoręczny", "", 1.5f, 3000, 5, 3, 0.1, 1));
	player.inventory.push_back(new Armor("Zbroja", "", 3.0f, 5000, 5, 1));

	while (1)
	{
		player.ShowInventory();

		player.ShowStats();
		_getch();
	}

	vector<string> s;
	s.push_back("1 Rozpocznij nowa gre");
	s.push_back("2 Wczytaj zapis");
	s.push_back("3 wyjdz");

	//TU ZACZYNA SIE GRA

	Map map;
	map.Load1map();
	map.ShowMap();

	map_generator(map);

	map.ShowMap();
	int x = 2, y = 2;

	while (1)//główna 
	{
		switch (DrawMenu(s))
		{
		case 0: //poczatek gry

			break;
		case 1:	//wczytanie zapisu
			break;
		case 2:	//wyjscie
			break;

		}

		if (map[x][y] == ".")			//puste pole
		{

		}
		else if (map[x][y] == "X")		//walka
		{

		}
		else if (map[x][y] == "H")		//baza
		{

		}
		else if (map[x][y] == "N")		//npc
		{

		}
		else if (map[x][y] == "S")		//sklep
		{

		}
		else if (map[x][y] == "P")		//przejście
		{

		}
		else if (map[x][y] == "")		//poza zakresem mapy
		{

		}
	}

	return 0;
}