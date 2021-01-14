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

bool Quest::IsOnQuestPoint(Point& playerPos)
{
	if (playerPos == QuestPoint)
		return true;
	return false;
}

bool Quest::IsQuestDone(Point& playerPos)
{
	cout << "eeeeeee" << endl;
	return 1;
}

void Quest::CreateQuest()
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

bool KillQuest::IsQuestDone(Point& playerPos)
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

bool DeliverQuest::IsQuestDone(Point& playerPos)
{
	if (playerPos == point)
		return true;
	return false;
}

void DeliverQuest::CreateQuest()
{
}

MainQuest1::MainQuest1()
{
}

void MainQuest1::CreateQuest()
{
	X(1, 0x000a, "*Budzisz siê i zauwa¿asz pod drzwiami list*");
}

void MainQuest1::UpdateQuest()
{
	CDrawText(L"\u25ac", { 60, 19 }, 0x0007);
}

bool MainQuest1::IsQuestDone(Point& playerPos)
{
	if (playerPos == p1 || playerPos == p2)
	{
		return true;
	}
	return false;
}

MainQuest2::MainQuest2()
{
}

void MainQuest2::CreateQuest()
{
	X(1, 0x000a, "*Otwiersz list i ...*");
	X(6, 0x000a, "Witaj mê¿ny wojowniku!", "Prosimy Ciê o pomoc w pokonaniu stworów,", "które nas atakuj¹.", "Pozb¹dŸ siê ich, a zdobêdziesz wynagrodzenie!", "", "Dziêkujemy !!!");
}

void MainQuest2::UpdateQuest()
{
}

bool MainQuest2::IsQuestDone(Point& playerPos)
{
	return false;
}

MainQuest0::MainQuest0()
{
}

void MainQuest0::CreateQuest()
{
}

void MainQuest0::UpdateQuest()
{
}

bool MainQuest0::IsQuestDone(Point& playerPos)
{
	return true;
}
