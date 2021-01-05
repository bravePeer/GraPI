#include "item.h"

Item::Item()
{
}

Item::Item(string _name)
{
	name = _name;
}

Item::~Item()
{
}

void Item::UseItem(FunnyStruct& funnyStruct)
{
}

void Item::ShowItemInfo()
{
}

Food::Food()
{
}

Food::Food(string _name, int _healthModifier)
{
	healthModifier = _healthModifier;
	name = _name;
}

Food::~Food()
{
}

void Food::UseItem(FunnyStruct& funnyStruct)
{
	funnyStruct.healthModifier = healthModifier;
}

void Food::ShowItemInfo()
{
}
