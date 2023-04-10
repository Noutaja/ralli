#include "drawable.h"

Drawable::Drawable()
{

}

Drawable::Drawable(Point *l, char c){
	_loc = *l;
	_ch = c;
}

Point Drawable::loc(){
	return _loc;
}

char Drawable::ch(){
	return _ch;
}

Drawable::~Drawable(){

}
