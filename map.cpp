﻿#include "map.h"

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

int Map::LoadHome(Point& position)
{
	map[0] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[1] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[2] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[3] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[4] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[5] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[6] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[7] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[8] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[9] =  "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[10] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[11] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[12] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[13] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[14] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[15] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[16] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[17] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%+-----------------+%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[18] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|  |L             |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[19] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|   |L            |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[20] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%+-------+      +--|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[21] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|                 |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[22] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%| bed.        [o] |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[23] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%+-----------------+%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[24] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[25] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[26] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[27] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[28] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[29] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[30] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[31] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[32] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[33] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[34] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[35] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[36] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[37] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[38] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[39] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	map[40] = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
	mapSize = Point(106, 41);
	
	position = {47,22};		//pozycja gracza
	nextMap =  {61,19};		//przejscie do nastepnej mapy
	
	

	return 0;
	
							/*Teoretycznie moby czysci*/
	/*for (int i = 0; i < mobs.size(); i++)
	{
		delete mobs[i];
	}
	mobs.clear();
	for (int i = 0; i < people.size(); i++)
	{
		delete people[i];
	}
	people.clear();
	*/
}

int Map::Load1map(Point& position)
{
	map[0] =  "----------------------------------------------------------------------------------------------------------";
	map[1] =  ".H....S........N..........................................................................................";
	map[2] =  "...____...................................................................................................";
	map[3] =  "..+----+..................................................................................................";
	map[4] =  "..|....|..................................................................................................";
	map[5] =  "..........................................................................................................";
	map[6] =  "..........................................................................................................";
	map[7] =  "....._______....N.........................................................................................";
	map[8] =  "..............|...........................................................................................";
	map[9] =  "..............|...........................................................................................";
	map[10] = "....N.....S...|...........................................................................................";
	map[11] = "..........................................................................................................";
	map[12] = "..........................................................................................................";
	map[13] = "..........................................................................................................";
	map[14] = "..........................................................................................................";
	map[15] = "..........................................................................................................";
	map[16] = "..........................................................................................................";
	map[17] = "..........................................................................................................";
	map[18] = ".................................................................................................___......";
	map[19] = "................................................................................................|[o]|.....";
	map[20] = "...............................................................................................|||||||....";
	map[21] = "..............................................................................................|       |...";
	map[22] = ".............................................................................................|         |..";
	map[23] = "............................................................................................|           |.";
	map[24] = "...........................................................................................|             |";
	map[25] = "..........................................................................................|               ";
	map[26] = ".........................................................................................|                ";
	map[27] = "........................................................................................|                 ";
	map[28] = ".......................................................................................|                  ";
	map[29] = "......................................................................................|                   ";
	map[30] = ".....................................................................................|                    ";
	map[31] = "....................................................................................|                     ";
	map[32] = "...................................................................................|                      ";
	map[33] = "..................................................................................|                       ";
	map[34] = ".................................................................................|                        ";
	map[35] = "................................................................................|               ###       ";
	map[36] = "...............................................................................|_____           ###       ";
	map[37] = ".....................................................................................----______-###_______";
	map[38] = "..........................................................................................................";
	map[39] = "..........................................................................................................";
	map[40] = "................................................................................................_______---";
	mapSize = Point(106,41);

	position = {6,5};		//pozycja gracza
	nextMap =  {105,39};	//przejscie do nastepnej mapy
	prevMap =  {6,4};		//powrot do poprzedniej mapy

	return 1;
/*
   h-home
   N-npc
   S sklep
   P przejscie
   */
}

int Map::Load2map(Point& position)
{
	map[0] = "+--------------------------------------------------------------------------------------------------------+";
	map[1] = ".N.............................................|  ~    ~|.......................................@@@@...@@@";
	map[2] = "................N..............................|~    ~  |......................................@@@@@@...@@";
	map[3] = "...............................................|  ~    |........................................@@@@......";
	map[4] = "..............................................| ~    ~ |.........................................II..@@@@.";
	map[5] = ".............................................| ~   ~    |...........................................@@@@@@";
	map[6] = ".................S............................|  ~   ~ |.............................................@@@@.";
	map[7] = ".............................................| ~   ~    |.............................................II..";
	map[8] = "......S.....................................|~    ~  ~ |..................................................";
    map[9] = "..............N.............................|  ~   ~  ~|..................................................";
   map[10] = "...................H.........................|    ~   |...................................................";
   map[11] = "..............................................| ~    ~|...................................................";
   map[12] = "..............................................|~   ~   |..................................................";
   map[13] = "..............................................|  ~  ~ |...................................................";
   map[14] = ".............................................+---------+..................................................";
   map[15] = ".............................................============..Miniboss.......................................";
   map[16] = ".............................................+-----------+................................................";
   map[17] = "..............................................| ~     ~ |.................................................";
   map[18] = "...............................................|    ~    |................................................";
   map[19] = "................................................| ~  ~  ~ |...............................................";
   map[20] = "..................................................|   ~    |..............................................";
   map[21] = "....................................................|   ~   +.............................................";
   map[22] = ".....................................................| ~   ~ -___.........................................";
   map[23] = ".......................................................| ~   ~   |........................................";
   map[24] = ".........................................................|  ~  ~  |................................_______";
   map[25] = "|.........................................................|  ~  ~  |...........___________---------       ";
   map[26] = " |.........................................................|     ~  +---------- ~         ~       ~     ~ ";
   map[27] = "  |.........................................................+  ~  ~        ~        ~        ~       ~    ";
   map[28] = "   |.........................................................-______    ~      ~        ~      ~  ________";
   map[29] = "    |...............................................................______      ~    ____________-........";
   map[30] = "     |....................................................................._________......................";
   map[31] = "      |...................................................................................................";
   map[32] = "       |..................................................................................................";
   map[33] = "        |.................................................................................................";
   map[34] = "         |................................................................................................";
   map[35] = "          |...............................................................................................";
   map[36] = "          _|..............................................................................................";
   map[37] = "       __--...............................................................................................";
   map[38] = "-------...................................................................................................";
   map[39] = "..........................................................................................................";
   map[40] = "-------...................................................................................................";
   mapSize = Point(106,41);

   position =  {3,39};		//pozycja gracza
   nextMap  =  {105,3};		//przejscie do nastepnej mapy
   prevMap  =  {2,39};		//powrot do poprzedniej mapy
   return 2;
/*
   h-home
   N-npc
   S sklep
   P przejscie
*/
}

