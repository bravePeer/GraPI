#include "person.h"

Person::Person()
{
	sp.strew = 3;
}

Person::~Person()
{
	for (int i = 0; i < inventory.size(); i++)
	{
		delete inventory[i];
	}
	inventory.clear();
}

int Person::spell()
{
	return 2;
}
