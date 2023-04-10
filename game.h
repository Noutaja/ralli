#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "ui.h"
#include <course.h>



class Game
{
private:
	Course _course;
	UI *ui;
	void draw();
	void input();
	bool logic();
	void reset();
	Player *_player;
	bool keyPressed;
	int time;
public:
	Game(Course course);
	int run();
};

#endif // GAME_H
