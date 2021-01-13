#include "mission.h"

Mission::Mission()
{
}

Mission::Mission(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem)
{
	name = _name;
	point = _point;
	missionPoint = _point;
	needLvl = _needLvl;
	gainXp = _gainXp;
	gainMoney = _gainMoney;
	neededItem = _neededItem;
	revardItem = _revardItem;
}

Mission::~Mission()
{
}

bool Mission::IsOnMissionPoint(Point& playerPos)
{
	if (playerPos == missionPoint)
		return true;
	return false;
}

bool Mission::IsMissionDone(Point& playerPos)
{
	cout << "eeeeeee" << endl;
	return 1;
}

void Mission::CreateQuest()
{
}

KillQuest::KillQuest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem, int _mobType, int _quantity)
{
	name = _name;
	point = _point;
	missionPoint = _point;
	needLvl = _needLvl;
	gainXp = _gainXp;
	gainMoney = _gainMoney;
	neededItem = _neededItem;
	revardItem = _revardItem;
	mobType = _mobType;
	quantity = _quantity;
}

KillQuest::~KillQuest()
{
}

bool KillQuest::IsMissionDone(Point& playerPos)
{
	if (quantity <= 0)
		return true;
	return false;
}

void KillQuest::CreateQuest()
{
}


DeliverQuest::DeliverQuest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem)
{
	name = _name;
	point = _point;
	missionPoint = _point;
	needLvl = _needLvl;
	gainXp = _gainXp;
	gainMoney = _gainMoney;
	neededItem = _neededItem;
	revardItem = _revardItem;
}

DeliverQuest::~DeliverQuest()
{
}

bool DeliverQuest::IsMissionDone(Point& playerPos)
{
	if (playerPos == point)
		return true;
	return false;
}

void DeliverQuest::CreateQuest()
{
}
