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

	int ShowPlace();
	int Load1map();
	int Load2map();
	int Load3map();
	int LoadHome();

	string map[41] = { "" };
	string buf = "";
	Point mapSize = Point(10, 10);
	Point lastPlayerPos;

	/*Trzyma NPC i moby*/
	vector<Mob*> mobs;
	vector<Person*> people;

	bool CanMove(Point& point);
	bool MoveToHome(int x,int y);
private:

};