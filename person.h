#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "item.h"

using namespace std;

struct Spell
{
	int strew;
};

class Person
{
public:
	Person();
	~Person();
	
	string name;

	char sex = 'm';

	bool dead = false;
	int xp = 0;
	int level = 1;

	int money = 100;
	float backpackMaxWeight = 5.0f;
	float backpackWeight = 1.0f;
	int armor = 2;		// pancerz

	int life = 100;		// wytrzymalosc -> zdrowie aktualne
	int lifeMax = 100;
	
	int accuracy = 0;	//celnosc
	int strength = 0;	//sila
	int inteligence = 0;//inteligencja
	int agility = 0;	//zrêcznoœæ
	int dodging = 0;	//uniki
	int crit_strike = 0;//uderzenia krytyczne
	//int speed;		//szybkosc
	
	int profession = 0; //klasa postaci
	//string profession_name;
	
	int spell();	//
	Spell sp;
	
	//vector<int> inventory;

	vector<Item *> inventory;

private:

};