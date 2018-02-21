#include "Screen.h"
#include "SDL.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "SDL_TTF.h"
#include "Fonts.h"
#include "Maps.h"

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
		if (!loadMapMedia(gPlaySurface, "images/bg0.bmp"))
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply image
			SDL_BlitSurface(gPlaySurface, NULL, gScreenSurface, NULL);
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
	//Transparent Background
	Uint32 colorkey = SDL_MapRGB(gText->format, 0, 0xFF, 0xFF);
	SDL_SetColorKey(gText, 1, colorkey);
	SDL_Rect textLocation = {  x - (gText->w)/2, y + 6, 0, 0 };
	SDL_BlitSurface(gText, NULL, gScreenSurface, &textLocation);
	SDL_FillRect(gText, NULL, 0x000000);
	SDL_FreeSurface(gText);
}

void Screen::displayLeftText(string text, float x, float y, TTF_Font* newfont)	//Centered Left
{
	if (text == "")
	{
		text = "NULL";
	}
	const char * charText = text.c_str();
	gText = TTF_RenderText_Shaded(newfont, charText, foregroundColor, backgroundColor);
	Uint32 colorkey = SDL_MapRGB(gText->format, 0, 0xFF, 0xFF);
	SDL_SetColorKey(gText, 1, colorkey);
	SDL_Rect textLocation = { x, y - 24, 0, 0 };
	SDL_BlitSurface(gText, NULL, gScreenSurface, &textLocation);
	//SDL_UpdateWindowSurface(gWindow);
	SDL_FillRect(gText, NULL, 0x000000);
	SDL_FreeSurface(gText);
	//SDL_FreeSurface(gScreenSurface);
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
	SDL_Delay(100);
	SDL_BlitSurface(gTemp, NULL, gScreenSurface, 0);
	SDL_UpdateWindowSurface(gWindow);
	SDL_FreeSurface(gTemp);
	SDL_FreeSurface(gScreenSurface);
	//SDL_FreeSurface(gMessage);
	return gameExit;
}


bool Screen::inputBox(string line1, string line2, TTF_Font* font, Player& player)	//9 Character Limit
{
	//gTemp = gScreenSurface;
	gMessage = SDL_LoadBMP("images/messageBox.bmp");
	SDL_BlitSurface(gMessage, NULL, gScreenSurface, 0);

	foregroundColor = { 255, 255, 255 };
	displayLeftText(line1, 48, 528, font);
	if (line2 != "")
	{
		displayLeftText(line2, 48, 600, font);
	}

	SDL_UpdateWindowSurface(gWindow);

	SDL_Event event;
	bool gameExit = false;
	bool quit = false;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			//Exit Window Event
			if (event.type == SDL_QUIT)
			{
				quit = true;
				gameExit = true;
			}

			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_BACKSPACE && player.name.length() > 0)
				{
					SDL_BlitSurface(gMessage, NULL, gScreenSurface, 0);
					displayLeftText(line1, 48, 528, font);
					player.name.pop_back();
					if (player.name.length() > 0)
						displayLeftText(player.name, 48, 600, font);
					SDL_UpdateWindowSurface(gWindow);
				}
				else if (event.key.keysym.sym == SDLK_RETURN)
				{
					quit = true;
				}
			}

			//Text Input
			if (event.type == SDL_TEXTINPUT && player.name.length() < 8)
			{
				SDL_BlitSurface(gMessage, NULL, gScreenSurface, 0);
				displayLeftText(line1, 48, 528, font);
				player.name += event.text.text;
				displayLeftText(player.name, 48, 600, font);
				SDL_UpdateWindowSurface(gWindow);
			}

			//Controller Button Event
			if (event.type == SDL_JOYBUTTONDOWN)
			{
				if (event.jbutton.button == 1)
				{
					quit = true;
				}

			}

		}//Event poll while loop
	}

	//SDL_BlitSurface(gTemp, NULL, gScreenSurface, 0);
	//SDL_FreeSurface(gTemp);
	SDL_FreeSurface(gMessage);
	SDL_FreeSurface(gScreenSurface);
	return gameExit;
}

bool Screen::loadMapMedia(SDL_Surface *& surface, string file)
{
	//Load success flag
	bool success = true;
	//Convert string to const char format
	const char * load = file.c_str();

	//Load image
	gTemp = SDL_LoadBMP(load);
	if (gTemp == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	surface = SDL_ConvertSurfaceFormat(gTemp, SDL_GetWindowPixelFormat(gWindow), 0);
	SDL_FreeSurface(gTemp);
	return success;
}

bool Screen::loadMedia(SDL_Surface *& surface, string file)
{

	const char * load = file.c_str();
	surface = NULL;
	SDL_Surface* loadedSurface = NULL;
	//Load image at specified path
	loadedSurface = SDL_LoadBMP(load);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", load, SDL_GetError());
	}
	else
	{
		surface = SDL_ConvertSurfaceFormat(loadedSurface, SDL_PIXELFORMAT_ARGB8888, 0);

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
		
	}
	return true;
}

