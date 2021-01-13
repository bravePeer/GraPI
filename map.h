#pragma once
#include <iostream>
#include <string>
#include "point.h"
#include "something.h"
#include "mob.h"
#include "person.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();
	void ShowMap(Point& playerPos);
	void ShowMap( );
	void Go(char d);
	float Distance(Point p1, Point p2);
	float Propability(Point p1, Point p2);

	int IsFight(Point& playerPos);
	void KillMob(int pos);

	int LoadMap(int id, Point& point);
	//int ShowPlace(Point& position);
	int Load1map(Point& position);
	int Load2map(Point& position);
	int Load3map(Point& position);
	int LoadHome(Point& position);

	string map[41] = { "" };
	string buf = "";
	Point mapSize = Point(10, 10);
	Point lastPlayerPos;
	Point nextMap = { 0,0 };


	/*Trzyma NPC i moby*/
	vector<Mob*> mobs;
	vector<Person*> people;

	bool CanMove(Point& point);
	bool MoveToHome(int x,int y);
	bool IsNextMap(Point& point);
private:

};

void map_generator(Player& player, Map& map);
Mob MobStats(Player& player, int return_map);