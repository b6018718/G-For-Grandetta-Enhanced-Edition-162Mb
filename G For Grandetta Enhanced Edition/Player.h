#pragma once
#include <string>
#include <vector>
#include "Maps.h"
#include "questPoint.h"
#include "Equipment.h"
#include <sstream>
using namespace std;

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

struct weapon
{
	string weaponName;
	int weaponPhysDamage;
	int weaponMagicDamage;
	int weaponAccuracy;
	int weaponCost;
};

struct chestPiece
{
	string chestName;
	int	chestPhysDef;
	int chestMagicDef;
	int chestCost;
};

struct helmet
{
	string helmetName;
	int	helmetPhysDef;
	int helmetMagicDef;
	int helmetCost;
};

struct gauntlet
{
	string gauntletName;
	int	gauntletPhysDef;
	int gauntletMagicDef;
	int gauntletCost;
};

struct boots
{
	string bootsName;
	int	bootsPhysDef;
	int bootsMagicDef;
	int bootsCost;
};

class Player
{
public:
	Player();
	~Player();

	string pClass; //Character's class
	string name; //Player's name
	int level;	//Character's level
	int expLevelUp;	//To next level up
	int currentExp; //Current experience points
	int maxHP; //Character's max health
	int currentHP; //Character's current health
	int maxMP; //Character's maximum magic points
	int currentMP; //Character's current magic points
	int phyAttack; //Character's physical attack strength
	int phyDefence; //Character's physical defence
	int magAttack; //Character's magic attack strength
	int	magDefence; //Character's magic defence
	int luck; //Critical hits, dodging and missing
	int gold; //Amount of currency
	int currentMap; //Current map location (0-7)
	int spriteSizeX = 32;	//Size of the players sprite
	int spriteSizeY = 32;	//Size of the players sprite
	int spriteFrame;
	int playerSpeed = 4;	//Speed of players movement per frame
	int currentQuestPoint = 0; //Current Quest Number
	int currentQuest = 0;
	string playerName;
	Equipment::weapon equippedWeapon;
	Equipment::chestPiece equippedChestPiece;
	Equipment::helmet equippedHelmet;
	Equipment::gauntlet equippedGauntlet;
	Equipment::boots equippedBoots;
	string levelUpString;
	bool questLoaded;
	float smokeBombEffect = 1;
	float ironPotionEffect = 1;
	float beserkPotionEffect = 1;	//Remember to reset these
	int hitChance;

	void equipWeapon(Equipment::weapon newWeapon);
	void equipChestPiece(Equipment::chestPiece newChest);
	void equipHelmet(Equipment::helmet newHelmet);
	void equipGauntlet(Equipment::gauntlet newGauntlet);
	void equipBoots(Equipment::boots newBoots);

	questPoint * quests[8][3];

	int x;	//X Relative to window
	int y;	//Y Relative to window

	struct Map
	{
		int x = 58 * 32; //X Relative to map
		int y = 1 * 32; //Y Relative to map
	};



	struct Direction
	{
		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;
	};

	Direction dir;
	Direction facing;
	Map map;
	

	int effectiveCurrentExp; //Current exp minus total exp
	int effectiveExpLevelUp; //Next level up minus total exp

	vector <int> levelExpNeeded = { 0, 15, 60, 120, 195, 345, 555, 825, 1125, 1485, 1935, 2475, 3105, 3825, 4635 };

	int getRandomInt(int min, int max);
	void initaliseStats(Equipment equipment);
	void levelUp();
	void playerGainsExp(int exp);
	void incrementQuest();

	void moveLeft(Maps maps);
	void moveRight(Maps maps);
	void moveUp(Maps maps);
	void moveDown(Maps maps);
};

