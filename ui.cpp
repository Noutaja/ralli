#include "ui.h"
#include <iostream>

UI::UI(int w, int h) {
	history = *new std::vector<Point*>;
	blinkOn = true;
	blinkTimer = 0;
	width = w;
	height = h;
}

std::string UI::draw(std::string frame, int w, int h) {
	width = w;
	height = h;

	frame = drawHistory(frame);
	frame = drawPrediction(frame);

	return frame;
}

std::string UI::drawHistory(std::string frame){
	for (Point *point : history){
		frame[point->coordToInt(width)] = 'o';
	}
	return frame;
}

std::string UI::drawPrediction(std::string frame) {
  if (blinkOn) {
	// Check that prediction doesn't go out of bounds
	if (!outOfBounds(&prediction))
		frame[prediction.coordToInt(width)] = '5';

	Point p = Point(prediction.x - 1, prediction.y);
	if (!outOfBounds(&p))
		frame[prediction.coordToInt(width) - 1] = '4';

	p = Point(prediction.x, prediction.y - 1);
	if (!outOfBounds(&p))
		frame[prediction.coordToInt(width) - width] = '8';

	p = Point(prediction.x + 1, prediction.y);
	if (!outOfBounds(&p))
		frame[prediction.coordToInt(width) + 1] = '6';

	p = Point(prediction.x, prediction.y + 1);
	if (!outOfBounds(&p))
		frame[prediction.coordToInt(width) + width] = '2';
  }
  ++blinkTimer %= 5;
  if (blinkTimer == 0)
	blinkOn = !blinkOn;

  return frame;
}

void UI::clearHistory(){
	for (Point *point : history){
		delete point;
	}
	history.clear();
}

void UI::refreshBlink(){
	blinkOn = true;
	blinkTimer = 0;
}

bool UI::outOfBounds(Point *p) {
	bool oob = false;
	if (p->x < 0 || p->x > width - 1)
		oob = true;
	if (p->y < 0 || p->y > height - 1)
		oob = true;
	return oob;
}
