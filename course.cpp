#include "course.h"
#include "tile.h"
#include <iostream>
#include <vector>

Course::Course(){
	_start = *new Point();
}

Course::Course(std::vector<Tile> mapData, int w, int h, Point start, int r)
{
	_map = *new std::vector<Tile>;
	width = w;
	height = h;
	_start = start;
	record = r;
	for(unsigned long long i = 0; i < mapData.size(); i++){
		_map.push_back(mapData[i]);
	}
}

std::string Course::asString(){
	std::string course = "";
	for(unsigned long long i = 0; i < _map.size(); i++){
		course += _map[i].ch();
	}
	return course;
}

Tile Course::getTileAt(Point p){
	return _map[width*p.y+p.x];
}

Point Course::getStart(){
	return _start;
}
