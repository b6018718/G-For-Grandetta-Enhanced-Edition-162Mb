#include "Mobs.h"
#include <time.h>



struct mob
{
	string enemyName;
	int maxHP;
	int physicalAttack;
	int magicalAttack;
	int physicalDefence;
	int magicDefence;
	int expDrop;
	int itemDrop;
	int AI;
	string imgSrc;
	int goldDrop;
	bool boss = false;


};

Mobs::Mobs()
{
	
		//Rat
		mobRat.enemyName = "Rat";
		mobRat.maxHP = 15;
		mobRat.physicalAttack = 15;
		mobRat.magicalAttack = 5;
		mobRat.physicalDefence = 15;
		mobRat.magicDefence = 3;
		mobRat.expDrop = 15;
		mobRat.itemDrop = 1;
		mobRat.AI = 1;
		mobRat.imgSrc = "images/rat.bmp";
		mobRat.goldDrop = 30;

		//Bat
		mobBat.enemyName=  "Bat";
		mobBat.maxHP = 11;
		mobBat.physicalAttack = 15;
		mobBat.magicalAttack = 0;
		mobBat.physicalDefence = 11;
		mobBat.magicDefence = 3;
		mobBat.expDrop = 16;
		mobBat.itemDrop = 1;
		mobBat.AI = 1;
		mobBat.imgSrc = "images/bat.bmp";
		mobBat.goldDrop = 35;

		//Goblin
		mobGoblin.enemyName= "Goblin";
		mobGoblin.maxHP = 60;
		mobGoblin.physicalAttack = 35;
		mobGoblin.magicalAttack = 5;
		mobGoblin.physicalDefence = 50;
		mobGoblin.magicDefence = 21;
		mobGoblin.expDrop = 50;
		mobGoblin.itemDrop = 3;
		mobGoblin.AI = 7;
		mobGoblin.imgSrc = "images/goblin.bmp";
		mobGoblin.goldDrop = 200;

		//Goblin Mage
		mobGoblinMage.enemyName= "Goblin Mage";
		mobGoblinMage.maxHP= 40;
		mobGoblinMage.physicalAttack= 9;
		mobGoblinMage.magicalAttack= 30;
		mobGoblinMage.physicalDefence= 25;
		mobGoblinMage.magicDefence= 50;
		mobGoblinMage.expDrop= 70;
		mobGoblinMage.itemDrop= 2;
		mobGoblinMage.AI=3;
		mobGoblinMage.imgSrc="images/goblinmage.bmp";
		mobGoblinMage.goldDrop = 250;

		//Goblin Younglings
		mobYoungGoblin.enemyName = "Goblin Younglings";
		mobYoungGoblin.maxHP = 10;
		mobYoungGoblin.physicalAttack = 5;
		mobYoungGoblin.magicalAttack = 5;
		mobYoungGoblin.physicalDefence = 5;
		mobYoungGoblin.magicDefence = 5;
		mobYoungGoblin.expDrop = -100;
		mobYoungGoblin.itemDrop = 2;
		mobYoungGoblin.AI = 8;
		mobYoungGoblin.imgSrc = "images/younglings.bmp";
		mobYoungGoblin.goldDrop = 10;

		//Spider
		mobSpider.enemyName = "Spider";
		mobSpider.maxHP = 40;
		mobSpider.physicalAttack = 40;
		mobSpider.magicalAttack = 5;
		mobSpider.physicalDefence = 30;
		mobSpider.magicDefence = 45;
		mobSpider.expDrop = 120;
		mobSpider.itemDrop = 4;
		mobSpider.AI = 4;
		mobSpider.imgSrc = "images/spider.bmp";
		mobSpider.goldDrop = 500;

		//Giant Spider
		mobGiantSpider.enemyName = "Giant Spider";
		mobGiantSpider.maxHP = 70;
		mobGiantSpider.physicalAttack = 60;
		mobGiantSpider.magicalAttack = 15;
		mobGiantSpider.physicalDefence = 70;
		mobGiantSpider.magicDefence = 50;
		mobGiantSpider.expDrop = 140;
		mobGiantSpider.itemDrop = 5;
		mobGiantSpider.AI = 1;
		mobGiantSpider.imgSrc = "images/gaintspider.bmp";
		mobGiantSpider.goldDrop = 750;

			//Cockroach
			mobCockroach.enemyName = "Cockroach";
			mobCockroach.maxHP = 80;
			mobCockroach.physicalAttack = 60;
			mobCockroach.magicalAttack = 5;
			mobCockroach.physicalDefence = 80;
			mobCockroach.magicDefence = 45;
			mobCockroach.expDrop = 120;
			mobCockroach.itemDrop = 4;
			mobCockroach.AI = 1;
			mobCockroach.imgSrc = "images/cockroach.bmp";
			mobCockroach.goldDrop = 650;

			//Group of rats
			mobRatGroup.enemyName = "A Group of Rats";
			mobRatGroup.maxHP = 150;
			mobRatGroup.physicalAttack = 50;
			mobRatGroup.magicalAttack = 5;
			mobRatGroup.physicalDefence = 30;
			mobRatGroup.magicDefence = 35;
			mobRatGroup.expDrop = 120;
			mobRatGroup.itemDrop = 1;
			mobRatGroup.AI = 7;
			mobRatGroup.imgSrc = "images/ratGroup.bmp";
			mobRatGroup.goldDrop = 1000;

			//Guard
			mobGuard.enemyName = "Guard";
			mobGuard.maxHP = 130;
			mobGuard.physicalAttack = 75;
			mobGuard.magicalAttack = 15;
			mobGuard.physicalDefence = 70;
			mobGuard.magicDefence = 22;
			mobGuard.expDrop = 150;
			mobGuard.itemDrop = 5;
			mobGuard.AI = 2;
			mobGuard.imgSrc = "images/guard.bmp";
			mobGuard.goldDrop = 2500;

			//Guard Mage
			mobGuardMage.enemyName = "Mage Knight";
			mobGuardMage.maxHP = 120;
			mobGuardMage.physicalAttack = 20;
			mobGuardMage.magicalAttack = 6;
			mobGuardMage.physicalDefence = 35;
			mobGuardMage.magicDefence = 70;
			mobGuardMage.expDrop = 200;
			mobGuardMage.itemDrop = 2;
			mobGuardMage.AI = 3;
			mobGuardMage.imgSrc = "images/guardMage.bmp";
			mobGuardMage.goldDrop = 3000;

			//Rabid Dog
			mobRabidDog.enemyName = "Rabid Dog";
			mobRabidDog.maxHP = 20;
			mobRabidDog.physicalAttack = 8;
			mobRabidDog.magicalAttack = 5;
			mobRabidDog.physicalDefence = 10;
			mobRabidDog.magicDefence = 5;
			mobRabidDog.expDrop = 15;
			mobRabidDog.itemDrop = 1;
			mobRabidDog.AI = 1;
			mobRabidDog.imgSrc = "images/rabiddog.bmp";
			mobRabidDog.goldDrop = 100;
			mobRabidDog.boss = true;

			//Goblin Boss
			mobGoblinBoss.enemyName = "Goblin Boss";
			mobGoblinBoss.maxHP = 250;
			mobGoblinBoss.physicalAttack = 30;
			mobGoblinBoss.magicalAttack = 10;
			mobGoblinBoss.physicalDefence = 35;
			mobGoblinBoss.magicDefence = 35;
			mobGoblinBoss.expDrop = 210;
			mobGoblinBoss.itemDrop = 5;
			mobGoblinBoss.AI = 2;
			mobGoblinBoss.imgSrc = "images/goblinboss.bmp";
			mobGoblinBoss.goldDrop = 2500;
			mobGoblinBoss.boss = true;

			//Spider Queen
			mobSpiderQueen.enemyName = "Spider Queen";
			mobSpiderQueen.maxHP = 500;
			mobSpiderQueen.physicalAttack = 65;
			mobSpiderQueen.magicalAttack = 50;
			mobSpiderQueen.physicalDefence = 45;
			mobSpiderQueen.magicDefence = 30;
			mobSpiderQueen.expDrop = 540;
			mobSpiderQueen.itemDrop = 2;
			mobSpiderQueen.AI = 3;
			mobSpiderQueen.imgSrc = "images/queenspider.bmp";
			mobSpiderQueen.goldDrop = 3000;
			mobSpiderQueen.boss = true;

			//Wizard
			mobWizard.enemyName = "Wizard";
			mobWizard.maxHP = 250;
			mobWizard.physicalAttack = 5;
			mobWizard.magicalAttack = 65;
			mobWizard.physicalDefence = 30;
			mobWizard.magicDefence = 50;
			mobWizard.expDrop = 2160;
			mobWizard.itemDrop = 2;
			mobWizard.AI = 9;
			mobWizard.imgSrc = "images/wizard.bmp";
			mobWizard.goldDrop = 5000;
			mobWizard.boss = true;

			//Demon
				mobDemonLord.enemyName = "Demon Lord Grandma!!!";
				mobDemonLord.maxHP = 1000;
				mobDemonLord.physicalAttack = 100;
				mobDemonLord.magicalAttack = 100;
				mobDemonLord.physicalDefence = 75;
				mobDemonLord.magicDefence = 75;
				mobDemonLord.expDrop = 30000;
				mobDemonLord.itemDrop = 2;
				mobDemonLord.AI = 10;
				mobDemonLord.imgSrc = "images/demon.bmp";
				mobDemonLord.goldDrop = 7000;
				mobDemonLord.boss = true;
}


