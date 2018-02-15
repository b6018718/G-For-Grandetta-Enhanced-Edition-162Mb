#pragma once
#include <string>
using namespace std;

class Collision
{
public:
	Collision(string name, double x, double y, double xDim, double yDim, bool interactable, string interactType, string signText1, string signText2, string function);
	Collision(string name, double x, double y, double xDim, double yDim, bool interactable, string interactType, string signText1, string signText2);
	Collision(string name, double x, double y, double xDim, double yDim, bool interactable, string interactType);
	~Collision();

	string name;
	double x;		//X length of box
	double y;		//Y length of box
	double xDim;	//X Location on map
	double yDim;	//Y Location on map
	bool interactable;
	string interactType;
	string signText1;
	string signText2;
	string function;
};

