#pragma once
#include "Player.h"
#include <time.h>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;


Player::Player()
{
}


Player::~Player()
{
}

int Player::getRandomInt(int min, int max)
{
	return rand() % max + min;
}

void Player::initaliseStats()
{
	level = 1;
	expLevelUp = 10;
	currentExp = 0;
	gold = 0;
	currentMap = 0;
	x = 28 * 32;
	y = 1 * 32;
	name = "Steven";
	int spriteFrame = 0;

	equippedWeapon = "bone";
	equippedChestPiece = "basic";
	equippedHelmet = "basic";
	equippedGaunlet = "basic";
	equippedBoots = "basic";
	effectiveCurrentExp = currentExp;
	effectiveExpLevelUp = expLevelUp;


	if (pClass == "Warrior")
	{
		maxHP = 30;
		currentHP = maxHP;
		maxMP = 5;
		currentMP = maxMP;
		phyAttack = 10;
		phyDefence = 5;
		magAttack = 3;
		magDefence = 3;
		luck = 1;
	}
	else if (pClass == "Mage")
	{
		maxHP = 20;
		currentHP = maxHP;
		maxMP = 15;
		currentMP = maxMP;
		phyAttack = 8;
		phyDefence = 3;
		magAttack = 6;
		magDefence = 6;
		luck = 1;
	}
	else if (pClass == "Rogue")
	{
		maxHP = 25;
		currentHP = maxHP;
		maxMP = 10;
		currentMP = maxMP;
		phyAttack = 9;
		phyDefence = 4;
		magAttack = 4;
		magDefence = 4;
		luck = 3;
	}

}


/*	Exp Philosophy: See Spreadsheet


	Field Enemy = Avg 15 Exp
	Camp Enemy = Avg 60 Exp
	Cave Enemy = Avg 120 Exp
	Goblin Boss Exp = 210 Exp
	Spider Boss Exp = 540 Exp
	Wizard Boss Exp = 2160 Exp

*/

