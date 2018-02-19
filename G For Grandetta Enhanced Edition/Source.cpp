#include "SDL.h"
#include "sdl_mixer.h"
#include "SDL_TTF.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <math.h>
#include <vector>
#include "Music.h"
#include "Fonts.h"
#include "Screen.h"
#include "Player.h"
#include "SDL_gamecontroller.h"
#include "Maps.h"
#include "Mobs.h"
#include "Equipment.h"

using namespace std;

const int JOYSTICK_DEAD_ZONE = 8000;

int main(int argc, char* args[])
{
	srand(time(NULL));
	void close(Screen screen, Music music, Fonts fonts);	//Function to free media and shut down SDL

	//Initalise Screen Class
	Screen screen;

	//Initalise Music Class
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Music music;

	//Initalise Fonts Class
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}

	//Initalise Fonts
	Fonts fonts;

	//START OF GAME
	//music.SetVolume(5);
	music.PlayMenu();

	//Initalise Controller Support
	SDL_Joystick* gGameController = NULL;

	if (SDL_NumJoysticks() < 1)
	{
		printf("Warning: No joysticks connected!\n");
	}
	else
	{
		//Load joystick
		gGameController = SDL_JoystickOpen(0);
		if (gGameController == NULL)
		{
			printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
		}
	}

	if (SDL_NumJoysticks() < 1)
	{
		printf("Warning: No joysticks connected!\n");
	}
	
	void MainMenu(Screen screen, Music& music, Fonts& fonts, SDL_Joystick* gGameController);
	MainMenu(screen, music, fonts, gGameController);
	//SDL_Delay(2000);
	close(screen, music, fonts);

	//Close game controller
	if (gGameController != NULL)
	{
		//SDL_JoystickClose(gGameController);
		gGameController = NULL;
	}

	system("pause");
	//Quit SDL
	SDL_Quit();

	return 0;
}

void close(Screen screen, Music music, Fonts fonts)
{
	//Free assets
	fonts.FreeFonts();
	music.FreeSounds();
	screen.FreeSurfaces();

	//Quit SDL subsystems
	SDL_Quit();
	Mix_Quit();
	TTF_Quit();
}

void MainMenu(Screen screen, Music& music, Fonts& fonts, SDL_Joystick* gGameController)
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
	bool play(Screen screen, Music music, Fonts fonts);
	bool settings(Screen screen, Music& music, Fonts fonts);
	void clear(SDL_Surface*& gScreenSurface);
	bool instructions(Screen screen);
	void menuAnimation(Screen screen, int frames, float& backgroundX, Fonts fonts, vector <int> buttonY, int arrowX, int arrowY);
	void DrawEXPBar(int posX, int posY, double currentStat, double maxStat, string colour, Screen& screen);
	//DrawEXPBar(25, 405, 50, 100, "#ffff00", screen);
	//For events, eg keyboard, mouse, click
	SDL_Event event;

	//Mouse Variables
	float mouseX = 0;
	float mouseY = 0;
	float arrowWidth = 48;
	float arrowSize = 48;
	float arrowHeight = 48;
	float arrowX = buttonX[0] - (arrowWidth / 2) - 22;
	float arrowY = buttonY[0];

	SDL_GameController *controller = NULL;
	controller = SDL_GameControllerOpen(0);
	
	//bool arrowVisible = false;
	//arrow is the little pointer to the left of the button, visual element

	SDL_GetColorKey;


	//Background animation variables
	int frames = 60;
	int timerID = 1;
	float backgroundX = 0;
	int cursorPos = 0;

	SDL_JoystickEventState(SDL_ENABLE);

	//Check Joystick
	/*
	int num_axes = SDL_JoystickNumAxes(gGameController);
	int num_buttons = SDL_JoystickNumButtons(gGameController);
	int num_hats = SDL_JoystickNumHats(gGameController);
	int num_balls = SDL_JoystickNumBalls(gGameController);

	SDL_JoystickGUID guid = SDL_JoystickGetGUID(gGameController);
	char guid_str[1024];
	SDL_JoystickGetGUIDString(guid, guid_str, sizeof(guid_str));
	const char* name = SDL_JoystickName(gGameController);
	*/
	

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			//Exit Window Event
			if (event.type == SDL_QUIT)
				quit = true;

			//Controller Axis Event
			if (event.type == SDL_JOYAXISMOTION)
			{
				//X axis motion
				/*if (event.jaxis.axis == 0)
				{
					//Left of dead zone
					if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
					{
						cout << "LEFT";
					}
					//Right of dead zone
					else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
					{
						cout << "RIGHT";
					}
					else
					{
						cout << "CENTRE";
					}
				}
				else */
				if (event.jaxis.axis == 1)
				{
					//Below of dead zone
					if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
					{
						if (cursorPos < buttonX.size() - 1)
						{
							++cursorPos;
							arrowX = buttonX[cursorPos] - (arrowWidth / 2) - 22;
							arrowY = buttonY[cursorPos];
						}
					}
					//Above of dead zone
					else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
					{
						if (cursorPos > 0)
						{
							--cursorPos;
							arrowX = buttonX[cursorPos] - (arrowWidth / 2) - 22;
							arrowY = buttonY[cursorPos];
						}
					}
				}
			}

			//Controller Movement Event
			if (event.type == SDL_JOYHATMOTION)
			{
				if (event.jhat.value == SDL_HAT_UP)
				{
					if (cursorPos > 0)
					{
						--cursorPos;
						arrowX = buttonX[cursorPos] - (arrowWidth / 2) - 22;
						arrowY = buttonY[cursorPos];
					}
				}
				//if (event.jhat.value == SDL_HAT_LEFT)
					//cout << "LEFT\n";
				//if (event.jhat.value == SDL_HAT_RIGHT)
					//cout << "RIGHT\n";
				if (event.jhat.value == SDL_HAT_DOWN)
				{
					if (cursorPos < buttonX.size() - 1)
					{
						++cursorPos;
						arrowX = buttonX[cursorPos] - (arrowWidth / 2) - 22;
						arrowY = buttonY[cursorPos];
					}
				}
			}

			//Mouse Movement Event
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
							cursorPos = i;
							arrowX = buttonX[i] - (arrowWidth / 2) - 22;
							arrowY = buttonY[i];
						}
					}
				}
			} 

			//Mouse Button Event
			if (event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED && stop == false)
			{
				for (int i = 0; i < buttonX.size(); i++)	//If mouse left clicks the button
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
									quit = play(screen, music, fonts);
									break;
								case 1:
									clear(screen.gScreenSurface);
									settingsOrigin = 1;
									quit = settings(screen, music, fonts);
									break;
								case 2:
									quit = instructions(screen);
									break;
							}
						}
					}
				}
			}
			
			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)
				{
					if (cursorPos > 0)
					{
						--cursorPos;
						arrowX = buttonX[cursorPos] - (arrowWidth / 2) - 22;
						arrowY = buttonY[cursorPos];
					}
				}
				else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)
				{
					if (cursorPos < buttonX.size() - 1)
					{
						++cursorPos;
						arrowX = buttonX[cursorPos] - (arrowWidth / 2) - 22;
						arrowY = buttonY[cursorPos];
					}
				}
				else if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE)
				{
					switch (cursorPos)
					{
					case 0:
						background = 0;
						stop = true;
						quit = play(screen, music, fonts);
						break;
					case 1:
						stop = true;
						clear(screen.gScreenSurface);
						settingsOrigin = 1;
						quit = settings(screen, music, fonts);
						break;
					case 2:
						stop = true;
						quit = instructions(screen);
						break;
					}
				}
			}
			
			//Controller Button Event
			if (event.type == SDL_JOYBUTTONDOWN)
			{
				if (event.jbutton.button == 0)
				{
					cout << "DOWN\n";
				}
				else if (event.jbutton.button == 1)
				{
					//cout << "RIGHT\n";
					switch (cursorPos)
					{
					case 0:
						background = 0;
						stop = true;
						clear(screen.gScreenSurface);
						quit = play(screen, music, fonts);
						break;
					case 1:
						stop = true;
						clear(screen.gScreenSurface);
						settingsOrigin = 1;
						quit = settings(screen, music, fonts);
						backgroundX = 0;
						break;
					case 2:
						stop = true;
						clear(screen.gScreenSurface);
						quit = instructions(screen);
						backgroundX = 0;
						break;
					}
				}
				else if (event.jbutton.button == 2)
				{
					cout << "LEFT\n";
				}
				else if (event.jbutton.button == 3)
				{
					cout << "UP\n";
				}
				else
				{
					cout << "Unknown button\n";
				}
			}
			
		}	//Poll Event While Loop

		if (!quit)
		{
			menuAnimation(screen, frames, backgroundX, fonts, buttonY, arrowX, arrowY);
		}

	}
	SDL_GameControllerClose(controller); //Close Controller
}

