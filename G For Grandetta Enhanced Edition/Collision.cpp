#include "Collision.h"



Collision::Collision(string name, double x, double y, double xDim, double yDim, bool interactable, string interactType, vector <string> text, string function)
{
	this->name = name;
	this->x = x * 32;
	this->y = y * 32;
	this->xDim = xDim * 32;
	this->yDim = yDim * 32;
	this->interactable = interactable;
	this->interactType = interactType;
	this->text = text;
	this->function = function;
}

Collision::Collision(string name, double x, double y, double xDim, double yDim, bool interactable, string interactType, vector <string> text)
{
	this->name = name;
	this->x = x * 32;
	this->y = y * 32;
	this->xDim = xDim * 32;
	this->yDim = yDim * 32;
	this->interactable = interactable;
	this->interactType = interactType;
	this->text = text;
}

Collision::Collision(string name, double x, double y, double xDim, double yDim, bool interactable, string interactType)
{
	this->name = name;
	this->x = x * 32;
	this->y = y * 32;
	this->xDim = xDim * 32;
	this->yDim = yDim * 32;
	this->interactable = interactable;
	this->interactType = interactType;
}


Collision::~Collision()
{
}
