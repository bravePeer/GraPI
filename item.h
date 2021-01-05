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
	virtual void UseItem(FunnyStruct& funnyStruct);
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
	void UseItem(FunnyStruct& funnyStruct);
	void ShowItemInfo();

	int healthModifier = 0;

private:

};

