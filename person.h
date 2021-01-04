#pragma once
#include <iostream>
#include <conio.h>
#include <vector>

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

	char sex;

	bool dead;
	int xp;
	int level;

	int money;
	float backpackMaxWeight;
	float backpackWeight;
	int armor;		// pancerz

	int life;		// wytrzymalosc -> zdrowie aktualne
	int lifeMax;
	
	int accuracy;	//celnosc
	int strength;	//sila
	int inteligence;//inteligencja
	int agility;	//zrêcznoœæ
	int dodging;	//uniki
	int crit_strike;//uderzenia krytyczne
	//int speed;		//szybkosc
	
	int profession; //klasa postaci
	//string profession_name;
	
	int spell();	//
	Spell sp;
	
	vector<int> inventory;


private:

};