void menuAnimation(Screen screen, int frames, float& backgroundX, Fonts fonts, vector <int> buttonY, int arrowX, int arrowY)
{
	void clear(SDL_Surface*& gScreenSurface);
	SDL_Delay(1000 / frames);
	
	clear(screen.gScreenSurface);
	backgroundX = backgroundX - 1;
	if (backgroundX == -960)
		backgroundX = 0;
	SDL_Rect dest;
	dest.x = backgroundX;
	dest.y = 0;
	SDL_BlitSurface(screen.gPlaySurface, NULL, screen.gScreenSurface, &dest);
	
	//					Text			X			Y			Font
	screen.displayText("Start", SCREEN_WIDTH/2, buttonY[0], fonts.font48);
	screen.displayText("Settings", SCREEN_WIDTH / 2, buttonY[1], fonts.font48);
	screen.displayText("Controls", SCREEN_WIDTH / 2, buttonY[2], fonts.font48);
	screen.displayText(">", arrowX, arrowY + 6, fonts.font48);

	SDL_UpdateWindowSurface(screen.gWindow);
	clear(screen.gScreenSurface);
	
}

bool play(Screen screen, Music music, Fonts fonts)
{
	void clear(SDL_Surface*& gScreenSurface);
	music.PlayVillage();
	int classSelected;
	bool gameExit = false;
	bool quit = false;

	Player player;
	Maps maps;
	Mobs mobs;

	player.questLoaded = true;

	bool classSelect(Screen screen, Music music, Fonts fonts, Player& player);
	bool setName(Screen screen, Fonts fonts, Player& player);
	bool interact(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music);
	int getRandomInt(int min, int max);
	bool turnBasedBattle(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music, Mobs mobs);

	gameExit = classSelect(screen, music, fonts, player);
	screen.gPlaySurface = NULL;
	screen.loadMedia(screen.gPlaySurface, "images/bg" + to_string(player.currentMap) + ".bmp");

	screen.updateMap(screen.gPlaySurface, player, maps.zone[player.currentMap], maps);
	
	//Load Sprite
	string classSprite = "images/" + player.pClass + ".bmp";
	screen.loadMedia(screen.gSprite, classSprite);
	void updateSprite(Screen screen, Player& player);
	updateSprite(screen, player);

	//Call input box for name entry
	gameExit = screen.inputBox("Enter your name:", player.name, fonts.font24, player);
	screen.updateMap(screen.gPlaySurface, player, maps.zone[player.currentMap], maps);
	updateSprite(screen, player);

	SDL_Event event;

	player.questLoaded = false;
	int battleBuffer = 0; //Inrements with every step
	bool controllerLeft = false;
	bool controllerRight = false;
	bool controllerUp = false;
	bool controllerDown = false;

	while (!quit)
	{
		float startTime = (float) SDL_GetTicks();
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
				if (event.jbutton.button == 0)
				{
					//Open Inventory
				}
				if (event.jbutton.button == 1)
				{
					gameExit = interact(player, screen, maps, fonts, music);
				}
				if (event.jbutton.button == 2)
				{
					//Open options
				}
			}

			//Controller Movement Event
			if (event.type == SDL_JOYHATMOTION)
			{
				if (event.jhat.value == SDL_HAT_LEFT)
				{
					controllerLeft = true;
					controllerRight = false;
					controllerUp = false;
					controllerDown = false;
					
				}

				if (event.jhat.value == SDL_HAT_RIGHT)
				{
					controllerLeft = false;
					controllerRight = true;
					controllerUp = false;
					controllerDown = false;
				}

				if (event.jhat.value == SDL_HAT_DOWN)
				{
					controllerLeft = false;
					controllerRight = false;
					controllerUp = false;
					controllerDown = true;
				}

				if (event.jhat.value == SDL_HAT_UP)
				{
					controllerLeft = false;
					controllerRight = false;
					controllerUp = true;
					controllerDown = false;
				}

				if (event.jhat.value == SDL_HAT_CENTERED)
				{
					controllerLeft = false;
					controllerRight = false;
					controllerUp = false;
					controllerDown = false;
				}

				if (event.jhat.value == SDL_HAT_LEFTDOWN)
				{
					controllerLeft = true;
					controllerRight = false;
					controllerUp = false;
					controllerDown = true;
				}

				if (event.jhat.value == SDL_HAT_LEFTUP)
				{
					controllerLeft = true;
					controllerRight = false;
					controllerUp = true;
					controllerDown = false;
				}

				if (event.jhat.value == SDL_HAT_RIGHTDOWN)
				{
					controllerLeft = false;
					controllerRight = true;
					controllerUp = false;
					controllerDown = true;
				}

				if (event.jhat.value == SDL_HAT_RIGHTUP)
				{
					controllerLeft = false;
					controllerRight = true;
					controllerUp = true;
					controllerDown = false;
				}
				//screen.updateMap(screen.gScreenSurface, player, maps.zone[player.currentMap], maps);
				//updateSprite(screen, player);
				//++battleBuffer;
			}

			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{

				if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_e)
				{
					//Interact
					gameExit = interact(player, screen, maps, fonts, music);
				}

				if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_SPACE)
				{
					//Open Inventory
					//cout << "Player X: " << player.x/32 << "\n";
					//cout << "Player Y: " << player.y/32 << "\n";
					//cout << "Map X: " << player.map.x/32 << "\n";
					//cout << "Map Y: " << player.map.y/32 << "\n";
				}

				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					//Open Options
				}
			}
		}

		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

		if (!currentKeyStates[NULL])
		{
			
			if (currentKeyStates[SDL_SCANCODE_LEFT] || currentKeyStates[SDL_SCANCODE_A])
			{
				//Move left
				player.moveLeft(maps);
				++battleBuffer;

			}
			if (currentKeyStates[SDL_SCANCODE_RIGHT] || currentKeyStates[SDL_SCANCODE_D])
			{
				//Move left
				player.moveRight(maps);
				++battleBuffer;
			}
			if (currentKeyStates[SDL_SCANCODE_UP] || currentKeyStates[SDL_SCANCODE_W])
			{
				//Move left
				player.moveUp(maps);
				++battleBuffer;
			}
			if (currentKeyStates[SDL_SCANCODE_DOWN] || currentKeyStates[SDL_SCANCODE_S])
			{
				//Move left
				player.moveDown(maps);
				++battleBuffer;
			}
			
		}
		
		//Move between areas switch statement
		switch (player.currentMap)
		{
			case 0: //Village Map
				if (player.map.y == 29 * 32 && player.map.x >= 9 * 32 && player.map.x <= 12 * 32 && player.y == 19 * 32)
				{
					//Village -> Field
					clear(screen.gPlaySurface);					//NEED THIS TO PREVENT MEMORY LEAKS
					SDL_FreeSurface(screen.gPlaySurface);		//MEMORY FIX
					screen.gPlaySurface = NULL;					//MEMORY FIX

					player.currentMap = 1;
					screen.loadMapMedia(screen.gPlaySurface, "images/bg1.bmp");
					player.map.y = 1 * 32;
					player.y = 1 * 32;
					player.questLoaded = false;

					music.PlayField();
				}
				break;
			case 1:	//Field Map
				if ((player.map.y <= 0) && (player.map.x >= 9 * 32) && (player.map.x <= 12 * 32) && (player.y == 0))
				{
					//Field -> Village
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					if (player.currentQuest == 6 && player.currentQuestPoint == 0)
						++player.currentQuestPoint;

					player.currentMap = 0;
					screen.loadMapMedia(screen.gPlaySurface, "images/bg0.bmp");
					player.map.y = 28 * 32;
					player.y = 18 * 32;
					player.questLoaded = false;

					music.PlayVillage();
				}
				else if (player.map.y == 49 * 32 && player.map.x >= 39 * 32 && player.map.x <= 44 * 32)
				{
					//Field -> Castle Town
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					screen.loadMapMedia(screen.gPlaySurface, "images/bg2.bmp");

					player.currentMap = 2;
					player.map.y = 1 * 32;
					player.y = 1 * 32;

					player.questLoaded = false;
					music.PlayCastleTown();
				}
				else if (player.map.x == 89 * 32 && player.map.y >= 16 * 32 && player.map.y <= 19 * 32)
				{
					//Field -> Goblin Camp
					if (player.currentQuest ==2 && player.currentQuestPoint == 0) {
						player.currentQuestPoint++;
					}

					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					player.currentMap = 4;
					screen.loadMapMedia(screen.gPlaySurface, "images/bg4.bmp");

					player.map.x = 1 * 32;
					player.map.y += 19 * 32;
					player.x = 1 * 32;
					player.y = player.map.y - 20 * 32;

					player.questLoaded = false;
					music.PlayCamp();
				}
				else if (player.map.x >= 3 * 32 && player.map.x <= 5 * 32 && player.map.y == 31 * 32)
				{
					//Field -> Cave
					if (player.currentQuest == 1 && player.currentQuestPoint == 1)
					{
						player.currentQuest++;
					}
					else if (player.currentQuest == 4 && player.currentQuestPoint == 0)
					{
						player.currentQuestPoint++;
					}

					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					player.currentMap = 6;
					screen.loadMapMedia(screen.gPlaySurface, "images/bg6.bmp");

					player.y = 18 * 32;
					player.x = 25 * 32 + (player.x - 3 * 32);
					player.map.x = 55 * 32 + (player.map.x - 3 * 32);
					player.map.y = 18 * 32;

					player.questLoaded = false;
					music.PlayCave();

				}
				break;
			case 2:
				if (player.map.y <= 0 && player.map.x >= 39 * 32 && player.map.x <= 44 * 32)
				{
					//Castle town -> field
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					screen.loadMapMedia(screen.gPlaySurface, "images/bg1.bmp");

					player.currentMap = 1;
					player.map.y = 48 * 32;
					player.y = 18 * 32;

					player.questLoaded = false;
					music.PlayField();
				}
				else if (player.map.y == 49 * 32 && player.map.x >= 39 * 32 && player.map.x <= 44 * 32)
				{
					//Castle town -> Castle
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					screen.loadMapMedia(screen.gPlaySurface, "images/bg3.bmp");

					player.currentMap = 3;
					player.map.y = 1 * 32;
					player.y = 1 * 32;

					player.questLoaded = false;
					music.PlayCastle();
				}
				else if (player.map.x >= 84 * 32 && player.map.x <= 86 * 32 && player.map.y == 5 * 32)
				{
					//Castle Town -> Casino
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					screen.loadMapMedia(screen.gPlaySurface, "images/bg7.bmp");
					player.currentMap = 7;

					player.x = 3 * 32 + (player.x - 24 * 32);
					player.y = 18.5 * 32;
					player.map.x = 3 * 32 + (player.map.x - 84 * 32);
					player.map.y = 18.5 * 32;

					player.questLoaded = false;
					music.PlayCasino();
				}
				break;
			case 3:	//Castle
				if (player.map.y <= 0 && player.map.x >= 39 * 32 && player.map.x <= 44 * 32)
				{
					//Castle -> Castle town
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					screen.loadMapMedia(screen.gPlaySurface, "images/bg2.bmp");

					player.currentMap = 2;
					player.map.y = 48 * 32;
					player.y = 18 * 32;

					player.questLoaded = false;
					music.PlayCastleTown();
				}
				break;
			case 4:
				if (player.map.x == 0 && player.map.y >= 35 * 32 && player.map.y <= 39 * 32)
				{
					//Camp -> Field
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					player.currentMap = 1;
					screen.loadMapMedia(screen.gPlaySurface, "images/bg1.bmp");

					player.map.x = 88 * 32;
					player.map.y -= 19 * 32;
					player.x = 28 * 32;
					player.y = 9.5 * 32;

					player.questLoaded = false;
					music.PlayField();
				}
				else if (player.map.x >= 31 * 32 && player.map.x <= 32 * 32 && player.map.y >= 5 * 32 && player.map.y <= 6 * 32)
				{
					//Camp -> Nursary
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					player.currentMap = 5;
					screen.loadMapMedia(screen.gPlaySurface, "images/bg5.bmp");

					player.map.x -= 16.5 * 32;
					player.map.y = 19 * 32;
					player.x = player.map.x;
					player.y = 18 * 32;
					player.questLoaded = false;
				}
				break;
			case 5:
				if (player.map.x >= 14 * 32 && player.map.x <= 15 * 32 && player.map.y == 20 * 32)
				{
					//Nursary To Camp
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					player.currentMap = 4;
					screen.loadMapMedia(screen.gPlaySurface, "images/bg4.bmp");

					player.map.x += 16.5 * 32;
					player.map.y = 7 * 32;
					player.x = 14.5 * 32;
					player.y = 7 * 32;
					player.questLoaded = false;
				}
			case 6:
				if (player.map.x >= 55 * 32 && player.map.x <= 57 * 32 && player.map.y >= 604)
				{
					//Cave -> Field
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					player.currentMap = 1;
					screen.loadMapMedia(screen.gPlaySurface, "images/bg1.bmp");

					player.x = 3 * 32 + (player.x - 25 * 32);
					player.y = 9.5 * 32;
					player.map.x = 3 * 32 + (player.map.x - 55 * 32);
					player.map.y = 31.375 * 32;

					player.questLoaded = false;
					music.PlayField();
				}
				break;
			case 7:
				if (player.map.x >= 3 * 32 && player.map.x <= 5 * 32 && player.map.y == 19 * 32)
				{
					//Casino -> Castletown
					clear(screen.gPlaySurface);
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;

					player.currentMap = 2;
					screen.loadMapMedia(screen.gPlaySurface, "images/bg2.bmp");

					player.x = 24 * 32 + (player.x - 3 * 32);
					player.y = 5.625 * 32;
					player.map.x = 84 * 32 + (player.map.x - 3 * 32);
					player.map.y = 5.625 * 32;

					player.questLoaded = false;
					music.PlayCastleTown();
				}
				break;
		}

		//Move Using Controller
		if (controllerLeft == true)
		{
			player.moveLeft(maps);
			++battleBuffer;
		}
		if (controllerRight == true)
		{
			player.moveRight(maps);
			++battleBuffer;
		}
		if (controllerUp == true)
		{
			player.moveUp(maps);
			++battleBuffer;
		}
		if (controllerDown == true)
		{
			player.moveDown(maps);
			++battleBuffer;
		}


		screen.updateMap(screen.gScreenSurface, player, maps.zone[player.currentMap], maps);
		updateSprite(screen, player);


		//Turn Based Battle
		if ((player.currentMap == 1 || player.currentMap == 3 || player.currentMap == 4 || player.currentMap == 6) && battleBuffer > 120)
		{
			if (getRandomInt(1, 200) == 1)
			{
				//cout << "Battle!";
				gameExit = turnBasedBattle(player, screen, maps, fonts, music, mobs);
				quit = gameExit;
				controllerLeft = false;
				controllerRight = false;
				controllerUp = false;
				controllerDown = false;
				battleBuffer = 0;
				if (player.currentMap == 0)
				{
					SDL_FreeSurface(screen.gPlaySurface);
					screen.gPlaySurface = NULL;
					if(!screen.loadMapMedia(screen.gPlaySurface, "images/bg0.bmp"))
					{
						//cout << "Can't load";
					}
				}
			}
		}

		//FPS Capped at 90
		float endTime = (float)SDL_GetTicks();
		while ((1000 / (endTime - startTime)) > 90)
		{
			endTime = (float)SDL_GetTicks();
		}
		//cout << "Frame rate: " << 1000.0f / (endTime - startTime) << "\n";
	}
	SDL_FreeSurface(screen.gSprite);
	return gameExit;
}

