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

	int xDim;	//X Size of Map
	int yDim;	//Y Size Of Map
	string name;
	vector <Collision> collisions;

};

