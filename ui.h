#ifndef UI_H
#define UI_H

#include "point.h"
#include <string>
#include <vector>
class UI
{
private:
	bool blinkOn;
	int blinkTimer;
	int width, height;
	std::string drawPrediction(std::string frame);
	std::string drawHistory(std::string frame);
	bool outOfBounds(Point *p);
public:
	UI(int w, int h);
	std::vector<Point*> history;
	void clearHistory();
	std::string draw(std::string frame, int w, int h);
	Point prediction;
	void refreshBlink();
};

#endif // UI_H
