#include "map.h"

Map::Map()
{

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

int Map::LoadVMap(Point& position)
{
	return 0;
}

void Map::ShowMap()
{
	for (int i = 1; i < mapSize.y; i++)
	{
		for (int j = 1; j < mapSize.x; j++)
		{
			CDrawText("", { (short)j, (short)i }, 0x0003);
			cout << map[i][j] ;
		}
		//cout << endl;
	}
	CDrawText(L"\u2229", { (short)nextMap.x, (short)nextMap.y }, 0x0006);
	CDrawText(L"\u2229", { (short)prevMap.x, (short)prevMap.y }, 0x0006);
}

/*Wyswietla mape i moby*/
void Map::ShowMap(Point& playerPos)
{
	CDrawText(buf, { (short)lastPlayerPos.x,(short)lastPlayerPos.y }, 0x0003);
	buf = map[playerPos.y][playerPos.x];
	lastPlayerPos = playerPos;

	CDrawText(L"\u1d25", { (short)playerPos.x,(short)playerPos.y }, 0x0002);
	CDrawText("Pozycja x: " + to_string(playerPos.x) + " y:" + to_string(playerPos.y), { 10,0 }, 0x0003);

	for (int i = 0; i < mobs.size(); i++)
	{
		CDrawText(L"\u0230", { (short)mobs[i]->position.x,(short)mobs[i]->position.y }, 0x0004);
	}
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

bool Map::CanMove(Point &point)
{
	if (map[point.y][point.x] == '|' || map[point.y][point.x] == '-' ||
		map[point.y][point.x] == '_' || map[point.y][point.x] == '+' ||
		map[point.y][point.x] == '/' || map[point.y][point.x] == 'L' ||
		map[point.y][point.x] == '@' || map[point.y][point.x] == 'I' ||
		map[point.y][point.x] == 'b' || map[point.y][point.x] == 'd'  )
	{
		return false;
	}
	return true;
}

bool Map::MoveToHome(int x,int y)
{
	
	return true;
}

bool Map::IsNextMap(Point& point)
{
	if (nextMap == point)
		return true;
	return false;
}

bool Map::IsPrevMap(Point& point)
{
	if (prevMap == point)
		return true; 
	return false;
}

void Map::GenerateMobs(int level, Point p1, Point p2, int quantity)
{
	int x, y;
	Mob mbo;
	Mob boss;
	for (int i = 0; i < quantity;i++)
	{
		 x = p1.x + rand() % (p2.x - p1.x);
		 y = p1.y + rand() % (p2.y - p1.y);
		 if    (map[y][x] == 'H' || map[y][x] == 'S' || map[y][x] == 'N'
			 || map[y][x] == 'P' || map[y][x] == '|' || map[y][x] == 'B'
			 || map[y][x] == '-' || map[y][x] == '_' || map[y][x] == '%'
			 || map[y][x] == ' ' || map[y][x] == '@' || map[y][x] == 'I'
			 || map[y][x] == '+' || map[y][x] == '[' || map[y][x] == ']'
			 || map[y][x] == 'o' || map[y][x] == '#' || map[y][x] == 'L')
		 {
			 i--;
			 continue;
		 }
		else		  
		{
			 mobs.push_back(new Mob(mbo.MobStats(level, 1)));

			 mobs[i]->position = { x,y };
				 
		/*	 if (map[x][y] == '1'&& mapID==1)					//dopisać znaczki minibossa i bossa
			 {
				 mobs.push_back(new Mob(boss.MobStats(level,1)));
			 }
			 else if (map[x][y] == '1'&& mapID==2)
			 {
				mobs.push_back(new Mob(boss.MobStats(level,2)));
			 }
			 else if (map[x][y] == '1'&& mapID==3)
			 {
				mobs.push_back(new Mob(boss.MobStats(level,3)));
			 }
			// map[x][y] = 'X';
			if ( mobs.size() > 0)
			{
				 mobs[ mobs.size() - 1]->position = { x,y };
			}*/

			x = 0;
			y = 0;
		}
	}
}
/*
int Map::LoadMap(int id, Point& point)
{
	switch (id)
	{
	case 0:
		return LoadHome(  point);
		break;
	case 1:
		return Load1map(  point);
		break;
	case 2:
		return Load2map(  point);
		break;
	case 3:
		return Load3map(  point);
		break;
	}
}*/

