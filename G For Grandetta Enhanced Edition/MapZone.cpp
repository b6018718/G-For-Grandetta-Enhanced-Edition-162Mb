#include "MapZone.h"



MapZone::MapZone(int x, int y, string name)
{
	xDim = x * 32;
	yDim = y * 32;
	this->name = name;
}


MapZone::~MapZone()
{
}
