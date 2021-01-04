#pragma once

class Item
{
public:
	Item();
	~Item();
	virtual void UseItem();
	virtual void ShowItemInfo();
	string name;
	string desc;

private:

};

class Food : public Item
{
public:
	Food();
	~Food();
	void UseItem();
	void ShowItemInfo();

private:

};

