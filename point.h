#ifndef POINT_H
#define POINT_H


class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();
	int x, y;
	Point *math(Point other);
	int coordToInt();
	int coordToInt(int w);
};

#endif // POINT_H