void Player::levelUp()
{
	if (pClass == "Warrior")
	{
		if (level < 16)
		{
			++level;
			expLevelUp = levelExpNeeded[level];
			effectiveExpLevelUp = levelExpNeeded[level] - currentExp;
			effectiveCurrentExp = 0;

			levelUpString = "Null";
			int randomNum;

			//Warrior HP Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 5) //5% Chance
			{
				//Display Screen TBI
				maxHP = maxHP + 2;
				levelUpString = "HP: +2 ";
			}
			else if (randomNum <= 10) //5% Chance
			{
				maxHP = maxHP + 3;
				levelUpString = "HP: +3 ";
			}
			else if (randomNum <= 45) //35% Chance
			{
				maxHP = maxHP + 4;
				levelUpString = "HP: +4 ";
			}
			else if (randomNum <= 85) //40% Chance
			{
				maxHP = maxHP + 5;
				levelUpString = "HP: +5 ";
			}
			else //15% Chance
			{
				maxHP = maxHP + 6;
				levelUpString = "HP: +6 ";
			}


			//Warrior MP Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 70) //70% Chance
			{
				maxMP = maxMP + 1;
				levelUpString += "MP: +1 ";
			}
			else if (randomNum <= 90) //20% Chance
			{
				maxMP = maxMP + 2;
				levelUpString += "MP: +2 ";
			}
			else if (randomNum <= 99) //9% Chance
			{
				maxMP = maxMP + 3;
				levelUpString += "MP: +3 ";
			}
			else //1% Chance
			{
				maxMP = maxMP + 4;
				levelUpString += "MP: +4 ";
			}


			//Warrior Physical Attack Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 45) //45% Chance
			{
				//Display Screen TBI
				phyAttack = phyAttack + 1;
				levelUpString += "phyAtt: +1 ";
			}
			else if (randomNum <= 75) //30% Chance
			{
				phyAttack = phyAttack + 2;
				levelUpString += "phyAtt: +2 ";
			}
			else if (randomNum <= 85) //10% Chance
			{
				phyAttack = phyAttack + 3;
				levelUpString += "phyAtt: +3 ";
			}
			else if (randomNum <= 95) //10% Chance
			{
				phyAttack = phyAttack + 4;
				levelUpString += "phyAtt: +4 ";
			}
			else //5% Chance
			{
				phyAttack = phyAttack + 5;
				levelUpString += "phyAtt: +5 ";
			}


			//Warrior Physical Defence Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 80) //80% Chance
			{
				//Display Screen TBI
				phyDefence = phyDefence + 1;
				levelUpString += "phyDef: +1 ";
			}
			else if (randomNum <= 75) //15% Chance
			{
				phyDefence = phyDefence + 2;
				levelUpString += "phyDef: +2 ";
			}
			else //5% Chance
			{
				phyDefence = phyDefence + 3;
				levelUpString += "phyDef: +3 ";
			}


			//Warrior Magic Attack Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 30) //30% Chance
			{
				//Display Screen TBI
				magAttack = magAttack + 0;
				levelUpString += "magAtt: +0 ";
			}
			else if (randomNum <= 85) //55% Chance
			{
				magAttack = magAttack + 1;
				levelUpString += "magAtt: +1 ";
			}
			else if (randomNum <= 90) //5% Chance
			{
				magAttack = magAttack + 2;
				levelUpString += "magAtt: +2 ";
			}
			else if (randomNum <= 95) //5% Chance
			{
				magAttack = magAttack + 3;
				levelUpString += "magAtt: +3 ";
			}
			else //5% Chance
			{
				magAttack = magAttack + 4;
				levelUpString += "magAtt: +4 ";
			}

			//Warrior Magic Defence Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 60) //60% Chance
			{
				//Display Screen TBI
				magDefence = magDefence + 0;
				levelUpString += "magDef: +0 ";
			}
			else if (randomNum <= 95) //35% Chance
			{
				magDefence = magDefence + 1;
				levelUpString += "magAtt: +1 ";
			}
			else //5% Chance
			{
				magDefence = magDefence + 2;
				levelUpString += "magAtt: +2 ";
			}


			//Warrior Luck Level UP
			randomNum = getRandomInt(1, 100);
			if (randomNum <= 20) //20% Chance
			{
				//Display Screen TBI
				luck = luck + 0;
				levelUpString += "Luck: +0 ";
			}
			else if (randomNum <= 95) //75% Chance
			{
				luck = luck + 1;
				levelUpString += "Luck: +1 ";

			}
			else //5% Chance
			{
				luck = luck + 2;
				levelUpString += "Luck: +2 ";
			}


		}
		
	}
	else if (pClass == "Mage")
	{
		++level;
		expLevelUp = levelExpNeeded[level];
		effectiveExpLevelUp = levelExpNeeded[level] - currentExp;
		effectiveCurrentExp = 0;

		levelUpString = "Null";
		int randomNum;

		//Mage HP Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 20) //20% Chance
		{
			//Display Screen TBI
			maxHP = maxHP + 1;
			levelUpString = "HP: +1 ";
		}
		else if (randomNum <= 60) //40% Chance
		{
			maxHP = maxHP + 2;
			levelUpString = "HP: +2 ";
		}
		else if (randomNum <= 80) //20% Chance
		{
			maxHP = maxHP + 3;
			levelUpString = "HP: +3 ";
		}
		else if (randomNum <= 90) //10% Chance
		{
			maxHP = maxHP + 4;
			levelUpString = "HP: +4 ";
		}
		else //10% Chance
		{
			maxHP = maxHP + 5;
			levelUpString = "HP: +5 ";
		}


		//Mage MP Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 30) //30% Chance
		{
			//Display Screen TBI
			maxMP = maxMP + 4;
			levelUpString += "MP: +4 ";
		}
		else if (randomNum <= 80) //50% Chance
		{
			maxMP = maxMP + 5;
			levelUpString += "MP: +5 ";
		}
		else if (randomNum <= 90) //10% Chance
		{
			maxMP = maxMP + 6;
			levelUpString += "MP: +6 ";
		}
		else if (randomNum <= 95) //5% Chance
		{
			maxMP = maxMP + 7;
			levelUpString += "MP: +7 ";
		}
		else //5% Chance
		{
			maxMP = maxMP + 8;
			levelUpString += "MP: +8 ";
		}


		//Mage Physical Attack Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 30) //30% Chance
		{
			//Display Screen TBI
			phyAttack = phyAttack + 0;
			levelUpString += "phyAtt: +0 ";
		}
		else if (randomNum <= 85) //55% Chance
		{
			phyAttack = phyAttack + 1;
			levelUpString += "phyAtt: +1 ";
		}
		else if (randomNum <= 90) //5% Chance
		{
			phyAttack = phyAttack + 2;
			levelUpString += "phyAtt: +2 ";
		}
		else if (randomNum <= 95) //10% Chance
		{
			phyAttack = phyAttack + 3;
			levelUpString += "phyAtt: +3 ";
		}
		else //5% Chance
		{
			phyAttack = phyAttack + 4;
			levelUpString += "phyAtt: +4 ";
		}


		//Mage Physical Defence Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 35) //35% Chance
		{
			//Display Screen TBI
			phyDefence = phyDefence + 0;
			levelUpString += "phyDef: +0 ";
		}
		else if (randomNum <= 95) //60% Chance
		{
			phyDefence = phyDefence + 1;
			levelUpString += "phyDef: +1 ";
		}
		else if (randomNum <= 99) //4% Chance
		{
			phyDefence = phyDefence + 2;
			levelUpString += "phyDef: +2 ";
		}
		else //1% Chance
		{
			phyDefence = phyDefence + 3;
			levelUpString += "phyDef: +3 ";
		}


		//Mage Magic Attack Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 30) //30% Chance
		{
			//Display Screen TBI
			magAttack = magAttack + 1;
			levelUpString += "magAtt: +1 ";
		}
		else if (randomNum <= 75) //45% Chance
		{
			magAttack = magAttack + 2;
			levelUpString += "magAtt: +2 ";
		}
		else if (randomNum <= 85) //10% Chance
		{
			magAttack = magAttack + 3;
			levelUpString += "magAtt: +3 ";
		}
		else if (randomNum <= 95) //10% Chance
		{
			magAttack = magAttack + 4;
			levelUpString += "magAtt: +4 ";
		}
		else //5% Chance
		{
			magAttack = magAttack + 5;
			levelUpString += "magAtt: +5 ";
		}

		//Mage Magic Defence Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 35) //35% Chance
		{
			//Display Screen TBI
			magDefence = magDefence + 1;
			levelUpString += "magDef: +1 ";
		}
		else if (randomNum <= 95) //60% Chance
		{
			magDefence = magDefence + 2;
			levelUpString += "magAtt: +2 ";
		}
		else if (randomNum <= 99) //4% Chance
		{
			magDefence = magDefence + 3;
			levelUpString += "magAtt: +3 ";
		}
		else //1% Chance
		{
			magDefence = magDefence + 4;
			levelUpString += "magAtt: +4 ";
		}


		//Mage Luck Level UP
		randomNum = getRandomInt(1, 100);
		if (randomNum <= 20) //20% Chance
		{
			//Display Screen TBI
			luck = luck + 0;
			levelUpString += "Luck: +0 ";
		}
		else if (randomNum <= 95) //75% Chance
		{
			luck = luck + 1;
			levelUpString += "Luck: +1 ";

		}
		else //5% Chance
		{
			luck = luck + 2;
			levelUpString += "Luck: +2 ";
		}
	}
	else if (pClass == "Rogue")
	{
		++level;
		expLevelUp = levelExpNeeded[level];
		effectiveExpLevelUp = levelExpNeeded[level] - currentExp;
		effectiveCurrentExp = 0;

		levelUpString = "Null";
		int randomNum;

		//Rogue HP Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 5) //5% Chance
		{
			//Display Screen TBI
			maxHP = maxHP + 1;
			levelUpString = "HP: +1 ";
		}
		else if (randomNum <= 25) //20% Chance
		{
			maxHP = maxHP + 2;
			levelUpString = "HP: +2 ";
		}
		else if (randomNum <= 60) //35% Chance
		{
			maxHP = maxHP + 3;
			levelUpString = "HP: +3 ";
		}
		else if (randomNum <= 90) //30% Chance
		{
			maxHP = maxHP + 4;
			levelUpString = "HP: +4 ";
		}
		else //10% Chance
		{
			maxHP = maxHP + 5;
			levelUpString = "HP: +5 ";
		}


		//Rogue MP Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 10) //10% Chance
		{
			//Display Screen TBI
			maxMP = maxMP + 1;
			levelUpString += "MP: +1 ";
		}
		else if (randomNum <= 60) //50% Chance
		{
			maxMP = maxMP + 2;
			levelUpString += "MP: +2 ";
		}
		else if (randomNum <= 80) //20% Chance
		{
			maxMP = maxMP + 3;
			levelUpString += "MP: +3 ";
		}
		else if (randomNum <= 95) //15% Chance
		{
			maxMP = maxMP + 4;
			levelUpString += "MP: +4 ";
		}
		else //5% Chance
		{
			maxMP = maxMP + 5;
			levelUpString += "MP: +5 ";
		}


		//Rogue Physical Attack Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 10) //10% Chance
		{
			//Display Screen TBI
			phyAttack = phyAttack + 0;
			levelUpString += "phyAtt: +0 ";
		}
		else if (randomNum <= 60) //50% Chance
		{
			phyAttack = phyAttack + 1;
			levelUpString += "phyAtt: +1 ";
		}
		else if (randomNum <= 85) //25% Chance
		{
			phyAttack = phyAttack + 2;
			levelUpString += "phyAtt: +2 ";
		}
		else if (randomNum <= 95) //10% Chance
		{
			phyAttack = phyAttack + 3;
			levelUpString += "phyAtt: +3 ";
		}
		else //5% Chance
		{
			phyAttack = phyAttack + 4;
			levelUpString += "phyAtt: +4 ";
		}


		//Rogue Physical Defence Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 25) //25% Chance
		{
			//Display Screen TBI
			phyDefence = phyDefence + 0;
			levelUpString += "phyDef: +0 ";
		}
		else if (randomNum <= 95) //70% Chance
		{
			phyDefence = phyDefence + 1;
			levelUpString += "phyDef: +1 ";
		}
		else if (randomNum <= 99) //4% Chance
		{
			phyDefence = phyDefence + 2;
			levelUpString += "phyDef: +2 ";
		}
		else //1% Chance
		{
			phyDefence = phyDefence + 3;
			levelUpString += "phyDef: +3 ";
		}


		//Rogue Magic Attack Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 10) //10% Chance
		{
			//Display Screen TBI
			magAttack = magAttack + 0;
			levelUpString += "magAtt: +0 ";
		}
		else if (randomNum <= 60) //50% Chance
		{
			magAttack = magAttack + 1;
			levelUpString += "magAtt: +1 ";
		}
		else if (randomNum <= 85) //25% Chance
		{
			magAttack = magAttack + 2;
			levelUpString += "magAtt: +2 ";
		}
		else if (randomNum <= 95) //10% Chance
		{
			magAttack = magAttack + 3;
			levelUpString += "magAtt: +3 ";
		}
		else //5% Chance
		{
			magAttack = magAttack + 5;
			levelUpString += "magAtt: +5 ";
		}

		//Rogue Magic Defence Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 25) //25% Chance
		{
			//Display Screen TBI
			magDefence = magDefence + 0;
			levelUpString += "magDef: +0 ";
		}
		else if (randomNum <= 95) //70% Chance
		{
			magDefence = magDefence + 1;
			levelUpString += "magAtt: +1 ";
		}
		else if (randomNum <= 99) //4% Chance
		{
			magDefence = magDefence + 2;
			levelUpString += "magAtt: +2 ";
		}
		else //1% Chance
		{
			magDefence = magDefence + 3;
			levelUpString += "magAtt: +3 ";
		}


		//Rogue Luck Level UP
		randomNum = getRandomInt(1, 100);
		if (randomNum <= 25) //25% Chance
		{
			//Display Screen TBI
			luck = luck + 1;
			levelUpString += "Luck: +0 ";
		}
		else //75% Chance
		{
			luck = luck + 2;
			levelUpString += "Luck: +2 ";

		}
	}
	else 
	{
		cout << "Class not found";
	}
}

