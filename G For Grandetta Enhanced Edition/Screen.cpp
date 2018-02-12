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

void Screen::displayText(string text, float x, float y, TTF_Font* newfont) //Centered Middle
{	
	const char * charText = text.c_str();
	gText = TTF_RenderText_Shaded(newfont, charText, foregroundColor, backgroundColor);
	Uint32 colorkey = SDL_MapRGB(gText->format, 0, 0xFF, 0xFF);
	SDL_SetColorKey(gText, 1, colorkey);
	SDL_Rect textLocation = {  x - (gText->w)/2, y + 6, 0, 0 };
	SDL_BlitSurface(gText, NULL, gScreenSurface, &textLocation);
	SDL_FillRect(gText, NULL, 0x000000);
	SDL_FreeSurface(gText);
}

void Screen::displayLeftText(string text, float x, float y, TTF_Font* newfont)	//Centered Left
{
	const char * charText = text.c_str();
	gText = TTF_RenderText_Shaded(newfont, charText, foregroundColor, backgroundColor);
	Uint32 colorkey = SDL_MapRGB(gText->format, 0, 0xFF, 0xFF);
	SDL_SetColorKey(gText, 1, colorkey);
	SDL_Rect textLocation = { x, y - 24, 0, 0 };
	SDL_BlitSurface(gText, NULL, gScreenSurface, &textLocation);
	SDL_FillRect(gText, NULL, 0x000000);
	SDL_FreeSurface(gText);
}

bool Screen::messageBox(string line1, string line2, TTF_Font* font)	//35 Character Limit Per Line
{
	gTemp = gScreenSurface;
	gMessage = SDL_LoadBMP("images/messageBox.bmp");
	SDL_BlitSurface(gMessage, NULL, gScreenSurface, 0);

	foregroundColor = { 255, 255, 255 };
	displayLeftText(line1, 48, 528, font);
	if (line2 != "")
	{
		displayLeftText(line2, 48, 600, font);
	}

	SDL_UpdateWindowSurface(gWindow);
	SDL_FreeSurface(gMessage);
	SDL_Event event;

	bool gameExit = false;
	bool quit = false;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			//Window Exit Event
			if (event.type == SDL_QUIT)
			{
				gameExit = true;
				quit = true;
			}

			//Controller Button Event
			if (event.type == SDL_JOYBUTTONDOWN)
			{
				if (event.jbutton.button == 1)
				{
					quit = true;
				}
			}

			//Left click Event
			if (event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED)
			{
				quit = true;
			}

			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_RETURN)
				{
					quit = true;
				}

			}

		}//Event Poll While Loop
	}
	SDL_BlitSurface(gTemp, NULL, gScreenSurface, 0);
	SDL_UpdateWindowSurface(gWindow);
	SDL_FreeSurface(gTemp);
	SDL_FreeSurface(gScreenSurface);
	//SDL_FreeSurface(gMessage);
	return gameExit;
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

void Screen::updateMap(SDL_Surface*& surface, Player player, MapZone mapZone)
{
	float canXC = (float)(SCREEN_WIDTH - player.spriteSizeX) / 2;	//Can X Camera, If there is room left for the map to move
	float canYC = (float)(SCREEN_HEIGHT - player.spriteSizeY) / 2;	//Can Y Camera

	SDL_Rect bg;
	if (player.currentX < canXC)	//If the player is as far left as possible
	{
		bg.x = 0;
	}
	else if (player.currentX > canYC)	//If the player is as far right as possible
	{
		bg.x = SCREEN_WIDTH - mapZone.xDim;
	}
	else //otherwise...
	{
		bg.x = canXC - mapZone.xDim;	//the background needs to be as far across as possible
	}

	if (player.currentY < canYC) //If the player is as far up as possible
	{
		bg.y = 0;
	}
	else if(player.currentY > canYC) //If player is as far down as possible
	{
		bg.y = SCREEN_HEIGHT - mapZone.yDim + 160; //160???
	}
	else //otherwise
	{
		bg.y = canYC - mapZone.yDim;
	}

	SDL_BlitSurface(surface, NULL, gScreenSurface, &bg);
	SDL_UpdateWindowSurface(gWindow);
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
