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
	for (int i = 0; i < mobs.size(); i++)
	{
		delete mobs[i];
	}
	mobs.clear();
	for (int i = 0; i < people.size(); i++)
	{
		delete people[i];
	}
	people.clear();
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
void Map::ShowMap(Point& playerPos)
{
	CDrawText(" ", { 0,0 }, 0x0007);

	for (int i = 0; i < mapSize.y; i++)
	{
		for (int j = 0; j < mapSize.x; j++)
		{
			if (playerPos.y == i && playerPos.x == j)
				cout << "T";
			else
			cout << map[i][j] << "";
		}
		cout << endl;
	}
	CDrawText("Pozycja x: " + to_string(playerPos.x) + " y:" + to_string(playerPos.y), { 10,0 }, 0x0003);
	for (int i = 0; i < mobs.size(); i++)
	{
		CDrawText("X", { (short)mobs[i]->position.x,(short)mobs[i]->position.y }, 0x000c);
	}
}

/*Dystans miedy 2 punktami*/
float Map::Distance(Point p1, Point p2)
{
	Point p = p1 - p2;
	return sqrtf((p.x * p.x) + (p.y * p.y));
}

/*Czy walka*/
int Map::IsFight(Point &playerPos)
{
	for (int i = 0; i < mobs.size(); i++)
	{
		if (mobs[i]->position.x == playerPos.x && mobs[i]->position.y == playerPos.y)
			return i + 1;
	}
	return 0;
}
/*Zabicie moba*/
void Map::KillMob(int pos)
{
	delete mobs[pos];
	mobs.erase(mobs.begin() + pos);
}