void Player::playerGainsExp(int exp)
{
	currentExp = currentExp + exp;
	effectiveCurrentExp = effectiveCurrentExp + exp;
	while ((currentExp >= expLevelUp) && (level < 16))
	{
		levelUp();
	}
}

void Player::moveLeft(Maps maps)
{
	float canXC = (float)(SCREEN_WIDTH - spriteSizeX) / 2;	//Can X Camera, If there is room left for the map to move
	float canYC = (float)(SCREEN_HEIGHT - spriteSizeY) / 2;	//Can Y Camera

	spriteFrame++;

	facing.up = false;
	facing.down = false;
	facing.left = true;
	facing.right = false;

	dir.up = false;
	dir.down = false;
	dir.left = true;
	dir.right = false;

	bool collision = false;

	for (int i = 0; i < maps.zone[currentMap].collisions.size(); i++) 
	{
		if (map.x == maps.zone[currentMap].collisions[i].x + maps.zone[currentMap].collisions[i].xDim)	//If player is touching x collision
		{
			if (map.y < maps.zone[currentMap].collisions[i].y + maps.zone[currentMap].collisions[i].yDim) //If player is above bottom y of collision
			{
				if (spriteSizeY + map.y > maps.zone[currentMap].collisions[i].y) //If player is below the top y of collision
				{
					collision = true;
					//cout << maps.zone[currentMap].collisions[i].name << "\n";
				}
			}
		}
	}

	if (!collision) 
	{
		if (x > canXC) 
		{
			x -= playerSpeed;
			map.x -= playerSpeed;
		}
		else if (map.x > canXC) 
		{
			map.x -= playerSpeed;
		}
		else if (map.x <= canXC && x > 0) 
		{
			x -= playerSpeed;
			map.x -= playerSpeed;
		}
		else 
		{
			dir.left = false;
		}
			
	}

	
}

