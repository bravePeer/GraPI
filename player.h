#pragma once
#include <iostream>
#include <string>
#include "person.h"
#include "something.h"
#include "gfx.h"


using namespace std;

class Player :public Person //dziedziczenie
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

class Npc
{
public:
	string name;
	Point position;
	Npc() {}
	Npc(string _name, Point _position)
	{
		name = _name;
		position = _position;
	}
	virtual void OnInteraction();
	 
	virtual int NpcType()
	{
		return 0;
	}
	//wstring wc = L"";
};

/*
class NpcFood : public Npc
{
public:

	NpcFood(string _name, Point _position)
	{
		name = _name;
		position = _position;
	}

	void OnInteraction()
	{
		//X(2, 0x000e, "G³odny? A mo¿e spragniony?", "U mnie wszystko znajdziesz co najlepszze mo¿na spo¿yæ!");
	}
	int NpcType()
	{
		return 1;
	}
};

class NpcWeapon : public Npc
{
public:

	NpcWeapon(string _name, Point _position)
	{
		name = _name;
		position = _position;
	}

	void OnInteraction()
	{
		//X(1, 0x000e, "Potrzebujesz ostrej jak brzytwa broni?");
		//X(1, 0x000e, "Dobrze trafi³eœ!");
	}
	int NpcType()
	{
		return 2;
	}
};

class NpcArmor : public Npc
{
public:
	NpcArmor(string _name, Point _position)
	{
		name = _name;
		position = _position;
	}

	void OnInteraction();
	
	int NpcType()
	{
		return 3;
	}
	//wc = L"\u0414";
};
/**/