bool interact(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music)
{
	bool exitGame = false;
	int i = 0;
	bool found = false;
	while (i < maps.zone[player.currentMap].collisions.size() && found == false)
	{
		if (maps.zone[player.currentMap].collisions[i].interactable == true)
		{
			if (player.facing.left == true)	//Left collisions
			{
				if (player.map.x == maps.zone[player.currentMap].collisions[i].x + maps.zone[player.currentMap].collisions[i].xDim)	//Touching X co-ordinate
				{
					if (player.map.y < maps.zone[player.currentMap].collisions[i].y + maps.zone[player.currentMap].collisions[i].yDim)	//Within end of y co-ordinate
					{
						if (player.map.y + player.spriteSizeY > maps.zone[player.currentMap].collisions[i].y) //Within start of the y co-ordinate
						{
							found = true;
						}
					}
				}
			}

			else if (player.facing.up == true) //Up collisions
			{
				if (player.map.y == maps.zone[player.currentMap].collisions[i].y + maps.zone[player.currentMap].collisions[i].yDim)	//Touching y co-ordinate
				{
					if (player.map.x < maps.zone[player.currentMap].collisions[i].x + maps.zone[player.currentMap].collisions[i].xDim) //Within end of the x co-ordinate
					{
						if (player.map.x + player.spriteSizeX > maps.zone[player.currentMap].collisions[i].x) //Within start of the x coordinate
						{
							found = true;
						}
					}
				}
			}

			else if (player.facing.right == true) //Right collisions
			{
				if (player.map.x + player.spriteSizeX == maps.zone[player.currentMap].collisions[i].x) //Touching X co-ordinate
				{
					if (player.map.y < maps.zone[player.currentMap].collisions[i].y + maps.zone[player.currentMap].collisions[i].yDim) //Within end of Y co-ordinate
					{
						if (player.map.x + player.spriteSizeY > maps.zone[player.currentMap].collisions[i].y) //Within start of Y co-ordinate
						{
							found = true;
						}
					}
				}
			}
			else if (player.facing.down == true)
			{
				if (player.map.y + player.spriteSizeY == maps.zone[player.currentMap].collisions[i].y) //Touching Y co-ordinate
				{
					if (player.map.x < maps.zone[player.currentMap].collisions[i].x + maps.zone[player.currentMap].collisions[i].xDim) //Within end of X co-ordinate
					{
						if (player.map.x + player.spriteSizeX > maps.zone[player.currentMap].collisions[i].x) //Within start of X co-ordinate
						{
							found = true;
						}
					}
				}
			}

		}
		if (found == false)
		{
			i++;
		}
	}//Collisons while loop

	if (found == true)
	{
		if (maps.zone[player.currentMap].collisions[i].interactType == "chest")
		{
			//Chest function
			int textLine = 0;
			while (textLine < maps.zone[player.currentMap].collisions[i].text.size() && exitGame == false)
			{
				string firstLine = maps.zone[player.currentMap].collisions[i].text[textLine];
				string secondLine = "";
				if (textLine + 1 < maps.zone[player.currentMap].collisions[i].text.size())
				{
					secondLine = maps.zone[player.currentMap].collisions[i].text[textLine + 1];
				}
				exitGame = screen.messageBox(firstLine, firstLine, fonts.font24);
				textLine = textLine + 2;
			}
			//Temp chest ONLY FOR NOW
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "sign")
		{
			int textLine = 0;
			while (textLine < maps.zone[player.currentMap].collisions[i].text.size() && exitGame == false)
			{
				string firstLine = maps.zone[player.currentMap].collisions[i].text[textLine];
				string secondLine = "";
				if (textLine + 1 < maps.zone[player.currentMap].collisions[i].text.size())
				{
					secondLine = maps.zone[player.currentMap].collisions[i].text[textLine + 1];
				}
				exitGame = screen.messageBox(firstLine, secondLine, fonts.font24);
				textLine = textLine + 2;
			}
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "quest")
		{
			//Quest Function
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "buyShop")
		{
			//Potion shop function
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "sellShop")
		{
			//Sell potion shop function
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "hatShop")
		{
			//Hat shop function
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "equipShop")
		{
			//Quest Function
		}
	}
	return exitGame;
}

