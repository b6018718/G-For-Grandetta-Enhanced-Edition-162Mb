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
#include "Shops.h"


//Count Lines OF Code = ctrl + shift + f
//^(?!(\s*\*))(?!(\s*\-\-\>))(?!(\s*\<\!\-\-))(?!(\s*\n))(?!(\s*\*\/))(?!(\s*\/\*))(?!(\s*\/\/\/))(?!(\s*\/\/))(?!(\s*\}))(?!(\s*\{))(?!(\s(using))).*$
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
	Shops shops;

	player.questLoaded = true;

	bool classSelect(Screen screen, Music music, Fonts fonts, Player& player);
	bool setName(Screen screen, Fonts fonts, Player& player);
	bool interact(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music, Mobs& mobs, Shops& shops);
	int getRandomInt(int min, int max);
	bool turnBasedBattle(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music, Mobs mobs);
	bool openInventory(Screen& screen, Player& player, Music& music, Fonts& fonts);

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

	screen.messageBox("You feel a breeze as you awake", "from your slumber", fonts.font24);
	screen.messageBox("To your surprise you notice that", "your roof has been destroyed!", fonts.font24);
	screen.messageBox("What's more you hear nothing but", "silence", fonts.font24);
	screen.messageBox("The village is usually a hub", "of activity, where is everyone?", fonts.font24);
	screen.messageBox("ADVENTURE TIP: Interact with ", "objects by pressing E.", fonts.font24);
	screen.messageBox("ADVENTURE TIP: Remember to press", "Q (Inventory) if you ever get lost.", fonts.font24);

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
					gameExit = openInventory(screen, player, music, fonts);
					quit = gameExit;
				}
				if (event.jbutton.button == 1)
				{
					gameExit = interact(player, screen, maps, fonts, music, mobs, shops);
					quit = gameExit;
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
					gameExit = interact(player, screen, maps, fonts, music, mobs, shops);
					quit = gameExit;
					cout << player.currentQuest;
					cout << "\n" << player.currentQuestPoint;
				}

				if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_SPACE)
				{
					//Open Inventory
					gameExit = openInventory(screen, player, music, fonts);
					quit = gameExit;
				}

				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					//Open Options
				}
			}
		}

		//Smooth Key Board Movement
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
					if (player.currentQuest == 0 && player.currentQuestPoint <= 1)
					{
						gameExit = screen.messageBox("You hear a howl in the distance", "Better check that before leaving", fonts.font24);
						for (size_t i = 0; i < 10; i++)
						{
							player.moveUp(maps);
							controllerDown = false;
						}
					}
					else
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
					if (player.currentQuest < 2)
					{
						gameExit = screen.messageBox("You are not strong enough for this", "area yet, progress the quest!", fonts.font24);
						for (size_t i = 0; i < 10; i++)
						{
							player.moveLeft(maps);
							controllerRight = false;
						}
					}
					else
					{
						if (player.currentQuest == 2 && player.currentQuestPoint == 0) {
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
				}
				else if (player.map.x >= 3 * 32 && player.map.x <= 5 * 32 && player.map.y == 31 * 32)
				{
					if (player.currentQuest < 4)
					{
						gameExit = screen.messageBox("You are not strong enough for this", "area yet, progress the quest!", fonts.font24);
						for (size_t i = 0; i < 10; i++)
						{
							player.moveDown(maps);
							controllerUp = false;
						}
					}
					//Field -> Cave
					if (player.currentQuest == 1 && player.currentQuestPoint == 1)
					{
						player.currentQuest++;
					}
					else if (player.currentQuest == 4 && player.currentQuestPoint == 0)
					{
						player.currentQuestPoint++;
					}

					if (player.currentQuest == 4 && player.currentQuestPoint == 0) 
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
			case 4://Camp
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
		
		//Refresh Screen
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

bool interact(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music, Mobs& mobs, Shops& shops)
{
	Equipment equipment;
	bool turnBasedBattle(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music, Mobs mobs);
	player.firstFail = false;
	bool exitGame = false;
	int i = 0;
	bool found = false;
	void updateSprite(Screen screen, Player& player);
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
			else if (player.facing.down == true) //Down collisions
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
			if (maps.zone[player.currentMap].collisions[i].function == "dogFunction")
			{
				if (player.currentQuest == 0 && player.currentQuestPoint == 0)
					player.incrementQuest();
				if (player.currentQuest == 0 && player.currentQuestPoint == 1)
				{
					exitGame = screen.messageBox("You see a rabid dog prowling the", "graveyard.", fonts.font24);
					exitGame = screen.messageBox("The dog has seen you and is coming", "right at you!", fonts.font24);
					exitGame = screen.messageBox("You grab the nearest weapon and", "prepare to fight!", fonts.font24);
					player.currentMap = 10; //Dog Boss Battle
					turnBasedBattle(player, screen, maps, fonts, music, mobs);

					if (player.currentQuest == 0 && player.currentQuestPoint == 2)
					{
						while (maps.findCollision(maps.zone[player.currentMap], "villageDog") != -1)
							maps.removeItem(0, "villageDog");
						screen.loadMapMedia(screen.gPlaySurface, "images/bg0.bmp");
						screen.updateMap(screen.gScreenSurface, player, maps.zone[player.currentMap], maps);
						updateSprite(screen, player);
						SDL_UpdateWindowSurface(screen.gWindow);
						exitGame = screen.messageBox("You have defeated the dog.", "", fonts.font24);
						exitGame = screen.messageBox("Your mind returns to the missing", "people of your village.", fonts.font24);
						exitGame = screen.messageBox("Where have they all gone?", "", fonts.font24);
						exitGame = screen.messageBox("You decide to travel to the castle", "to request an audience with the king", fonts.font24);
					}
					player.questLoaded = false;
				}
				if (player.currentQuest == 7 && player.currentQuestPoint == 0)
				{
					player.currentMap = 14; //Demon Boss Battle
					turnBasedBattle(player, screen, maps, fonts, music, mobs);
				}
			}
			else if (maps.zone[player.currentMap].collisions[i].function == "kingFunction")
			{
				if (player.currentQuest == 0 && player.currentQuestPoint == 2) {
					exitGame = screen.messageBox("You explain to the king how all the", "people in your village have...", fonts.font24);
					exitGame = screen.messageBox("disappeared overnight", "without a trace.", fonts.font24);
					exitGame = screen.messageBox("The king says: You poor soul", "I will commit all resources...", fonts.font24);
					exitGame = screen.messageBox("available to me to help find your", "people. You may want to go...", fonts.font24);
					exitGame = screen.messageBox("have a chat with this kingdom's", "resident wizard.", fonts.font24);
					exitGame = screen.messageBox("Good luck " + player.name, "", fonts.font24);
					player.incrementQuest();
				}
				else if (player.currentQuest == 1 && player.currentQuestPoint == 0) {
					exitGame = screen.messageBox("The king says: A sword?", "You'll have to buy one from the", fonts.font24);
					exitGame = screen.messageBox("market. There's one in the courtyard", "of this castle, just keep an eye", fonts.font24);
					exitGame = screen.messageBox("out for the stall with the armour", "symbol on it.", fonts.font24);
					player.incrementQuest();
				}
				else
				{
					exitGame = screen.messageBox("The king says: Well?", "Get on with it", fonts.font24);
					exitGame = screen.messageBox("no time like the", "present!", fonts.font24);
				}
			}
			else if (maps.zone[player.currentMap].collisions[i].function == "wizFunction")
			{
				if (player.currentQuest == 0 && player.currentQuestPoint <= 2)
				{
					exitGame = screen.messageBox("The wizard says 'Busy, busy, busy", "Always in a rush...", fonts.font24);
				}
				else if (player.currentQuest == 0 && player.currentQuestPoint == 3)
				{
					exitGame = screen.messageBox("You explain to the wizard the", "circumstances surrounding", fonts.font24);
					exitGame = screen.messageBox("your village and that the king", "has given his blessing to", fonts.font24);
					exitGame = screen.messageBox("investigate.", "The wizard says: Well this is", fonts.font24);
					exitGame = screen.messageBox("wonderful! I mean not", "wonderful. Awful, truly awful. See", fonts.font24);
					exitGame = screen.messageBox("the thing is I know a ritual that", "may bring your people back. However", fonts.font24);
					exitGame = screen.messageBox("I've never tried it since I don't", "have all the elements needed to", fonts.font24);
					exitGame = screen.messageBox("perform it. Since you seem to be", "a strong youth, it's going to be", fonts.font24);
					exitGame = screen.messageBox("your job to collect the elements", "for me.", fonts.font24);
					exitGame = screen.messageBox("Now let's think, first I need the", "staff of the goblin elder. It is", fonts.font24);
					exitGame = screen.messageBox("a precious artefact and symbol", "of power among the goblin people.", fonts.font24);
					exitGame = screen.messageBox("Stupid creatures.", "", fonts.font24);
					exitGame = screen.messageBox("The only way to get the staff", "will have to be to take it by", fonts.font24);
					exitGame = screen.messageBox("force! You'll need a proper sword", "if you're going to take on goblins,", fonts.font24);
					exitGame = screen.messageBox("perhaps the king has one for you.", "You had better go ask.", fonts.font24);
					player.incrementQuest();
				}
				else if (player.currentQuest == 1 && player.currentQuestPoint == 2)
				{
					exitGame = screen.messageBox("The wizard says:", "Ah yes! That's a proper weapon!", fonts.font24);
					exitGame = screen.messageBox("Now we're ready to get that staff.", "The goblins have a camp to the east", fonts.font24);
					exitGame = screen.messageBox("If you have to, raze it down.", "The goblins are like a vermin", fonts.font24);
					exitGame = screen.messageBox("And should be treated as such.", "", fonts.font24);
					player.incrementQuest();
				}
				else if (player.currentQuest == 2 && player.currentQuestPoint == 2)
				{
					exitGame = screen.messageBox("The wizard says:", "You're back!", fonts.font24);
					exitGame = screen.messageBox("And you got the staff, excellent!", "We are well on our way to saving", fonts.font24);
					exitGame = screen.messageBox("your people. Next I'm going to need", "a ritual hat. Any will do, there", fonts.font24);
					exitGame = screen.messageBox("is a hat shop in the courtyard.", "Just pick one and bring it back.", fonts.font24);
					player.incrementQuest();
				}
				else if (player.currentQuest == 3 && player.currentQuestPoint == 1)
				{
					exitGame = screen.messageBox("The wizard says:", "Let's have a look.", fonts.font24);
					exitGame = screen.messageBox("This hat will do nicely.", "I need just one more item for the", fonts.font24);
					exitGame = screen.messageBox("ritual. West of here is a cave that", "houses the World Orb.", fonts.font24);
					exitGame = screen.messageBox("It is a relic left by our ancestors", "that allows an individual to control", fonts.font24);
					exitGame = screen.messageBox("life and death itself.", "If we cannot get the World Orb the", fonts.font24);
					exitGame = screen.messageBox("ritual cannot go ahead.", "", fonts.font24);
					player.incrementQuest();
				}
				else if (player.currentQuest == 4 && player.currentQuestPoint == 2)
				{
					exitGame = screen.messageBox("The World Orb... you actually", "managed to get it.", fonts.font24);
					exitGame = screen.messageBox("Never in all my years did I think", "I'd see it in person.", fonts.font24);
					exitGame = screen.messageBox("Well now the time has come.", "We have all the necessary parts", fonts.font24);
					exitGame = screen.messageBox("to perform the ritual.", "I have some preparations to make.", fonts.font24);
					exitGame = screen.messageBox("Meet me in your village.", "", fonts.font24);
					player.currentQuest = 6;
					player.currentQuestPoint = 0;
				}
				else if (player.currentQuest == 6 && player.currentQuestPoint == 1)
				{
					exitGame = screen.messageBox("You're here.", "", fonts.font24);
					exitGame = screen.messageBox("Now before we begin I have just", "one last thing to deal with.", fonts.font24);
					player.currentMap = 13;
					turnBasedBattle(player, screen, maps, fonts, music, mobs);
				}
				else
				{
					exitGame = screen.messageBox("The wizard says: Chop chop, we", "don't have all day.", fonts.font24);
				}

			}
			else if (maps.zone[player.currentMap].collisions[i].function == "campChestFunc")
			{
				if (player.currentQuest == 2 && player.currentQuestPoint == 1)
				{
					exitGame = screen.messageBox("You try to take the goblin staff", "but a goblin appears and stops you", fonts.font24);
					//exitGame = screen.messageBox("The dog has seen you and is coming", "right at you!", fonts.font24);
					//exitGame = screen.messageBox("You grab the nearest weapon and", "prepare to fight!", fonts.font24);
					player.currentMap = 11; //Goblin Boss Battle
					turnBasedBattle(player, screen, maps, fonts, music, mobs);
					screen.updateMap(screen.gScreenSurface, player, maps.zone[player.currentMap], maps);
					updateSprite(screen, player);
					SDL_UpdateWindowSurface(screen.gWindow);
					if (player.lost == false)
					{
						exitGame = screen.messageBox("You stole the Goblin Staff!", "", fonts.font24);
						player.incrementQuest();
					}
					//@
				}
			}
			else if (maps.zone[player.currentMap].collisions[i].function == "caveChestFunc")
			{
				if (player.currentQuest == 2 && player.currentQuestPoint == 1)
				{
					exitGame = screen.messageBox("You try to take the World Orb", "but a spider appears and stops you", fonts.font24);
					//exitGame = screen.messageBox("The dog has seen you and is coming", "right at you!", fonts.font24);
					//exitGame = screen.messageBox("You grab the nearest weapon and", "prepare to fight!", fonts.font24);
					player.currentMap = 12; //Goblin Boss Battle
					turnBasedBattle(player, screen, maps, fonts, music, mobs);
					screen.updateMap(screen.gScreenSurface, player, maps.zone[player.currentMap], maps);
					updateSprite(screen, player);
					SDL_UpdateWindowSurface(screen.gWindow);
					if (player.lost == false)
					{
						exitGame = screen.messageBox("You stole the World Orb!", "", fonts.font24);
						player.incrementQuest();
					}
					//@
				}
			}
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "buyShop")
		{
			//Potion shop function
			shops.buyShop(screen, player, fonts, equipment);
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "sellShop")
		{
			//Sell potion shop function
			shops.sellShop(screen, player, fonts, equipment);
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "hatShop")
		{
			//Hat shop function
			shops.hatShop(screen, player, fonts, equipment);
		}
		else if (maps.zone[player.currentMap].collisions[i].interactType == "equipShop")
		{
			//Quest Function
			shops.armouryShop(screen, player, fonts, equipment);
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
				SDL_Delay(500);
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
	//@
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
	return rand() % (max - min + 1) + min;
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

	

	SDL_FillRect(screen.gBattleTextBox, &topRectangle, SDL_MapRGB(screen.gBattleTextBox->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gBattleTextBox, &botRectangle, SDL_MapRGB(screen.gBattleTextBox->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gBattleTextBox, &leftRectangle, SDL_MapRGB(screen.gBattleTextBox->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gBattleTextBox, &rightRectangle, SDL_MapRGB(screen.gBattleTextBox->format, 0xFFF, 0xFFF, 0xFFF));
	SDL_FillRect(screen.gBattleTextBox, &expBar, SDL_MapRGB(screen.gBattleTextBox->format, 255, 255, 0));

	SDL_UpdateWindowSurface(screen.gWindow);
	SDL_FreeSurface(screen.gScreenSurface);

}


bool turnBasedBattle(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music, Mobs mobs)
{
	//Generate random enemy based on location
	Mobs::mob enemy;
	enemy = mobs.determineMonster(player.currentMap);
	player.firstFail = false;
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
	player.lost = false;

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
	int optionSelected = 1; //Menu option chosen

	//Start Battle Music
	music.PlayBattle();

	gameExit = screen.messageBox("A " + enemy.enemyName + " appeared!", "Time to fight for your life!", fonts.font24);
	quit = gameExit;
	mobs.enemyOpeningMessage(screen, enemy, player, fonts);

	drawBaseImage(player, screen, enemy, fonts);

	bool drawCombatCanvas(Player& player, Screen& screen, Mobs::mob& enemy, Fonts fonts, int& combatCursorPos, Mobs mobs, Music music, int& phaseHolder);
	void drawCombatMenu(Screen& screen, int combatCursorPos, Fonts& fonts);
	bool battleMenu(int optionSelected, int& phaseHolder, bool& quit, Player& player, Mobs::mob& enemy, Screen& screen, Fonts& fonts, Music& music, int& combatCursorPos);
	drawCombatMenu(screen, combatCursorPos, fonts);
	SDL_UpdateWindowSurface(screen.gWindow);
	void moveLeft(int& combatCursorPos, int phaseHolder);
	void moveRight(int& combatCursorPos, int phaseHolder);
	void moveUp(int& combatCursorPos, int phaseHolder);
	void moveDown(int& combatCursorPos, int phaseHolder);

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
							int calculateDamageDealt(int attack, int defence);
							optionSelected = combatCursorPos;
							gameExit = battleMenu(optionSelected, phaseHolder, quit, player, enemy, screen, fonts, music, combatCursorPos);
						}
					}
				}
				SDL_Delay(500);
			}

			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT)
				{	
					moveLeft(combatCursorPos, phaseHolder);
				}
					
				if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
				{
					moveRight(combatCursorPos, phaseHolder);
				}

				if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
				{
					moveDown(combatCursorPos, phaseHolder);
				}

				if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP)
				{
					moveUp(combatCursorPos, phaseHolder);
				}
						
				if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE)
				{
					optionSelected = combatCursorPos;
					gameExit = battleMenu(optionSelected, phaseHolder, quit, player, enemy, screen, fonts, music, combatCursorPos);
				}

						
			}

			//Controller move event
			if (event.type == SDL_JOYHATMOTION)
			{
				if (event.jhat.value == SDL_HAT_LEFT)
				{
					moveLeft(combatCursorPos, phaseHolder);
				}

				if (event.jhat.value == SDL_HAT_RIGHT)
				{
					moveRight(combatCursorPos, phaseHolder);
				}

				if (event.jhat.value == SDL_HAT_UP)
				{
					moveUp(combatCursorPos, phaseHolder);
				}

				if (event.jhat.value == SDL_HAT_DOWN)
				{
					moveDown(combatCursorPos, phaseHolder);
				}
			}

			//Controller button event
			if (event.type == SDL_JOYBUTTONDOWN)
			{
				if (event.jbutton.button == 0)
				{
					if (phaseHolder != 1)
					{
						optionSelected = 5;
						gameExit = battleMenu(optionSelected, phaseHolder, quit, player, enemy, screen, fonts, music, combatCursorPos);
					}
				}

				if (event.jbutton.button == 1)
				{
					optionSelected = combatCursorPos;
					gameExit = battleMenu(optionSelected, phaseHolder, quit, player, enemy, screen, fonts, music, combatCursorPos);
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
			{
				SDL_UpdateWindowSurface(screen.gWindow);
				gameExit = didPlayerLose(player, enemy, screen, fonts, phaseHolder, mobs, combatCursorPos, gameExit);
				SDL_UpdateWindowSurface(screen.gWindow);
			}
			else
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

	if (player.lost == false)
	{
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
	}

	music.PlayMap(player.currentMap);

	return gameExit;
}


void moveLeft(int& combatCursorPos, int phaseHolder)
{
	if (phaseHolder == 1)
	{
		switch (combatCursorPos)  //{  0    1    2  }
		{						  //{  3    4    5  }
		case 0:
			break;
		case 1:
			break;
		case 2:
			combatCursorPos = 1;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			combatCursorPos = 4;
			break;
		}
	}
	else
	{
		switch (combatCursorPos)  //{  0    1    2  }
		{						  //{  3    4    5  }
		case 0:
			break;
		case 1:
			combatCursorPos = 0;
			break;
		case 2:
			combatCursorPos = 1;
			break;
		case 3:
			break;
		case 4:
			combatCursorPos = 3;
			break;
		case 5:
			combatCursorPos = 4;
			break;
		}
	}
}

void moveRight(int& combatCursorPos, int phaseHolder)
{
	switch (combatCursorPos)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		combatCursorPos = 1;
		break;
	case 1:
		combatCursorPos = 2;
		break;
	case 2:
		break;
	case 3:
		combatCursorPos = 4;
		break;
	case 4:
		combatCursorPos = 5;
		break;
	case 5:
		break;
	}
}