void Screen::updateMap(SDL_Surface*& surface, Player& player, MapZone mapZone, Maps& maps)
{
	float canXC = (float)(SCREEN_WIDTH - player.spriteSizeX) / 2;	//Can X Camera, If there is room left for the map to move
	float canYC = (float)(SCREEN_HEIGHT - player.spriteSizeY) / 2;	//Can Y Camera

	SDL_Rect bg;

	if (player.x < canXC)
	{
		bg.x = 0;	//Is as far left as possible
		
	}
	else if (player.x > canXC)
	{
		bg.x = SCREEN_WIDTH - mapZone.xDim;	//Is as far right as possible
		
	}
	else
	{
		bg.x = canXC - player.map.x;	//Is in the middle of the X axis of the map
		
	}


	if (player.y < canYC)	
	{
		bg.y = 0; //Is in as far up as possible
	}
	else if (player.y > canYC)
	{
		bg.y = SCREEN_HEIGHT - mapZone.yDim + 160; //Is as far down as possible
	}
	else
	{
		bg.y = canYC - player.map.y; //Is in middle of the Y axis of the map
		
	}

	//cout << "Background X " << bg.x/32 << "\n";
	//cout << "Background Y " << bg.y/32 << "\n";
	

	//Display Dog
	if (player.questLoaded == false)
	{
		switch (player.currentMap)
		{
			case 0:	//Village Events
				if ((player.currentQuest == 0 && player.currentQuestPoint < 2) || player.currentQuest == 7)
				{
					while (maps.findCollision(maps.zone[player.currentMap], "villageWizard") != -1)
						maps.removeItem(0, "villageWizard");
					if (maps.findCollision(maps.zone[player.currentMap], "villageDog") == -1)
						maps.zone[0].collisions.push_back(Collision("villageDog", 8, 5, 1, 1, true, "quest", { "*Woof woof*", "I think it's telling me to leave..." }, "dogFunction"));
					if (!loadMedia(gTemp, "images/woof.bmp"))
						cout << "Cannot load media";
					SDL_Rect position;
					position.x = (8 * 32);
					position.y = (5 * 32);
					SDL_BlitSurface(gTemp, NULL, gPlaySurface, &position);
					player.questLoaded = true;
					SDL_FreeSurface(gTemp);
					//maps.removeItem(0, "villageDog");
				}
				//else if (player.currentQuest == 0 && player.currentQuestPoint == 2)
				//{  //@
				//	while (maps.findCollision(maps.zone[player.currentMap], "villageDog") != -1)
				//		maps.removeItem(0, "villageDog");
				//	loadMapMedia(gPlaySurface, "images/bg0.bmp");
				//	player.questLoaded = true;
				//}
				else if (player.currentQuest == 6)
				{
					if (maps.findCollision(maps.zone[player.currentMap], "villageWizard") == -1)
						maps.zone[0].collisions.push_back(Collision("villageWizard", 9, 5, 1, 2, true, "quest", {"Prepare to die", " You fool!"}, "wizFunction"));
				}
			
				break;
			case 3:	//Castle Events
				if (player.currentQuest < 6)
				{
					if (!loadMedia(gTemp, "images/overworldWizard.bmp"))
						cout << "Cannot load media";
					SDL_Rect position;
					position.x = (55 * 32);
					position.y = (32 * 32);
					SDL_BlitSurface(gTemp, NULL, gPlaySurface, &position);
					player.questLoaded = true;
					SDL_FreeSurface(gTemp);
				}
				else if (player.currentQuest == 6)
				{
					while (maps.findCollision(maps.zone[player.currentMap], "castleWizard") != -1)
						maps.removeItem(0, "castleWizard");
					//loadMapMedia(gPlaySurface, "images/bg3.bmp");
				}
					
		}
	}
	

	
	//loadMedia(gPlaySurface, "images/bg0.bmp");
	SDL_BlitSurface(gPlaySurface, NULL, gScreenSurface, &bg);
	
}

void Screen::FreeSurfaces()
{
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	SDL_FreeSurface(gText);
	gScreenSurface = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_FreeSurface(gMessage);
	gMessage = NULL;

	//SDL_FreeSurface(gTemp);
	gTemp = NULL;

	SDL_FreeSurface(gSprite);
	gSprite = NULL;

	SDL_FreeSurface(gBattleBg);
	gBattleBg = NULL;
	SDL_FreeSurface(gBattleTextBox);
	gBattleTextBox = NULL;
	SDL_FreeSurface(gEnemy);
	gEnemy = NULL;
}