void Player::moveRight(Maps maps)
{
	float canXC = (float)(SCREEN_WIDTH - spriteSizeX) / 2;	//Can X Camera, If there is room left for the map to move
	float canYC = (float)(SCREEN_HEIGHT - spriteSizeY) / 2;	//Can Y Camera

	spriteFrame++;

	facing.up = false;
	facing.down = false;
	facing.left = false;
	facing.right = true;

	dir.up = false;
	dir.down = false;
	dir.left = false;
	dir.right = true;

	bool collision = false;

	for (int i = 0; i < maps.zone[currentMap].collisions.size(); i++)
	{
		if (map.x + spriteSizeX == maps.zone[currentMap].collisions[i].x)	//If player is touching x collision
		{
			if (map.y < maps.zone[currentMap].collisions[i].y + maps.zone[currentMap].collisions[i].yDim) //If player is above bottom y of collision
			{
				if (spriteSizeY + map.y > maps.zone[currentMap].collisions[i].y) //If player is below the top y of collision
				{
					collision = true;
					//cout << maps.zone[currentMap].collisions[i].name << "\n";
				}
			}
		}
	}

	if (!collision)
	{
		if (x < canXC)
		{
			x += playerSpeed;	//Far Left
			map.x += playerSpeed;
		}
		else if (map.x < maps.zone[currentMap].xDim - (SCREEN_WIDTH / 2) - (spriteSizeX / 2))
		{
			map.x += playerSpeed;	//Middle
		}
		else if (map.x >= (maps.zone[currentMap].xDim - (SCREEN_WIDTH / 2) - (spriteSizeX / 2)) && x < (SCREEN_WIDTH - spriteSizeX))
		{
			x += playerSpeed;	//Far Right
			map.x += playerSpeed;
		}
		else
		{
			dir.right = false;
		}

	}

	
}

