#include "item.h"

Item::Item()
{
}

Item::Item(string _name, string _desc, float _weight, int _price)
{
	name = _name;
	desc = _desc;
	weight = _weight;
	price = _price;
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

Food::Food(Item item)
{
	name = item.name;
	desc = item.desc;
	weight = item.weight;
	price = item.price;
}

Food::Food(string _name, string _desc, float _weight, int _price, int _healthModifier)
{
	name = _name;
	desc = _desc;
	weight = _weight;
	price = _price;
	
	healthModifier = _healthModifier;
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

Weapon::Weapon()
{
}

Weapon::Weapon(Item item)
{
	name = item.name;
	desc = item.desc;
	weight = item.weight;
	price = item.price;
}

Weapon::Weapon(string _name, string _desc, float _weight, int _price, int _strength, int _critStrength, float _critPropability, int _profBonus)
{
	name = _name;
	desc = _desc;
	weight = _weight;
	price = _price;

	strength = _strength;
	critStrength = _critStrength;
	critPropability = _critPropability;
	professionBonus = _profBonus;
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

Armor::Armor()
{
}

Armor::Armor(Item item)
{
	name = item.name;
	desc = item.desc;
	weight = item.weight;
	price = item.price;
}

Armor::Armor(string _name, string _desc, float _weight, int _price, int _armor, int _profBonus)
{
	name = _name;
	desc = _desc;
	weight = _weight;
	price = _price;

	armor = _armor;
	professionBonus = _profBonus;
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