void moveDown(int& combatCursorPos, int phaseHolder)
{
	switch (combatCursorPos)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		combatCursorPos = 3;
		break;
	case 1:
		combatCursorPos = 4;
		break;
	case 2:
		combatCursorPos = 5;
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
}

void moveUp(int& combatCursorPos, int phaseHolder)
{
	switch (combatCursorPos)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		combatCursorPos = 0;
		break;
	case 4:
		combatCursorPos = 1;
		break;
	case 5:
		combatCursorPos = 2;
		break;
	}
}

int calculateDamageDealt(int attack, int defence)
{
	//calculates and returns damage after subtracting the defence stat of the oppenent
	int damageDealt = attack - defence;
	if (damageDealt <= 0) {  //prevents passing negative damage that would effectively heal the openent
	damageDealt = 1;	//applies chip damage if no damage would be dealt
	}
	return damageDealt;
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
		gameExit = screen.messageBox("Escape Attempt Fail!", "You can\'t run from bosses", fonts.font24);
		phaseHolder = 1; //Players turn
	}
	else if (getRandomInt(1 + player.luck, 50) > 30 || enemy.enemyName == "Goblin Younglings") 
	{
		gameExit = screen.messageBox("Escape Attempt Success!", " ", fonts.font24);
		run = true;
	}
	else 
	{
		gameExit = screen.messageBox("Escape Attempt Failed", "Now its " + enemy.enemyName + "\'s turn!", fonts.font24);
		phaseHolder = 4; //Enemy's Turn
	}
	return run;
}

