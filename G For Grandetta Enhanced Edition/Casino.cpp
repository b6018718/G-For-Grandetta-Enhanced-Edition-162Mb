#include "Casino.h"



Casino::Casino()
{
}


Casino::~Casino()
{
}

bool Casino::wheelOfFortune(Screen & screen, Player & player, Fonts& fonts, Equipment equipment)
{
	//Wheel of fortune = 0, fruit machine = 1, roulette table = 2
	bool gameExit = false;
	gameExit = shopEvent(player, screen, 0, fonts, equipment);
	return gameExit;
}

void Casino::drawWheelOfFortune(Screen & screen, Player & player, int shopCursorPos, Fonts & fonts)
{
	screen.displayLeftText("Bet 50 Gold", 70, 528, fonts.font20);
	screen.displayLeftText("Bet 100 Gold", 370, 528, fonts.font20);
	screen.displayLeftText("Bet 500 Gold", 680, 528, fonts.font20);
	screen.displayLeftText("Bet 1000 Gold", 70, 600, fonts.font20);
	screen.displayLeftText("Bet 2500 Gold", 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);

	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText(">", 46, 528, fonts.font18);
		screen.displayLeftText("Small bet eh?", 30, 433, fonts.font18);
		break;
	case 2:
		screen.displayLeftText(">", 346, 528, fonts.font18);
		screen.displayLeftText("A little better", 30, 433, fonts.font18);
		break;
	case 3:
		screen.displayLeftText(">", 656, 528, fonts.font18);
		screen.displayLeftText("Now we're talking! ", 30, 433, fonts.font18);
		break;
	case 4:
		screen.displayLeftText(">", 46, 600, fonts.font18);
		screen.displayLeftText("Big man bet here!", 30, 433, fonts.font18);
		break;
	case 5:
		screen.displayLeftText(">", 346, 600, fonts.font18);
		screen.displayLeftText("Someone has a problem...", 30, 433, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		screen.displayLeftText("Leaving with your head?", 30, 433, fonts.font18);
		break;
	}
}

void Casino::playWheelOfFortune(Player& player, int bet, Screen& screen, Fonts& fonts)
{
	if (player.gold >= bet)
	{
		if (getRandomInt(0, 100) + player.luck <= 50)
		{
			player.gold += bet;
			screen.messageBox("Lucky! You doubled ", "the gold you bet!", fonts.font24);
		}
		else
		{
			player.gold -= bet;
			screen.messageBox("You lost!", "Try again next time!", fonts.font24);
		}
	}
	else
	{
		screen.messageBox("You can't afford this!", "", fonts.font24);
	}
}

void Casino::wheelOfFortuneMenu(Player& player, int cursor, bool& quit, Screen& screen, Fonts& fonts)
{
	switch (cursor) {
	case 1:
		playWheelOfFortune(player, 50, screen, fonts);
		break;
	case 2:
		playWheelOfFortune(player, 100, screen, fonts);
		break;
	case 3:
		playWheelOfFortune(player, 500, screen, fonts);
		break;
	case 4:
		playWheelOfFortune(player, 1000, screen, fonts);
		break;
	case 5:
		playWheelOfFortune(player, 2500, screen, fonts);
		break;
	case 6:
		quit = true;
		break;
	}
}

bool Casino::fruitMachine(Screen& screen, Player& player, Fonts& fonts, Equipment equipment)
{
	bool gameExit = false;
	playFruitMachine(player, screen, fonts);
	return gameExit;
}

void Casino::playFruitMachine(Player& player, Screen& screen, Fonts& fonts)
{
	if (player.gold >= 50)
	{
		screen.messageBox("You insert 50 Gold", "and pull the lever", fonts.font24);
		player.gold -= 50;
		int result = getRandomInt(1, 10000);
		if (result == 1)
		{
			screen.messageBox("JACKPOT LUCKY 777s", "Win 50,000 Gold!", fonts.font24);
			player.gold += 50000;
		}
		else if(result <= 10)
		{
			screen.messageBox("BAR BAR BAR", "Win 5,000 Gold!", fonts.font24);
			player.gold += 5000;
		}
		else if (result <= 50)
		{
			screen.messageBox("MELON MELON MELON", "Win 2,500 Gold!", fonts.font24);
			player.gold += 2500;
		}
		else if (result <= 100)
		{
			screen.messageBox("LEMON LEMON LEMON", "Win 500 Gold!", fonts.font24);
			player.gold += 500;
		}
		else if (result <= 250)
		{
			screen.messageBox("CHERRY CHERRY CHERRY", "Win 250 Gold!", fonts.font24);
			player.gold += 250;
		}
		else
		{
			screen.messageBox("Unlucky, you lost", "Better luck next time", fonts.font24);
		}
	}
	else
	{
		screen.messageBox("This machine costs 50 Gold", "Come back when you have more", fonts.font24);
	}
}


