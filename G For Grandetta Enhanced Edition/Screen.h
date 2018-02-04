#pragma once

#include "SDL.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

using namespace std;

class Screen
{
public:
	Screen();
	~Screen();

	SDL_Window* gWindow = NULL;				//Window rendering to
	SDL_Surface* gScreenSurface = NULL;		//Surface contained by the window
	SDL_Surface* gPlaySurface = NULL;		//The image to load
	
	SDL_Surface* gMainMenuText = NULL;

	

	bool init(SDL_Window*& gWindow, SDL_Surface*& gScreenSurface, SDL_Surface*& gMainMenuText);
	
	void displayText(String text, float x, float y);

	bool loadInitialMedia(SDL_Surface*& gHelloWorld);
	
	bool loadMedia(SDL_Surface*& surface, string file);

	void FreeSurfaces();
};

