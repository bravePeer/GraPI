#include "map.h"

Map::Map()
{
	/*map[0] = "+------------------------+";
	map[1] = "|A.......................|";
	map[2] = "|.......B.......A........|";
	map[3] = "|........................|";
	map[4] = "|..A.....................|";
	map[5] = "|........................|";
	map[6] = "|........................|";
	map[7] = "|........A...............|";
	map[8] = "|........................|";
	map[9] = "+------------------------+";
	map[10] = "|...N.....S.............P|";
	map[11] = "+-----------------------+";*/
}

Map::~Map()
{
	//delete anomalies;
}

int Map::Load1map()
{
	map[0] =  "+-------------------+";
	map[1] =  "|H.............N....|";
	map[2] =  "|.....S.............|";
	map[3] =  "|...................|";
	map[4] =  "|...................|";
	map[5] =  "|...................|";
	map[6] =  "|...................|";
	map[7] =  "|...............N...|";
	map[8] =  "|...................|";
    map[9] =  "|...................|";
   map[10] =  "|...N.....S........P|";
   map[11] =  "+-------------------+";
   mapSize = Point(22,12);
   return 1;
/*
   h-home
   N-npc
   S sklep
   P przejscie
   */
}

int Map::Load2map()
{
	map[0] =  "+-------------------+";
	map[1] =  "|N..................|";
	map[2] =  "|...............N...|";
	map[3] =  "|.........|.........|";
	map[4] =  "|.........|.........|";
	map[5] =  "|.........|.........|";
	map[6] =  "|.........|......S..|";
	map[7] =  "|.........|.........|";
	map[8] =  "|.....S...|.........|";
    map[9] =  "|.........|...N.....|";
   map[10] =  "|p........|........H|";
   map[11] =  "+-------------------+";
   mapSize = Point(22,12);
   return 2;
/*
   h-home
   N-npc
   S sklep
   P przejscie
   */
}

int Map::Load3map()
{
	map[0] =  "+-------------------+";
	map[1] =  "|..S...............B|";
	map[2] =  "|...............N...|";
	map[3] =  "|......_____________|";
	map[4] =  "|...................|";
	map[5] =  "|...N...............|";
	map[6] =  "|...................|";
	map[7] =  "|______________.....|";
	map[8] =  "|...N...............|";
    map[9] =  "|...................|";
   map[10] =  "|H..........S.......|";
   map[11] =  "+-------------------+";
   mapSize = Point(22,12);
   return 3;
/*
   h-home
   N-npc
   S sklep
   P przejscie
   b- boss
   */
}

/*Wyswietla mape*/
void Map::ShowMap()
{
	for (int i = 0; i < mapSize.y; i++)
	{
		for (int j = 0; j < mapSize.x; j++)
		{
			//if (playerPos.y == i && playerPos.x == j)
				//cout << "T";
			//else
			cout << map[i][j] << "";
		}
		cout << endl;
	}
	cout << "Pozycja x: " << playerPos.x << " y: " << playerPos.y << endl;
}

/*Ruch gracza*/
void Map::Go(char d)
{

}

/*Dystans miedy 2 punktami*/
float Map::Distance(Point p1, Point p2)
{
	Point p = p1 - p2;
	return sqrtf((p.x * p.x) + (p.y * p.y));
}

/*Prawdopodobienstwo pojawienia walki*/
float Map::Propability(Point p1, Point p2)
{
	return Distance(p1, p2) / Distance(Point(0, 0), mapSize);
}

bool Map::IsFight()
{
	return rand() % 100 + 1 <= Propability(playerPos, Point(8, 2)) * 100 ? true : false;
}

int Map::ShowPlace()
{
	switch (map[playerPos.y][playerPos.x])
	{
	case 'A':
		cout << "Anomalia" << endl;
		cout << "1 -> Szukaj artefaktu" << endl;
		return anomalia;
		break;
	case 'B':
		cout << "Baza" << endl;
		cout << "1 -> Idz do szefa" << endl;
		cout << "2 -> Idz do sprzedawcy" << endl;
		cout << "3 -> Idz do lekarza" << endl;
		cout << "s -> Zapisz gre" << endl;
		cout << "q -> Zapisz i wyjdz" << endl;
		return baza;
		break;
	}
	return 0;
}