void Casino::drawFruitMachine(Screen & screen, Player & player, int shopCursorPos, Fonts & fonts)
{
	screen.displayLeftText("Health P.X" + to_string(player.inventory[1]), 70, 528, fonts.font20);
	screen.displayLeftText("Ironskin P.X" + to_string(player.inventory[4]), 370, 528, fonts.font20);
	screen.displayLeftText("Berserk P.X" + to_string(player.inventory[5]), 680, 528, fonts.font20);
	screen.displayLeftText("Magic P.X" + to_string(player.inventory[2]), 70, 600, fonts.font20);
	screen.displayLeftText("Smoke B.X" + to_string(player.inventory[3]), 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);

	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText(">", 46, 528, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string((int)floor(player.inventoryItemCost[1] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 2:
		screen.displayLeftText(">", 346, 528, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string((int)floor(player.inventoryItemCost[4] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 3:
		screen.displayLeftText(">", 656, 528, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string((int)floor(player.inventoryItemCost[5] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 4:
		screen.displayLeftText(">", 46, 600, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string((int)floor(player.inventoryItemCost[2] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 5:
		screen.displayLeftText(">", 346, 600, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string((int)floor(player.inventoryItemCost[3] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}

}

bool Casino::rouletteTable(Screen& screen, Player& player, Fonts& fonts, Equipment equipment)
{
	//Wheel of fortune = 0, fruit machine = 1, roulette table = 2
	bool gameExit = false;
	gameExit = shopEvent(player, screen, 2, fonts, equipment);
	return gameExit;
}

void Casino::drawRoutetteTable(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts)
{
	screen.displayLeftText("Bet on Red", 70, 528, fonts.font20);
	screen.displayLeftText("Bet on 23", 370, 528, fonts.font20);
	screen.displayLeftText("Bet on 3rd 12", 680, 528, fonts.font20);
	screen.displayLeftText("Bet on Black", 70, 600, fonts.font20);
	screen.displayLeftText("Bet on 00", 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);
	screen.displayLeftText("Bet: 100", 30, 433, fonts.font18);
	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText(">", 46, 528, fonts.font18);
		break;
	case 2:
		screen.displayLeftText(">", 346, 528, fonts.font18);
		break;
	case 3:
		screen.displayLeftText(">", 656, 528, fonts.font18);
		break;
	case 4:
		screen.displayLeftText(">", 46, 600, fonts.font18);
		break;
	case 5:
		screen.displayLeftText(">", 346, 600, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
}

void Casino::playRouletteTable(Player& player, string bet, Screen& screen, Fonts& fonts)
{
	if (player.gold >= 100)
	{
		player.gold -= 100;
		int result = getRandomInt(0, 36);
		if (bet == "red")
		{
			if ((result == 3) || (result == 9) || (result == 12) || (result == 21) || (result == 27) || (result == 30) || (result == 36) || (result == 5) || (result == 14) || (result == 23) || (result == 32) || (result == 1) || (result == 7) || (result == 16) || (result == 19) || (result == 25) || (result == 34))
			{
				screen.messageBox("The result was " + to_string(result), "Whichs means your bet on " + bet + " WINS", fonts.font24);
				screen.messageBox("Congratulations you DOUBLED ", "your bet!", fonts.font24);
				player.gold += 200;
			}
			else
				screen.messageBox("The result was " + to_string(result), "Unfortunately you lose!", fonts.font24);
		}
		else if (bet == "23")
		{
			if (result == 23) 
			{
				screen.messageBox("The result was " + to_string(result), "Which mean your bet on " + bet + " WINS!", fonts.font24);
				screen.messageBox("Congratulatios you multiplied ", "your bet by 36!!!", fonts.font24);
				player.gold += 100 * 36;

			}
			else
				screen.messageBox("The result was " + to_string(result), "Unfortunately you lose!", fonts.font24);
		}
		else if (bet == "3rd 12")
		{
			if ((result == 27) || (result == 33) || (result == 30) || (result == 36) || (result == 26) || (result == 29) || (result == 32) || (result == 35) || (result == 25) || (result == 28) || (result == 31) || (result == 34))
			{
				screen.messageBox("The result was " + to_string(result), "Which mean your bet on " + bet + " WINS!", fonts.font24);
				screen.messageBox("Congratulatios you TRIPLED", "your money!!!", fonts.font24);
				player.gold += 100 * 3;
			}
			else
				screen.messageBox("The result was " + to_string(result), "Unfortunately you lose!", fonts.font24);
		}
		else if (bet == "black")
		{
			if (!((result == 3) || (result == 9) || (result == 12) || (result == 21) || (result == 27) || (result == 30) || (result == 36) || (result == 5) || (result == 14) || (result == 23) || (result == 32) || (result == 1) || (result == 7) || (result == 16) || (result == 19) || (result == 25) || (result == 34)))
			{
				screen.messageBox("The result was " + to_string(result), "Which mean your bet on " + bet + " WINS!", fonts.font24);
				screen.messageBox("Congratulations you DOUBLED", "your monies!!!", fonts.font24);
				player.gold += (100 * 2);
			}
			else
				screen.messageBox("The result was " + to_string(result), "Unfortunately you lose!", fonts.font24);
		}
		else if (bet == "00")
		{
			if (result == 0)
			{
				screen.messageBox("The result was " + to_string(result), "Which mean your bet on " + bet + " WINS!", fonts.font24);
				screen.messageBox("Congratulations you multiplied", "your money by 36!!!", fonts.font24);
				player.gold += 100 * 36;
			}
			else
				screen.messageBox("The result was " + to_string(result), "Unfortunately you lose!", fonts.font24);
		}
	}
	else
	{
		screen.messageBox("You don't have", "enough gold!", fonts.font24);
	}
}

bool Casino::shopEvent(Player & player, Screen & screen, int shop, Fonts fonts, Equipment equipment)
{
	bool gameExit = false;
	bool quit = false;
	int mouseX = 0;
	int mouseY = 0;
	vector <int> buttonXCombat = { 19, 327, 636, 19, 327, 636 };
	vector <int> buttonYCombat = { 481, 481, 481, 545, 545, 545 };
	int combatButtonHeight = 60;
	int combatButtonWidth = 306;
	int combatCursorPos = 1;	//The location of the cursor on screen
	int optionSelected = 1; //Menu option chosen
	int armouryPos = 1;
	if (!screen.loadMedia(screen.gBattleTextBox, "images/messageLong.png"));
	{
		//printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
#

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
							combatCursorPos = i + 1;
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
							*/
							switch (shop)
							{
							case 0:
								switch (combatCursorPos) //Wheel Of Fortune
								{
								case 1:
									playWheelOfFortune(player, 50, screen, fonts);
									break;
								case 2:
									playWheelOfFortune(player, 100, screen, fonts);
									break;
								case 3:
									playWheelOfFortune(player, 500, screen, fonts);
									break;
								case 4:
									playWheelOfFortune(player, 1000, screen, fonts);
									break;
								case 5:
									playWheelOfFortune(player, 2500, screen, fonts);
									break;
								case 6:
									quit = true;
									break;
								}
								break;
							case 1:	//Fruit Machine
								playFruitMachine(player, screen, fonts); //Health Potion
								break;
							case 2:	//Roulette Table
								switch (combatCursorPos) {
								case 1:
									playRouletteTable(player, "red", screen, fonts);
									break;
								case 2:
									playRouletteTable(player, "23", screen, fonts);
									break;
								case 3:
									playRouletteTable(player, "3rd 12", screen, fonts);
									break;
								case 4:
									playRouletteTable(player, "black", screen, fonts);
									break;
								case 5:
									playRouletteTable(player, "00", screen, fonts);
									break;
								case 6:
									quit = true;
									break;
								}
								break;
							}
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
					moveLeft(combatCursorPos, shop);
				}

				if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
				{
					moveRight(combatCursorPos, shop);
				}

				if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
				{
					moveDown(combatCursorPos, shop);
				}

				if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP)
				{
					moveUp(combatCursorPos, shop);
				}

				if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE)
				{
					/*  Menu
					case 0		case 1		case 2
					case 3		case 4		case 5
					*/
					switch (shop)
					{
					case 0:
						switch (combatCursorPos) //Wheel Of Fortune
						{
						case 1:
							playWheelOfFortune(player, 50, screen, fonts);
							break;
						case 2:
							playWheelOfFortune(player, 100, screen, fonts);
							break;
						case 3:
							playWheelOfFortune(player, 500, screen, fonts);
							break;
						case 4:
							playWheelOfFortune(player, 1000, screen, fonts);
							break;
						case 5:
							playWheelOfFortune(player, 2500, screen, fonts);
							break;
						case 6:
							quit = true;
							break;
						}
						break;
					case 1:	//Fruit Machine
						playFruitMachine(player, screen, fonts); 
						break;
					case 2:	//Roulette Table
						switch (combatCursorPos) {
						case 1:
							playRouletteTable(player, "red", screen, fonts);
							break;
						case 2:
							playRouletteTable(player, "23", screen, fonts);
							break;
						case 3:
							playRouletteTable(player, "3rd 12", screen, fonts);
							break;
						case 4:
							playRouletteTable(player, "black", screen, fonts);
							break;
						case 5:
							playRouletteTable(player, "00", screen, fonts);
							break;
						case 6:
							quit = true;
							break;
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
					moveLeft(combatCursorPos, shop);
				}

				if (event.jhat.value == SDL_HAT_RIGHT)
				{
					moveRight(combatCursorPos, shop);
				}

				if (event.jhat.value == SDL_HAT_UP)
				{
					moveUp(combatCursorPos, shop);
				}

				if (event.jhat.value == SDL_HAT_DOWN)
				{
					moveDown(combatCursorPos, shop);
				}
			}

			//Controller button event
			if (event.type == SDL_JOYBUTTONDOWN)
			{
				if (event.jbutton.button == 0)
				{
					if (armouryPos == 1)
						quit = true;
					else
						armouryPos = 1;
				}

				if (event.jbutton.button == 1)
				{
					/*  Menu
					case 0		case 1		case 2
					case 3		case 4		case 5
					*/
					switch (shop)
					{
					case 0:
						switch (combatCursorPos) //Wheel Of Fortune
						{
						case 1:
							playWheelOfFortune(player, 50, screen, fonts);
							break;
						case 2:
							playWheelOfFortune(player, 100, screen, fonts);
							break;
						case 3:
							playWheelOfFortune(player, 500, screen, fonts);
							break;
						case 4:
							playWheelOfFortune(player, 1000, screen, fonts);
							break;
						case 5:
							playWheelOfFortune(player, 2500, screen, fonts);
							break;
						case 6:
							quit = true;
							break;
						}
						break;
					case 1:	//Fruit Machine
						playFruitMachine(player, screen, fonts);
						break;
					case 2:	//Roulette Table
						switch (combatCursorPos) {
						case 1:
							playRouletteTable(player, "red", screen, fonts);
							break;
						case 2:
							playRouletteTable(player, "23", screen, fonts);
							break;
						case 3:
							playRouletteTable(player, "3rd 12", screen, fonts);
							break;
						case 4:
							playRouletteTable(player, "black", screen, fonts);
							break;
						case 5:
							playRouletteTable(player, "00", screen, fonts);
							break;
						case 6:
							quit = true;
							break;
						}
						break;
					}
				}
			}
		}//POLL EVENT WHILE
		SDL_BlitSurface(screen.gBattleTextBox, NULL, screen.gScreenSurface, 0);
		switch (shop)
		{
		case 0:
			drawWheelOfFortune(screen, player, combatCursorPos, fonts);
			break;
		case 1:
			//drawFruitMachine(screen, player, combatCursorPos, fonts);
			break;
		case 2:
			drawRoutetteTable(screen, player, combatCursorPos, fonts);
			break;
		}
		SDL_UpdateWindowSurface(screen.gWindow);
	}
	SDL_FreeSurface(screen.gBattleTextBox);		//MEMORY FIX
	screen.gBattleTextBox = NULL;				//MEMORY FIX
	return gameExit;
}

void Casino::moveLeft(int & combatCursorPos, int & shop)
{
	switch (combatCursorPos - 1)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		break;
	case 1:
		combatCursorPos = 1;
		break;
	case 2:
		combatCursorPos = 2;
		break;
	case 3:
		break;
	case 4:
		combatCursorPos = 4;
		break;
	case 5:
		combatCursorPos = 5;
		break;
	}
}

void Casino::moveRight(int & combatCursorPos, int & shop)
{
	switch (combatCursorPos - 1)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		combatCursorPos = 2;
		break;
	case 1:
		combatCursorPos = 3;
		break;
	case 2:
		break;
	case 3:
		combatCursorPos = 5;
		break;
	case 4:
		combatCursorPos = 6;
		break;
	case 5:
		break;
	}

}

void Casino::moveUp(int & combatCursorPos, int & shop)
{
	switch (combatCursorPos - 1)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		combatCursorPos = 1;
		break;
	case 4:
		combatCursorPos = 2;
		break;
	case 5:
		combatCursorPos = 3;
		break;
	}
}

void Casino::moveDown(int & combatCursorPos, int & shop)
{
	switch (combatCursorPos - 1)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		combatCursorPos = 4;
		break;
	case 1:
		combatCursorPos = 5;
		break;
	case 2:
		combatCursorPos = 6;
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
}

