#ifndef TILE_H
#define TILE_H

#include "drawable.h"
#include "point.h"
#include <vector>
class Tile : public Drawable
{
public:
	Tile(Point l, char terrain);
};

#endif // TILE_H
