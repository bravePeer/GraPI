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

