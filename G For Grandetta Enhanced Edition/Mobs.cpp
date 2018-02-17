#include "Mobs.h"



Mobs::Mobs()
{
		//Rat
		mobRat.enemyName = "Rat";		mobRat.maxHP = 15;		mobRat.physicalAttack = 15;		mobRat.magicalAttack = 5;		mobRat.physicalDefence = 15;		mobRat.magicDefence = 3;		mobRat.expDrop = 15;		mobRat.itemDrop = 1;		mobRat.AI = 1;		mobRat.imgSrc = "images/rat.bmp";		mobRat.goldDrop = 30;

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

			//Demon
				mobDemonLord.enemyName = "Demon Lord Grandma!!!";
				mobDemonLord.maxHP = 1000;
				mobDemonLord.physicalAttack = 100;
				mobDemonLord.magicalAttack = 100;
				mobDemonLord.physicalDefence = 75;
				mobDemonLord.magicDefence = 75;
				mobDemonLord.expDrop = 0;
				mobDemonLord.itemDrop = 2;
				mobDemonLord.AI = 10;
				mobDemonLord.imgSrc = "images/demon.bmp";
				mobDemonLord.goldDrop = 7000;
}


Mobs::~Mobs()
{
}
