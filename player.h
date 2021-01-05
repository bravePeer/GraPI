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

	void ShowInventory();
	
private:
	void Use(FunnyStruct& funnyStruct);

};

