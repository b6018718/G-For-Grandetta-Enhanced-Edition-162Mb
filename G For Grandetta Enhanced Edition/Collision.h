#pragma once
#include <string>
#include <vector>
using namespace std;

class Collision
{
public:
	Collision(string name, double x, double y, double xDim, double yDim, bool interactable, string interactType, vector <string> text, string function);
	Collision(string name, double x, double y, double xDim, double yDim, bool interactable, string interactType, vector <string> text);
	Collision(string name, double x, double y, double xDim, double yDim, bool interactable, string interactType);
	~Collision();

	string name;
	double x;		//X length of box
	double y;		//Y length of box
	double xDim;	//X Location on map
	double yDim;	//Y Location on map
	bool interactable = false;
	string interactType = "";
	vector <string> text;
	string function = "";
	
};

