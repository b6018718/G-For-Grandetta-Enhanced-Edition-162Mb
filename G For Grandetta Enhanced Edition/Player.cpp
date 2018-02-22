#pragma once
#include "Player.h"
#include <time.h>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;


Player::Player()
{
	//get the bone from the dog
	quests[0][0] = new questPoint("Find the dog", "in the village");
	quests[0][1] = new questPoint("Defeat the dog", "in battle");
	quests[0][2] = new questPoint("Speak to the king", "in the castle in Castletown");
	quests[0][3] = new questPoint("Speak to the wizard", "in the castle in Castletown");
	//get the sword from the stall
	quests[1][0] = new questPoint("Speak to the king", "in the castle in Castletown");
	quests[1][1] = new questPoint("Buy a sword", "from the market stall in Castletown");
	quests[1][2] = new questPoint("Speak to the wizard", "in the castle in Castletown");
	//get the staff
	quests[2][0] = new questPoint("Go to the camp", "to the right of the field");
	quests[2][1] = new questPoint("Get the staff", "from the Goblin Camp");
	quests[2][2] = new questPoint("Return the staff", "to the wizard in the castle");
	//get the hat
	quests[3][0] = new questPoint("Get the hat", "from the market stall");
	quests[3][1] = new questPoint("Return the hat", "to the wizard in the castle");
	//get the orb
	quests[4][0] = new questPoint("Go to the cave", "to the left of the field");
	quests[4][1] = new questPoint("Get the orb", "from the cave");
	quests[4][2] = new questPoint("Return the orb", "to the wizard in the castle");
	//get the necklace
	quests[5][0] = new questPoint("Break into the castle", "to get the necklace");			//CUT
	quests[5][1] = new questPoint("Get the necklace", "from the Princess' room");			//CUT
	quests[5][2] = new questPoint("Get out of the castle", "to avoid capture");				//CUT
	quests[5][3] = new questPoint("Return the necklace", "to the wizard in the castle");	//CUT
	//fight the wizard
	quests[6][0] = new questPoint("Go to the village", "to find the wizard");
	quests[6][1] = new questPoint("Speak to the wizard", "to save the village");
	quests[6][2] = new questPoint("Fight the wizard", "because he summoned a demon");
	//fight the demon
	quests[7][0] = new questPoint("Fight the demon", "to save the country from destruction");
	//speak to the king / end game
	quests[8][0] = new questPoint("Speak to the king", "in the castle in Castletown");
}


Player::~Player()
{
}

void Player::equipWeapon(Equipment::weapon newWeapon)
{
	phyAttack -= equippedWeapon.weaponPhysDamage;
	magAttack -= equippedWeapon.weaponMagicDamage;
	equippedWeapon = newWeapon;
	phyAttack += equippedWeapon.weaponPhysDamage;
	magAttack += equippedWeapon.weaponMagicDamage;
	hitChance = equippedWeapon.weaponAccuracy;
}

void Player::equipChestPiece(Equipment::chestPiece newChest)
{
	phyDefence -= equippedChestPiece.chestPhysDef;
	magDefence -= equippedChestPiece.chestMagicDef;
	equippedChestPiece = newChest;
	phyDefence += equippedChestPiece.chestPhysDef;
	magDefence += equippedChestPiece.chestMagicDef;
}

void Player::equipHelmet(Equipment::helmet newHelmet)
{
	phyDefence -= equippedHelmet.helmetPhysDef;
	magDefence -= equippedHelmet.helmetMagicDef;
	equippedHelmet = newHelmet;
	phyDefence += equippedHelmet.helmetPhysDef;
	magDefence += equippedHelmet.helmetMagicDef;
}

void Player::equipGauntlet(Equipment::gauntlet newGauntlet)
{
	phyDefence -= equippedGauntlet.gauntletPhysDef;
	magDefence -= equippedGauntlet.gauntletMagicDef;
	equippedGauntlet = newGauntlet;
	phyDefence += equippedGauntlet.gauntletPhysDef;
	magDefence += equippedGauntlet.gauntletMagicDef;
}

