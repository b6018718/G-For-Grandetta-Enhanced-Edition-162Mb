#include "SDL.h"
#include "sdl_mixer.h"
#include "SDL_TTF.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <vector>
#include "Music.h"
#include "Fonts.h"


const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;
using namespace std;

int main(int argc, char* args[])
{
	bool init(SDL_Window*& gWindow, SDL_Surface*& gScreenSurface);	//Function to create window
	
	bool loadMedia(SDL_Surface*& gHelloWorld);						//Function to load media from files
	void close(SDL_Window*& gWindow, SDL_Surface*& gHelloWorld, SDL_Surface* gPlaySurface, Music music, Fonts fonts);	//Function to free media and shut down SDL

	SDL_Window* gWindow = NULL;				//Window rendering to
	SDL_Surface* gScreenSurface = NULL;		//Surface contained by the window
	SDL_Surface* gPlaySurface = NULL;		//The image to load


	//Initalise fonts class
	TTF_Init();
	Fonts fonts;

	if (!init(gWindow, gScreenSurface))
	{
		printf("Failed to initalise\n");
	}
	else
	{
		//Load Media
		if (!loadMedia(gPlaySurface))
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
	

	//Initalise Music Class
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Music music;


	//START OF GAME
	music.SetVolume(5);
	music.PlayMenu();
	
	void MainMenu(SDL_Window*& gWindow, SDL_Surface*& gPlaySurface, SDL_Surface*& gScreenSurface, Music& music);
	MainMenu(gWindow, gPlaySurface, gScreenSurface, music);
	//SDL_Delay(2000);
	close(gWindow, gPlaySurface, gPlaySurface, music, fonts);

	system("pause");

	//Quit SDL
	SDL_Quit();

	return 0;
}

bool init(SDL_Window*& gWindow, SDL_Surface*& gScreenSurface)
{
	//Initalisation Flag
	bool success = true;

	//Initalise SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL Initalisation failed. Error Message: %s\n", SDL_GetError());
		success = false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
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

bool loadMedia(SDL_Surface*& gHelloWorld)
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

void close(SDL_Window*& gWindow, SDL_Surface*& gHelloWorld, SDL_Surface* gPlaySurface, Music music, Fonts fonts)
{
	
	font.FreeFonts();
	music.FreeSounds();

	//Dealocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//SDL_FreeSurface(gPlaySurface);
	//gPlaySurface = NULL;

	//Destroy Window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
	Mix_Quit();
	TTF_Quit();
}

void MainMenu(SDL_Window*& gWindow, SDL_Surface*& gPlaySurface, SDL_Surface*& gScreenSurface, Music& music)
{
	//Main Menu Variables
	bool press = false;
	vector <int> buttonX = { 480 - ((48 * 5) / 2), 480 - ((48 * 8) / 2), 480 - ((48 * 8) / 2) };
	vector <int> buttonY = { 50, 150, 250 };
	vector <int> buttonWidth = { 48 * 5, 48 * 8, 48 * 8 };
	vector <int> buttonHeight = { 48, 48, 48 };
	int settingsOrigin;
	bool quit = false;
	bool stop = false;
	int background;

	//double effectiveCurrentExp = 5;
	//double effectiveExpLevelUp = 10;
	void play(SDL_Window*& gWindow);
	void settings(SDL_Window*& gWindow);
	void clear(SDL_Surface*& gScreenSurface);
	void instructions(SDL_Window*& gWindow);
	void DrawEXPBar(int posX, int posY, double currentStat, double maxStat, string colour, SDL_Surface*& gScreenSurface, SDL_Window*& gWindow);
	//DrawEXPBar(25, 405, effectiveCurrentExp, effectiveExpLevelUp, "#ffff00", gScreenSurface, gWindow);
	
	//For events, eg keyboard, mouse, click
	SDL_Event event;

	//Mouse Variables
	float mouseX;
	float mouseY;
	float arrowX = 0;
	float arrowY = 0;
	float arrowWidth = 48;
	float arrowSize = 48;
	float arrowHeight = 48;
	bool arrowVisible = false;
	//arrow is the little pointer to the left of the button, visual element

	//Background animation variables
	int frames = 60;
	int timerID = 1;
	float backgroundX = 0;
	

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = true;
			if (event.type == SDL_MOUSEMOTION)
			{
				mouseX = event.motion.x;	//Gets the mouse position
				mouseY = event.motion.y;

				for (int i = 0; i < buttonX.size(); i++)
				{
					if (mouseX > buttonX[i] && mouseX < buttonX[i] + buttonWidth[i]) //If mouse is over X and Y of button
					{
						if (mouseY > buttonY[i] && mouseY < buttonY[i] + buttonHeight[i]) //Buttons are defined in the button array
						{
							arrowVisible = true;
							arrowX = buttonX[i] - (arrowWidth / 2) - 22;
							arrowY = buttonY[i];
						}
					}
					else
					{
						arrowVisible = false;
					}
				}
			}

			if (event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED && stop == false)
			{
				for (int i = 0; i < buttonX.size(); i++)
				{
					if (mouseX > buttonX[i] && mouseX < buttonX[i] + buttonWidth[i])
					{
						if (mouseY > buttonY[i] && mouseY < buttonY[i] + buttonHeight[i])
						{
							switch (i)
							{
								case 0:
									background = 0;
									stop = true;
									play(gWindow);
									break;
								case 1:
									stop = true;
									clear(gScreenSurface);
									settingsOrigin = 1;
									settings(gWindow);
									break;
								case 2:
									stop = true;
									instructions(gWindow);
									break;
							}
						}
					}
				}
			}

			
		}	//Poll Event While Loop
		void menuAnimation(SDL_Surface*& gScreenSurface, SDL_Surface*& gPlaySurface, SDL_Window*& gWindow, int frames, float& backgroundX);
		menuAnimation(gScreenSurface, gPlaySurface, gWindow, frames, backgroundX);
	}
}

