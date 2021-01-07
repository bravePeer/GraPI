#pragma once
#include <iostream>
#include "person.h"
#include "mission.h"
#include "something.h"

using namespace std;

class Player : public Person
{
public:
	
	Player();
	~Player();

	int dmg_output;		//obra¿enia zadawane przez bohatera
	
	int profession = 0; //klasa postaci
	string profession_name;

	void Select_profession(int proffesion, string profession_name); // wybieranie klasy

	int Spell(int profession, int level, int life, int lifeMax, int tura, int armor, int dmg_output);	// skille dla postaci 

	int Dmg_formula(int strength, int agility, int inteligence);	//wylicza obra¿enia bazowe bohatera

	void Bonus_stats_per_lvl(int strength, int agility, int inteligence, int accuracy, int dodging, int crit_strike); 
	//dodatkowe dodawanie statów przy nowych levelach


	vector<Mission> mis;
	void CreateCharacter();
	void UsePreset();
	/*Otwiera plecak*/
	void ShowInventory();
	/*Wyswietla statystyki*/
	void ShowStats();
	/*Dodaj element do plecaka*/
	void AddItem(Item* item);

private:

};