bool classSelect(Screen screen, Music music, Fonts fonts, Player& player)
{
	vector <int> ClassbuttonX = { 20, 326, 632 };
	vector <int> ClassbuttonY = { 120, 120, 120 };
	int Classbuttonwidth = 300;
	int Classbuttonheight = 480;

	screen.loadMedia(screen.gPlaySurface, "images/ClassScreen.bmp");
	screen.loadMedia(screen.gText, "images/classSel.bmp");

	bool classBoxVisible = true;
	int cursorSelected = 0;
	int classSelected = -1;

	int ClassBoxWidth = 300;
	int ClassBoxSize = ClassBoxWidth;
	int ClassBoxHeight = 480;
	SDL_Rect dest;

	int mouseX = 0;
	int mouseY = 0;

	bool quit = false;
	bool gameExit = false;

	while (!quit)
	{
		SDL_Event event;

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
					classSelected = cursorSelected;
				}
			}

			//Controller Movement Event
			if (event.type == SDL_JOYHATMOTION)
			{
				if (cursorSelected > 0)
				{
					if (event.jhat.value == SDL_HAT_LEFT)
					{
						--cursorSelected;
					}

				}

				if (cursorSelected < 2)
				{
					if (event.jhat.value == SDL_HAT_RIGHT)
					{
						++cursorSelected;
					}
				}
			}

			//Mouse Movement Event
			if (event.type == SDL_MOUSEMOTION)
			{
				mouseX = event.motion.x;
				mouseY = event.motion.y;

				for (int i = 0; i < ClassbuttonX.size(); i++)
				{
					if (mouseX > ClassbuttonX[i] && mouseX < ClassbuttonX[i] + ClassBoxWidth)
					{
						if (mouseY > ClassbuttonY[i] && mouseY < ClassbuttonY[i] + ClassBoxHeight)
						{
							cursorSelected = i;
						}
					}
				}
			}

			//Left click Event
			if (event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED)
			{
				for (int i = 0; i < ClassbuttonX.size(); i++)
				{
					if (mouseX > ClassbuttonX[i] && mouseX < ClassbuttonX[i] + ClassBoxWidth)
					{
						if (mouseY > ClassbuttonY[i] && mouseY < ClassbuttonY[i] + ClassBoxHeight)
						{
							classSelected = cursorSelected;
						}
					}
				}
			}

			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT)
				{
					if (cursorSelected > 0)
					{
						--cursorSelected;
					}
				}

				if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
				{
					if (cursorSelected < 2)
					{
						++cursorSelected;
					}
				}

				if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_e)
				{
					classSelected = cursorSelected;
				}
			}

		}//Event Poll While Loop

		dest.x = ClassbuttonX[cursorSelected];
		dest.y = ClassbuttonY[cursorSelected];
		SDL_BlitSurface(screen.gPlaySurface, NULL, screen.gScreenSurface, 0);
		SDL_BlitSurface(screen.gText, NULL, screen.gScreenSurface, &dest);
		SDL_UpdateWindowSurface(screen.gWindow);
		SDL_FreeSurface(screen.gScreenSurface);

		Equipment equipment;

		if (classSelected != -1)
		{
			if (classSelected == 0)
			{
				player.pClass = "warrior";
			}
			else if (classSelected == 1)
			{
				player.pClass = "mage";
			}
			else if (classSelected == 2)
			{
				player.pClass = "rogue";
			}
			player.initaliseStats(equipment);
			quit = true;
		}
	}
	SDL_FreeSurface(screen.gText);
	SDL_FreeSurface(screen.gPlaySurface);
	SDL_FreeSurface(screen.gScreenSurface);
	return gameExit;
}

bool instructions(Screen screen)
{
	bool quit = false;
	bool exitGame = false;
	screen.loadMedia(screen.gPlaySurface, "images/controls.bmp");
	SDL_BlitSurface(screen.gPlaySurface, NULL, screen.gScreenSurface, 0);

	SDL_UpdateWindowSurface(screen.gWindow);

	SDL_FreeSurface(screen.gPlaySurface);
	SDL_FreeSurface(screen.gScreenSurface);

	while (!quit)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			//Exit Window Event
			if (event.type == SDL_QUIT)
			{
				quit = true;
				exitGame = true;
			}

			//Controller button event
			if (event.type == SDL_JOYBUTTONDOWN)
			{
				if (event.jbutton.button == 0)
				{
					quit = true;
				}
				else if (event.jbutton.button == 1)
				{
					quit = true;
				}
				else if (event.jbutton.button == 2)
				{
					quit = true;
				}
				else if (event.jbutton.button == 3)
				{
					quit = true;
				}
				else
				{
					cout << "Unknown button\n";
				}
			}

			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_BACKSPACE || event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_ESCAPE)
					quit = true;
			}
		}
	}
	return exitGame;
}

