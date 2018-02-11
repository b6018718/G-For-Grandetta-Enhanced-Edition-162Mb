#include "Player.h"
#include <time.h>
#include <cstdlib>

#include <string>

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


/*	Exp Philosophy; See Spreadsheet


	Field Enemy = Avg 15 Exp
	Camp Enemy = Avg 60 Exp
	Cave Enemy = Avg 120 Exp
	Goblin Boss Exp = 210 Exp
	Spider Boss Exp = 540 Exp
	Wizard Boss Exp = 2160 Exp

*/

void Player::levelUp(Screen screen)
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
			if (randomNum <= 30) //30% Chance
			{
				//Display Screen TBI
				maxMP = maxMP + 0;
				levelUpString += "MP: +0 ";
			}
			else if (randomNum <= 70) //40% Chance
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

	}
	else if (pClass == "Rogue")
	{

	}
}
