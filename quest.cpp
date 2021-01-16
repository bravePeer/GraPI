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
	cout << "Done" << endl;
	return 1;
}

void Quest::CreateQuest( Player& player, Map& map)
{
}

void Quest::UpdateQuest(Map& map)
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
 

 