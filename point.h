#pragma once
struct Point
{
	int x;
	int y;

	Point(int _x, int _y);
	Point();
};

Point operator+ (Point& p1, Point& p2);
Point operator- (Point& p1, Point& p2);
bool operator== (Point& p1, Point& p2);
 