void wasEnemyDefeated(Player& player, Mobs::mob enemy, Screen& screen, Fonts& fonts, int& phaseHolder, Mobs mobs, bool& gameExit, bool& quit) {
	//checks if the enemy was defeated, if defeated, game gives the play exp for winning
	int getRandomInt(int min, int max);
	void drawBaseImage(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts);
	if (enemy.hp <= 0) {
		player.killCount++;
		if (enemy.enemyName == "Goblin Younglings")
			player.badEnd = true;	//Player gets bad end if they kill any younglings
		if (enemy.boss == true)
			player.incrementQuest();	//Boss Fight Won
		phaseHolder = 0; //Set to end battle phase
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
			gameExit = screen.messageBox("Congratulations!", "You levelled up to level " + to_string(player.level), fonts.font24);
			gameExit = screen.messageBox(levelUpString1, levelUpString2, fonts.font24);
			drawBaseImage(player, screen, enemy, fonts);
			gameExit = screen.messageBox("HP: " + to_string(player.maxHP) + " MP: " + to_string(player.maxMP) + " phyAtt: " + to_string(player.phyAttack) + " phyDef: " + to_string(player.phyDefence), "magAtt: " + to_string(player.magAttack) + " magDef: " + to_string(player.magDefence) + " Luck: " + to_string(player.luck), fonts.font24);

			
			if (player.pClass == "warrior")
			{
				if (player.level == 2) {  //flame slash
					gameExit = screen.messageBox("You learnt a new spell!", "Burn foes with Flame Slash!", fonts.font24);
					gameExit = screen.messageBox("Remember to cast a spell,", "you need enough MP to cast it!", fonts.font24);
				}
				if (player.level == 3) {   //Sheer will
					gameExit = screen.messageBox("You learnt a new spell!", "Heal yourself with Sheer Will!", fonts.font24);
				}
				if (player.level == 5) {   //tornado slash
					gameExit = screen.messageBox("You learnt a new spell!", "Tear foes to shreds with tornado slash!", fonts.font24);
				}
				if (player.level == 10) {  //bulk up
					gameExit = screen.messageBox("You learnt a new spell!", "Bulk Up to boost your stats!", fonts.font24);
				}
				if (player.level == 15) {  //nova slash
					gameExit = screen.messageBox("You learnt a new spell!", "Unleash your full power Nova Slash!", fonts.font24);
					gameExit = screen.messageBox("Congratulations!", "You now have learnt every spell!", fonts.font24);
					gameExit = screen.messageBox("Have fun using them", "to defeat your foes!", fonts.font24);
				}
			}

			else if (player.pClass == "mage")
			{
				if (player.level == 2) { //fire
					gameExit = screen.messageBox("You learnt a new spell!", "Scorch your foes with Fire!", fonts.font24);
					gameExit = screen.messageBox("Remember to cast a spell,", "you need enough MP to cast it!", fonts.font24);
				}
				if (player.level == 3) { //heal
					gameExit = screen.messageBox("You learnt a new spell!", "Heal yourself with Heal!", fonts.font24);
				}
				if (player.level == 5) { //thunder
					gameExit = screen.messageBox("You learnt a new spell!", "Zap your foes with Thunder!", fonts.font24);
				}
				if (player.level == 10) { //health drain
					gameExit = screen.messageBox("You learnt a new spell!", "Steal health with Health Drain!", fonts.font24);
				}
				if (player.level == 15) { //g nova
					gameExit = screen.messageBox("You learnt a new spell!", "Unleash your full power with Grand Nova!", fonts.font24);
					gameExit = screen.messageBox("Congratulations!", "You now have learnt every spell!", fonts.font24);
					gameExit = screen.messageBox("Have fun using them", "to defeat your foes!", fonts.font24);
				}
			}

			else if (player.pClass == "rogue")
			{
				if (player.level == 2) { //Steal
					gameExit = screen.messageBox("You learnt a new spell!", "Plunder items with Steal!", fonts.font24);
					gameExit = screen.messageBox("Remember to cast a spell,", "you need enough MP to cast it!", fonts.font24);
				}
				if (player.level == 3) {//Life steal
					gameExit = screen.messageBox("You learnt a new spell!", "Life Steal from your foes!", fonts.font24);
				}
				if (player.level == 5) {//Cash N Grab
					gameExit = screen.messageBox("You learnt a new spell!", "Cash N Grab enemy gold!", fonts.font24);
				}
				if (player.level == 10) { //Backstab
					gameExit = screen.messageBox("You learnt a new spell!", "Hit weak points with Backstab!", fonts.font24);
				}
				if (player.level == 15) { //Nova Blitz
					gameExit = screen.messageBox("You learnt a new spell!", "Unleash your full power of Nova Blitz!", fonts.font24);
					gameExit = screen.messageBox("Congratulations!", "You now have learnt every spell!", fonts.font24);
					gameExit = screen.messageBox("Have fun using them", "to defeat your foes!", fonts.font24);
				}
			}
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
	void drawBaseImage(Player& player, Screen& screen, Mobs::mob enemy, Fonts fonts);
	bool quit = false;
	if (player.currentHP <= 0) {
		player.currentHP = 0;
		drawBaseImage(player, screen, enemy, fonts);
		SDL_UpdateWindowSurface(screen.gWindow);
		phaseHolder = 0;
		player.gold = floor(player.gold / 2);
		player.x = 28 * 32;
		player.y = 1 * 32;
		player.map.x = 58 * 32;
		player.map.y = 1 * 32;
		player.currentMap = 0;
		player.currentHP = player.maxHP;
		player.currentMP = player.maxMP;
		player.deathCount++;
		player.lost = true;
		quit = screen.messageBox("You fainted & lost half your gold!", "Restart from the village!", fonts.font24);
		if (player.deathCount == 3)
			quit = screen.messageBox("You seem to be having a hard time", "Buy some armour from the shop", fonts.font24);
	}
	else {
		phaseHolder = 1; //switches back to the player's turn
		//quit = screen.messageBox("It is now your turn again", " ", fonts.font24);
		combatCursorPos = 1;
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
			screen.displayLeftText("Tornado S 6MP", 680, 528, fonts.font20);
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
			screen.displayLeftText("Fire 2MP", 70, 528, fonts.font20);
		}
		if (player.level >= 3) {
			screen.displayLeftText("Heal 4MP", 380, 528, fonts.font20);
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
			screen.displayLeftText("Steal 2MP", 70, 528, fonts.font20);
		}
		if (player.level >= 3) {
			screen.displayLeftText("Life Steal 4MP", 380, 528, fonts.font20);
		}
		if (player.level >= 5) {
			screen.displayLeftText("Cash Grab 6MP", 680, 528, fonts.font20);
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
	screen.displayLeftText(("Health P.X" + to_string(player.inventory[1])), 48, 528, fonts.font20);
	screen.displayLeftText(("Ironskin P.X" + to_string(player.inventory[4])), 370, 528, fonts.font20);
	screen.displayLeftText(("Berserk P.X" + to_string(player.inventory[5])), 680, 528, fonts.font20);
	screen.displayLeftText(("Magic P.X" + to_string(player.inventory[2])), 48, 600, fonts.font20);
	screen.displayLeftText(("Smoke B.X" + to_string(player.inventory[3])), 370, 600, fonts.font20);
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

bool drawCombatCanvas(Player& player, Screen& screen, Mobs::mob& enemy, Fonts fonts, int& combatCursorPos, Mobs mobs, Music music, int& phaseHolder)
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
			gameExit = screen.messageBox("It's the enemy's turn!", "", fonts.font24);
			mobs.enemyTurn(player, screen, fonts, music, enemy);
			drawBaseImage(player, screen, enemy, fonts);
			//phaseHolder = 1;
			//gameExit = didPlayerLose(player, enemy, screen, fonts, phaseHolder, mobs, combatCursorPos, gameExit);
			break;
	}
	return gameExit;
}

bool battleMenu(int optionSelected, int& phaseHolder, bool& quit, Player& player, Mobs::mob& enemy, Screen& screen, Fonts& fonts, Music& music, int& combatCursorPos)
{
	bool crit = false;
	int damage;
	bool gameExit = false;

	switch (optionSelected)
	{
	case 0: //Button 0
		if (phaseHolder == 2) //Magic Menu
		{
			if (player.level >= 2)
			{
				if (player.currentMP >= 2)
				{
					if (player.pClass == "warrior")
					{
						//Flame Slash
						damage = calculateDamageDealt(floor(player.magicFlameSlash() * player.berserkPotionEffect), floor(enemy.magicDefence + enemy.physicalDefence) / 2);
						enemy.hp -= damage;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayHit();
						gameExit = screen.messageBox("You set your sword on fire, ", "You slash with volcanic fury", fonts.font24);
						gameExit = screen.messageBox(to_string(damage) + " Damage!!! ", "", fonts.font24);
					}
					else if (player.pClass == "mage")
					{
						//Fire
						damage = calculateDamageDealt(floor(player.magicFire() * player.berserkPotionEffect), floor(enemy.magicDefence));
						enemy.hp -= damage;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayMagic();
						gameExit = screen.messageBox("Through the arcane arts, you summon", "a blaze that scorches the enemy!", fonts.font24);
						gameExit = screen.messageBox(to_string(damage) + " Damage!!! ", "", fonts.font24);
					}
					else if (player.pClass == "rogue")
					{
						//Steal
						music.PlayHit();
						gameExit = screen.messageBox("You attempt to steal ", "an item from the enemy", fonts.font24);
						bool steal = false;
						int damage = player.magicSteal(steal);
						enemy.hp -= damage;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						if (steal == true)
						{
							gameExit = screen.messageBox(to_string(damage) + " Damage!!! ", "", fonts.font24);
							gameExit = screen.messageBox("You stole a " + player.inventoryNames[enemy.itemDrop], "from the " + enemy.enemyName, fonts.font24);
							player.inventory[enemy.itemDrop]++;
						}
						else
						{
							gameExit = screen.messageBox("Your steal attempt failed...", "", fonts.font24);
						}
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
					}
					phaseHolder = 4; //Enemies Turn
				}
				else
				{
					gameExit = screen.messageBox("Not enough MP to cast", "", fonts.font24);
					phaseHolder = 2; //Magic Menu

				}
			}
		}
		else if (phaseHolder == 3) //Item Menu
		{
			if (player.inventory[1] > 0) //health potion = 1, mana potion = 2, smoke bomb = 3, iron skin potion =  4, berserk potion = 5
			{
				int beforeHeal = player.currentHP;
				int afterHeal = 0;
				player.currentHP += player.itemHealthPotion();
				music.PlayHeal();
				if (player.currentHP > player.maxHP)
					player.currentHP = player.maxHP;
				afterHeal = player.currentHP - beforeHeal;
				gameExit = screen.messageBox("The potion restored " + to_string(afterHeal) + "HP!", "Your defence and attack were restored", fonts.font24);
				phaseHolder = 4; //Enemy Turn
			}
		}
	case 1:
		if (phaseHolder == 1) //Combat Menu
		{
			if (getRandomInt(1, 100) > player.hitChance)
			{
				gameExit = screen.messageBox("You attack with " + player.equippedWeapon.weaponName, "Attack Missed!", fonts.font24);
			}
			else
			{
				music.PlayHit();
				damage = calculateDamageDealt(floor(player.playerNormalAttack(crit) * player.berserkPotionEffect), enemy.physicalDefence);
				enemy.hp -= damage;
				drawBaseImage(player, screen, enemy, fonts);
				SDL_UpdateWindowSurface(screen.gWindow);
				if (crit == true)
					gameExit = screen.messageBox("You attack with " + player.equippedWeapon.weaponName, "Critical hit! " + to_string(damage) + " Damage!", fonts.font24);
				else
					gameExit = screen.messageBox("You attack with " + player.equippedWeapon.weaponName, to_string(damage) + " Damage!", fonts.font24);
			}
			phaseHolder = 4;
		}
		else if (phaseHolder == 2) //Magic Menu
		{
			if (player.level >= 3)
			{
				if (player.currentMP >= 4)
				{
					if (player.pClass == "warrior")
					{
						//Sheer Will
						int heal = player.magicSheerWill();
						int maxHealed = player.maxHP - player.currentHP;
						player.currentHP += heal;
						music.PlayHeal();
						if (player.currentHP > player.maxHP)
							player.currentHP = player.maxHP;
						if (heal > maxHealed)
							heal = maxHealed;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayMagic();
						gameExit = screen.messageBox("You focus your mind and body ", "You healed " + to_string(heal) + " HP!", fonts.font24);
					}
					else if (player.pClass == "mage")
					{
						//Heal
						bool restored = false;
						int heal = player.magicHeal();
						int maxHealed = player.maxHP - player.currentHP;
						player.currentHP += heal;
						if (player.currentHP > player.maxHP)
							player.currentHP = player.maxHP;
						if (heal > maxHealed)
							heal = maxHealed;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayHeal();
						gameExit = screen.messageBox("Your magic flows through your body", "You healed " + to_string(heal) + " HP!", fonts.font24);
						gameExit = screen.messageBox("Your attack and defence", "were restored! ", fonts.font24);
					}
					else if (player.pClass == "rogue")
					{
						//Life Steal
						damage = calculateDamageDealt(floor(player.magicLifeSteal() * player.berserkPotionEffect), enemy.magicDefence);
						if (damage > enemy.hp)
							damage = enemy.hp;
						enemy.hp -= damage;
						int heal = damage * 0.9;
						int maxHealed = player.maxHP - player.currentHP;
						player.currentHP += heal;
						if (player.currentHP > player.maxHP)
							player.currentHP = player.maxHP;
						if (heal > maxHealed)
							heal = maxHealed;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayHeal();
						gameExit = screen.messageBox("You sap the enemy of " + to_string(damage) + " HP! ", "You regain " + to_string(heal) + " HP!", fonts.font24);
					}
					phaseHolder = 4; //Enemy Turn
				}
				else
				{
					gameExit = screen.messageBox("Not enough MP to cast", "", fonts.font24);
					phaseHolder = 2; //Magic Menu
				}
			}
		}
		else if (phaseHolder == 3) //Item Menu
		{
			if (player.inventory[4] > 0) //health potion = 1, mana potion = 2, smoke bomb = 3, iron skin potion =  4, berserk potion = 5
			{
				player.itemIronSkinPotion();
				phaseHolder = 4; // Enemy Turn
			}
		}
		break;
	case 2:
		if (phaseHolder == 1) //Main Menu Options
		{
			phaseHolder = 2;  //Magic Menu
			combatCursorPos = 0;
		}
		else if (phaseHolder == 2) //Magic Menu Options
		{
			if (player.level >= 5)
			{
				if (player.currentMP >= 6)
				{
					if (player.pClass == "warrior")
					{
						//Tornado Slash
						int damage = calculateDamageDealt(floor(player.magicTornadoSlash() * player.berserkPotionEffect), floor((enemy.magicDefence + enemy.physicalDefence) / 2));
						enemy.hp -= damage;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayHit();
						gameExit = screen.messageBox("Your magic calls down thunder bolts!", "To strike your foe!", fonts.font24);
						gameExit = screen.messageBox(to_string(damage) + " Damage!!! ", "", fonts.font24);
					}
					else if (player.pClass == "mage")
					{
						//Thunder
						int damage = calculateDamageDealt(floor(player.magicThunder() * player.berserkPotionEffect), enemy.magicDefence);
						enemy.hp -= damage;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayMagic();
						gameExit = screen.messageBox("Your magic calls down thunder bolts!", "To strike your foe!", fonts.font24);
						gameExit = screen.messageBox(to_string(damage) + " Damage!!! ", "", fonts.font24);
					}
					else if (player.pClass == "rogue")
					{
						//Cash N Grab
						gameExit = screen.messageBox("You attack the enemy,", "and attempt to steal gold", fonts.font24);
						damage = calculateDamageDealt(floor(player.magicCashNGrab() * player.berserkPotionEffect), enemy.magicDefence);
						enemy.hp -= damage;
						int goldEarned = ceil(enemy.goldDrop * 3);
						player.gold += goldEarned;
						music.PlayHit();
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						gameExit = screen.messageBox("Your swift movements causes " + to_string(damage) + " damage!", "You steal " + to_string(goldEarned) + " gold!", fonts.font24);
					}
					phaseHolder = 4; //Enemy Turn
				}
				else
				{
					gameExit = screen.messageBox("Not enough MP to cast", "", fonts.font24);
					phaseHolder = 2; //Magic Menu
				}
			}
		}
		else if (phaseHolder == 3) //Item Menu
		{
			if (player.inventory[5] > 0) //health potion = 1, mana potion = 2, smoke bomb = 3, iron skin potion =  4, berserk potion = 5
			{
				player.itemBerserkPotion();
				phaseHolder = 4; //Enemy Turn
			}
		}
		break;
	case 3:
		if (phaseHolder == 2) //Magic Menu Options
		{
			if (player.level >= 10)
			{
				if (player.currentMP >= 8)
				{
					if (player.pClass == "warrior")
					{
						//Bulk Up
						if (player.berserkPotionEffect == 4)
						{
							gameExit = screen.messageBox("You are already at full strength!", "Go get 'em!", fonts.font24);
							phaseHolder = 2;
						}
						else
						{
							player.magicBulkUp();
							music.PlayHeal();
							gameExit = screen.messageBox("Both physical attack and physical", " defence massively improved!", fonts.font24);
							if (player.berserkPotionEffect == 4)
								gameExit = screen.messageBox("You are now at full strength!", "Go get 'em!", fonts.font24);
							phaseHolder = 4;
						}

					}
					else if (player.pClass == "mage")
					{
						//Drain Health
						damage = calculateDamageDealt(floor(player.magicDrainHealth() * player.berserkPotionEffect), enemy.magicDefence);
						int heal = damage / 2;
						enemy.hp -= damage;
						player.currentHP += heal;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayHeal();
						screen.messageBox("You sap " + enemy.enemyName + "'s vitality", to_string(damage) + " Damage! " + to_string(heal) + " Health restored!", fonts.font24);
						phaseHolder = 4;	//Enemy's Turn
					}
					else if (player.pClass == "rogue")
					{
						//Backstab
						damage = calculateDamageDealt(floor(player.magicBackstab() * player.berserkPotionEffect), enemy.physicalDefence);
						enemy.hp -= damage;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayHit();
						gameExit = screen.messageBox("You attack the enemy's weakpoint ", "for a massive" + to_string(damage) + " damage! ", fonts.font24);
						phaseHolder = 4; //Enemy's Turn
					}
				}
				else
				{
					gameExit = screen.messageBox("Not enough MP to cast", "", fonts.font24);
					phaseHolder = 2; //Magic Menu
				}
			}
		}
		else if (phaseHolder == 3) //Item Menu
		{
			if (player.inventory[2] > 0) //health potion = 1, mana potion = 2, smoke bomb = 3, iron skin potion =  4, berserk potion = 5
			{
				music.PlayHeal();
				player.currentMP = player.itemMagicPotion();
				if (player.currentMP > player.maxMP)
					player.currentMP = player.maxMP;
				phaseHolder = 4; //Enemy Turn
			}
		}
		break;
	case 4:
	{
		if (phaseHolder == 1) //If Main Menu
		{
			phaseHolder = 3;  //Item Menu
			combatCursorPos = 0;
		}
		else if (phaseHolder == 2) //Magic Menu
		{
			if (player.level >= 15)
			{
				if (player.currentMP >= 10)
				{
					if (player.pClass == "warrior")
					{
						//Nova Slash
						damage = calculateDamageDealt(floor(player.magicNovaSlash() * player.berserkPotionEffect), floor((enemy.magicDefence + enemy.physicalDefence) / 2));
						enemy.hp -= damage;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayMagic();
						gameExit = screen.messageBox("You slash with the power of a demon", "But where did you get this power?!?", fonts.font24);
						gameExit = screen.messageBox(to_string(damage) + " Damage!!! ", "", fonts.font24);
					}
					else if (player.pClass == "mage")
					{
						//Magic Nova
						damage = calculateDamageDealt(floor(player.magicNova() * player.berserkPotionEffect), enemy.magicDefence);
						enemy.hp -= damage;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayMagic();
						gameExit = screen.messageBox("Your power rivals that of a demon!", "But where did you get this power?!?", fonts.font24);
						gameExit = screen.messageBox(to_string(damage) + " Damage!!! ", "", fonts.font24);
					}
					else if (player.pClass == "rogue")
					{
						//Nova Blitz
						damage = calculateDamageDealt(floor(player.magicNovaBlitz() * player.berserkPotionEffect), enemy.magicDefence);
						enemy.hp -= damage;
						drawBaseImage(player, screen, enemy, fonts);
						SDL_UpdateWindowSurface(screen.gWindow);
						music.PlayMagic();
						gameExit = screen.messageBox("You attack with the fury of a demon", "But where did you get this power?!?", fonts.font24);
						gameExit = screen.messageBox(to_string(damage) + " Damage!!! ", "", fonts.font24);
					}
					phaseHolder = 4; //Enemies Turn
				}
				else
				{
					gameExit = screen.messageBox("Not enough MP to cast", "", fonts.font24);
					phaseHolder = 2; //Magic Menu
				}
			}
		}
		else if (phaseHolder == 3) //Item Menu
		{
			if (player.inventory[3] > 0) //health potion = 1, mana potion = 2, smoke bomb = 3, iron skin potion =  4, berserk potion = 5
			{
				player.itemSmokeBomb();
				phaseHolder = 4; //Enemy Turn
			}
		}
	}
	break;
	case 5:
		combatCursorPos = 1;
		if (phaseHolder == 1) //Main Menu
			quit = runAway(player, enemy, screen, fonts, phaseHolder, gameExit); //Run Away
		else if (phaseHolder == 2 || phaseHolder == 3)
			phaseHolder = 1;	//Return to Main Menu
		break;

	}
	return gameExit;
}

bool openInventory(Screen& screen, Player& player, Music& music, Fonts& fonts)
{
	bool gameExit = false;
	bool quit = false;
	vector <int> InvbuttonX = { 665, 750 };
	vector <int> InvbuttonY = { 85, 85 };
	int InvbuttonWidth = 64;
	int InvbuttonHeight = 64;

	bool InvBoxVisible = false;
	int InvBoxX = 0;
	int InvBoxY = 0;
	int InvBoxWidth = 64;
	int InvBoxSize = 64;
	int InvBoxHeight = 32;
	int mouseX = 0;
	int mouseY = 0;
	int coinCount = 0;
	int shift = 0;
	int frameWidth = 60;
	int frameHeight = 60;
	int totalFrames = 12;
	int currentFrame = 0;
	int cursorSelected = 0;

	void drawInventory(Screen& screen, Player& player, int& coinCount, int& shift, int frameWidth, int frameHeight, int totalFrames, int& currentFrame, Fonts fonts, int cursorSelected);

	screen.loadMedia(screen.gCoin, "images/coin.bmp");
	screen.loadMedia(screen.gBattleTextBox, "images/invScreen.bmp");
	screen.loadMedia(screen.gWeaponIcon, "images/sword.bmp");
	screen.loadMedia(screen.gSelectIcon, "images/VOL.bmp");
	screen.loadMedia(screen.gMessage, "images/messageBox.bmp");

	if (player.equippedWeapon.weaponName == "Bone")
	{
		screen.loadMedia(screen.gWeaponIcon, "images/bone.bmp");
	}
	else if (player.equippedWeapon.weaponName == "Wooden Staff" || player.equippedWeapon.weaponName == "Master Wand")
	{
		screen.loadMedia(screen.gWeaponIcon, "images/staff.bmp");
	}
	else
	{
		screen.loadMedia(screen.gWeaponIcon, "images/sword.bmp");
	}

	void drawInventory(Screen& screen);

	//screen.loadMedia(screen.gWeaponIcon, "images/coin.bmp");

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

				for (size_t i = 0; i < InvbuttonX.size(); i++)
				{
					if (mouseX > InvbuttonX[i] && mouseX < InvbuttonX[i] + InvbuttonWidth)
					{
						if (mouseY > InvbuttonY[i] && mouseY < InvbuttonX[i] + InvbuttonWidth)
						{
							InvBoxX = InvbuttonX[i];
							InvBoxY = InvbuttonY[i];
							cursorSelected = i;
							//settingsBoxVisible = true;
						}
					}
				}
			}

			//Left Click Event
			if (event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED)
			{
				for (int i = 0; i < InvbuttonX.size(); i++)
				{
					if (mouseX > InvbuttonX[i] && mouseX < InvbuttonX[i] + InvbuttonWidth)
					{
						if (mouseY > InvbuttonY[i] && mouseY < InvbuttonY[i] + InvbuttonHeight)
						{
							switch (i)
							{
								case 0:
								{

									if (player.currentHP < player.maxHP && player.inventory[1] > 0)
									{
										music.PlayHeal();
										player.currentHP += player.itemHealthPotion();
										if (player.currentHP > player.maxHP)
										{
											player.currentHP = player.maxHP;
										}
									}

								}
								break;
								case 1:
								{
									if (player.currentMP < player.maxMP&& player.inventory[2] > 0)
									{
										music.PlayHeal();
										player.currentMP = player.itemMagicPotion();
										if (player.currentMP > player.maxMP)
										{
											player.currentMP = player.maxMP;
										}
									}
								}
								break;
							}
						}
					}
				}
			}
			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_BACKSPACE || event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
				else if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT)
				{
					InvBoxX = InvbuttonX[0];
					InvBoxY = InvbuttonY[0];
					cursorSelected = 0;
				}
				else if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
				{
					InvBoxX = InvbuttonX[1];
					InvBoxY = InvbuttonY[1];
					cursorSelected = 1;
				}
				else if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_RETURN)
				{
					switch (cursorSelected)
					{
						case 0:
						{
							if (player.currentHP < player.maxHP && player.inventory[1] > 0)
							{
								music.PlayHeal();
								player.currentHP += player.itemHealthPotion();
								if (player.currentHP > player.maxHP)
								{
									player.currentHP = player.maxHP;
								}
							}
						}
						break;
						case 1:
						{
							if (player.currentMP < player.maxMP&& player.inventory[2] > 0)
							{
								music.PlayHeal();
								player.currentMP = player.itemMagicPotion();
								if (player.currentMP > player.maxMP)
								{
									player.currentMP = player.maxMP;
								}
							}
						}
						break;
					}
				}

			}
			//Controller move event
			if (event.type == SDL_JOYHATMOTION)
			{
				if (event.jhat.value == SDL_HAT_LEFT)
				{
					InvBoxX = InvbuttonX[0];
					InvBoxY = InvbuttonY[0];
					cursorSelected = 0;
				}

				if (event.jhat.value == SDL_HAT_RIGHT)
				{
					InvBoxX = InvbuttonX[1];
					InvBoxY = InvbuttonY[1];
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
						if (player.currentHP < player.maxHP && player.inventory[1] > 0)
						{
							music.PlayHeal();
							player.currentHP += player.itemHealthPotion();
							if (player.currentHP > player.maxHP)
							{
								player.currentHP = player.maxHP;
							}
						}
					}
					else if (cursorSelected == 1)
					{
						if (player.currentMP < player.maxMP&& player.inventory[2] > 0)
						{
							music.PlayHeal();
							player.currentMP = player.itemMagicPotion();
							if (player.currentMP > player.maxMP)
							{
								player.currentMP = player.maxMP;
							}
						}
					}
				}
			}


		}//Event Poll

		//Draw Inventory
		drawInventory(screen, player, coinCount, shift, frameWidth, frameHeight, totalFrames, currentFrame, fonts, cursorSelected);

	}// Quit = true
		SDL_FreeSurface(screen.gCoin);				//MEMORY FIX
		screen.gCoin = NULL;						//MEMORY FIX

		SDL_FreeSurface(screen.gWeaponIcon);		//MEMORY FIX
		screen.gWeaponIcon = NULL;					//MEMORY FIX

		SDL_FreeSurface(screen.gBattleTextBox);		//MEMORY FIX
		screen.gBattleTextBox = NULL;				//MEMORY FIX

		SDL_FreeSurface(screen.gSelectIcon);		//MEMORY FIX
		screen.gSelectIcon = NULL;					//MEMORY FIX

		SDL_FreeSurface(screen.gMessage);		//MEMORY FIX
		screen.gMessage = NULL;					//MEMORY FIX

		return gameExit;
}