void Player::equipBoots(Equipment::boots newBoots)
{
	phyDefence -= equippedBoots.bootsPhysDef;
	magDefence -= equippedBoots.bootsMagicDef;
	equippedBoots = newBoots;
	phyDefence += equippedBoots.bootsPhysDef;
	magDefence += equippedBoots.bootsMagicDef;
}

int Player::getRandomInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Player::initaliseStats(Equipment equipment)
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

	
	effectiveCurrentExp = currentExp;
	effectiveExpLevelUp = expLevelUp;


	if (pClass == "warrior")
	{
		maxHP = 30;
		currentHP = maxHP;
		maxMP = 5;
		currentMP = maxMP;
		phyAttack = 10;//10
		phyDefence = 5;
		magAttack = 3;
		magDefence = 3;
		luck = 1;
	}
	else if (pClass == "mage")
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
	else if (pClass == "rogue")
	{
		maxHP = 25;
		currentHP = maxHP;
		maxMP = 10;
		currentMP = maxMP;
		phyAttack = 9;
		phyDefence = 5;
		magAttack = 4;
		magDefence = 4;
		luck = 3;
	}



	equippedWeapon = equipment.bone;
	equippedChestPiece = equipment.basicChest;
	equippedHelmet = equipment.basicHelmet;
	equippedGauntlet = equipment.basicGauntlet;
	equippedBoots = equipment.basicBoots;

	phyAttack += equippedWeapon.weaponPhysDamage;
	phyDefence += equippedBoots.bootsPhysDef + equippedChestPiece.chestPhysDef + equippedGauntlet.gauntletPhysDef + equippedHelmet.helmetPhysDef;
	magAttack += equippedWeapon.weaponMagicDamage;
	magDefence += equippedBoots.bootsMagicDef + equippedChestPiece.chestMagicDef + equippedGauntlet.gauntletMagicDef + equippedHelmet.helmetMagicDef;
	hitChance = equippedWeapon.weaponAccuracy;

}


/*	Exp Philosophy: See Spreadsheet


	Field Enemy = Avg 15 Exp
	Camp Enemy = Avg 60 Exp
	Cave Enemy = Avg 120 Exp
	Goblin Boss Exp = 210 Exp
	Spider Boss Exp = 540 Exp
	Wizard Boss Exp = 2160 Exp

*/

