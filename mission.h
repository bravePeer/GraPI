#pragma once
#include <iostream>
#include "point.h"
#include "item.h"

using namespace std;

class Mission
{
public:
	Mission(string _name);
	~Mission();

	bool IsOnMissionPoint(Point &playerPos);
	virtual void ShowMessege();

	Point missionPoint = { 5,5 };
	
	string name;
	string desc;

	int needLvl = 0;
	int gainXp = 10;
	int gainMoney = 0;

	Item neededItem;
	Item gainItem;

private:

};
