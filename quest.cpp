#include "quest.h"

Quest::Quest()
{
}

Quest::Quest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem)
{
	name = _name;
	point = _point;
	QuestPoint = _point;
	needLvl = _needLvl;
	gainXp = _gainXp;
	gainMoney = _gainMoney;
	neededItem = _neededItem;
	revardItem = _revardItem;
}

Quest::~Quest()
{
}

bool Quest::IsQuestDone(Player& player, Map& map)
{
	cout << "eeeeeee" << endl;
	return 1;
}

void Quest::CreateQuest( Player& player, Map& map)
{
}

void Quest::UpdateQuest()
{
}


KillQuest::KillQuest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem, int _mobType, int _quantity)
{
	name = _name;
	point = _point;
	QuestPoint = _point;
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

bool KillQuest::IsQuestDone(Player& player, Map& map)
{
	if (quantity <= 0)
		return true;
	return false;
}

void KillQuest::CreateQuest( Player& player, Map& map)
{
}

DeliverQuest::DeliverQuest(string _name, Point _point, int _needLvl, int _gainXp, int _gainMoney, Item _neededItem, Item _revardItem)
{
	name = _name;
	point = _point;
	QuestPoint = _point;
	needLvl = _needLvl;
	gainXp = _gainXp;
	gainMoney = _gainMoney;
	neededItem = _neededItem;
	revardItem = _revardItem;
}

DeliverQuest::~DeliverQuest()
{
}

bool DeliverQuest::IsQuestDone(Player& player, Map& map)
{
	if (player.positon == point)
		return true;
	return false;
}

void DeliverQuest::CreateQuest(Player& player, Map& map)
{
}

MainQuest0::MainQuest0()
{
}

void MainQuest0::CreateQuest( Player& player, Map& map)
{
}

void MainQuest0::UpdateQuest()
{
}

bool MainQuest0::IsQuestDone(Player& player, Map& map)
{
	return true;
}

MainQuest1::MainQuest1()
{
}

void MainQuest1::CreateQuest(Player& player,Map& map)
{
	player.positon = { 47,22 };
	map.ShowMap();
	map.ShowMap(player.positon);
	X(1, 0x000a, "*Budzisz siê i zauwa¿asz pod drzwiami list*");
}

void MainQuest1::UpdateQuest()
{
	CDrawText(L"\u25ac", { 60, 19 }, 0x0007);
}

bool MainQuest1::IsQuestDone(Player& player, Map& map)
{
	if (player.positon == p1 || player.positon == p2)
	{
		return true;
	}
	return false;
}

MainQuest2::MainQuest2()
{
}

void MainQuest2::CreateQuest(Player& player,Map& map)
{
	X(1, 0x000a, "*Otwiersz list i ...*");
	X(7, 0x000a, "Witaj mê¿ny wojowniku!", "W imieniu ca³ej wsi proszê Ciê o pomoc", "w pokonaniu stworów, które nas atakuj¹.", "Spotkaj siê ze mn¹ a powiem Tobie coœ wiêcej o tych bestiach.", "Czekam przed Twoim domem.","",  "Dziêkujemy !!!");
}

void MainQuest2::UpdateQuest()
{
}

bool MainQuest2::IsQuestDone(Player& player, Map& map)
{
	if (map.mapID == 1)
	{
		return true;
	}
		
	return false;
}
/**/