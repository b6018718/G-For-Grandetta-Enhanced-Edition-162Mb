#include "Screen.h"
#include "SDL.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "SDL_TTF.h"
#include "Fonts.h"

using namespace std;
Screen::Screen()
{
	if (!init(gWindow, gScreenSurface))
	{
		printf("Failed to initalise\n");
	}
	else
	{
		//Load Media
		if (!loadInitialMedia(gPlaySurface))
		{
			printf("Failed to load media!\n");
		}
		else
		{
			SDL_SetColorKey(gScreenSurface, SDL_TRUE, SDL_MapRGB(gScreenSurface->format, 0, 0xFF, 0xFF));
			//Apply image
			SDL_BlitSurface(gPlaySurface, NULL, gScreenSurface, NULL);
			//SDL_UpdateWindowSurface(gWindow);
			//SDL_Delay(2000);
		}
	}
}


Screen::~Screen()
{
}

bool Screen::init(SDL_Window *& gWindow, SDL_Surface *& gScreenSurface)
{
	//Initalisation Flag
	bool success = true;

	SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");

	//Initalise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL Initalisation failed. Error Message: %s\n", SDL_GetError());
		success = false;
	}

	else
	{
		//Create Window
		gWindow = SDL_CreateWindow("G For Grandetta Enhanced Edition", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get Window Surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

void Screen::displayText(string text, float x, float y, TTF_Font* newfont)
{	
	const char * charText = text.c_str();
	gText = TTF_RenderText_Shaded(newfont, charText, foregroundColor, backgroundColor);	Uint32 colorkey = SDL_MapRGB(gText->format, 0, 0xFF, 0xFF);	SDL_SetColorKey(gText, 1, colorkey);	SDL_Rect textLocation = {  x - (gText->w)/2, y, 0, 0 };	SDL_BlitSurface(gText, NULL, gScreenSurface, &textLocation);	SDL_FillRect(gText, NULL, 0x000000);	SDL_FreeSurface(gText);
}

bool Screen::loadInitialMedia(SDL_Surface *& gHelloWorld)
{
	//Load success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("images/bg0.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Screen::loadMedia(SDL_Surface *& surface, string file)
{
	//Load success flag
	bool success = true;

	const char * load = file.c_str();

	//Load splash image
	surface = SDL_LoadBMP(load);
	if (surface == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Screen::FreeSurfaces()
{
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	SDL_FreeSurface(gText);
	gScreenSurface = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
}