void updateSprite(Screen screen, Player& player)
{
	SDL_Rect sheet;
	sheet.x = 0;
	sheet.y = 0;
	sheet.h = player.spriteSizeX;
	sheet.w = player.spriteSizeY;

	SDL_Rect mapLoc;
	mapLoc.x = player.x;
	mapLoc.y = player.y;
	mapLoc.h = 0;
	mapLoc.w = 0;
	
	//No movement facing
	if (!player.dir.left && !player.dir.right && !player.dir.up && !player.dir.down)
	{
		
		if (player.facing.left)
		{
			sheet.x = 2 * 32;	//Facing Left not moving
			sheet.y = 0 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
		}
		else if (player.facing.up)
		{
			sheet.x = 0 * 32;	//Facing Up not moving
			sheet.y = 2 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
		} 
		else if (player.facing.right)
		{
			sheet.x = 0 * 32;	//Facing Right not moving
			sheet.y = 0 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
		} 
		else
		{
			sheet.x = 1 * 32;	//Facing Down not moving
			sheet.y = 1 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
		}
	}
	//Left Movement
	else if (player.dir.left)
	{
		if (player.spriteFrame < 30)
		{
			sheet.x = 2 * 32;	//Moving Left First Frame
			sheet.y = 0 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
		}
		else
		{
			sheet.x = 0 * 32;	//Moving Left Second Frame
			sheet.y = 1 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
			if (player.spriteFrame > 60)
			{
				player.spriteFrame = 0;
			}
		}
	}
	//Up Movement
	else if (player.dir.up)
	{
		if (player.spriteFrame < 30)
		{
			sheet.x = 0 * 32;	//Moving Right First Frame
			sheet.y = 2 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
		}
		else
		{
			sheet.x = 1 * 32;
			sheet.y = 2 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
			if (player.spriteFrame > 60)
			{
				player.spriteFrame = 0;
			}
		}
	}
	//Right Movement
	else if (player.dir.right)
	{
		if (player.spriteFrame < 30)
		{
			sheet.x = 0 * 32;	//Moving Right First Frame
			sheet.y = 0 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
		}
		else
		{
			sheet.x = 1 * 32;	//Moving Right Second Frame
			sheet.y = 0 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
			if (player.spriteFrame > 60)
			{
				player.spriteFrame = 0;
			}
		}
	}
	//Down Movement
	else
	{
		if (player.spriteFrame < 30)
		{
			sheet.x = 1 * 32;	//Moving Down First Frame
			sheet.y = 1 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
		}
		else
		{
			sheet.x = 2 * 32;	//Moving Down Second Frame
			sheet.y = 1 * 32;
			SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);
			if (player.spriteFrame > 60)
			{
				player.spriteFrame = 0;
			}
		}
	}
	
	//player.spriteFrame++;
	SDL_UpdateWindowSurface(screen.gWindow);
	SDL_FreeSurface(screen.gScreenSurface);
}

void clear(SDL_Surface*& gScreenSurface)
{
	SDL_FillRect(gScreenSurface, NULL, 0x000000);
}

bool settings(Screen screen, Music& music, Fonts fonts)
{
	SDL_Event event;

	bool quit = false;
	bool gameExit = false;
	screen.loadMedia(screen.gPlaySurface, "images/settingsScreenMenu.bmp");
	SDL_BlitSurface(screen.gPlaySurface, NULL, screen.gScreenSurface, 0);

	SDL_UpdateWindowSurface(screen.gWindow);
	//SDL_FreeSurface(screen.gPlaySurface);
	SDL_FreeSurface(screen.gScreenSurface);

	bool settingsBoxVisible = false;
	vector <int> VolbuttonX = { 300, 500 };
	vector <int> VolbuttonY = { 200, 200 };
	int VolbuttonWidth = 64;
	int VolbuttonHeight = 64;
	int mouseX = 0;
	int mouseY = 0;
	int settingsBoxX = 0;
	int settingsBoxY = 0;
	int settingsBoxWidth = 64;
	int settingsBoxSize = settingsBoxWidth;
	int settingsBoxHeight = 32;
	float tempVol;
	int cursorSelected = -1;

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

			//Mouse Motion Event
			if (event.type == SDL_MOUSEMOTION)
			{
				mouseX = event.motion.x;
				mouseY = event.motion.y;

				for (size_t i = 0; i < VolbuttonX.size(); i++)
				{
					if (mouseX > VolbuttonX[i] && mouseX < VolbuttonX[i] + VolbuttonWidth)
					{
						if (mouseY > VolbuttonY[i] && mouseY < VolbuttonX[i] + VolbuttonWidth)
						{
							settingsBoxX = VolbuttonX[i];
							settingsBoxY = VolbuttonY[i];
							settingsBoxVisible = true;
						}
					}
				}
			}

			//Left Click Event
			if(event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED)
			{
				for (int i = 0; i < VolbuttonX.size(); i++)
				{
					if (mouseX > VolbuttonX[i] && mouseX < VolbuttonX[i] + VolbuttonWidth)
					{
						if (mouseY > VolbuttonY[i] && mouseY < VolbuttonY[i] + VolbuttonHeight)
						{
							switch (i)
							{
								case 0:
								{
									if (music.volume > 0)
									{
										tempVol = (float)music.volume - 1;
										music.SetVolume(tempVol);
										SDL_Delay(10);
									}
									break;
								}
								case 1:
								{
									if (music.volume < 10)
									{
										tempVol = (float)music.volume + 1;
										music.SetVolume(tempVol);
										SDL_Delay(10);
									}
									break;
								}
							}
						}
					}
				}
			}

			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_BACKSPACE || event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_ESCAPE)
					quit = true;
				else
					if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT)
					{
						settingsBoxX = VolbuttonX[0];
						settingsBoxY = VolbuttonY[0];
						settingsBoxVisible = true;
						cursorSelected = 0;
					}
					else
						if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
						{
							settingsBoxX = VolbuttonX[1];
							settingsBoxY = VolbuttonY[1];
							settingsBoxVisible = true;
							cursorSelected = 1;
						}
						else
						{
							if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_RETURN)
							{
								if (cursorSelected == 0)
								{
									if (music.volume > 0)
									{
										tempVol = (float)music.volume - 1;
										music.SetVolume(tempVol);
										SDL_Delay(10);
									}
								}
								else if (cursorSelected == 1)
								{
									if (music.volume < 10)
									{
										tempVol = (float)music.volume + 1;
										music.SetVolume(tempVol);
										SDL_Delay(10);
									}
								}
							}

						}
			}

			//Controller move event
			if (event.type == SDL_JOYHATMOTION)
			{
				if (event.jhat.value == SDL_HAT_LEFT)
				{
					settingsBoxX = VolbuttonX[0];
					settingsBoxY = VolbuttonY[0];
					settingsBoxVisible = true;
					cursorSelected = 0;
				}

				if (event.jhat.value == SDL_HAT_RIGHT)
				{
					settingsBoxX = VolbuttonX[1];
					settingsBoxY = VolbuttonY[1];
					settingsBoxVisible = true;
					cursorSelected = 1;
				}
			}

			//Controller button event
			if (event.type == SDL_JOYBUTTONDOWN)
			{
				if (event.jbutton.button == 0)
				{
					quit = true;
				}

				if (event.jbutton.button == 1)
				{
					if (cursorSelected == 0)
					{
						if (music.volume > 0)
						{
							tempVol = (float)music.volume - 1;
							music.SetVolume(tempVol);
							SDL_Delay(10);
						}
					}
					else
					if (cursorSelected == 1)
					{
						if (music.volume < 10)
						{
							tempVol = (float)music.volume + 1;
							music.SetVolume(tempVol);
							SDL_Delay(10);
						}
					}
				}
			}

		}//POLL EVENT WHILE
		SDL_BlitSurface(screen.gPlaySurface, NULL, screen.gScreenSurface, 0);

		string volText = to_string(music.volume);
		screen.displayText(volText, 430, 220, fonts.font48);

		if (settingsBoxVisible)
		{
			screen.loadMedia(screen.gText, "images/VOL.bmp");
			SDL_Rect boxPosition;
			boxPosition.x = settingsBoxX;
			boxPosition.y = settingsBoxY;
			SDL_BlitSurface(screen.gText, NULL, screen.gScreenSurface, &boxPosition);
			//SDL_UpdateWindowSurface(screen.gWindow);
			//clear(screen.gText);
			SDL_FreeSurface(screen.gText);
		}

		SDL_UpdateWindowSurface(screen.gWindow);
		clear(screen.gScreenSurface);
		
	}
	SDL_FreeSurface(screen.gPlaySurface);
	return gameExit;
}

