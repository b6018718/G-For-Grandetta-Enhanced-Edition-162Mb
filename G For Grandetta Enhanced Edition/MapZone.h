#pragma once
#include <string>
#include <vector>
#include "Collision.h"
using namespace std;
class MapZone
{
public:
	MapZone(int x, int y, string name);
	~MapZone();

	int xDim;
	int yDim;
	string name;
	vector <Collision> collisions;

};