void Player::moveUp(Maps maps)
{
	float canXC = (float)(SCREEN_WIDTH - spriteSizeX) / 2;	//Can X Camera, If there is room left for the map to move
	float canYC = (float)(SCREEN_HEIGHT - spriteSizeY) / 2;	//Can Y Camera

	spriteFrame++;

	facing.up = true;
	facing.down = false;
	facing.left = false;
	facing.right = false;

	dir.up = true;
	dir.down = false;
	dir.left = false;
	dir.right = false;

	bool collision = false;

	for (int i = 0; i < maps.zone[currentMap].collisions.size(); i++)
	{
		if (map.y == maps.zone[currentMap].collisions[i].y + maps.zone[currentMap].collisions[i].yDim)	//If player is touching x collision
		{
			if (map.x < maps.zone[currentMap].collisions[i].x + maps.zone[currentMap].collisions[i].xDim) //If player is above bottom y of collision
			{
				if (map.x + spriteSizeX > maps.zone[currentMap].collisions[i].x) //If player is below the top y of collision
				{
					collision = true;
					//cout << maps.zone[currentMap].collisions[i].name << "\n";
				}
			}
		}
	}

	if (!collision)
	{
		if (y > canYC)
		{
			y -= playerSpeed;
			map.y -= playerSpeed;
		}
		else if (map.y > canYC)
		{
			map.y -= playerSpeed;
		}
		else if (map.y <= canYC && y > 0)
		{
			y -= playerSpeed;
			map.y -= playerSpeed;
		}
		else
		{
			dir.up = false;
		}

	}

}

