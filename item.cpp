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

int Item::UseItem()
{
	return 0;
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

int Food::UseItem()
{
	return 1;
}

void Food::ShowItemInfo()
{
}

Weapon::Weapon(string _name)
{
	name = _name;
}

Weapon::~Weapon()
{
}

int Weapon::UseItem()
{
	return 2;
}

void Weapon::ShowItemInfo()
{
}

Armor::Armor(string _name)
{
	name = _name;
}

Armor::~Armor()
{
}

int Armor::UseItem( )
{
	return 3;

}

void Armor::ShowItemInfo()
{
}
