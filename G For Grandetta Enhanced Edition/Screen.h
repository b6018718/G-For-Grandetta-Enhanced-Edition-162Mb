#pragma once
#include "SDL.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "SDL_TTF.h"
#include "Maps.h"
#include "Player.h"
#include "MapZone.h"

//const int SCREEN_WIDTH = 960;
//const int SCREEN_HEIGHT = 640;

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
	SDL_Surface* gMessage = NULL;
	SDL_Surface* gTemp = NULL;
	SDL_Surface* gSprite = NULL;
	SDL_Surface* gEnemy = NULL;
	SDL_Surface* gBattleBg = NULL;
	SDL_Surface* gBattleTextBox = NULL;
	SDL_Surface* gCoin = NULL;
	SDL_Surface* gWeaponIcon = NULL;
	SDL_Surface* gSelectIcon = NULL;

	SDL_Color foregroundColor = { 0, 0, 0 };
	SDL_Color backgroundColor = { 0, 255, 255 };

	


	bool init(SDL_Window*& gWindow, SDL_Surface*& gScreenSurface);
	
	void displayText(string text, float x, float y, TTF_Font* font);

	void displayLeftText(string text, float x, float y, TTF_Font * newfont);

	bool messageBox(string line1, string line2, TTF_Font* fonts);

	bool inputBox(string line1, string line2, TTF_Font* fonts, Player& player);

	bool loadMapMedia(SDL_Surface*& surface, string file);
	
	bool loadMedia(SDL_Surface*& surface, string file);

	void updateMap(SDL_Surface*& surface, Player& player, MapZone mapZone, Maps& maps);

	void FreeSurfaces();
};

