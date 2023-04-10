#include "game.h"
#include "ui.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

Game::Game(Course course)
{
	_course = course;
	ui = new UI(_course.width, _course.height);
	_player = new Player(_course.getStart());

	keyPressed = false;
	time = 0;
}

void Game::draw(){
	//Clear screen
	std::system("cls");
	//Use a string as a "frame" to avoid calling cout multiple times
	std::string frame = _course.asString();

	//Add player
	Point p = _player->loc();
	frame[_course.width*p.y+p.x] = _player->ch();

	//Add UI elements
	frame = ui->draw(frame, _course.width, _course.height);

	//Draw the frame
	std::cout << frame;
}

void Game::input() {
		// Check if/what key is pressed
	int kbhit = _kbhit();
	char ch = 0;
		if(kbhit){
			ch = _getch();
			//Wait for the key to release before a new command is accepted
			if(!keyPressed){
				switch (ch) {
				case '8':
				case 'w':
					_player->speed.y -= 1;
					 keyPressed = true;
					 _player->moving = true;
					 break;
				case '4':
				case 'a':
					_player->speed.x -= 1;
					keyPressed = true;
					_player->moving = true;
					break;
				case '6':
				case 'd':
					_player->speed.x += 1;
					keyPressed = true;
					_player->moving = true;
					break;
				case '2':
				case 's':
					_player->speed.y += 1;
					keyPressed = true;
					_player->moving = true;
					break;
				case '5':
				case ' ':
					// Don't change speed
					keyPressed = true;
					_player->moving = true;
					break;
				}
			}

		}
	else {
		// Reset
		keyPressed = false;
	}
		//Movement debuging
		//std::cout << "kbhit: " << kbhit << "  getch: " <<  ch << "  kPressed: " << keyPressed;
}

bool Game::logic(){
	bool gameContinue = true;
	if(_player->moving){
		//Mark current location to history
		ui->history.push_back(new Point(_player->loc().x,_player->loc().y));

		//Move player
		_player->move();
		_player->moving = false;

		//Out of bounds check
		Point p = _player->loc();
		if(p.x < 0 || p.x > _course.width-1 ||
				p.y < 0 || p.y > _course.height-1){
			std::cout << "You crashed!" << std::endl;
			system("pause");
			reset();
		}
		ui->refreshBlink();
		time++;
	}

	//Next turn's prediction
	int x = _player->loc().x + _player->speed.x;
	int y = _player->loc().y + _player->speed.y;
	Point *p = new Point(x,y);
	ui->prediction = *p;
	delete p;

	//Continue/win/crash check
	char currentTerrain = _course.getTileAt(_player->loc()).ch();
	if(currentTerrain == '.'){
		//Do nothing
	} else if (currentTerrain == 'F'){
		std::cout << "You won!" << std::endl;
		gameContinue = false;
	}
	else {
		std::cout << "You crashed!" << std::endl;
		system("pause");
		reset();
	}
	return gameContinue;
}

void Game::reset(){
	ui->clearHistory();
	delete _player;
	_player = new Player(_course.getStart());
	time = 0;
}

int Game::run(){
	do{
		draw();
		input();
		Sleep(48);
	}while(logic());
	return time;
}
