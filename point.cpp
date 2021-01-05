#include "point.h"

/*Punkty xd*/
Point::Point()
{
	x = 0;
	y = 0;
}
Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}

Point operator+ (Point& p1, Point& p2)
{
	return Point(p1.x + p2.x, p1.y + p2.y);
}
Point operator-(Point& p1, Point& p2)
{
	return Point(p1.x - p2.x, p1.y - p2.y);
}
bool operator==(Point& p1, Point& p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return 1;
	else
		return 0;
}