void Player::moveDown(Maps maps)
{
	float canXC = (float)(SCREEN_WIDTH - spriteSizeX) / 2;	//Can X Camera, If there is room left for the map to move
	float canYC = (float)(SCREEN_HEIGHT - spriteSizeY) / 2;	//Can Y Camera

	spriteFrame++;

	facing.up = false;
	facing.down = true;
	facing.left = false;
	facing.right = false;

	dir.up = false;
	dir.down = true;
	dir.left = false;
	dir.right = false;

	bool collision = false;

	for (int i = 0; i < maps.zone[currentMap].collisions.size(); i++)
	{
		if (map.y + spriteSizeY == maps.zone[currentMap].collisions[i].y)	//If player is touching x collision
		{
			if (map.x < maps.zone[currentMap].collisions[i].x + maps.zone[currentMap].collisions[i].xDim) //If player is above bottom y of collision
			{
				if (map.x + spriteSizeX > maps.zone[currentMap].collisions[i].x) //If player is below the top y of collision
				{
					collision = true;
					//cout << maps.zone[currentMap].collisions[i].name << "\n";
				}
			}
		}
	}

	if (!collision)
	{
		if (y < canYC)
		{
			y += playerSpeed;
			map.y += playerSpeed;
		}
		else if (map.y < maps.zone[currentMap].yDim - (SCREEN_WIDTH / 2) - (spriteSizeY / 2))
		{
			map.y += playerSpeed;
		}
		else if (map.y >= maps.zone[currentMap].yDim - (SCREEN_WIDTH / 2) - (spriteSizeY / 2) && y < (SCREEN_HEIGHT - spriteSizeY))
		{
			y += playerSpeed;
			map.y += playerSpeed;
		}
		else
		{
			dir.down = false;
		}

	}
	

}
