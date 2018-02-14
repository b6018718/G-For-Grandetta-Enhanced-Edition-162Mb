#pragma once
#include <string>
#include <vector>
#include "Maps.h"
using namespace std;

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
	int currentX;	//X Location of the player
	int currentY;	//Y Location of the player
	int spriteSizeX = 32;	//Size of the players sprite
	int spriteSizeY = 32;	//Size of the players sprite
	int spriteFrame;
	string playerName;
	string equippedWeapon;
	string equippedChestPiece;
	string equippedHelmet;
	string equippedGaunlet;
	string equippedBoots;
	string levelUpString;


	struct Direction
	{
		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;
	};

	Direction collision;
	Direction dir;
	Direction facing;
	

	int effectiveCurrentExp; //Current exp minus total exp
	int effectiveExpLevelUp; //Next level up minus total exp

	vector <int> levelExpNeeded = { 0, 15, 60, 120, 195, 345, 555, 825, 1125, 1485, 1935, 2475, 3105, 3825, 4635 };

	int getRandomInt(int min, int max);
	void initaliseStats();
	void levelUp();
	void playerGainsExp(int exp);

	void moveLeft(Maps maps);
	void moveRight();
	void moveUp();
	void moveDown();
};

