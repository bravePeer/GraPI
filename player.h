#pragma once
#include <iostream>
#include <string>
#include "person.h"
#include "something.h"

using namespace std;

class Player : public Person //dziedziczenie
{
public:
	
	Player();
	~Player();
	// wybieranie klasy
	void Select_profession(); 
	// skille dla postaci
	int Spell(int atak_moba);	 
	//wylicza obra¿enia bazowe bohatera
	int Dmg_formula();	
	//dodatkowe dodawanie statów przy nowych levelach
	void Bonus_stats_per_lvl(); 
	//Tworzenie Postaci
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

	int dmg_output;		//obra¿enia zadawane przez bohatera
	int profession; //klasa postaci
	int xpToNextLvl = 100;
	int questID = 0;
	int mapID = 0;

	string profession_name;
private:

};