void drawInventory(Screen& screen, Player& player, int& coinCount, int& shift, int frameWidth, int frameHeight, int totalFrames, int& currentFrame, Fonts fonts, int cursorSelected)
{
	
	SDL_Rect sheet;

	SDL_Rect mapLoc;
	mapLoc.x = 350;
	mapLoc.y = 330;
	mapLoc.h = frameWidth;
	mapLoc.w = frameHeight;
	//SDL_BlitSurface(screen.gSprite, &sheet, screen.gScreenSurface, &mapLoc);

	SDL_BlitSurface(screen.gBattleTextBox, 0, screen.gScreenSurface, 0);

	if (coinCount <= 6)
	{
		sheet.x = shift;
		sheet.y = 0;
		sheet.h = frameWidth;
		sheet.w = frameHeight;

		SDL_BlitSurface(screen.gCoin, &sheet, screen.gScreenSurface, &mapLoc);
	}
	if (coinCount == 6) {
		shift += frameWidth;
		coinCount = 0;
		currentFrame++;
	}
	if (currentFrame == totalFrames) {
		shift = 0;
		currentFrame = 0;
	}
	coinCount++;

	mapLoc.x = 840;
	mapLoc.y = 280;
	SDL_BlitSurface(screen.gWeaponIcon, 0, screen.gScreenSurface, &mapLoc);
	drawHealthBar(25, 325, player.currentHP, player.maxHP, "#0F0", screen, false);
	drawHealthBar(25, 365, player.currentMP, player.maxMP, "#00F", screen, false);

	if (cursorSelected == 0)
	{
		mapLoc.x = 665;
		mapLoc.y = 85;
		SDL_BlitSurface(screen.gSelectIcon, 0, screen.gScreenSurface, &mapLoc);
	}
	else if (cursorSelected == 1)
	{
		mapLoc.x = 750;
		mapLoc.y = 85;
		SDL_BlitSurface(screen.gSelectIcon, 0, screen.gScreenSurface, &mapLoc);
	}

	screen.displayLeftText(to_string(player.currentHP) + "|" + to_string(player.maxHP) + "HP", 143, 353, fonts.font20);
	screen.displayLeftText(to_string(player.currentMP) + "|" + to_string(player.maxMP) + "HP", 143, 393, fonts.font20);
	screen.displayLeftText("XP", 560, 433, fonts.font20);
	screen.displayLeftText(to_string(player.inventory[1]), 700, 120, fonts.font20);
	screen.displayLeftText(to_string(player.inventory[2]), 785, 120, fonts.font20);
	screen.displayLeftText(to_string(player.inventory[5]), 870, 120, fonts.font20);
	screen.displayLeftText(to_string(player.inventory[4]), 700, 200, fonts.font20);
	screen.displayLeftText(to_string(player.inventory[3]), 785, 200, fonts.font20);
	screen.displayLeftText(to_string(player.gold), 420, 380, fonts.font28);

	SDL_BlitSurface(screen.gMessage, 0, screen.gScreenSurface, 0);
	screen.displayLeftText("Current quest: " + player.quests[player.currentQuest][player.currentQuestPoint]->des1, 48, 528, fonts.font24);
	screen.displayLeftText(player.quests[player.currentQuest][player.currentQuestPoint]->des2, 48, 600, fonts.font24);
	screen.displayLeftText("Name: " + player.name , 25, 100, fonts.font18);
	screen.displayLeftText("Physical Attack: " + to_string(player.phyAttack), 25, 130, fonts.font18);
	screen.displayLeftText("Magic Attack: " + to_string(player.magAttack), 25, 160, fonts.font18);
	screen.displayLeftText("Physical Defence: " + to_string(player.phyDefence), 25, 190, fonts.font18);
	screen.displayLeftText("Magic Defence: " + to_string(player.magDefence), 25, 220, fonts.font18);
	screen.displayLeftText("Luck: " + to_string(player.luck), 25, 250, fonts.font18);
	screen.displayLeftText("Level: " + to_string(player.level), 25, 280, fonts.font18);

	DrawEXPBar(25, 405, player.effectiveCurrentExp, player.effectiveExpLevelUp, "#ffff00", screen);	//Update window is inside here
}