int getRandomInt(int min, int max)
{
	return rand() % max + min;
}

void DrawEXPBar(int posX, int posY, double currentStat, double maxStat, string colour, Screen& screen)
{
	int percentFill =  (currentStat / maxStat) * 520;
	if (percentFill < 0)
		percentFill = 0;

	SDL_Rect topRectangle = { posX + 4, posY, 520, 4 };			 // {X, Y, H, W}
	SDL_Rect botRectangle = { posX + 4,  posY + 28, 520, 4 };
	SDL_Rect leftRectangle = { posX,  posY + 4, 4, 24 };
	SDL_Rect rightRectangle = { posX + 524, posY + 4, 4, 24 };
	SDL_Rect expBar = { posX + 6, posY + 6, percentFill, 20 };

	

	SDL_FillRect(screen.gPlaySurface, &topRectangle, SDL_MapRGB(screen.gPlaySurface->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gPlaySurface, &botRectangle, SDL_MapRGB(screen.gPlaySurface->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gPlaySurface, &leftRectangle, SDL_MapRGB(screen.gPlaySurface->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gPlaySurface, &rightRectangle, SDL_MapRGB(screen.gPlaySurface->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gPlaySurface, &expBar, SDL_MapRGB(screen.gPlaySurface->format, 255, 255, 0));

	SDL_UpdateWindowSurface(screen.gWindow);
	SDL_FreeSurface(screen.gScreenSurface);

}

//@
bool turnBasedBattle(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music, Mobs mobs)
{
	//Generate random enemy based on location
	Mobs::mob enemy;
	enemy = mobs.determineMonster(player.currentMap);

	//Play Encounter sound effect
	if (enemy.enemyName == "Rat")
		music.PlayRat();
	else
		music.PlayEncounter();
	
	//Select Background to display
	bool boss = false;
	string selectBackground(int mapNumber);

	//Declare functions
	void drawHealthBar(int posX, int posY, double currentStat, double maxStat, string colour, Screen& screen, bool boss);
	bool runAway(Player& player, Mobs::mob enemy, Screen& screen, Fonts& fonts, int& phaseHolder, bool& gameExit);
	bool didPlayerLose(Player& player, Mobs::mob enemy, Screen& screen, Fonts& fonts, int& phaseHolder, Mobs mobs, int& combatCursorPos, bool& playerExit);
	void wasEnemyDefeated(Player& player, Mobs::mob enemy, Screen& screen, Fonts& fonts, int& phaseHolder, Mobs mobs, bool& gameExit, bool& quit);

	//Set potion multipliers
	player.ironPotionEffect = 1;
	player.berserkPotionEffect = 1;
	player.smokeBombEffect = 1;
	
	//Select Background based on location
	selectBackground(player.currentMap);
	
	if (!screen.loadMedia(screen.gBattleBg, selectBackground(player.currentMap)))
		cout << "Failed to load map media";
	if (!screen.loadMedia(screen.gEnemy, enemy.imgSrc))
		cout << "Failed to enemy media";
	if (!screen.loadMedia(screen.gBattleTextBox, "images/messageHealth.bmp"));
	{
		//printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}


	//Load health, enemy and message box
	void drawBaseImage(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts);
	drawBaseImage(player, screen, enemy, fonts);

	//Create rect for enemy to spawn at
	SDL_Rect enemyLoc;
	enemyLoc.x = 330;
	enemyLoc.y = 150;

	//Initalise Variables
	bool quit = false;
	bool gameExit = false;
	int mouseX = 0;
	int mouseY = 0;
	vector <int> buttonXCombat = { 19, 327, 636, 19, 327, 636 };
	vector <int> buttonYCombat = { 481, 481, 481, 545, 545, 545 };
	int combatButtonHeight = 60;
	int combatButtonWidth = 306;
	int combatCursorPos = 1;	//The location of the cursor on screen
	int phaseHolder = 1;		//Which phaseHolder the player is on (1 = Combat, 2 = Magic, 3 = Items, 4 = Enemy's Turn)
	bool crit = false;
	int damage;

	//Start Battle Music
	music.PlayBattle();

	gameExit = screen.messageBox("A " + enemy.enemyName + " appeared!", "Time to fight for your life!", fonts.font24);
	quit = gameExit;
	mobs.enemyOpeningMessage(screen, enemy, player, fonts);

	drawBaseImage(player, screen, enemy, fonts);

	bool drawCombatCanvas(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts, int& combatCursorPos, Mobs mobs, Music music, int& phaseHolder);
	void drawCombatMenu(Screen& screen, int combatCursorPos, Fonts& fonts);
	drawCombatMenu(screen, combatCursorPos, fonts);
	SDL_UpdateWindowSurface(screen.gWindow);

	SDL_Event event;

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

			//Mouse Motion Event
			if (event.type == SDL_MOUSEMOTION)
			{
				mouseX = event.motion.x;
				mouseY = event.motion.y;
				//Mose hover event
				for (size_t i = 0; i < buttonXCombat.size(); i++)
				{
					if (mouseX > buttonXCombat[i] && mouseX < buttonXCombat[i] + combatButtonWidth)
					{
						if (mouseY > buttonYCombat[i] && mouseY < buttonYCombat[i] + combatButtonHeight)
						{
							combatCursorPos = i;
						}
					}
				}
			}

			//Left Click Event
			if (event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED)
			{
				for (int i = 0; i < buttonXCombat.size(); i++)
				{
					if (mouseX > buttonXCombat[i] && mouseX < buttonXCombat[i] + combatButtonWidth)
					{
						if (mouseY > buttonYCombat[i] && mouseY < buttonYCombat[i] + combatButtonHeight)
						{
							/*  Menu
								case 0		case 1		case 2
								case 3		case 4		case 5

								Phase Holder (1 = Main Menu, 2 = Magic Menu, 3 = Item Menu, 4 = Enemy Turn)
							*/
							
							switch (i)
							{
							case 1:
								if (phaseHolder == 1)
								{
									if (getRandomInt(1, 100) > player.hitChance)
									{
										
										gameExit = screen.messageBox("You attack with " + player.equippedWeapon.weaponName, "Attack Missed!", fonts.font24);
									}
									else
									{
										music.PlayHit();
										damage = player.playerNormalAttack(crit);
										enemy.hp -= damage;
										drawBaseImage(player, screen, enemy, fonts);
										SDL_UpdateWindowSurface(screen.gWindow);
										if (crit == true)
											gameExit = screen.messageBox("You attack with " + player.equippedWeapon.weaponName, "Critical hit! " + to_string(damage) + " Damage!", fonts.font24);
										else
											gameExit = screen.messageBox("You attack with " + player.equippedWeapon.weaponName, to_string(damage) + " Damage!", fonts.font24);
									}
									phaseHolder = 4;
									SDL_Delay(500);
									
								}
								break;
							case 2:
								if (phaseHolder == 1) //If Main Menu
									phaseHolder = 2;  //Magic Menu
								break;
							case 4:
								if (phaseHolder == 1) //If main phaseHolder
									phaseHolder = 3;  //Item Menu
								break;
							case 5:
								if (phaseHolder == 1) //Main Menu
									quit = runAway(player, enemy, screen, fonts, phaseHolder, gameExit); //Run Away
								else if (phaseHolder == 2 || phaseHolder == 3)
									phaseHolder = 1;	//Return to Main Menu
								break;

							}
						}
					}
				}
			}

			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT)
				{	
						
				}
					
				if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
				{
						
				}

				if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
				{

				}

				if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP)
				{

				}
						
				if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE)
				{
								
				}

						
			}

			//Controller move event
			if (event.type == SDL_JOYHATMOTION)
			{
				if (event.jhat.value == SDL_HAT_LEFT)
				{
					
				}

				if (event.jhat.value == SDL_HAT_RIGHT)
				{
					
				}

				if (event.jhat.value == SDL_HAT_UP)
				{

				}

				if (event.jhat.value == SDL_HAT_DOWN)
				{

				}
			}

			//Controller button event
			if (event.type == SDL_JOYBUTTONDOWN)
			{
				if (event.jbutton.button == 0)
				{
					
				}

				if (event.jbutton.button == 1)
				{
					
				}
			}
			
		}//POLL EVENT WHILE
		drawBaseImage(player, screen, enemy, fonts);

		
		wasEnemyDefeated(player, enemy, screen, fonts, phaseHolder, mobs, gameExit, quit);
		if (quit == false)
		{
			gameExit = drawCombatCanvas(player, screen, enemy, fonts, combatCursorPos, mobs, music, phaseHolder);
			if (player.currentHP <= 0)
			{
				quit = true;
			}
			if (phaseHolder == 4)
				gameExit = didPlayerLose(player, enemy, screen, fonts, phaseHolder, mobs, combatCursorPos, gameExit);
			SDL_UpdateWindowSurface(screen.gWindow);
			
		}
		if (gameExit == true)
			quit = gameExit;
	}



	SDL_UpdateWindowSurface(screen.gWindow);

	clear(screen.gEnemy);
	SDL_FreeSurface(screen.gEnemy);
	screen.gEnemy = NULL;

	clear(screen.gBattleBg);
	SDL_FreeSurface(screen.gBattleBg);
	screen.gBattleBg = NULL;

	clear(screen.gBattleTextBox);
	SDL_FreeSurface(screen.gBattleTextBox);
	screen.gBattleTextBox = NULL;

	if (player.currentMap == 10)		//Dog Boss Battle
		player.currentMap = 0;			//Set to Village
	else if (player.currentMap == 11)	//Goblin Boss Battle
		player.currentMap = 4;			//Set to Camp
	else if (player.currentMap == 12)	//Spider Boss Battle
		player.currentMap = 6;			//Set to Cave
	else if (player.currentMap == 13)	//Wizard Boss Battle
		player.currentMap = 0;			//Set to Village
	else if (player.currentMap == 14)	//Demon Boss Battle
		player.currentMap = 0;			//Set to Village

	music.PlayMap(player.currentMap);

	return gameExit;
}