void Player::levelUp(string& levelUpString1, string& levelUpString2)
{
	if (pClass == "warrior")
	{
		if (level < 16)
		{
			++level;
			expLevelUp = levelExpNeeded[level];
			effectiveExpLevelUp = levelExpNeeded[level] - currentExp;
			effectiveCurrentExp = 0;

			levelUpString1 = "Null";
			levelUpString2 = "Null";
			int randomNum;

			//Warrior HP Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 5) //5% Chance
			{
				//Display Screen TBI
				maxHP = maxHP + 2;
				levelUpString1 = "HP: +2 ";
			}
			else if (randomNum <= 10) //5% Chance
			{
				maxHP = maxHP + 3;
				levelUpString1 = "HP: +3 ";
			}
			else if (randomNum <= 45) //35% Chance
			{
				maxHP = maxHP + 4;
				levelUpString1 = "HP: +4 ";
			}
			else if (randomNum <= 85) //40% Chance
			{
				maxHP = maxHP + 5;
				levelUpString1 = "HP: +5 ";
			}
			else //15% Chance
			{
				maxHP = maxHP + 6;
				levelUpString1 = "HP: +6 ";
			}


			//Warrior MP Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 70) //70% Chance
			{
				maxMP = maxMP + 1;
				levelUpString1 += "MP: +1 ";
			}
			else if (randomNum <= 90) //20% Chance
			{
				maxMP = maxMP + 2;
				levelUpString1 += "MP: +2 ";
			}
			else if (randomNum <= 99) //9% Chance
			{
				maxMP = maxMP + 3;
				levelUpString1 += "MP: +3 ";
			}
			else //1% Chance
			{
				maxMP = maxMP + 4;
				levelUpString1 += "MP: +4 ";
			}


			//Warrior Physical Attack Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 45) //45% Chance
			{
				//Display Screen TBI
				phyAttack = phyAttack + 1;
				levelUpString1 += "phyAtt: +1 ";
			}
			else if (randomNum <= 75) //30% Chance
			{
				phyAttack = phyAttack + 2;
				levelUpString1 += "phyAtt: +2 ";
			}
			else if (randomNum <= 85) //10% Chance
			{
				phyAttack = phyAttack + 3;
				levelUpString1 += "phyAtt: +3 ";
			}
			else if (randomNum <= 95) //10% Chance
			{
				phyAttack = phyAttack + 4;
				levelUpString1 += "phyAtt: +4 ";
			}
			else //5% Chance
			{
				phyAttack = phyAttack + 5;
				levelUpString1 += "phyAtt: +5 ";
			}


			//Warrior Physical Defence Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 80) //80% Chance
			{
				//Display Screen TBI
				phyDefence = phyDefence + 1;
				levelUpString1 += "phyDef: +1 ";
			}
			else if (randomNum <= 75) //15% Chance
			{
				phyDefence = phyDefence + 2;
				levelUpString1 += "phyDef: +2 ";
			}
			else //5% Chance
			{
				phyDefence = phyDefence + 3;
				levelUpString1 += "phyDef: +3 ";
			}


			//Warrior Magic Attack Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 30) //30% Chance
			{
				//Display Screen TBI
				magAttack = magAttack + 0;
				levelUpString2 = "magAtt: +0 ";
			}
			else if (randomNum <= 85) //55% Chance
			{
				magAttack = magAttack + 1;
				levelUpString2 = "magAtt: +1 ";
			}
			else if (randomNum <= 90) //5% Chance
			{
				magAttack = magAttack + 2;
				levelUpString2 = "magAtt: +2 ";
			}
			else if (randomNum <= 95) //5% Chance
			{
				magAttack = magAttack + 3;
				levelUpString2 = "magAtt: +3 ";
			}
			else //5% Chance
			{
				magAttack = magAttack + 4;
				levelUpString2 = "magAtt: +4 ";
			}

			//Warrior Magic Defence Level UP
			randomNum = getRandomInt(1, 100);
			randomNum = randomNum + luck;
			if (randomNum <= 60) //60% Chance
			{
				//Display Screen TBI
				magDefence = magDefence + 0;
				levelUpString2 += "magDef: +0 ";
			}
			else if (randomNum <= 95) //35% Chance
			{
				magDefence = magDefence + 1;
				levelUpString2 += "magAtt: +1 ";
			}
			else //5% Chance
			{
				magDefence = magDefence + 2;
				levelUpString2 += "magAtt: +2 ";
			}


			//Warrior Luck Level UP
			randomNum = getRandomInt(1, 100);
			if (randomNum <= 20) //20% Chance
			{
				//Display Screen TBI
				luck = luck + 0;
				levelUpString2 += "Luck: +0 ";
			}
			else if (randomNum <= 95) //75% Chance
			{
				luck = luck + 1;
				levelUpString2 += "Luck: +1 ";

			}
			else //5% Chance
			{
				luck = luck + 2;
				levelUpString2 += "Luck: +2 ";
			}


		}
		
	}
	else if (pClass == "mage")
	{
		++level;
		expLevelUp = levelExpNeeded[level];
		effectiveExpLevelUp = levelExpNeeded[level] - currentExp;
		effectiveCurrentExp = 0;

		levelUpString1 = "Null";
		levelUpString2 = "Null";
		int randomNum;

		//Mage HP Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 20) //20% Chance
		{
			//Display Screen TBI
			maxHP = maxHP + 1;
			levelUpString1 = "HP: +1 ";
		}
		else if (randomNum <= 60) //40% Chance
		{
			maxHP = maxHP + 2;
			levelUpString1 = "HP: +2 ";
		}
		else if (randomNum <= 80) //20% Chance
		{
			maxHP = maxHP + 3;
			levelUpString1 = "HP: +3 ";
		}
		else if (randomNum <= 90) //10% Chance
		{
			maxHP = maxHP + 4;
			levelUpString1 = "HP: +4 ";
		}
		else //10% Chance
		{
			maxHP = maxHP + 5;
			levelUpString1 = "HP: +5 ";
		}


		//Mage MP Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 30) //30% Chance
		{
			//Display Screen TBI
			maxMP = maxMP + 4;
			levelUpString1 += "MP: +4 ";
		}
		else if (randomNum <= 80) //50% Chance
		{
			maxMP = maxMP + 5;
			levelUpString1 += "MP: +5 ";
		}
		else if (randomNum <= 90) //10% Chance
		{
			maxMP = maxMP + 6;
			levelUpString1 += "MP: +6 ";
		}
		else if (randomNum <= 95) //5% Chance
		{
			maxMP = maxMP + 7;
			levelUpString1 += "MP: +7 ";
		}
		else //5% Chance
		{
			maxMP = maxMP + 8;
			levelUpString1 += "MP: +8 ";
		}


		//Mage Physical Attack Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 30) //30% Chance
		{
			//Display Screen TBI
			phyAttack = phyAttack + 0;
			levelUpString1 += "phyAtt: +0 ";
		}
		else if (randomNum <= 85) //55% Chance
		{
			phyAttack = phyAttack + 1;
			levelUpString1 += "phyAtt: +1 ";
		}
		else if (randomNum <= 90) //5% Chance
		{
			phyAttack = phyAttack + 2;
			levelUpString1 += "phyAtt: +2 ";
		}
		else if (randomNum <= 95) //10% Chance
		{
			phyAttack = phyAttack + 3;
			levelUpString1 += "phyAtt: +3 ";
		}
		else //5% Chance
		{
			phyAttack = phyAttack + 4;
			levelUpString1 += "phyAtt: +4 ";
		}


		//Mage Physical Defence Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 35) //35% Chance
		{
			//Display Screen TBI
			phyDefence = phyDefence + 0;
			levelUpString1 += "phyDef: +0 ";
		}
		else if (randomNum <= 95) //60% Chance
		{
			phyDefence = phyDefence + 1;
			levelUpString1 += "phyDef: +1 ";
		}
		else if (randomNum <= 99) //4% Chance
		{
			phyDefence = phyDefence + 2;
			levelUpString1 += "phyDef: +2 ";
		}
		else //1% Chance
		{
			phyDefence = phyDefence + 3;
			levelUpString1 += "phyDef: +3 ";
		}


		//Mage Magic Attack Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 30) //30% Chance
		{
			//Display Screen TBI
			magAttack = magAttack + 1;
			levelUpString2 = "magAtt: +1 ";
		}
		else if (randomNum <= 75) //45% Chance
		{
			magAttack = magAttack + 2;
			levelUpString2 = "magAtt: +2 ";
		}
		else if (randomNum <= 85) //10% Chance
		{
			magAttack = magAttack + 3;
			levelUpString2 = "magAtt: +3 ";
		}
		else if (randomNum <= 95) //10% Chance
		{
			magAttack = magAttack + 4;
			levelUpString2 = "magAtt: +4 ";
		}
		else //5% Chance
		{
			magAttack = magAttack + 5;
			levelUpString2 = "magAtt: +5 ";
		}

		//Mage Magic Defence Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 35) //35% Chance
		{
			//Display Screen TBI
			magDefence = magDefence + 1;
			levelUpString2 += "magDef: +1 ";
		}
		else if (randomNum <= 95) //60% Chance
		{
			magDefence = magDefence + 2;
			levelUpString2 += "magAtt: +2 ";
		}
		else if (randomNum <= 99) //4% Chance
		{
			magDefence = magDefence + 3;
			levelUpString2 += "magAtt: +3 ";
		}
		else //1% Chance
		{
			magDefence = magDefence + 4;
			levelUpString2 += "magAtt: +4 ";
		}


		//Mage Luck Level UP
		randomNum = getRandomInt(1, 100);
		if (randomNum <= 20) //20% Chance
		{
			//Display Screen TBI
			luck = luck + 0;
			levelUpString2 += "Luck: +0 ";
		}
		else if (randomNum <= 95) //75% Chance
		{
			luck = luck + 1;
			levelUpString2 += "Luck: +1 ";

		}
		else //5% Chance
		{
			luck = luck + 2;
			levelUpString2 += "Luck: +2 ";
		}
	}
	else if (pClass == "rogue")
	{
		++level;
		expLevelUp = levelExpNeeded[level];
		effectiveExpLevelUp = levelExpNeeded[level] - currentExp;
		effectiveCurrentExp = 0;

		levelUpString1 = "Null";
		levelUpString2 = "Null";
		int randomNum;

		//Rogue HP Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 5) //5% Chance
		{
			//Display Screen TBI
			maxHP = maxHP + 1;
			levelUpString1 = "HP: +1 ";
		}
		else if (randomNum <= 25) //20% Chance
		{
			maxHP = maxHP + 2;
			levelUpString1 = "HP: +2 ";
		}
		else if (randomNum <= 60) //35% Chance
		{
			maxHP = maxHP + 3;
			levelUpString1 = "HP: +3 ";
		}
		else if (randomNum <= 90) //30% Chance
		{
			maxHP = maxHP + 4;
			levelUpString1 = "HP: +4 ";
		}
		else //10% Chance
		{
			maxHP = maxHP + 5;
			levelUpString1 = "HP: +5 ";
		}


		//Rogue MP Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 10) //10% Chance
		{
			//Display Screen TBI
			maxMP = maxMP + 1;
			levelUpString1 += "MP: +1 ";
		}
		else if (randomNum <= 60) //50% Chance
		{
			maxMP = maxMP + 2;
			levelUpString1 += "MP: +2 ";
		}
		else if (randomNum <= 80) //20% Chance
		{
			maxMP = maxMP + 3;
			levelUpString1 += "MP: +3 ";
		}
		else if (randomNum <= 95) //15% Chance
		{
			maxMP = maxMP + 4;
			levelUpString1 += "MP: +4 ";
		}
		else //5% Chance
		{
			maxMP = maxMP + 5;
			levelUpString1 += "MP: +5 ";
		}


		//Rogue Physical Attack Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 10) //10% Chance
		{
			//Display Screen TBI
			phyAttack = phyAttack + 0;
			levelUpString1 += "phyAtt: +0 ";
		}
		else if (randomNum <= 60) //50% Chance
		{
			phyAttack = phyAttack + 1;
			levelUpString1 += "phyAtt: +1 ";
		}
		else if (randomNum <= 85) //25% Chance
		{
			phyAttack = phyAttack + 2;
			levelUpString1 += "phyAtt: +2 ";
		}
		else if (randomNum <= 95) //10% Chance
		{
			phyAttack = phyAttack + 3;
			levelUpString1 += "phyAtt: +3 ";
		}
		else //5% Chance
		{
			phyAttack = phyAttack + 4;
			levelUpString1 += "phyAtt: +4 ";
		}


		//Rogue Physical Defence Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 25) //25% Chance
		{
			//Display Screen TBI
			phyDefence = phyDefence + 0;
			levelUpString1 += "phyDef: +0 ";
		}
		else if (randomNum <= 95) //70% Chance
		{
			phyDefence = phyDefence + 1;
			levelUpString1 += "phyDef: +1 ";
		}
		else if (randomNum <= 99) //4% Chance
		{
			phyDefence = phyDefence + 2;
			levelUpString1 += "phyDef: +2 ";
		}
		else //1% Chance
		{
			phyDefence = phyDefence + 3;
			levelUpString1 += "phyDef: +3 ";
		}


		//Rogue Magic Attack Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 10) //10% Chance
		{
			//Display Screen TBI
			magAttack = magAttack + 0;
			levelUpString2 = "magAtt: +0 ";
		}
		else if (randomNum <= 60) //50% Chance
		{
			magAttack = magAttack + 1;
			levelUpString2 = "magAtt: +1 ";
		}
		else if (randomNum <= 85) //25% Chance
		{
			magAttack = magAttack + 2;
			levelUpString2 = "magAtt: +2 ";
		}
		else if (randomNum <= 95) //10% Chance
		{
			magAttack = magAttack + 3;
			levelUpString2 = "magAtt: +3 ";
		}
		else //5% Chance
		{
			magAttack = magAttack + 5;
			levelUpString2 = "magAtt: +5 ";
		}

		//Rogue Magic Defence Level UP
		randomNum = getRandomInt(1, 100);
		randomNum = randomNum + luck;
		if (randomNum <= 25) //25% Chance
		{
			//Display Screen TBI
			magDefence = magDefence + 0;
			levelUpString2 += "magDef: +0 ";
		}
		else if (randomNum <= 95) //70% Chance
		{
			magDefence = magDefence + 1;
			levelUpString2 += "magAtt: +1 ";
		}
		else if (randomNum <= 99) //4% Chance
		{
			magDefence = magDefence + 2;
			levelUpString2 += "magAtt: +2 ";
		}
		else //1% Chance
		{
			magDefence = magDefence + 3;
			levelUpString2 += "magAtt: +3 ";
		}


		//Rogue Luck Level UP
		randomNum = getRandomInt(1, 100);
		if (randomNum <= 25) //25% Chance
		{
			//Display Screen TBI
			luck = luck + 1;
			levelUpString2 += "Luck: +0 ";
		}
		else //75% Chance
		{
			luck = luck + 2;
			levelUpString2 += "Luck: +2 ";

		}
	}
	else 
	{
		cout << "Class not found";
	}
	
}



