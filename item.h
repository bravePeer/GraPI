#pragma once
#include <iostream>

using namespace std;

struct FunnyStruct	//nie wiedzialem jak strukture nazwac xd
{
	int healthModifier;
};

class Item
{
public:
	Item();
	Item(string _name);
	~Item();
	virtual int UseItem();
	virtual void ShowItemInfo();
	string name;
	string desc;

private:

};

class Food : public Item
{
public:
	Food();
	Food(string _name,int _inc);
	~Food();
	int UseItem( );
	void ShowItemInfo();

	int healthModifier = 0;

private:

};

class Weapon : public Item
{
public:
	Weapon(string _name);
	~Weapon();
	int UseItem( );
	void ShowItemInfo();

	int strength = 0;
	int critStrength = 0;

	//bonus gdy osoba korzysta z broni dla jej postaci
	int professionBonus = 0;

	int neededLvl = 0;
private:

};

class Armor : public Item
{
public:
	Armor(string _name);
	~Armor();
	int UseItem( );
	void ShowItemInfo();

	int armor = 0;

private:

};

