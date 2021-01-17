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
	virtual void UpdateQuest(Map& map);
	//virtual int GetTypeOfQuest();
	Point QuestPoint = { 5,5 };
	
	string name;
	string desc;

	int needLvl = 0;
	int gainXp  ;
	int gainMoney  ;

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
	MainQuest0() {}
	void CreateQuest(Player& player, Map& map) {}
	void UpdateQuest(Map& map) {}
	bool IsQuestDone(Player& player, Map& map) { return true; }
};

class MainQuest1 : public Quest
{
public:
	MainQuest1() {}
	~MainQuest1() {}
	void CreateQuest(Player& player, Map& map)
	{
		player.positon = { 47,22 };
		map.ShowMap();
		map.ShowMap(player.positon);
		X(1, 0x000a, "*Budzisz się i zauważasz pod drzwiami list*");
	}
	void UpdateQuest(Map& map)
	{
		CDrawText(L"\u25ac", { 60, 19 }, 0x0007);
	}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (player.positon == p1 || player.positon == p2)
		{
			return true;
		}
		return false;
	}

private:
	Point p1 = Point(60, 19);
	Point p2 = Point(61, 20);
};

class MainQuest2 : public Quest
{
public:
	MainQuest2() {}
	~MainQuest2() {}
	void CreateQuest(Player& player, Map& map)
	{
		X(1, 0x000a, "*Otwiersz list i ...*");
		X(7, 0x000a, "Witaj mężny wojowniku!", "W imieniu całej wsi proszę Cię o pomoc", "w pokonaniu stworów, które nas atakują.", "Spotkaj się ze mną a powiem Tobie coś więcej o tych bestiach.", "Czekam przed Twoim domem.", "", "Dziękujemy !!!");
	}
	void UpdateQuest(Map& map) {}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (map.mapID == 1)
		{
			return true;
		}

		return false;
	}

	Point p1 = Point(5, 5);
};

class MainQuest3 : public Quest
{
public:
	MainQuest3() {}
	~MainQuest3() {}
	void CreateQuest( Player& player, Map& map)
	{
		X(1, 0x000a, "*Widzisz człowieka ubranego w fioletowe ubranie*");
	}
	void UpdateQuest(Map& map)
	{
		if(map.mapID == 1)
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
	int gainMoney = 300;
	int gainXp = 50;
public:
	MainQuest4() {}
	~MainQuest4() {}
	void CreateQuest(Player& player, Map& map)
	{
		ClearMapPlace();
		ShowGfx_NPC(101,{(WHEREINFO-60)/2,2 });
		
		X(3, 0x0005, "Witaj jestem nowym zarządcom tutejszej wioski.", "Przepraszam, że od razu zawracam Tobie głowę", "ale mamy straszny problem z bestiami.");
		ShowGfx_NPC(101,{(WHEREINFO-60)/2,2 });
		X(2, 0x0002, "Coś o tych potworach wiadomo?", "Gdzie są? Ile ich jest?");
		ShowGfx_NPC(101,{(WHEREINFO-60)/2,2 });
		X(4, 0x0005, "Widziano je na południu stąd.", "Słyszałem, że jest ich co najmniej 5.","" ,"Za pomoc zostaniesz wynagrodzony!");
		ShowGfx_NPC(101,{(WHEREINFO-60)/2,2 });
		map.ShowMap();
		map.GenerateMobs(player.level, { 2,27 }, { 20, 20 }, 3);
	}
	void UpdateQuest(Map& map)
	{
		if(shown)
			CDrawText(L"\u1d25", { (short)p1.x,(short)p1.y }, 0x0005);
	}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (map.mobs.size() <= 0 && map.mapID == 1 && !shown)
		{
			X(1, 0x0002, "*Powinienem się teraz udać do Zarządcy wioski*");
			shown = !shown;
			map.ShowMap();
		}
		if (shown && player.positon == p1)
		{
			ClearMapPlace();
			ShowGfx_NPC(101,{(WHEREINFO-60)/2,2 });
			X(2, 0x0005, "Dziękuję za pokonanie bestii.", "Proszę o to Twoja należność." );
			CDrawText("+ " + to_string(gainMoney) + "G", { 108,38 }, 0x000a);
			player.money += gainMoney;
			CDrawText("+ " + to_string(gainXp) + "XP", { 108,39 }, 0x000e);
			player.xp += gainXp;
			return true;

		}
		return false;
	}
	
	bool shown = false;
	Point p1 = Point(34, 4);
};
class MainQuest5 : public Quest
{
	Mob boss;
	
	void CreateQuest(Player& player, Map& map)
	{
		boss.name="Golem";
		boss.armor = 15;
		boss.life = 150;
		boss.mob_lvl = 5;
		boss.money_from_mob = 500;
		boss.exp_after_win = 300;
		boss.position = { 104,39 };
		boss.onMap = L"\u0551";
		boss.gfxID = 703;
		map.mobs.push_back(new Mob(boss));
		//map.GenerateMobs()
	}
	void UpdateQuest(Map& map)
	{
		//if (map.mapID == 1) CDrawText(L"\u0551",{104,39},0x0007);
	}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (map.mobs.size() <= 0)
		{
			map.is_boss_dead = true;
			return true;
		}
		return false;
	}

};

