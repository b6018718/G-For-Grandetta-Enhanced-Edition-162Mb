#pragma once
#include "MapZone.h"
#include <vector>

using namespace std;

class Maps
{
public:
	Maps();
	~Maps();
	vector <MapZone> zone;

	int findCollision(MapZone mapZone, string name);
	void removeItem(int map, string name);

};

