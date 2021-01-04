#pragma once
#include <iostream>
#include "person.h"
#include "mission.h"

using namespace std;

class Player : public Person
{
public:
	
	Player();
	~Player();

	vector<Mission> mis;
	void CreateCharacter();

	void ShowInventory();

private:

};

