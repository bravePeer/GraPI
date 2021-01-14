#pragma once
#include <iostream>
#include "item.h"
#include "something.h"
#include "point.h"
#include "map.h"
#include "player.h"
//#include "mob.h"

using namespace std;

class Quest
{
public:
	Quest();
	Quest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem);
	~Quest();

	//bool IsOnQuestPoint(Point &playerPos);
	//virtual void ShowMessege();
	virtual bool IsQuestDone(Player& player, Map& map);
	virtual int CreateQuest(Player& player, Map& map);
	virtual void UpdateQuest();
	//virtual int GetTypeOfQuest();
	Point QuestPoint = { 5,5 };
	
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

class KillQuest : Quest
{
public:
	KillQuest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem, int _mobType, int _quantity);
	~KillQuest();
	bool IsQuestDone(Player& player, Map& map);
	int CreateQuest(Player& player, Map& map);

private:
	int mobType = 0;
	int quantity = 0;
};

class DeliverQuest : Quest
{
public:
	DeliverQuest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem);
	~DeliverQuest();
	bool IsQuestDone(Player& player, Map& map);
	int CreateQuest(Player& player, Map& map);

private:

};

//Main Quests
class MainQuest0 : public Quest
{
public:
	MainQuest0();
	int CreateQuest(Player& player, Map& map);
	void UpdateQuest();
	bool IsQuestDone(Player& player, Map& map);
};

class MainQuest1 : public Quest
{
public:
	MainQuest1();
	~MainQuest1();
	int CreateQuest( Player& player, Map& map);
	void UpdateQuest();
	bool IsQuestDone(Player& player, Map& map);

private:
	Point p1 = Point(60, 19);
	Point p2 = Point(61, 20);
};

class MainQuest2 : public Quest
{
public:
	MainQuest2();
	~MainQuest2();
	int CreateQuest( Player& player, Map& map);
	void UpdateQuest();
	bool IsQuestDone(Player& player, Map& map);

	Point p1 = Point(6, 5);
};

class MainQuest3 : public Quest
{
public:
	MainQuest3() {}
	~MainQuest3() {}
	int CreateQuest( Player& player, Map& map)
	{
		map.GenerateMobs(player.level);
		return 1;
	}
	void UpdateQuest()
	{

	}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (map.mobs.size() <= 0)
			return true;
		return false;
	}
	//vector<Mobs*> mobs;
	Point p1 = Point(6, 4);
};
/*
*/