#pragma once
#include <iostream>
#include "point.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();
	void ShowMap(Point& playerPos);
	void Go(char d);
	float Distance(Point p1, Point p2);
	float Propability(Point p1, Point p2);
	bool IsFight();

	int ShowPlace();
	int Load1map();
	int Load2map();
	int Load3map();

	string map[12];

	Point mapSize = Point(10, 10);
private:

};