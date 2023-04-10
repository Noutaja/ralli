#ifndef DRAWABLE_H
#define DRAWABLE_H


#include "point.h"
class Drawable
{
protected:
	Point _loc;
	char _ch;
public:
	Drawable();
	Drawable(Point *l, char c);
	virtual ~Drawable(); //crash without virtual??
	Point loc();
	char ch();
};

#endif // DRAWABLE_H
