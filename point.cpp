#include "point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}

//Add another point to this
Point *Point::math(Point other){
	x += other.x;
	y += other.y;
	return this;
}

int Point::coordToInt(int w){
	return w*y+x;
}

Point::~Point(){

}
