#pragma once
#include <iostream>
#include "person.h"
#include "mission.h"
#include "something.h"

using namespace std;

class Player : public Person //dziedziczenie
{
public:
	
	Player();
	~Player();

	int dmg_output=1;		//obra¿enia zadawane przez bohatera
	int profession = 3; //klasa postaci
	int xpToNextLvl = 100;

	string profession_name;

	void Select_profession(); // wybieranie klasy

	int Spell();	// skille dla postaci 

	int Dmg_formula();	//wylicza obra¿enia bazowe bohatera

	void Bonus_stats_per_lvl(); 
	//dodatkowe dodawanie statów przy nowych levelach
	
	Mission* quest = NULL;

	void CreateCharacter();
	void UsePreset();
	/*Otwiera plecak*/
	void ShowInventory();
	/*Wyswietla statystyki*/
	void ShowStats();
	/*Dodaj element do plecaka*/
	void AddItem(Item* item);
	/*Pokazuje questy*/
	void ShowQuests();

private:

};
