#pragma once
#include <iostream>
#include <string>
#include "person.h"
#include "mission.h"
#include "something.h"
#include "mob.h"

using namespace std;

class Player : public Person //dziedziczenie
{
public:
	
	Player();
	~Player();

	int dmg_output;		//obra¿enia zadawane przez bohatera
	int profession; //klasa postaci
	int xpToNextLvl = 100;

	string profession_name;

	void Select_profession(); // wybieranie klasy

	int Spell(int atak_moba);	// skille dla postaci 

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

	bool CritIs();
	bool DodgeIs();
	bool AccIs();

private:

};
