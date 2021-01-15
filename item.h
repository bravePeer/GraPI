#pragma once
#include <iostream>
//#include <string>

using namespace std;


class Item
{
public:
	Item();
	Item(string _name, string _desc, float _weight, int _price);
	~Item();
	virtual int UseItem();
	virtual void ShowItemInfo();
	virtual int ItemType()
	{
		return 0;
	}

	string name;
	string desc;

	float weight;
	int price;

private:

};

class Food : public Item
{
public:
	Food();
	Food(Item item);
	Food(string _name,  string _desc, float _weight, int _price, int _mod);
	~Food();
	int UseItem( );
	void ShowItemInfo();
	int ItemType()
	{
		return 1;
	}
	int healthModifier = 0;

private:

};

class Weapon : public Item
{
public:
	Weapon();
	Weapon(Item item);
	Weapon(string _name, string _desc, float _weight, int _price, int _strength, int _critStrength, float _critPropability, int _profBonus);
	~Weapon();
	int UseItem( );
	void ShowItemInfo();
	int ItemType()
	{
		return 2;
	}

	int strength = 0;
	int critStrength = 0;
	float critPropability = 0;

	//bonus gdy osoba korzysta z broni dla jej postaci
	float professionBonus = 0;
	int neededLvl = 0;
private:

};

class Armor : public Item
{
public:
	Armor();
	Armor(Item item);
	Armor(string _name, string _desc, float _weight, int _price, int _armor, int _profBonus);
	~Armor();
	int UseItem( );
	void ShowItemInfo();
	int ItemType()
	{
		return 3;
	}
	int armor = 0;
	int professionBonus = 0;
	int neededLvl = 0;
private:

};

