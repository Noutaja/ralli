#include "player.h"

Player::Player()
{

}

Player::Player(Point start){
	_ch = 'O';
	_loc = start;
	speed = Point();
	moving = false;
}

void Player::move(){
	_loc.math(speed);
	moving = false;
}

Player::~Player(){
}
