#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "item.h"

using namespace std;

class Person
{
public:
	Person();
	~Person();
	
	string name;

	char sex;

	bool dead = false;
	int xp = 0;
	int level = 1;

	int money = 100;
	float backpackMaxWeight = 5.0f;
	float backpackWeight = 1.0f;
	int armor=1;		// pancerz

	int life = 100;		// wytrzymalosc -> zdrowie aktualne
	int lifeMax = 100;
	
	int accuracy = 1;	//celnosc
	int strength = 1;	//sila
	int inteligence = 1;//inteligencja
	int agility = 1;	//zrêcznoœæ
	int dodging = 1;	//uniki
	int crit_strike = 1;//uderzenia krytyczne

	
	//ekwipunek
	vector<Item *> inventory;

	//ubrane rzeczy
	Weapon *equipedWeapon = NULL;
	Armor *equipedArmor = NULL;

private:

};