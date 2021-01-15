#pragma once
#include <iostream>
#include <string>
#include "point.h"
#include "something.h"
#include "person.h"
#include "mob.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();
	void ShowMap(Point& playerPos);
	void ShowMap( );

	int IsFight(Point& playerPos);
	void KillMob(int pos);

	//int LoadMap(int id, Point& point);
	//int ShowPlace(Point& position);
	virtual int LoadVMap(Point& position);

	string map[41] = { "" };
	string buf = "";
	Point mapSize = Point(10, 10);
	Point lastPlayerPos;
	Point nextMap = { 0,0 };
	Point prevMap = { 0,0 };
	int mapID = -1;

	/*Trzyma NPC i moby*/
	vector<Mob*> mobs;
	vector<Person*> people;

	bool CanMove(Point& point);
	bool MoveToHome(int x,int y);
	bool IsNextMap(Point& point);
	bool IsPrevMap(Point& point);
	/*p1,p2 punkty tworzoce obszar generowania sie mobow*/
	void GenerateMobs(int level, Point p1, Point p2, int quantity);
private:

};

class MapHome : public Map
{
	int LoadVMap(Point& position)
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

		nextMap = { 61,19 };		//przejscie do nastepnej mapy
		prevMap = { 61,19 };

		
		position = { 47,22 }; //pozycja gracza na starcie
		 
		if (position.x == 5 && position.y == 4)
			position = { 62,19 }; //pozycja po powrocie
		mapID = 0;

	return 0;
	}
	//int

};

class Map1 : public Map
{
	int LoadVMap(Point& position)
	{
		map[0]  = "----------------------------------------------------------------------------------------------------------";
		map[1]  = ".H....S........N..........................................................................................";
		map[2]  = "..._--_...................................................................................................";
		map[3]  = "..+----+..................................................................................................";
		map[4]  = "..|....|..................................................................................................";
		map[5]  = "..........................................................................................................";
		map[6]  = "..........................................................................................................";
		map[7]  = "................N.........................................................................................";
		map[8]  = "..........................................................................................................";
		map[9]  = "..........................................................................................................";
		map[10] = "....N.....S...............................................................................................";
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
		mapSize = Point(106, 41);

		nextMap = { 105,39 };	//przejscie do nastepnej mapy
		prevMap = { 5,4 };		//powrot do poprzedniej mapy

		if (position.x == 61 && position.y == 19)
			position = { 5,5 };		//pozycja gracza przy przejsciu
		else if (position.x == 2 && position.y == 39)
			position = { 104, 39 };	//pozycja przy powrocie

mapID =  1;
		return 1;
	}

};

class Map2 : public Map
{
	int LoadVMap(Point& position)
	{
		map[0] =  "+--------------------------------------------------------------------------------------------------------+";
		map[1] =  "...............................................|  ~    ~|.......................................@@@@...@@@";
		map[2] =  "...............................................|~    ~  |......................................@@@@@@...@@";
		map[3] =  "...............................................|  ~    |........................................@@@@......";
		map[4] =  "..............................................| ~    ~ |.........................................II..@@@@.";
		map[5] =  ".............................................| ~   ~    |...........................................@@@@@@";
		map[6] =  "..............................................|  ~   ~ |.............................................@@@@.";
		map[7] =  ".............................................| ~   ~    |.............................................II..";
		map[8] =  "............................................|~    ~  ~ |..................................................";
		map[9] =  "............................................|  ~   ~  ~|..................................................";
		map[10] = ".............................................|    ~   |...................................................";
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
		mapSize = Point(106, 41);

		
		nextMap = { 105,3 };		//przejscie do nastepnej mapy
		prevMap = { 2,39 };		//powrot do poprzedniej mapy

		if (position.x == 105 && position.y == 39)
			position = { 3,39 };		//pozycja gracza na przejsciu
		else if (position.x == 3 && position.y == 3)
			position = { 104, 3 };		//pozycja przy powrocie
		mapID = 2;
		return 2;
	}
};

class Map3 : public Map
{
	int LoadVMap(Point& position)
	{
		map[0]  = "+--------------------------------------------------------------------------------------------------------+";
		map[1]  = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[2]  = "@@..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[3]  = "I....II@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@";
		map[4]  = ".......@II@@@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@";
		map[5]  = "@......@@@@@@@@...............@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[6]  = "@@......@@@@@@......@@@@@@..@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@@.@@@.@@@@";
		map[7]  = "@@@.....@@@@@@.....@@@@@@@@..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[8]  = "@@@....@@@@@@@@....@@@@@@@@...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[9]  = "@@@....@@@@@@@@.....@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[10] = "@@@.....@@@@@@........II......@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[11] = "@@@.....@@@@@@................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[12] = "@@@....@@@@@@@@.....@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[13] = "@@@....@@@@@@@@....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[14] = "@@@.....@@@@@@.....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[15] = "@@@.....@@@@@@......@@@@@@.....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[16] = "@@@....@@@@@@@@....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[17] = "@@@....@@@@@@@@....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[18] = "@@@.....@@@@@@......@@@@@@.....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[19] = "@@@.....@@@@@@.....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[20] = "@@@....@@@@@@@@....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[21] = "@@@....@@@@@@@@.....@@@@@@.....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[22] = "@@@.....@@@@@@.....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[23] = "@@@.....@@@@@@.....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[24] = "@@@....@@@@@@@@.....@@@@@@.....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[25] = "@@@....@@@@@@@@....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[26] = "@@@.....@@@@@@.....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[27] = "@@@.....@@@@@@......@@@@@@.....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[28] = "@@@....@@@@@@@@....@@@@@@@@....@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[29] = "@@@....@@@@@@@@....@@@@@@@@....@@@@@@@@...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[30] = "@@@.....@@@@@@......@@@@@@.....@@@@@@@@...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[31] = "@@@.....@@@@@@.....@@@@@@@@....@@@@@@@.....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[32] = "@@@....@@@@@@@@....@@@@@@@@....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[33] = "@@@....@@@@@@@@.....@@@@@@.....@@@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[34] = "@@@@....@@@@@@........II........@@@@@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[35] = "@@@@@.....II.......@@@@@@@@.......II.....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[36] = ".@@@@@@........@@@@@@.@@@@@@.@@........@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.";
		map[37] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[38] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		map[39] = ".@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.@@@@@@.";
		map[40] = "...II.....II.....II.....II.....II.....II.....II.....II.....II.....II.....II.....II.....II.....II.....II...";
		mapSize = Point(106, 41);

		position = { 4,3 };		//pozycja gracza
		//nextMap	= {x,y}		//przejscie do nastepnej mapy
		prevMap = { 3,3 };		//powrot do poprzedniej mapy
		mapID = 3;
		return 3;
	}
};
