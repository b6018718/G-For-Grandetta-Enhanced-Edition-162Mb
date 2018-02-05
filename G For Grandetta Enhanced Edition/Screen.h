#pragma once

#include "SDL.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "SDL_TTF.h"
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
	
	SDL_Surface* gText = NULL;

	SDL_Color foregroundColor = { 0, 0, 0 };
	SDL_Color backgroundColor = { 0, 255, 255 };

	bool init(SDL_Window*& gWindow, SDL_Surface*& gScreenSurface);
	
	void displayText(string text, float x, float y, TTF_Font* font);

	bool loadInitialMedia(SDL_Surface*& gHelloWorld);
	
	bool loadMedia(SDL_Surface*& surface, string file);

	void FreeSurfaces();
};

