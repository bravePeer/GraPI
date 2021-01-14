#pragma once
#include <iostream>
#include "item.h"
#include "something.h"
#include "point.h"


using namespace std;

class Quest
{
public:
	Quest();
	Quest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem);
	~Quest();

	bool IsOnQuestPoint(Point &playerPos);
	//virtual void ShowMessege();
	virtual bool IsQuestDone(Point& playerPos);
	virtual void CreateQuest();
	virtual void UpdateQuest();
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
	bool IsQuestDone(Point& playerPos);
	void CreateQuest();

private:
	int mobType = 0;
	int quantity = 0;
};

class DeliverQuest : Quest
{
public:
	DeliverQuest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem);
	~DeliverQuest();
	bool IsQuestDone(Point& playerPos);
	void CreateQuest();

private:

};

/*Main Quests*/
class MainQuest0 : public Quest
{
public:
	MainQuest0();
	void CreateQuest();
	void UpdateQuest();
	bool IsQuestDone(Point& playerPos);
};

class MainQuest1 :public Quest
{
public:
	MainQuest1();
	~MainQuest1();
	void CreateQuest();
	void UpdateQuest();
	bool IsQuestDone(Point& playerPos);

private:
	Point p1 = Point(60, 19);
	Point p2 = Point(61, 20);
};
class MainQuest2 : public Quest
{
public:
	MainQuest2();
	~MainQuest2();
	void CreateQuest();
	void UpdateQuest();
	bool IsQuestDone(Point& playerPos);

private:

};

