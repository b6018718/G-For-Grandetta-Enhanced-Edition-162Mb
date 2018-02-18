#pragma once
#include <string>

using namespace std;

class Equipment
{
public:
	Equipment();
	~Equipment();

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

	weapon bone;
	weapon stoneSword;
	weapon steelSword;
	weapon staff;
	weapon rubySword;
	weapon masterWand;


	chestPiece basicChest;
	chestPiece leatherChest;
	chestPiece chainmailChest;
	chestPiece kingChest;
	chestPiece apprenticeChest;
	chestPiece masterChest;


	helmet basicHelmet;
	helmet leatherHelmet;
	helmet chainmailHelmet;
	helmet kingHelmet;
	helmet apprenticeHelmet;
	helmet masterHelmet;


	gauntlet basicGauntlet;
	gauntlet leatherGauntlet;
	gauntlet chainmailGauntlet;
	gauntlet kingGauntlet;
	gauntlet apprenticeGauntlet;
	gauntlet masterGauntlet;


	boots basicBoots;
	boots leatherBoots;
	boots chainmailBoots;
	boots kingBoots;
	boots apprenticeBoots;
	boots masterBoots;

};

