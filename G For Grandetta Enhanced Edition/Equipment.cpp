#include "Equipment.h"




Equipment::Equipment()
{
	

	bone.weaponName = "Grandma's Femur";
	stoneSword.weaponName = "Stone Sword";
	steelSword.weaponName = "Steel Sword";
	staff.weaponName = "Wooden Staff of Magic";
	rubySword.weaponName = "Ruby Sword";
	masterWand.weaponName = "Wand of the Masters";

	bone.weaponPhysDamage= 2;
	stoneSword.weaponPhysDamage = 10;
	steelSword.weaponPhysDamage = 13;
	staff.weaponPhysDamage = 20;
	rubySword.weaponPhysDamage = 50;
	masterWand.weaponPhysDamage = 30;

	bone.weaponMagicDamage= 0;
	stoneSword.weaponMagicDamage = 2;
	steelSword.weaponMagicDamage = 5;
	staff.weaponMagicDamage = 35;
	rubySword.weaponMagicDamage = 30;
	masterWand.weaponMagicDamage = 50;

	bone.weaponAccuracy = 80;
	stoneSword.weaponAccuracy = 80;
	steelSword.weaponAccuracy = 90;
	staff.weaponAccuracy = 80;
	rubySword.weaponAccuracy = 95;
	masterWand.weaponAccuracy = 98;

	bone.weaponCost = 0;
	stoneSword.weaponCost = 50;
	steelSword.weaponCost = 750;
	staff.weaponCost = 2000;
	rubySword.weaponCost = 5000;
	masterWand.weaponCost = 6500;

	

	basicChest.chestName = "Peasant Rags";
	leatherChest.chestName = "leather Vest";
	chainmailChest.chestName = "Knights chainmail";
	kingChest.chestName = "Armour of the king";
	apprenticeChest.chestName = "Wizards apprentice Cloak";
	masterChest.chestName = "Cloak of the master Wizard";

	basicChest.chestPhysDef = 5;
	leatherChest.chestPhysDef = 15;
	chainmailChest.chestPhysDef = 20;
	kingChest.chestPhysDef = 25;
	apprenticeChest.chestPhysDef = 30;
	masterChest.chestPhysDef = 35;

	basicChest.chestMagicDef = 0;
	leatherChest.chestMagicDef = 2;
	chainmailChest.chestMagicDef = 5;
	kingChest.chestMagicDef = 15;
	apprenticeChest.chestMagicDef = 20;
	masterChest.chestMagicDef = 30;

	basicChest.chestCost = 0;
	leatherChest.chestCost = 40;
	chainmailChest.chestCost = 300;
	kingChest.chestCost = 750;
	apprenticeChest.chestCost = 1300;
	masterChest.chestCost = 2500;

	

	basicHelmet.helmetName = "Peasant Hat";
	leatherHelmet.helmetName = "Leather Helmet";
	chainmailHelmet.helmetName = "Knights Helmet Hood";
	kingHelmet.helmetName = "High king Crown";
	apprenticeHelmet.helmetName = "Apprentice Helmet Hood";
	masterHelmet.helmetName = "Hood of the master Wizard";

	basicHelmet.helmetPhysDef = 3;
	leatherHelmet.helmetPhysDef = 7;
	chainmailHelmet.helmetPhysDef = 10;
	kingHelmet.helmetPhysDef = 13;
	apprenticeHelmet.helmetPhysDef = 15;
	masterHelmet.helmetPhysDef = 20;

	basicHelmet.helmetMagicDef = 0;
	leatherHelmet.helmetMagicDef = 2;
	chainmailHelmet.helmetMagicDef = 4;
	kingHelmet.helmetMagicDef = 8;
	apprenticeHelmet.helmetMagicDef = 10;
	masterHelmet.helmetMagicDef = 20;

	basicHelmet.helmetCost = 0;
	leatherHelmet.helmetCost = 25;
	chainmailHelmet.helmetCost = 150;
	kingHelmet.helmetCost = 650;
	apprenticeHelmet.helmetCost = 800;
	masterHelmet.helmetCost = 1500;

	

	basicGauntlet.gauntletName = "Wooden Wrist Charms";
	leatherGauntlet.gauntletName = "Leather Gauntlets";
	chainmailGauntlet.gauntletName = "Knights Chainmail Gauntlets";
	kingGauntlet.gauntletName = "High Kings Metal Sleeves";
	apprenticeGauntlet.gauntletName = "Apprentice Wrist Wraps";
	masterGauntlet.gauntletName = "Sleeves of the Master Wizard";

	basicGauntlet.gauntletPhysDef = 2;
	leatherGauntlet.gauntletPhysDef = 5;
	chainmailGauntlet.gauntletPhysDef = 7;
	kingGauntlet.gauntletPhysDef = 10;
	apprenticeGauntlet.gauntletPhysDef = 11;
	masterGauntlet.gauntletPhysDef = 15;

	basicGauntlet.gauntletMagicDef = 0;
	leatherGauntlet.gauntletMagicDef = 1;
	chainmailGauntlet.gauntletMagicDef = 2;
	kingGauntlet.gauntletMagicDef = 4;
	apprenticeGauntlet.gauntletMagicDef = 6;
	masterGauntlet.gauntletMagicDef = 9;

	basicGauntlet.gauntletCost = 0;
	leatherGauntlet.gauntletCost = 20;
	chainmailGauntlet.gauntletCost = 100;
	kingGauntlet.gauntletCost = 350;
	apprenticeGauntlet.gauntletCost = 500;
	masterGauntlet.gauntletCost = 1000;


	basicBoots.bootsName = "Cloth Socks";
	leatherBoots.bootsName = "Leather Battle Boots";
	chainmailBoots.bootsName = "Knights Steel Boots";
	kingBoots.bootsName = "High Kings Kicks";
	apprenticeBoots.bootsName = "Apprentice Sandals";
	masterBoots.bootsName = "Flip Flops of the Master Wizard";

	basicBoots.bootsPhysDef = 1;
	leatherBoots.bootsPhysDef = 3;
	chainmailBoots.bootsPhysDef = 5;
	kingBoots.bootsPhysDef = 7;
	apprenticeBoots.bootsPhysDef = 1;
	masterBoots.bootsPhysDef = 3;

	basicBoots.bootsMagicDef = 0;
	leatherBoots.bootsMagicDef = 1;
	chainmailBoots.bootsMagicDef = 2;
	kingBoots.bootsMagicDef = 3;
	apprenticeBoots.bootsMagicDef = 7;
	masterBoots.bootsMagicDef = 13;

	basicBoots.bootsCost = 0;
	leatherBoots.bootsCost = 15;
	chainmailBoots.bootsCost = 75;
	kingBoots.bootsCost = 250;
	apprenticeBoots.bootsCost = 400;
	masterBoots.bootsCost = 800;

}


Equipment::~Equipment()
{
}
