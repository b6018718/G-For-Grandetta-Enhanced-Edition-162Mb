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
		mobRat.maxHP = 20;
		mobRat.physicalAttack = 14;
		mobRat.magicalAttack = 5;
		mobRat.physicalDefence = 4;
		mobRat.magicDefence = 3;
		mobRat.expDrop = 15;
		mobRat.itemDrop = 1;
		mobRat.AI = 1;
		mobRat.imgSrc = "images/rat.bmp";
		mobRat.goldDrop = 30;
		

		//Bat
		mobBat.enemyName=  "Bat";
		mobBat.maxHP = 18;
		mobBat.physicalAttack = 14;
		mobBat.magicalAttack = 0;
		mobBat.physicalDefence = 4;
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
		mobGoblin.magicDefence = 10;
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
		mobGoblinMage.physicalDefence= 10;
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
		mobGuard.maxHP = 30;
		mobGuard.physicalAttack = 17;
		mobGuard.magicalAttack = 5;
		mobGuard.physicalDefence = 10;
		mobGuard.magicDefence = 5;
		mobGuard.expDrop = 30;
		mobGuard.itemDrop = 5;
		mobGuard.AI = 2;
		mobGuard.imgSrc = "images/guard.bmp";
		mobGuard.goldDrop = 50;

		

		//Guard Mage
		mobGuardMage.enemyName = "Mage Knight";
		mobGuardMage.maxHP = 25;
		mobGuardMage.physicalAttack = 4;
		mobGuardMage.magicalAttack = 9;
		mobGuardMage.physicalDefence = 5;
		mobGuardMage.magicDefence = 70;
		mobGuardMage.expDrop = 45;
		mobGuardMage.itemDrop = 2;
		mobGuardMage.AI = 3;
		mobGuardMage.imgSrc = "images/guardMage.bmp";
		mobGuardMage.goldDrop = 80;

		//Rabid Dog
		mobRabidDog.enemyName = "Rabid Dog";
		mobRabidDog.maxHP = 20;
		mobRabidDog.physicalAttack = 8;
		mobRabidDog.magicalAttack = 5;
		mobRabidDog.physicalDefence = 5;
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

int Mobs::getRandomInt(int min, int max)
{
	int randomNum;
	if (max == 0 && max == 0)
		randomNum = 0;
	else
		randomNum = rand() % (max - min + 1) + min;
	return randomNum;
}

