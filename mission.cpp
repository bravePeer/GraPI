#include "mission.h"

Mission::Mission(string _name)
{
	name = _name;
}

Mission::~Mission()
{
}

bool Mission::IsOnMissionPoint(Point& playerPos)
{
	if (playerPos == missionPoint)
		return true;
	return false;
}

void Mission::ShowMessege()
{
	cout << "eeeeeee" << endl;
}
