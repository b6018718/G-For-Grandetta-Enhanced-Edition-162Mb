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
	void DrawEXPBar(int posX, int posY, double currentStat, double maxStat, string colour, Screen screen);
	//DrawEXPBar(25, 405, effectiveCurrentExp, effectiveExpLevelUp, "#ffff00", Screen screen);
	
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

			//Controller Joystick Event
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
			menuAnimation(screen, frames, backgroundX, fonts, buttonY, arrowX, arrowY);

	}
	SDL_GameControllerClose(controller);
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
	music.PlayVillage();
	int classSelected;
	bool gameExit = false;
	bool quit = false;

	Player player;
	Maps maps;

	bool classSelect(Screen screen, Music music, Fonts fonts, Player& player);
	bool setName(Screen screen, Fonts fonts, Player& player);
	bool interact(Player& player, Screen& screen, Maps& maps, Fonts fonts, Music& music);

	gameExit = classSelect(screen, music, fonts, player);
	screen.gPlaySurface = NULL;
	screen.loadMedia(screen.gPlaySurface, "images/bg" + to_string(player.currentMap) + ".bmp");

	//screen.gPlaySurface = SDL_ConvertSurfaceFormat(screen.gTemp, SDL_GetWindowPixelFormat(screen.gWindow), 0);
	//SDL_FreeSurface(screen.gTemp);

	screen.updateMap(screen.gPlaySurface, player, maps.zone[player.currentMap]);
	
	//Load Sprite
	string classSprite = "images/" + player.pClass + ".bmp";
	screen.loadMedia(screen.gSprite, classSprite);


	void updateSprite(Screen screen, Player& player);
	updateSprite(screen, player);

	//Call input box for name entry
	gameExit = screen.inputBox("Enter your name:", player.name, fonts.font24, player);
	screen.updateMap(screen.gPlaySurface, player, maps.zone[player.currentMap]);
	updateSprite(screen, player);

	SDL_Event event;

	

	

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
					//Interact
				}
			}

			//Controller Movement Event
			if (event.type == SDL_JOYHATMOTION)
			{
				if (event.jhat.value == SDL_HAT_LEFT)
				{
					player.moveLeft(maps);
				}

				if (event.jhat.value == SDL_HAT_RIGHT)
				{
					player.moveRight(maps);
				}

				if (event.jhat.value == SDL_HAT_DOWN)
				{
					player.moveDown(maps);
				}

				if (event.jhat.value == SDL_HAT_UP)
				{
					player.moveUp(maps);
				}
				screen.updateMap(screen.gScreenSurface, player, maps.zone[player.currentMap]);
				updateSprite(screen, player);
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
					cout << "Map X: " << player.map.x/32 << "\n";
					cout << "Map Y: " << player.map.y/32 << "\n";
				}

				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					//Open Inventory
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
			}
			if (currentKeyStates[SDL_SCANCODE_RIGHT] || currentKeyStates[SDL_SCANCODE_D])
			{
				//Move left
				player.moveRight(maps);
			}
			if (currentKeyStates[SDL_SCANCODE_UP] || currentKeyStates[SDL_SCANCODE_W])
			{
				//Move left
				player.moveUp(maps);
			}
			if (currentKeyStates[SDL_SCANCODE_DOWN] || currentKeyStates[SDL_SCANCODE_S])
			{
				//Move left
				player.moveDown(maps);
			}
			
			

			screen.updateMap(screen.gScreenSurface, player, maps.zone[player.currentMap]);
			updateSprite(screen, player);

			//FPS Capped at 90
			float endTime = (float)SDL_GetTicks();
			while ((1000 / (endTime - startTime)) > 90)
			{
				endTime = (float)SDL_GetTicks();
			}

			//cout << "Frame rate: " << 1000.0f / (endTime - startTime) << "\n";
		}
		
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
			player.initaliseStats();
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

void DrawEXPBar(int posX, int posY, double currentStat, double maxStat, string colour, Screen screen)
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

}