void Mobs::generateEnemyStats(mob& mob)
{
	if (mob.boss == false)
	{
		mob.maxHP = getRandomInt(mob.maxHP * 0.8, mob.maxHP * 1.2);
		mob.hp = mob.maxHP;
		mob.physicalAttack = getRandomInt(mob.physicalAttack * 0.8, mob.physicalAttack * 1.2);
		mob.magicalAttack = getRandomInt(mob.magicalAttack * 0.8, mob.magicalAttack * 1.2);
		mob.physicalDefence = getRandomInt(mob.physicalDefence * 0.8, mob.physicalDefence * 1.2);
		mob.magicDefence = getRandomInt(mob.magicDefence * 0.8, mob.magicDefence * 1.2);
		mob.goldDrop = getRandomInt(mob.goldDrop * 0.8, mob.goldDrop * 1.2);
		mob.expDrop = getRandomInt(mob.expDrop * 0.8, mob.expDrop * 1.2);
	}
	else
	{
		mob.hp = mob.maxHP;
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

void Mobs::mobWeakAttack(Player& player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	screen.messageBox("The enemy prepares for", "a melee based attack!", fonts.font24);
	int movePower = 5;
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.physicalAttack + movePower, floor(player.phyDefence * player.ironPotionEffect));
		player.currentHP = player.currentHP - damage;
		music.PlayHit();
		screen.messageBox("The enemy attacks you", "with a weak attack! " + to_string(damage) + " Damage!", fonts.font24);
		
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::mobStrongAttack(Player& player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	int movePower = 20;
	screen.messageBox("The enemy prepares for", "a melee based attack!", fonts.font24);
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.physicalAttack + movePower, floor(player.phyDefence*player.ironPotionEffect));
		player.currentHP = player.currentHP - damage;
		music.PlayHit();
		screen.messageBox("The enemy attacks you", "with a strong attack! " + to_string(damage) + " Damage!", fonts.font24);
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::mobTackle(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	int movePower = 10;
	screen.messageBox("The enemy prepares for", "a melee based attack!", fonts.font24);
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.physicalAttack + movePower, floor(player.phyDefence*player.ironPotionEffect));
		player.currentHP = player.currentHP - damage;
		music.PlayHit();
		screen.messageBox("The enemy tackles you", "with their full force! " + to_string(damage) + " Damage!" , fonts.font24);
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::mobSwordSlash(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	int movePower = 30;
	screen.messageBox("The enemy prepares for", "a melee based attack!", fonts.font24);
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.physicalAttack + movePower, floor(player.phyDefence*player.ironPotionEffect));
		player.currentHP = player.currentHP - damage;
		music.PlayHit();
		screen.messageBox("The slashes their sword", "fiercely! " + to_string(damage) + " Damage!", fonts.font24);
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::mobCastFreeze(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	int movePower = 10;
	screen.messageBox("The enemy starts chanting", "and tries to cast a spell!", fonts.font24);
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.magicalAttack + movePower, floor(player.magDefence*player.ironPotionEffect));
		player.currentHP = player.currentHP - damage;
		music.PlayHit();
		screen.messageBox("The enemy freezes you", "lowering your defence! " + to_string(damage) + " Damage!", fonts.font24);
		
		if (player.ironPotionEffect > 0.5) {
			player.ironPotionEffect = player.ironPotionEffect / 2;
		}
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::mobCastFire(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	int movePower = 15;
	screen.messageBox("The enemy starts chanting", "and tries to cast a spell!", fonts.font24);
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.magicalAttack + movePower, floor(player.magDefence*player.ironPotionEffect));
		player.currentHP = player.currentHP - damage;
		music.PlayHit();
		screen.messageBox("The enemy cast fire burning", "away your health! " + to_string(damage) + " Damage!", fonts.font24);
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::mobCastThunder(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	int movePower = 25;
	screen.messageBox("The enemy starts chanting", "and tries to cast a spell!", fonts.font24);
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.magicalAttack + movePower, floor(player.magDefence*player.ironPotionEffect));
		player.currentHP = player.currentHP - damage; 
		music.PlayHit();
		screen.messageBox("The enemy zaps you", "with a thunderbolt! " + to_string(damage) + " Damage!", fonts.font24);
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::mobBreathFire(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	int movePower = 30;
	screen.messageBox("The enemy breathes in deeply", "and prepares to exhale!", fonts.font24);
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.magicalAttack + movePower, floor(player.magDefence*player.ironPotionEffect));
		player.currentHP = player.currentHP - damage;
		music.PlayHit();
		screen.messageBox("The enemy breathes fire", "lowering your attack! " + to_string(damage) + " Damage!", fonts.font24);
		if (player.berserkPotionEffect > 0.5) {
			player.berserkPotionEffect = player.berserkPotionEffect / 2;
		}
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::mobBegMercy(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	screen.messageBox("Please strong warrior, we are weak", "Let us go, we pose no threat!", fonts.font24);
}

void Mobs::mobTryToRun(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	screen.messageBox("The younglings turn around", "and try to run!", fonts.font24);
}

void Mobs::mobReason(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	screen.messageBox("Fighting doesn't solve anything", "Please let us live!", fonts.font24);
}

void Mobs::mobUltimateGNova(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	int movePower = 50;
	screen.messageBox("Demon Lord Grandma casts", "Ultimate G Nova!", fonts.font24);
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.magicalAttack + movePower, floor(player.magDefence*player.ironPotionEffect));
		player.currentHP = player.currentHP - damage;
		music.PlayHit();
		screen.messageBox("Its power is... ", "OUT OF THIS WORLD!!! " + to_string(damage) + " Damage!", fonts.font24);
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::mobHeal(Player & player, Screen screen, Fonts fonts, Music music, mob& enemy)
{
	int hpGain = calculateEnemyHeal(200, enemy);
	enemy.hp = enemy.hp + hpGain;
	screen.messageBox("The enemy casts a healing spell,", "They recover " + to_string(hpGain) + " HP!", fonts.font24);
	if (player.smokeBombEffect != 1) {
		player.smokeBombEffect == 1;
		screen.messageBox("The spell also reset the effects", " of your smoke bomb!", fonts.font24);
	}
}

void Mobs::mobPotion(Player & player, Screen screen, Fonts fonts, Music music, mob& enemy)
{
	int hpGain = calculateEnemyHeal(200, enemy);
	enemy.hp = enemy.hp + hpGain;
	screen.messageBox("The enemy drinks a potion,", "They recover " + to_string(hpGain) + " HP!", fonts.font24);
}

void Mobs::mobStickyWeb(Player & player, Screen screen, Fonts fonts, Music music, mob enemy)
{
	int movePower = 5;
	screen.messageBox("The enemy eyes you up", "its web shooter ready!", fonts.font24);
	if ((getRandomInt(1, 100)) < (90 * player.smokeBombEffect)) {
		int damage = calculateDamageDealt(enemy.magicalAttack + movePower, floor(player.magDefence*player.ironPotionEffect));
		player.currentHP = player.currentHP - damage;
		music.PlayHit();
		screen.messageBox("The enemy traps you in their web,", "Lowering your attack!" + to_string(damage) + "Damage!", fonts.font24);
		if (player.berserkPotionEffect > 0.5) {
			player.berserkPotionEffect = player.berserkPotionEffect / 2;
		}
	}
	else {
		screen.messageBox("You dodged then enemies attack!", "You took no damage! GG!", fonts.font24);
	}
	
}

void Mobs::selectMonsterMove(Player & player, Screen screen, Fonts fonts, Music music, mob& enemy)
{
	switch (enemy.AI) {

	case 1: //BASIC
		switch (getRandomInt(1, 2)) {
		case 1:
			mobWeakAttack(player, screen, fonts, music, enemy);
			break;
		case 2:
			mobTackle(player, screen, fonts, music, enemy);
			break;
		}
		break;

	case 2: //KNIGHT
		switch (getRandomInt(1, 8)) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			mobStrongAttack(player, screen, fonts, music, enemy);
			break;
		case 7:
			if (enemy.hp < enemy.maxHP) {
				mobPotion(player, screen, fonts, music, enemy);
			}
			else {
				mobSwordSlash(player, screen, fonts, music, enemy);
			}
			break;
		case 8:
			mobSwordSlash(player, screen, fonts, music, enemy);
			break;
		}
		break;

	case 3: //MAGE
		switch (getRandomInt(1, 3)) {
		case 1:
			if (enemy.hp < enemy.maxHP) {
				mobHeal(player, screen, fonts, music, enemy);
			}
			else {
				mobCastFire(player, screen, fonts, music, enemy);
			}
			break;

		case 2:
			mobCastFreeze(player, screen, fonts, music, enemy);
			break;
		case 3:
			mobCastFire(player, screen, fonts, music, enemy);
			break;
		}
		break;

	case 4: //SPIDER
		switch (getRandomInt(1, 2)) {
		case 1:
			mobWeakAttack(player, screen, fonts, music, enemy);
			break;
		case 2:
			mobStickyWeb(player, screen, fonts, music, enemy);
			break;
		}
		break;

	case 5: //GIANT SPIDER
		switch (getRandomInt(1, 3)) {
		case 1:
			mobStrongAttack(player, screen, fonts, music, enemy);
			break;
		case 2:
			mobTackle(player, screen, fonts, music, enemy);
			break;
		case 3:
			mobStickyWeb(player, screen, fonts, music, enemy);
			break;
		}
		break;

	case 6: //SPIDER QUEEN
		switch (getRandomInt(1, 3)) {
		case 1:
			mobBreathFire(player, screen, fonts, music, enemy);
			break;
		case 2:
			mobStrongAttack(player, screen, fonts, music, enemy);
			break;
		case 3:
			mobStickyWeb(player, screen, fonts, music, enemy);
			break;
		}
		break;

	case 7: //STRONG ATTACKER
		switch (getRandomInt(1, 2)) {
		case 1:
			mobTackle(player, screen, fonts, music, enemy);
			break;
		case 2:
			mobStrongAttack(player, screen, fonts, music, enemy);
			break;
		}
		break;

	case 8: //YOUNGLIN
		switch (getRandomInt(1, 3)) {
		case 1:
			mobReason(player, screen, fonts, music, enemy);
			break;
		case 2:
			mobTryToRun(player, screen, fonts, music, enemy);
			break;
		case 3:
			mobBegMercy(player, screen, fonts, music, enemy);
			break;
		}
		break;

	case 9: //WIZARD
		switch (getRandomInt(1, 4)) {
		case 1:
			mobCastFire(player, screen, fonts, music, enemy);
			break;
		case 2:
			mobCastThunder(player, screen, fonts, music, enemy);
			break;
		case 3:
			mobCastFreeze(player, screen, fonts, music, enemy);
			break;
		case 4:
			if (enemy.hp < enemy.maxHP) {
				mobHeal(player, screen, fonts, music, enemy);
			}
			else {
				mobCastFire(player, screen, fonts, music, enemy);
			}
			break;
		}
		break;

	case 10: //FINAL BOSS
		switch (getRandomInt(1, 10)) {
		case 1:
			mobCastFire(player, screen, fonts, music, enemy);
			break;
		case 2:
			if (enemy.hp < enemy.maxHP) {
				mobHeal(player, screen, fonts, music, enemy);
			}
			else {
				mobCastFire(player, screen, fonts, music, enemy);
			}
			break;
		case 3:
			mobCastFreeze(player, screen, fonts, music, enemy);
			break;
		case 4:
			mobStrongAttack(player, screen, fonts, music, enemy);
			break;
		case 5:
			mobBreathFire(player, screen, fonts, music, enemy);
			break;
		case 6:
			mobCastThunder(player, screen, fonts, music, enemy);
			break;
		case 7:
		case 8:
		case 9:
		case 10:
			mobUltimateGNova(player, screen, fonts, music, enemy);
			break;
		}
		break;

	}


}

void Mobs::enemyOpeningMessage(Screen screen, mob enemy, Player player, Fonts fonts)
{
	
	if (enemy.enemyName == "Rabid Dog") {
		screen.messageBox("Ruff Ruff!", "BARK!", fonts.font24);
		}
	if (enemy.enemyName == "A Group of Rats") {
		screen.messageBox("As the Shepard, I won't", "let you beat my Congregation", fonts.font24);
		}
	if (enemy.enemyName == "Goblin Younglings") {
		screen.messageBox("*They appear weak...*", "*Maybe I should just walk away*", fonts.font24);
		}
	if (enemy.enemyName == "Goblin Boss") {
		screen.messageBox("You invade my camp,", "kill my men and want my treasure?", fonts.font24);
		screen.messageBox("Prepare to die by my", "sword arm!", fonts.font24);
		}
	if (enemy.enemyName == "Spider Queen") {
		screen.messageBox("(Err... do spiders)", "(even make sounds?)", fonts.font24);
		screen.messageBox("(WHATEVER!!! Prepare to)", "(die for trespassing into my cave!)", fonts.font24);
		}
	if (enemy.enemyName == "Wizard") {
		screen.messageBox("Your people are never coming back.", "They are all long dead!", fonts.font24);
		screen.messageBox("Finally, the Demon Lord", "is reborn!", fonts.font24);
		screen.messageBox("You have served your", "purpose " + player.name + "!", fonts.font24);
		screen.messageBox("So now I will offer your life", "to my Lord!!!!", fonts.font24);
		}
	if (enemy.enemyName == "Mage Knight"){
		screen.messageBox("May I practise my magic", "against you warrior?", fonts.font24);
	}
	if (enemy.enemyName == "Guard") {
		screen.messageBox("Let me test your strength", "Don't go easy on me!", fonts.font24);

	}
		//if (enemy.enemyName == "Bat") {
	if (enemy.enemyName == "Demon Lord Grandma!!!") {
		screen.messageBox(player.name + " long time,", "no see my grandchild", fonts.font24);
		screen.messageBox("Don't get full of yourself", "just because you beat my puppet", fonts.font24);
		screen.messageBox("Why don't you join me?", "No, we both know that cannot be", fonts.font24);
		screen.messageBox("Now raise your weapon", "and prepare to be CRUSHED!", fonts.font24);
		screen.messageBox("By my demon might!!!!", "Die now" + player.name + "!", fonts.font24);
		}
}

void Mobs::enemyDefeatMessage(Screen& screen, mob enemy, Player& player, Fonts fonts)
{
	if (enemy.enemyName == "Rabid Dog")
	{
		screen.messageBox("Wimper wimper...", "", fonts.font24);
		
	}
	else if (enemy.enemyName == "Goblin Boss") 
	{
		screen.messageBox("Fine, take our treasure...", "Just know that...", fonts.font24);
		screen.messageBox("One day we shall rebuild", "We have the technology!", fonts.font24);
		//phaseHolder = 0;
	}
	else if (enemy.enemyName == "Spider Queen") 
	{
		screen.messageBox("(We lost...)", "(Congratulations Hero)", fonts.font24);
		screen.messageBox("(You killed a spider!)", "(such strength, such wow, such heroics)", fonts.font24);
		//phaseHolder = 0;
	}
	else if (enemy.enemyName == "Wizard")
	{
		screen.messageBox("Master...", "Take my remaining magic...", fonts.font24);
		screen.messageBox("and my soul...", "Avenge me!!!!", fonts.font24);
		//phaseHolder = 0;
	}
	else if (enemy.enemyName == "Demon Lord Grandma!!!") 
	{
		screen.messageBox("So killed by my own", "Grandchild....?", fonts.font24);
		screen.messageBox("On the one hand", "I am sad...", fonts.font24);
		screen.messageBox("But on another...", "I now know that...", fonts.font24);
		screen.messageBox("You also carry the", "demon lord's blood...", fonts.font24);
		screen.messageBox("Maybe some day", "You will too will realise it's power!", fonts.font24);
		//phaseHolder = 0;
	}
}

void Mobs::enemyTurn(Player & player, Screen screen, Fonts fonts, Music music, mob& enemy)
{
	selectMonsterMove(player, screen, fonts, music, enemy); //selects different moves based on The enemy's AI set
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


