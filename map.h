#pragma once
#include <iostream>
#include "point.h"

using namespace std;

enum MapLocations
{
	nic,
	baza,
	anomalia
};

class Map
{
public:
	Map();
	~Map();
	void ShowMap();
	void Go(char d);
	float Distance(Point p1, Point p2);
	float Propability(Point p1, Point p2);
	bool IsFight();

	int ShowPlace();
	void Load1map();
	void Load2map();
	void Load3map();

	string map[12];

	Point playerPos = Point(8, 2);
	Point mapSize = Point(10, 10);
	Point* anomalies = new Point[10];
private:

};