string selectBackground(int mapNumber)
{
	string battleBackground;
	switch (mapNumber)
	{
	case 1: //Field
	case 10: //Dog Boss Battle
	case 13: //Wizard Boss Fight
	case 14: //Demon Lord
		battleBackground = "images/field.bmp";
		break;
	case 3: //Castle
		battleBackground = "images/castleBattle.bmp";
		break;
	case 4: //Goblin Camp
	case 11: //Goblin Boss
		battleBackground = "images/goblinCampBattle.bmp";
		break;
	case 6: //Cave
	case 12: //Spider Queen
		battleBackground = "images/cave.bmp";
		break;

	default:
		battleBackground = "images/field.bmp";
		break;
	}
	return battleBackground;
}

void drawHealthBar(int posX, int posY, double currentStat, double maxStat, string colour, Screen& screen, bool boss)
{
	int percentFill;
	int barLength;
	if (boss == false)
	{
		percentFill = (currentStat / maxStat) * 100;
		barLength = 104;
	}
	else
	{
		percentFill = (currentStat / maxStat) * 308;
		barLength = 312;
	}

	if (percentFill < 0)
		percentFill = 0;

	SDL_Rect topRectangle = { posX + 4, posY, barLength, 4 };			 // {X, Y, H, W}
	SDL_Rect botRectangle = { posX + 4, posY + 28, barLength, 4 };
	SDL_Rect leftRectangle = { posX, posY + 4, 4,24 };
	SDL_Rect rightRectangle = { posX + barLength + 4, posY + 4 , 4,24 };
	SDL_Rect bar = { posX + 6, posY + 6, percentFill, 20 };
	SDL_Rect refreshBar = { posX + 6, posY + 6, barLength-4, 20 };

	int r = 0;
	int g = 0;
	int b = 0;

	if (colour == "#0F0") //Green
	{
		 g = 255;
	}
	else if (colour == "#00F") //Blue "#00F"
	{
		 b = 255;
	}
	else if (colour == "#F00") //Red 
	{
		 r = 255;
	}

	SDL_FillRect(screen.gBattleTextBox, &refreshBar, SDL_MapRGB(screen.gBattleTextBox->format, 0, 0, 0));
	SDL_FillRect(screen.gBattleTextBox, &topRectangle, SDL_MapRGB(screen.gBattleTextBox->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gBattleTextBox, &botRectangle, SDL_MapRGB(screen.gBattleTextBox->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gBattleTextBox, &leftRectangle, SDL_MapRGB(screen.gBattleTextBox->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gBattleTextBox, &rightRectangle, SDL_MapRGB(screen.gBattleTextBox->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gBattleTextBox, &bar, SDL_MapRGB(screen.gBattleTextBox->format, r, g, b));

	//SDL_UpdateWindowSurface(screen.gWindow);
	//SDL_FreeSurface(screen.gScreenSurface);#
}

bool runAway(Player& player, Mobs::mob enemy, Screen& screen, Fonts& fonts, int& phaseHolder, bool& gameExit)
{
	bool run = false;
	if ((enemy.enemyName == "Rabid Dog") || (enemy.enemyName == "Goblin Boss") || (enemy.enemyName == "Spider Queen") || (enemy.enemyName == "Wizard") || (enemy.enemyName == "Demon Lord Grandma!!!")) {
		gameExit = screen.messageBox("Escape Attempt Fail!", "You can't run from bosses", fonts.font24);
		phaseHolder = 1; //Players turn
	}
	else if (getRandomInt(1 + player.luck, 50) > 30) 
	{
		gameExit = screen.messageBox("Escape Attempt Success!", " ", fonts.font24);
		run = true;
	}
	else 
	{
		gameExit = screen.messageBox("Escape Attempt Failed", "Now its " + enemy.enemyName + "'s turn!", fonts.font24);
		phaseHolder = 4; //Enemy's Turn
	}
	return run;
}

void wasEnemyDefeated(Player& player, Mobs::mob enemy, Screen& screen, Fonts& fonts, int& phaseHolder, Mobs mobs, bool& gameExit, bool& quit) {
	//checks if the enemy was defeated, if defeated, game gives the play exp for winning
	int getRandomInt(int min, int max);
	void drawBaseImage(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts);
	if (enemy.hp <= 0) {
		phaseHolder = 0;
		gameExit = screen.messageBox("You defeated " + enemy.enemyName + "!", "You gained " + to_string(enemy.expDrop) + " exp and " + to_string(enemy.goldDrop) + " gold", fonts.font24);
		mobs.enemyDefeatMessage(screen, enemy, player, fonts);
		bool leveled = false;
		string levelUpString1 = "";
		string levelUpString2 = "";
		player.currentExp = player.currentExp + enemy.expDrop;
		player.effectiveCurrentExp = player.effectiveCurrentExp + enemy.expDrop;
		while ((player.currentExp >= player.expLevelUp) && (player.level < 16) && gameExit == false)
		{
			player.levelUp(levelUpString1, levelUpString2);
			player.currentHP = player.maxHP;
			player.currentMP = player.maxMP;
			drawBaseImage(player, screen, enemy, fonts);
			gameExit = screen.messageBox("Congratulations!", "You levelled up to level " + to_string(player.level), fonts.font24);
			gameExit = screen.messageBox(levelUpString1, levelUpString2, fonts.font24);
		}
		player.gold += enemy.goldDrop;
		if (enemy.itemDrop != 0)
		{
			if (getRandomInt(1, 50) <= player.luck)
			{
				player.inventory[enemy.itemDrop]++;
				gameExit = screen.messageBox("Enemy dropped an item!", "You got a " + player.inventoryNames[enemy.itemDrop] + "!", fonts.font24);
			}
		}

		phaseHolder = 0;
		quit = true;
	}
	else {
		//phaseHolder = 4;//enemies turn
	}
}

bool didPlayerLose(Player& player, Mobs::mob enemy, Screen& screen, Fonts& fonts, int& phaseHolder, Mobs mobs, int& combatCursorPos, bool& playerExit) {
	//checks if the enemy was defeated, if defeated, game gives the play exp for winning and returns them to the main phaseHolder of the demo.
	bool quit = false;
	if (player.currentHP <= 0) {
		phaseHolder = 0;
		quit = screen.messageBox("You fainted & lost half your gold!", "Restart from the village!", fonts.font24);
		player.gold = floor(player.gold / 2);
		player.x = 28 * 32;
		player.y = 1 * 32;
		player.map.x = 58 * 32;
		player.map.y = 1 * 32;
		player.currentMap = 0;
		player.currentHP = player.maxHP;
		player.currentMP = player.maxMP;
		
	}
	else {
		phaseHolder = 1; //switches back to the player's turn
		quit = screen.messageBox("It is now your turn again", " ", fonts.font24);
		combatCursorPos = 0;
	}
	return quit;
}

void drawBaseImage(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts)
{
	SDL_Rect enemyLoc;
	enemyLoc.x = 330;
	enemyLoc.y = 150;

	drawHealthBar(25, 365, (double)player.currentHP, (double)player.maxHP, "#0F0", screen, false); //Player HP
	drawHealthBar(25, 405, (double)player.currentMP, (double)player.maxMP, "#00F", screen, false); //Player MP

	if (enemy.boss == true)
		drawHealthBar(424 - 104, 50, (double)enemy.hp, (double)enemy.maxHP, "#F00", screen, true); //Boss Enemy with 3x health bar size
	else
		drawHealthBar(424, 50, (double)enemy.hp, (double)enemy.maxHP, "#F00", screen, false); //Normal Enemy

	SDL_BlitSurface(screen.gBattleBg, NULL, screen.gScreenSurface, 0);
	SDL_BlitSurface(screen.gEnemy, NULL, screen.gScreenSurface, &enemyLoc);
	SDL_BlitSurface(screen.gBattleTextBox, NULL, screen.gScreenSurface, 0);

	string HPString = to_string(player.currentHP);
	HPString += "|";
	HPString += to_string(player.maxHP);
	HPString += "HP";

	string MPString = to_string(player.currentMP);
	MPString += "|";
	MPString += to_string(player.maxMP);
	MPString += "MP";

	screen.displayLeftText(HPString, 143, 393, fonts.font20);
	screen.displayLeftText(MPString, 143, 433, fonts.font20);
	screen.displayText(enemy.enemyName, 480, 130 - 30, fonts.font24); //Display Enemy Name
}

void drawCombatMenu(Screen& screen, int combatCursorPos, Fonts& fonts)
{
	screen.displayLeftText("Attack", 420, 528, fonts.font24);
	screen.displayLeftText("Use Items", 420, 600, fonts.font24);
	screen.displayLeftText("Magic", 720, 528, fonts.font24);
	screen.displayLeftText("Run Away", 720, 600, fonts.font24);
	switch (combatCursorPos) {
	case 1:
		screen.displayLeftText((">"), 396, 528, fonts.font24);
		break;
	case 2:
		screen.displayLeftText((">"), 696, 528, fonts.font24);
		break;
	case 4:
		screen.displayLeftText((">"), 396, 600, fonts.font24);
		break;
	case 5:
		screen.displayLeftText((">"), 696, 600, fonts.font24);
		break;
	}
}

void drawMagicMenu(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts, int combatCursorPos) {
	drawBaseImage(player, screen, enemy, fonts);
	if (player.pClass == "warrior")
	{
		if (player.level >= 2) {
			screen.displayLeftText("Flame S. 2MP", 70, 528, fonts.font20);
		}
		if (player.level >= 3) {
			screen.displayLeftText("Sheer W. 4MP", 380, 528, fonts.font20);
		}
		if (player.level >= 5) {
			screen.displayLeftText("Tornado S. 6MP", 680, 528, fonts.font20);
		}
		if (player.level >= 10) {
			screen.displayLeftText(("Bulk Up 8MP"), 70, 600, fonts.font20);
		}
		if (player.level >= 15) {
			screen.displayLeftText(("Nova S 10MP"), 375, 600, fonts.font20);
		}
	}
	else if (player.pClass == "mage")
	{
		if (player.level >= 2) {
			screen.displayLeftText("Fire 			 2MP", 70, 528, fonts.font20);
		}
		if (player.level >= 3) {
			screen.displayLeftText("Heal		4MP", 380, 528, fonts.font20);
		}
		if (player.level >= 5) {
			screen.displayLeftText("Thunder 6MP", 680, 528, fonts.font20);
		}
		if (player.level >= 10) {
			screen.displayLeftText(("Drain H. 8MP"), 70, 600, fonts.font20);
		}
		if (player.level >= 15) {
			screen.displayLeftText(("G Nova 10MP"), 375, 600, fonts.font20);
		}
	}
	else if (player.pClass ==  "rogue")
	{
		if (player.level >= 2) {
			screen.displayLeftText("Steal		2MP", 70, 528, fonts.font20);
		}
		if (player.level >= 3) {
			screen.displayLeftText("Life Steal 4MP", 380, 528, fonts.font20);
		}
		if (player.level >= 5) {
			screen.displayLeftText("Cash N Grab 6MP", 680, 528, fonts.font20);
		}
		if (player.level >= 10) {
			screen.displayLeftText("Backstab 8MP", 70, 600, fonts.font20);
		}
		if (player.level >= 15) {
			screen.displayLeftText("Nova B 10MP", 375, 600, fonts.font20);
		}

	}

	screen.displayLeftText("return", 680, 600, fonts.font20);


	switch (combatCursorPos) {
	case 0:
		screen.displayLeftText((">"), 24, 528, fonts.font20);
		break;
	case 1:
		screen.displayLeftText((">"), 346, 528, fonts.font20);
		break;
	case 2:
		screen.displayLeftText((">"), 656, 528, fonts.font20);
		break;
	case 3:
		screen.displayLeftText((">"), 24, 600, fonts.font20);
		break;
	case 4:
		screen.displayLeftText((">"), 346, 600, fonts.font20);
		break;
	case 5:
		screen.displayLeftText((">"), 656, 600, fonts.font20);
		break;
	}
}

void drawItemMenu(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts, int combatCursorPos) {
	drawBaseImage(player, screen, enemy, fonts);
	screen.displayLeftText(("Health P.X" + player.inventory[1]), 48, 528, fonts.font20);
	screen.displayLeftText(("Ironskin P.X" + player.inventory[4]), 370, 528, fonts.font20);
	screen.displayLeftText(("Berserk P.X" + player.inventory[5]), 680, 528, fonts.font20);
	screen.displayLeftText(("Magic P.X" + player.inventory[2]), 48, 600, fonts.font20);
	screen.displayLeftText(("Smoke B.X" + player.inventory[3]), 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	switch (combatCursorPos) {
	case 0:
		screen.displayLeftText(">", 24, 528, fonts.font20);
		break;
	case 1:
		screen.displayLeftText((">"), 346, 528, fonts.font20);
		break;
	case 2:
		screen.displayLeftText((">"), 656, 528, fonts.font20);
		break;
	case 3:
		screen.displayLeftText((">"), 24, 600, fonts.font20);
		break;
	case 4:
		screen.displayLeftText((">"), 346, 600, fonts.font20);
		break;
	case 5:
		screen.displayLeftText((">"), 656, 600, fonts.font20);
		break;
	}
}

bool drawCombatCanvas(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts, int& combatCursorPos, Mobs mobs, Music music, int& phaseHolder)
{
	bool gameExit = false;
	void drawCombatMenu(Screen& screen, int combatCursorPos, Fonts& fonts);
	void drawMagicMenu(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts, int combatCursorPos);
	void drawItemMenu(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts, int combatCursorPos);
	switch (phaseHolder)
	{
		
		case 1: //Normal case
			drawCombatMenu(screen, combatCursorPos, fonts);
			break;
		case 2://Magic Attacks
			drawMagicMenu(player, screen, enemy, fonts, combatCursorPos);
			break;
		case 3: //item phaseHolder
			drawItemMenu(player, screen, enemy, fonts, combatCursorPos);
			break;
		case 4://Enemies Turn
			drawBaseImage(player, screen, enemy, fonts);
			gameExit = screen.messageBox("It is the enemy's turn!", "", fonts.font24);
			mobs.enemyTurn(player, screen, fonts, music, enemy);
			//phaseHolder = 1;
			//gameExit = didPlayerLose(player, enemy, screen, fonts, phaseHolder, mobs, combatCursorPos, gameExit);
			break;
	}
	return gameExit;
}