class MainQuest6 : public Quest
{
	Mob boss;

	void CreateQuest(Player& player, Map& map)
	{
		boss.name="Wilkołak";
		boss.armor = 25;
		boss.life = 200;
		boss.mob_lvl = 10;
		boss.money_from_mob = 750;
		boss.exp_after_win = 600;
		boss.position = { 60,15 };
		boss.gfxID = 702;
		boss.onMap = L"\u0551";
		map.mobs.push_back(new Mob(boss));
	}
	void UpdateQuest(Map& map)
	{
	//if (map.mapID == 2)		CDrawText(L"\u0176",{60,15},0x0004);
	}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (map.mobs.size() <= 0)
		{
			map.is_boss_dead = true;
			return true;
		}
		return false;
	}

};
class MainQuest7 : public Quest
{

Mob boss;
	void CreateQuest(Player& player, Map& map)
	{
		boss.name="Smok dzikiego wzgórza";
		boss.armor = 30;
		boss.life = 250;
		boss.mob_lvl = 15;
		boss.money_from_mob = 1000;
		boss.exp_after_win = 1000;
		boss.position = { 53,20 };
		boss.gfxID = 900;
		boss.onMap = L"\u0551";
		map.mobs.push_back(new Mob(boss));
	}
	void UpdateQuest(Map& map)
	{
	//	if (map.mapID == 3)		CDrawText(L"\u20a6",{53,20},0x0004);
	}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (map.mobs.size() <= 0)
		{
			map.is_boss_dead = true;
			return true;
		}
		return false;
	}
//ጰ
};

class MainQuest8 : public Quest
{
	void CreateQuest(Player& player, Map& map)
	{

	}
	void UpdateQuest(Map& map)
	{

	}
	bool IsQuestDone(Player& player, Map& map)
	{
		vector<string> s;
		s.push_back("Tak");
		s.push_back("Nie");
		if (map.mapID == 2 && punkt == player.positon)
		{
			
			X(-4, 0x0004, " Z dala zobaczyłeś dziwnego potwora\n", "    Czy chcesz podejść bliżej?\n","\n","\n");

			switch (DrawMenu(s,{(WHEREINFO-2)/2,32}))
			{
			case 0:
				
				ClearMapPlace();
				ShowGfx_Mobs(700);
				Sleep(2000);
				ClearMapPlace();
				ShowGfx_Mobs(701);
				Sleep(2000);
				 player.positon = { 60,15 };
				 map.ShowMap();
				 return true;
				 break;
			case 1:
				map.ShowMap();
				player.positon = { 44,15 };
				break;
			}
		}
		return false;
	}

	Point punkt = { 45,15 };
};

class MainQuest9 : public Quest
{
	void CreateQuest(Player& player, Map& map)
	{

	}
	void UpdateQuest(Map& map)
	{

	}
	bool IsQuestDone(Player& player, Map& map)
	{
		vector<string> s;
		s.push_back("Tak");
		s.push_back("Nie");
		if (map.mapID == 2 && punkt == player.positon)
		{
			ClearMapPlace();
			ShowGfx_Envi(1000, {(WHEREINFO-75)/2,18});
			X(-4, 0x0004, "Widzisz tajemniczą studnie.", "Czy chcesz zaglądnąć co jest w środku?","","");
			switch (DrawMenu(s,{(WHEREINFO-2)/2,32}))
			{
			case 0:
				map.ShowMap();
				player.positon = { 105,3 };
				break;
			case 1:
				map.ShowMap();
				player.positon = { 103,3 };
				break;
			}
		}return false;

	}
	Point punkt ={104,3};
};

class MainQuestNWM : public Quest
{
	void CreateQuest(Player& player, Map& map)
	{

	}
	void UpdateQuest(Map& map)
	{

	}
	bool IsQuestDone(Player& player, Map& map)
	{
		if (map.mapID == 3)
			return true;
		return false;

	}
};

/*jakieś napisy koncowe xd czy cus xd*/
class MainQuestEnd : public Quest
{
	void CreateQuest(Player& player, Map& map)
	{
		X(4, 0x0002, "Gratulacje", "Udało Ci się ukończyć wątek fabularny!","","Dziękujemy!!!");
		X(5, 0x0002, "Grę stworzyli:", "","Dąbrowski Hubert","Dąbrowski Kacper","Gojowczyk Bartłomiej");
		X(9, 0x0002, "Muzyka:", "Move it Out", "Mountainside", "Balloon Fantasy 3", "Indian Ocen Twilight", "", "by Eric Matyas", "", "www.soundimage.org");
	}
	void UpdateQuest(Map& map)
	{

	}
	bool IsQuestDone(Player& player, Map& map)
	{
		return false;
	}

};


