#pragma once
#include <string>
using namespace std;

class Collision
{
public:
	Collision(string name, int x, int y, int xDim, int yDim, bool interactable, string interactType, string signText1, string signText2, string function);
	Collision(string name, int x, int y, int xDim, int yDim, bool interactable, string interactType, string signText1, string signText2);
	Collision(string name, int x, int y, int xDim, int yDim, bool interactable, string interactType);
	~Collision();

	string name;
	int x;		//X length of box
	int y;		//Y length of box
	int xDim;	//X Location on map
	int yDim;	//Y Location on map
	bool interactable;
	string interactType;
	string signText1;
	string signText2;
	string function;
};

