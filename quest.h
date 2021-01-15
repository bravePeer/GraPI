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
	virtual void CreateQuest(Player& player, Map& map);
	virtual void UpdateQuest();
	//virtual int GetTypeOfQuest();
	Point QuestPoint = { 5,5 };
	
	string name;
	string desc;

	int needLvl = 0;
	int gainXp = 0;
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
	void CreateQuest(Player& player, Map& map);

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
	void CreateQuest(Player& player, Map& map);

private:

};

//Main Quests
class MainQuest0 : public Quest
{
public:
	MainQuest0();
	void CreateQuest(Player& player, Map& map);
	void UpdateQuest();
	bool IsQuestDone(Player& player, Map& map);
};

class MainQuest1 : public Quest
{
public:
	MainQuest1();
	~MainQuest1();
	void CreateQuest( Player& player, Map& map);
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
	void CreateQuest( Player& player, Map& map);
	void UpdateQuest();
	bool IsQuestDone(Player& player, Map& map);

	Point p1 = Point(5, 5);
};

class MainQuest3 : public Quest
{
public:
	MainQuest3() {}
	~MainQuest3() {}
	void CreateQuest( Player& player, Map& map)
	{
		X(1, 0x000a, "*Widzisz cz³owieka ubranego w fioletowe ubranie*");
	}
	void UpdateQuest()
	{
		CDrawText(L"\u1d25", { (short)p1.x,(short)p1.y }, 0x0005);
	}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (player.positon == p1)
			return true;
		return false;
	}
	
	Point p1 = Point(5, 6);
};

class MainQuest4 : public Quest
{
public:
	MainQuest4() {}
	~MainQuest4() {}
	void CreateQuest(Player& player, Map& map)
	{
		X(3, 0x0005, "Witaj jestem nowym zarz¹dcom tutejszej wioski.", "Przepraszam, ¿e od razu zawracam Tobie g³owê", "ale mamy straszny problem z bestiami.");
		map.ShowMap();
		X(2, 0x0002, "Coœ o tych potworach wiadomo?", "Gdzie s¹? Ile ich jest?");
		map.ShowMap();
		X(4, 0x0005, "Widziano je na po³udniu st¹d.", "S³ysza³em, ¿e jest ich co najmniej 5.","" ,"Za pomoc zostaniesz wynagrodzony!");

		map.GenerateMobs(player.level, { 2,27 }, {40, 39}, 8);
	}
	void UpdateQuest()
	{
		if(shown)
			CDrawText(L"\u203c",{ (short)p1.x,(short)p1.y }, 0x0003);
	}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (map.mobs.size() <= 0 && map.mapID == 1 && !shown)
		{
			X(2, 0x0002, "*Powinienem siê teraz udaæ do Zarz¹dcy wioski*");
			shown = !shown;
		}
		if(shown && player.positon == p1)
			return true;
		return false;
	}
	bool shown = false;
	Point p1 = Point(20, 20);
};

