#include "Collision.h"



Collision::Collision(string name, int x, int y, int xDim, int yDim, bool interactable, string interactType, string signText1, string signText2, string function)
{
	this->name = name;
	this->x = x * 32;
	this->y = y * 32;
	this->xDim = xDim * 32;
	this->yDim = yDim * 32;
	this->interactable = interactable;
	this->interactType = interactType;
	this->signText1 = signText1;
	this->signText2 = signText2;
	this->function = function;
}

Collision::Collision(string name, int x, int y, int xDim, int yDim, bool interactable, string interactType, string signText1, string signText2)
{
	this->name = name;
	this->x = x * 32;
	this->y = y * 32;
	this->xDim = xDim * 32;
	this->yDim = yDim * 32;
	this->interactable = interactable;
	this->interactType = interactType;
	this->signText1 = signText1;
	this->signText2 = signText2;
}

Collision::Collision(string name, int x, int y, int xDim, int yDim, bool interactable, string interactType)
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
