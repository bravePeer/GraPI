#include "mission.h"

Mission::Mission(string _name, Point _point)
{
	name = _name;
	missionPoint = _point;
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

bool Mission::IsMissionDone()
{
	cout << "eeeeeee" << endl;
		return 1;
}