Mobs::~Mobs()
{
}

int Mobs::getRandomInt(int max, int min)
{
	return rand() % min + max;
}

void Mobs::generateEnemyStats(mob& mob)
{
	if (mob.boss == false)
	{
		mob.maxHP = getRandomInt(mob.maxHP * 0.8, mob.maxHP * 1.2);
		mob.physicalAttack = getRandomInt(mob.physicalAttack * 0.8, mob.physicalAttack * 1.2);
		mob.magicalAttack = getRandomInt(mob.magicalAttack * 0.8, mob.magicalAttack * 1.2);
		mob.physicalDefence = getRandomInt(mob.physicalDefence * 0.8, mob.physicalDefence * 1.2);
		mob.magicDefence = getRandomInt(mob.magicDefence * 0.8, mob.magicDefence * 1.2);
		mob.goldDrop = getRandomInt(mob.goldDrop * 0.8, mob.goldDrop * 1.2);
		mob.expDrop = getRandomInt(mob.expDrop * 0.8, mob.expDrop * 1.2);
	}
	
}

Mobs::mob Mobs::determineMonster(int mapZone)
{
	mob monster;

	switch (mapZone)
	{
		case 1: //Field
			switch (getRandomInt(1, 2))
			{
				case 1:	//Rat
					monster = mobRat;
					generateEnemyStats(monster);
					break;
				case 2:	//Bat
					monster = mobBat;
					generateEnemyStats(monster);
					break;
			}
			break;
		case 3: //Castle
			switch (getRandomInt(1, 3))
			{
				case 1:
				case 2:
					monster = mobGuard;
					generateEnemyStats(monster);
					break;
				case 3: 
					monster = mobGuardMage;
					generateEnemyStats(monster);
					break;
			}
			break;
		case 4: //Goblin Camp
			switch (getRandomInt(1, 5))
			{
				case 1:
				case 2:
					monster = mobGoblin;
					generateEnemyStats(monster);
					break;
				case 3:
				case 4:
					monster = mobGoblinMage;
					generateEnemyStats(monster);
					break;
				case 5:
					monster = mobYoungGoblin;
					generateEnemyStats(monster);
					break;
			}
			break;
		case 6: //Spider Cave
			switch (getRandomInt(1, 5))
			{
			case 1:
			case 2:	//Spider
				monster = mobSpider;
				generateEnemyStats(monster);
				break;
			case 3: //Giant Spider
				monster = mobGiantSpider;
				generateEnemyStats(monster);
				break;
			case 4: //Cockroach
				monster = mobCockroach;
				generateEnemyStats(monster);
				break;
			case 5: //Group of rats
				monster = mobRatGroup;
				generateEnemyStats(monster);
				break;
			}
			break;
			//Bosses Special Cases
		case 10://Dog
			monster = mobRabidDog;
			generateEnemyStats(monster);
			break;
		case 11:// Goblin Boss
			monster = mobGoblinBoss;
			generateEnemyStats(monster);
			break;
		case 12: //Spider Queen
			monster = mobSpiderQueen;
			generateEnemyStats(monster);
			break;
		case 13: //Wizard
			monster = mobWizard;
			generateEnemyStats(monster);
			break;
		case 14: //Demon Lord
			monster = mobDemonLord;
			generateEnemyStats(monster);
			break;
	}

	return monster;
}

void Mobs::mobWeakAttack(Player player, Screen screen, Fonts fonts, Music music)
{
	screen.messageBox("The enemy prepares for", "a melee based attack!", fonts.font24);
	music.PlayHit();
	
}

int Mobs::calculateDamageDealt(int attack, int defence)
{
	//calculates and returns damage after subtracting the defence stat of the oppenent
	int damageDealt = attack - defence;
	if (damageDealt <= 0) {  //prevents passing negative damage that would effectively heal the openent
		damageDealt = getRandomInt(1, 5);	//applies chip damage if no damage would be dealt
	}
	return damageDealt;	
}

int Mobs::calculateEnemyHeal(int heal, mob monster)
{
	int damageHealed = heal;
	if ((heal + monster.hp) > monster.maxHP) {
		damageHealed = monster.maxHP - monster.hp;
	}
	return damageHealed;
}