void menuAnimation(SDL_Surface*& gScreenSurface, SDL_Surface*& gPlaySurface, SDL_Window*& gWindow, int frames, float& backgroundX)
{
	void clear(SDL_Surface*& gScreenSurface);
	SDL_Delay(1000 / frames);
	//clear(gScreenSurface);
	backgroundX = backgroundX - 0.5;
	if (backgroundX == -960)
		backgroundX = 0;
	SDL_Rect dest;
	dest.x = backgroundX;
	dest.y = 0;

	SDL_BlitSurface(gPlaySurface, NULL, gScreenSurface, &dest);
	SDL_UpdateWindowSurface(gWindow);
	
}

void play(SDL_Window*& gWindow)
{

}

void instructions(SDL_Window*& gWindow)
{

}

void clear(SDL_Surface*& gScreenSurface)
{
	SDL_FillRect(gScreenSurface, NULL, 0x000000);
}

void settings(SDL_Window*& gWindow)
{

}

void DrawEXPBar(int posX, int posY, double currentStat, double maxStat, string colour, SDL_Surface*& gPlaySurface, SDL_Window*& gWindow)
{
	int percentFill =  (currentStat / maxStat) * 520;
	if (percentFill < 0)
		percentFill = 0;

	SDL_Rect topRectangle = { posX + 4, posY, 520, 4 };			 // {X, Y, H, W}
	SDL_Rect botRectangle = { posX + 4,  posY + 28, 520, 4 };
	SDL_Rect leftRectangle = { posX,  posY + 4, 4, 24 };
	SDL_Rect rightRectangle = { posX + 524, posY + 4, 4, 24 };
	SDL_Rect expBar = { posX + 6, posY + 6, percentFill, 20 };

	SDL_FillRect(gPlaySurface, &topRectangle, SDL_MapRGB(gPlaySurface->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(gPlaySurface, &botRectangle, SDL_MapRGB(gPlaySurface->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(gPlaySurface, &leftRectangle, SDL_MapRGB(gPlaySurface->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(gPlaySurface, &rightRectangle, SDL_MapRGB(gPlaySurface->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(gPlaySurface, &expBar, SDL_MapRGB(gPlaySurface->format, 255, 255, 0));

	SDL_UpdateWindowSurface(gWindow);

}