#ifndef COURSE_H
#define COURSE_H

#include "tile.h"
#include <point.h>
#include <string>
#include <vector>

//using namespace std;

class Course
{
private:

	std::vector<Tile> _map;
	Point _start;
public:
	int width, height, record;
	Course();
	Course(std::vector<Tile> mapData, int width, int height, Point start, int rec = 0);
	std::string asString();
	Tile getTileAt(int x, int y);
	Tile getTileAt(Point p);
	Point getStart();
};

#endif // COURSE_H
