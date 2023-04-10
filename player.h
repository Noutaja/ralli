#ifndef PLAYER_H
#define PLAYER_H


#include "drawable.h"
#include "point.h"
class Player : public Drawable
{
public:
	Player();
	Player(Point start);
	~Player();
	Point speed;
	bool moving;
	void move();
	void stop();
};

#endif // PLAYER_H
