#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "item.h"
#include "point.h"
#include <string>


using namespace std;

class Person
{
public:
	Person();
	~Person();
	
	bool dead = false;
	
	string name;
	short sex;
	int xp = 0;
	int level = 1;

	int money = 100;
	float backpackMaxWeight = 5.0f;
	float backpackWeight = 1.0f;
	int armor = 10;		// pancerz

	int life = 100;		// wytrzymalosc -> zdrowie aktualne
	int lifeMax = 100;
	
	int accuracy;		//celnosc
	int strength;		//sila
	int inteligence;	//inteligencja
	int agility;		//zrêcznoœæ
	int dodging;		//uniki
	int crit_strike;	//uderzenia krytyczne
	int gfxID = 0;
	
	Point positon = { 5,5 };
	
	//ekwipunek
	vector<Item *> inventory;

	//ubrane rzeczy
	Weapon *equipedWeapon = NULL;
	Armor *equipedArmor = NULL;

private:

};

