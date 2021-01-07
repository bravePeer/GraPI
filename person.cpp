#include "person.h"

Person::Person()
{

}

Person::~Person()
{
	for (int i = 0; i < inventory.size(); i++)
	{
		delete inventory[i];
	}
	inventory.clear();
}