int Map::Load3map(Point& position)
{
	map[0] =  "+--------------------------------------------------------------------------------------------------------+";
	map[1] =  "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[2] =  "@@.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[3] =  "I....II@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[4] =  "........II.@@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[5] =  ".........@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[6] =  ".@@......@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[7] =  ".@@@.......@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[8] =  "@@@@@@@..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[9] =  ".@@@..@@@@...@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[10] = ".@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[11] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[12] = ".@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[13] = ".@@@..@@@@...@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[14] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[15] = ".@@@..@@@@...@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[16] = ".@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[17] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[18] = ".@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[19] = ".@@@..@@@@...@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[20] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[21] = ".@@@..@@@@...@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[22] = ".@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[23] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[24] = ".@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[25] = ".@@@..@@@@...@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[26] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[27] = ".@@@..@@@@...@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[28] = ".@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[29] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[30] = ".@@@..@@@@...@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[31] = ".@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[32] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[33] = ".@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
	map[34] = ".@@@..@@@@...@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
	map[35] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[36] = "@.@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.";
	map[37] = ".@@@@..@@@@II.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@";
	map[38] = "@@@@@@@@@@@@(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	map[39] = " @@@@  @@@@   @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@@@ @@";
	map[40] = "..II....II.....II...II...II...II...II...II...II...II...II...II...II...II...II...II...II...II...II...II...I";
	mapSize = Point(106, 41);
	position = {4,3};		//pozycja gracza
	//nextMap	= {x,y}		//przejscie do nastepnej mapy
	prevMap =  {3,3};		//powrot do poprzedniej mapy
    return 3;
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
	CDrawText(L"\u220f", { (short)nextMap.x, (short)nextMap.y }, 0x0001);
	CDrawText(L"\u2229", { (short)prevMap.x, (short)nextMap.y}, 0x0006);
}

/*Wyswietla mape i moby*/
void Map::ShowMap(Point& playerPos)
{
	CDrawText(buf, { (short)lastPlayerPos.x,(short)lastPlayerPos.y }, 0x0003);
	buf = map[playerPos.y][playerPos.x];
	lastPlayerPos = playerPos;

	CDrawText(L"\u1d25", { (short)playerPos.x,(short)playerPos.y }, 0x0004);
	CDrawText("Pozycja x: " + to_string(playerPos.x) + " y:" + to_string(playerPos.y), { 10,0 }, 0x0003);

	for (int i = 0; i < mobs.size(); i++)
	{
		CDrawText(L"\u1d6a", { (short)mobs[i]->position.x,(short)mobs[i]->position.y }, 0x000c);
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

bool Map::CanMove(Point &point)
{
	if(	  map[point.y][point.x]=='|'  || map[point.y][point.x]=='-' || map[point.y][point.x]=='_' ||
		  map[point.y][point.x]=='+'  || map[point.y][point.x] == '/' ||
	      map[point.y][point.x] == 'L'|| map[point.y][point.x] =='@'|| map[point.y][point.x] =='I' )
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
	else 
	return false;
}

void Map::GenerateMobs(int level)
{
	int x, y;
	Mob mbo;
	for (int i = 0; i < 20;i++)
	{
		y = 1 + rand() % mapSize.x;
		x = 1 + rand() %  mapSize.y;
		if ( map[x][y] == 'H' ||  map[x][y] == 'S' ||  map[x][y] == 'N'
			||  map[x][y] == 'P' ||  map[x][y] == '|' ||  map[x][y] == 'B'
			||  map[x][y] == '-' ||  map[x][y] == '_' ||  map[x][y] == '%'
			||  map[x][y] == ' ' ||  map[x][y] == '@' ||  map[x][y] == 'I'
			||  map[x][y] == '+' ||  map[x][y] == '[' ||  map[x][y] == ']'
			||  map[x][y] == 'o' ||  map[x][y] == '#' ||  map[x][y] == 'L')
		{
			i--;
			continue;
		}
		else
		{
			
			 mobs.push_back(new Mob(mbo.MobStats(level, 1)));
			// map[x][y] = 'X';
			if ( mobs.size() > 0)
			{
				 mobs[ mobs.size() - 1]->position = { y,x };
			}

			x = 0;
			y = 0;
		}
	}
}

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
}


