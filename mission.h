#pragma once
#include <iostream>
#include "point.h"
#include "item.h"

using namespace std;

class Mission
{
public:
	Mission();
	Mission(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem);
	~Mission();

	bool IsOnMissionPoint(Point &playerPos);
	//virtual void ShowMessege();
	virtual bool IsMissionDone(Point& playerPos);
	virtual void CreateQuest();
	Point missionPoint = { 5,5 };
	
	string name;
	string desc;

	int needLvl = 0;
	int gainXp = 10;
	int gainMoney = 0;

	Item neededItem;
	Item revardItem;

	Point point;

private:

};

class KillQuest : Mission
{
public:
	KillQuest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem, int _mobType, int _quantity);
	~KillQuest();
	bool IsMissionDone(Point& playerPos);
	void CreateQuest();

private:
	int mobType = 0;
	int quantity = 0;
};


class DeliverQuest : Mission
{
public:
	DeliverQuest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem);
	~DeliverQuest();
	bool IsMissionDone(Point& playerPos);
	void CreateQuest();

private:

};

