#include "Screen.h"
#include "SDL.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;
Screen::Screen()
{
	init(gWindow, gScreenSurface, gMainMenuText);
	if (!init(gWindow, gScreenSurface, gMainMenuText))
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
			//Apply image
			SDL_BlitSurface(gPlaySurface, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
			//SDL_Delay(2000);
		}
	}
}


Screen::~Screen()
{
}

bool Screen::init(SDL_Window *& gWindow, SDL_Surface *& gScreenSurface, SDL_Surface *& gMainMenuText)
{
	//Initalisation Flag
	bool success = true;

	//Initalise SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
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

void Screen::displayText(String text, float x, float y)
{
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

	SDL_FreeSurface(gMainMenuText);
	gScreenSurface = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
}