void Player::incrementQuest()
{
	if (quests[currentQuest][currentQuestPoint + 1] == NULL)
	{
		++currentQuest;
		currentQuestPoint = 0;
	}
	else
		++currentQuestPoint;
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

int Player::magicFlameSlash()
{
	int magicCost = 2;//anount of magic required to cast the spell
	int magicDamage = 15;
	int attackStrength = floor((magAttack + phyAttack) / 2) + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicSheerWill()
{
	int magicCost = 4;//anount of magic required to cast the spell
	int healPower = 30 + floor((magAttack / 2));//amount magic heals the player
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		healPower = 0;
		
	}
	return healPower;
}

void Player::magicBulkUp()
{
	int magicCost = 6;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
		if (ironPotionEffect == 1) {
			ironPotionEffect = 2;
		}
		else if (ironPotionEffect <= 2) {
			ironPotionEffect = 4;
		}
		if (berserkPotionEffect <= 1) {
			berserkPotionEffect = 2;
		}
		else if (berserkPotionEffect == 2) {
			berserkPotionEffect = 4;
		}
	}
	else {
		
	}
	
}

int Player::magicTornadoSlash()
{
	int magicCost = 6;  //anount of magic required to cast the spell
	int magicDamage = 50;
	int attackStrength = floor((magAttack + phyAttack) / 2) + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicNovaSlash()
{
	int magicCost = 10;//anount of magic required to cast the spell
	int magicDamage = 200;
	int attackStrength = floor((magAttack + phyAttack) / 2) + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicFire()
{
	int magicCost = 2;	//anount of magic required to cast the spell
	int magicDamage = 15;
	int attackStrength = magAttack + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicHeal()
{
	int magicCost = 4;//anount of magic required to cast the spell
	int healPower = 15 + floor((magAttack / 2));//amount magic heals the player
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
		if (berserkPotionEffect < 1) {
			berserkPotionEffect = 1;
			//setMessage("Your heal spell also cures", "your lowered attack stat!");
		}
		if (ironPotionEffect < 1) {
			ironPotionEffect = 1;
			
			//setMessage("Your heal spell also cures", "your lowered defence stat!");
		}
	}
	else {
		healPower = 0;
		
	}

	return healPower;
}

int Player::magicThunder()
{
	int magicCost = 6;  //anount of magic required to cast the spell
	int magicDamage = 50;
	int attackStrength = magAttack + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicDrainHealth()
{
	int magicCost = 8;//anount of magic required to cast the spell
	int magicDamage = 30;
	int attackStrength = magAttack + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
		currentHP = currentHP + calculatedamageHealed(floor(attackStrength / 2 * berserkPotionEffect));
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicNova()
{
	int magicCost = 10;//anount of magic required to cast the spell
	int magicDamage = 200;
	int attackStrength = magAttack + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicSteal(bool& stealing)
{
	int attackStrength = floor((phyAttack) / 2);
	int magicCost = 2;//anount of magic required to cast the spell
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
		if (luck + getRandomInt(1, 50) > 25 || firstFail == false) {
			firstFail = true;
			stealing = true;
		}
		else {
			attackStrength = 0;
			stealing = false;
		}
	}
	return attackStrength;
}

int Player::magicLifeSteal()
{
	int magicCost = 4;//amount of magic required to cast the spell
	int magicDamage = 15;
	int attackStrength = floor((magAttack + phyAttack)/2) + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicCashNGrab()
{
	int magicCost = 6;  //amount of magic required to cast the spell
	int magicDamage = 25;
	int attackStrength = magAttack + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicBackstab()
{
	int magicCost = 8;  //anount of magic required to cast the spell
	int magicDamage = 50;
	int attackStrength = floor((phyAttack + luck)*1.2) + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::magicNovaBlitz()
{
	int magicCost = 10;  //anount of magic required to cast the spell
	int magicDamage = 200;
	int attackStrength = floor((magAttack + phyAttack) / 2) + luck + magicDamage;
	if (currentMP >= magicCost) {
		currentMP = currentMP - magicCost;
	}
	else {
		attackStrength = 0;
		
	}
	return attackStrength;
}

int Player::calculatedamageHealed(int heal)
{
	int damageHealed = heal;
	if ((heal + currentHP) > maxHP) {
		damageHealed = maxHP - currentHP;
	}
	return damageHealed;
}

int Player::itemHealthPotion()
{
	int healPower = 50;
	inventory[1] = inventory[1] - 1;
	if (ironPotionEffect < 1)
		ironPotionEffect = 1;
	if (berserkPotionEffect < 1)
		berserkPotionEffect = 1;

	return healPower;
}

int Player::itemMagicPotion()
{
	int healPower = 30;
	inventory[2] --;
	return healPower;
}

void Player::itemSmokeBomb()
{
	smokeBombEffect = 0.5;
	inventory[3] --;
}

void Player::itemIronSkinPotion()
{
	if (ironPotionEffect <= 1) {
		ironPotionEffect = 2;
		inventory[4] --;
	}
	else if (ironPotionEffect == 2) {
		ironPotionEffect = 4;
		inventory[4] --;
	}
}

void Player::itemBerserkPotion()
{
	if (berserkPotionEffect <= 1) {
		berserkPotionEffect = 2;
		inventory[5] --;
	}
	else if (berserkPotionEffect == 2) {
		berserkPotionEffect = 4;
		inventory[5] --;
	}
}

int Player::playerNormalAttack(bool& crit)
{
	int attackStrength = phyAttack;
	if (getRandomInt(1 + luck, 50) > 40) {
		//setMessage("Critical Hit!", "Your attack deals extra damage!");
		crit = true;
		attackStrength = attackStrength * 2;
	}
	else
		crit = false;
	attackStrength -= 1;
	attackStrength = attackStrength + getRandomInt(1, 2);
	return attackStrength;
}