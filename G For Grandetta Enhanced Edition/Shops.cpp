#include "Shops.h"



Shops::Shops()
{
}


Shops::~Shops()
{
}

bool Shops::buyShop(Screen & screen, Player & player, Fonts& fonts, Equipment equipment)
{
	//Buy = 0, Sell = 1, Hat = 2, Armour = 3
	bool gameExit = false;
	gameExit = shopEvent(player, screen, 0, fonts, equipment);
	return gameExit;
}

void Shops::drawBuyShop(Screen & screen, Player & player, int shopCursorPos, Fonts & fonts)
{
	screen.displayLeftText("Health P.X" + to_string(player.inventory[1]), 70, 528, fonts.font20);
	screen.displayLeftText("Ironskin P.X" + to_string(player.inventory[4]), 370, 528, fonts.font20);
	screen.displayLeftText("Berserk P.X" + to_string(player.inventory[5]), 680, 528, fonts.font20);
	screen.displayLeftText("Magic P.X" + to_string(player.inventory[2]), 70, 600, fonts.font20);
	screen.displayLeftText("Smoke B.X" + to_string(player.inventory[3]), 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);

	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText(">", 46, 528, fonts.font18);
		screen.displayLeftText("Item cost: " + to_string(player.inventoryItemCost[1]), 30, 433, fonts.font18);
		break;
	case 2:
		screen.displayLeftText(">", 346, 528, fonts.font18);
		screen.displayLeftText("Item cost: " + to_string(player.inventoryItemCost[4]), 30, 433, fonts.font18);
		break;
	case 3:
		screen.displayLeftText(">", 656, 528, fonts.font18);
		screen.displayLeftText("Item cost: " + to_string(player.inventoryItemCost[5]), 30, 433, fonts.font18);
		break;
	case 4:
		screen.displayLeftText(">", 46, 600, fonts.font18);
		screen.displayLeftText("Item cost: " + to_string(player.inventoryItemCost[2]), 30, 433, fonts.font18);
		break;
	case 5:
		screen.displayLeftText(">", 346, 600, fonts.font18);
		screen.displayLeftText("Item cost: " + to_string(player.inventoryItemCost[3]), 30, 433, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
}

void Shops::buyItem(Player& player, int item)
{
	if (player.gold >= player.inventoryItemCost[item])
	{
		player.gold = player.gold - player.inventoryItemCost[item];
		player.inventory[item]++;
	}
}

void Shops::buyShopMenu(Player& player, int cursor, bool& quit)
{
	switch (cursor) {
	case 1:
		buyItem(player, 1);
		break;
	case 2:
		buyItem(player, 4);
		break;
	case 3:
		buyItem(player, 5);
		break;
	case 4:
		buyItem(player, 2);
		break;
	case 5:
		buyItem(player, 3);
		break;
	case 6:
		quit = true;
		break;
	}
}

bool Shops::sellShop(Screen& screen, Player& player, Fonts& fonts, Equipment equipment)
{
	//Buy = 0, Sell = 1, Hat = 2, Armour = 3
	bool gameExit = false;
	gameExit = shopEvent(player, screen, 1, fonts, equipment);
	return gameExit;
}

void Shops::sellItem(Player& player, int item)
{
	if (1 <= player.inventory[item]) {
		player.gold = player.gold + floor(player.inventoryItemCost[item] / 4 * 3);
		player.inventory[item]--;
	}
}


void Shops::drawSellShop(Screen & screen, Player & player, int shopCursorPos, Fonts & fonts)
{
	screen.displayLeftText("Health P.X" + to_string(player.inventory[1]), 70, 528, fonts.font20);
	screen.displayLeftText("Ironskin P.X" + to_string(player.inventory[4]), 370, 528, fonts.font20);
	screen.displayLeftText("Berserk P.X" + to_string(player.inventory[5]), 680, 528, fonts.font20);
	screen.displayLeftText("Magic P.X" + to_string(player.inventory[2]), 70, 600, fonts.font20);
	screen.displayLeftText("Smoke B.X" + to_string(player.inventory[3]), 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);

	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText(">", 46, 528, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string( (int)floor(player.inventoryItemCost[1] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 2:
		screen.displayLeftText(">", 346, 528, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string((int)floor(player.inventoryItemCost[4] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 3:
		screen.displayLeftText(">", 656, 528, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string((int)floor(player.inventoryItemCost[5] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 4:
		screen.displayLeftText(">", 46, 600, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string((int)floor(player.inventoryItemCost[2] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 5:
		screen.displayLeftText(">", 346, 600, fonts.font18);
		screen.displayLeftText("Sale Price: " + to_string((int)floor(player.inventoryItemCost[3] / 4 * 3)), 30, 433, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
	
}

bool Shops::hatShop(Screen& screen, Player& player, Fonts& fonts, Equipment equipment)
{
	//Buy = 0, Sell = 1, Hat = 2, Armour = 3
	bool gameExit = false;
	gameExit = shopEvent(player, screen, 2, fonts, equipment);
	return gameExit;
}

void Shops::drawHatShop(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts)
{
	screen.displayLeftText("Red", 70, 528, fonts.font20);
	screen.displayLeftText("Shadow", 370, 528, fonts.font20);
	screen.displayLeftText("Gold", 680, 528, fonts.font20);
	screen.displayLeftText("Cerulean", 70, 600, fonts.font20);
	screen.displayLeftText("Rainbow", 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);
	screen.displayLeftText("Item cost: 1000", 30, 433, fonts.font18);
	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText(">", 46, 528, fonts.font18);
		break;
	case 2:
		screen.displayLeftText(">", 346, 528, fonts.font18);
		break;
	case 3:
		screen.displayLeftText(">", 656, 528, fonts.font18);
		break;
	case 4:
		screen.displayLeftText(">", 46, 600, fonts.font18);
		break;
	case 5:
		screen.displayLeftText(">", 346, 600, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
}

void Shops::buyHatShop(Player& player, string hat)
{
	int hatCost = 1000;
	if (player.gold >= hatCost)
	{
		player.gold -= hatCost;
		if (player.currentQuest == 3 && player.currentQuestPoint == 0)
		{
			player.incrementQuest();
		}
	}
}

bool Shops::armouryShop(Screen& screen, Player& player, Fonts& fonts, Equipment equipment)
{
	//Buy = 0, Sell = 1, Hat = 2, Armour = 3
	bool gameExit = false;
	gameExit = shopEvent(player, screen, 3, fonts, equipment);
	return gameExit;
}


void Shops::drawArmouryShop(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, int armouryPos, Equipment equipment)
{
	switch (armouryPos) {
	case 1:
		drawArmouryMainMenu(screen, player, shopCursorPos, fonts);
		break;
	case 2:
		drawArmouryWeapons(screen, player, shopCursorPos, fonts, equipment);
		break;
	case 3:
		drawArmouryHelmet(screen, player, shopCursorPos, fonts, equipment);
		break;
	case 4:
		drawArmouryGauntlets(screen, player, shopCursorPos, fonts, equipment);
		break;
	case 5:
		drawArmouryChest(screen, player, shopCursorPos, fonts, equipment);
		break;
	case 6:
		drawArmouryBoots(screen, player, shopCursorPos, fonts, equipment);
		break;
	}
}

void Shops::drawArmouryMainMenu(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts)
{
	screen.displayLeftText("Weapons", 70, 528, fonts.font20);
	screen.displayLeftText("Helmets", 370, 528, fonts.font20);
	screen.displayLeftText("Gauntlets" , 680, 528, fonts.font20);
	screen.displayLeftText("Chestpiece" , 70, 600, fonts.font20);
	screen.displayLeftText("Boots", 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);
	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText("Equipped: " + player.equippedWeapon.weaponName, 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 528, fonts.font18);
		break;
	case 2:
		screen.displayLeftText("Equipped: " + player.equippedHelmet.helmetName, 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 528, fonts.font18);
		break;
	case 3:
		screen.displayLeftText("Equipped: " + player.equippedGauntlet.gauntletName, 30, 433, fonts.font18);
		screen.displayLeftText(">", 656, 528, fonts.font18);
		break;
	case 4:
		screen.displayLeftText("Equipped: " + player.equippedChestPiece.chestName, 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 600, fonts.font18);
		break;
	case 5:
		screen.displayLeftText("Equipped: " + player.equippedBoots.bootsName, 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 600, fonts.font18);
		break;
	case 6:
		screen.displayLeftText("See you later", 30, 433, fonts.font18);
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
}

void Shops::armouryMainMenu(Player& player, int& combatCursorPos, int& armouryPos, bool& quit)
{
	switch (combatCursorPos) {
	case 1:
		armouryPos = 2;
		combatCursorPos = 1;
		break;
	case 2:
		armouryPos = 3;
		combatCursorPos = 1;
		break;
	case 3:
		armouryPos = 4;
		combatCursorPos = 1;
		break;
	case 4:
		armouryPos = 5;
		combatCursorPos = 1;
		break;
	case 5:
		armouryPos = 6;
		combatCursorPos = 1;
		break;
	case 6:
		quit = true;
		break;
	}
}

void Shops::drawArmouryWeapons(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment)
{
	screen.displayLeftText("Stone S.", 70, 528, fonts.font20);
	screen.displayLeftText("Steel S.", 370, 528, fonts.font20);
	screen.displayLeftText("Staff", 680, 528, fonts.font20);
	screen.displayLeftText("Ruby S.", 70, 600, fonts.font20);
	screen.displayLeftText("Wand", 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);
	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText("Item cost: " + to_string(equipment.stoneSword.weaponCost) + " Stat change: phyAtt " + to_string(equipment.stoneSword.weaponPhysDamage - player.equippedWeapon.weaponPhysDamage) + " magAtt " + to_string(equipment.stoneSword.weaponMagicDamage - player.equippedWeapon.weaponMagicDamage), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 528, fonts.font18);
		break;
	case 2:
		screen.displayLeftText("Item cost: " + to_string(equipment.steelSword.weaponCost) + " Stat change: phyAtt " + to_string(equipment.steelSword.weaponPhysDamage - player.equippedWeapon.weaponPhysDamage) + " magAtt " + to_string(equipment.steelSword.weaponMagicDamage - player.equippedWeapon.weaponMagicDamage), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 528, fonts.font18);
		break;
	case 3:
		screen.displayLeftText("Item cost: " + to_string(equipment.staff.weaponCost) + " Stat change: phyAtt " + to_string(equipment.staff.weaponPhysDamage - player.equippedWeapon.weaponPhysDamage) + " magAtt " + to_string(equipment.staff.weaponMagicDamage - player.equippedWeapon.weaponMagicDamage), 30, 433, fonts.font18);
		screen.displayLeftText(">", 656, 528, fonts.font18);
		break;
	case 4:
		screen.displayLeftText("Item cost: " + to_string(equipment.rubySword.weaponCost) + " Stat change: phyAtt " + to_string(equipment.rubySword.weaponPhysDamage - player.equippedWeapon.weaponPhysDamage) + " magAtt " + to_string(equipment.rubySword.weaponMagicDamage - player.equippedWeapon.weaponMagicDamage), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 600, fonts.font18);
		break;
	case 5:
		screen.displayLeftText("Item cost: " + to_string(equipment.masterWand.weaponCost) + " Stat change: phyAtt " + to_string(equipment.masterWand.weaponPhysDamage - player.equippedWeapon.weaponPhysDamage) + " magAtt " + to_string(equipment.masterWand.weaponMagicDamage - player.equippedWeapon.weaponMagicDamage), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 600, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
}

void Shops::armouryWeapon(Player& player, int& combatCursorPos, Equipment equipment, int& armouryPos)
{
	switch (combatCursorPos)
	{
	case 1:
		if (player.gold >= equipment.stoneSword.weaponCost) {
			player.equipWeapon(equipment.stoneSword);
			player.gold = player.gold - equipment.stoneSword.weaponCost;
		}
		break;
	case 2:
		if (player.gold >= equipment.steelSword.weaponCost) {
			player.equipWeapon(equipment.steelSword);
			player.gold = player.gold - equipment.steelSword.weaponCost;
		}
		break;
	case 3:
		if (player.gold >= equipment.staff.weaponCost) {
			player.equipWeapon(equipment.staff);
			player.gold = player.gold - equipment.staff.weaponCost;
		}
		break;
	case 4:
		if (player.gold >= equipment.rubySword.weaponCost) {
			player.equipWeapon(equipment.rubySword);
			player.gold = player.gold - equipment.rubySword.weaponCost;
		}
		break;
	case 5:
		if (player.gold >= equipment.masterWand.weaponCost) {
			player.equipWeapon(equipment.masterWand);
			player.gold = player.gold - equipment.masterWand.weaponCost;
		}
		break;
	case 6:
		armouryPos = 1;
		combatCursorPos = 1;
		break;
	}

	if (player.currentQuest == 1 && player.currentQuestPoint == 1)
		player.incrementQuest();
}

void Shops::drawArmouryHelmet(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment)
{
	screen.displayLeftText("Leather H.", 70, 528, fonts.font20);
	screen.displayLeftText("Chainmail H.", 370, 528, fonts.font20);
	screen.displayLeftText("King H.", 680, 528, fonts.font20);
	screen.displayLeftText("Apprentice H.", 70, 600, fonts.font20);
	screen.displayLeftText("Master H.", 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);
	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText("Item cost: " + to_string(equipment.leatherHelmet.helmetCost) + " Stat change: phyDef " + to_string(equipment.leatherHelmet.helmetPhysDef - player.equippedHelmet.helmetPhysDef) + " magDef " + to_string(equipment.leatherHelmet.helmetMagicDef - player.equippedHelmet.helmetMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 528, fonts.font18);
		break;
	case 2:
		screen.displayLeftText("Item cost: " + to_string(equipment.chainmailHelmet.helmetCost) + " Stat change: phyDef " + to_string(equipment.chainmailHelmet.helmetPhysDef - player.equippedHelmet.helmetPhysDef) + " magDef " + to_string(equipment.chainmailHelmet.helmetMagicDef - player.equippedHelmet.helmetMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 528, fonts.font18);
		break;
	case 3:
		screen.displayLeftText("Item cost: " + to_string(equipment.kingHelmet.helmetCost) + " Stat change: phyDef " + to_string(equipment.kingHelmet.helmetPhysDef - player.equippedHelmet.helmetPhysDef) + " magDef " + to_string(equipment.kingHelmet.helmetMagicDef - player.equippedHelmet.helmetMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 656, 528, fonts.font18);
		break;
	case 4:
		screen.displayLeftText("Item cost: " + to_string(equipment.apprenticeHelmet.helmetCost) + " Stat change: phyDef " + to_string(equipment.apprenticeHelmet.helmetPhysDef - player.equippedHelmet.helmetPhysDef) + " magDef " + to_string(equipment.apprenticeHelmet.helmetMagicDef - player.equippedHelmet.helmetMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 600, fonts.font18);
		break;
	case 5:
		screen.displayLeftText("Item cost: " + to_string(equipment.masterHelmet.helmetCost) + " Stat change: phyDef " + to_string(equipment.masterHelmet.helmetPhysDef - player.equippedHelmet.helmetPhysDef) + " magDef " + to_string(equipment.masterHelmet.helmetMagicDef - player.equippedHelmet.helmetMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 600, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
}

void Shops::armouryHelmet(Player& player, int& combatCursorPos, Equipment equipment, int& armourCursorPos)
{
	switch (combatCursorPos) {
	case 1:
		if (player.gold >= equipment.leatherHelmet.helmetCost) {
			player.equipHelmet(equipment.leatherHelmet);
			player.gold = player.gold - equipment.leatherHelmet.helmetCost;
		}
		break;
	case 2:
		if (player.gold >= equipment.chainmailHelmet.helmetCost) {
			player.equipHelmet(equipment.chainmailHelmet);
			player.gold = player.gold - equipment.chainmailHelmet.helmetCost;
		}
		break;
	case 3:
		if (player.gold >= equipment.kingHelmet.helmetCost) {
			player.equipHelmet(equipment.kingHelmet);
			player.gold = player.gold - equipment.kingHelmet.helmetCost;
		}
		break;
	case 4:
		if (player.gold >= equipment.apprenticeHelmet.helmetCost) {
			player.equipHelmet(equipment.apprenticeHelmet);
			player.gold = player.gold - equipment.apprenticeHelmet.helmetCost;
		}
		break;
	case 5:
		if (player.gold >= equipment.masterHelmet.helmetCost) {
			player.equipHelmet(equipment.masterHelmet);
			player.gold = player.gold - equipment.masterHelmet.helmetCost;
		}
		break;
	case 6:
		armourCursorPos = 1;
		combatCursorPos = 2;
		break;
	}
}

void Shops::drawArmouryGauntlets(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment)
{
	screen.displayLeftText("Leather G.", 70, 528, fonts.font20);
	screen.displayLeftText("Chainmail G.", 370, 528, fonts.font20);
	screen.displayLeftText("King G.", 680, 528, fonts.font20);
	screen.displayLeftText("Apprentice G.", 70, 600, fonts.font20);
	screen.displayLeftText("Master G.", 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);
	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText("Item cost: " + to_string(equipment.leatherGauntlet.gauntletCost) + " Stat change: phyDef " + to_string(equipment.leatherGauntlet.gauntletPhysDef - player.equippedGauntlet.gauntletPhysDef) + " magAtt " + to_string(equipment.leatherGauntlet.gauntletMagicDef - player.equippedGauntlet.gauntletMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 528, fonts.font18);
		break;
	case 2:
		screen.displayLeftText("Item cost: " + to_string(equipment.chainmailGauntlet.gauntletCost) + " Stat change: phyDef " + to_string(equipment.chainmailGauntlet.gauntletPhysDef - player.equippedGauntlet.gauntletPhysDef) + " magAtt " + to_string(equipment.chainmailGauntlet.gauntletMagicDef - player.equippedGauntlet.gauntletMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 528, fonts.font18);
		break;
	case 3:
		screen.displayLeftText("Item cost: " + to_string(equipment.kingGauntlet.gauntletCost) + " Stat change: phyDef " + to_string(equipment.kingGauntlet.gauntletPhysDef - player.equippedGauntlet.gauntletPhysDef) + " magAtt " + to_string(equipment.kingGauntlet.gauntletMagicDef - player.equippedGauntlet.gauntletMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 656, 528, fonts.font18);
		break;
	case 4:
		screen.displayLeftText("Item cost: " + to_string(equipment.apprenticeGauntlet.gauntletCost) + " Stat change: phyDef " + to_string(equipment.apprenticeGauntlet.gauntletPhysDef - player.equippedGauntlet.gauntletPhysDef) + " magAtt " + to_string(equipment.apprenticeGauntlet.gauntletMagicDef - player.equippedGauntlet.gauntletMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 600, fonts.font18);
		break;
	case 5:
		screen.displayLeftText("Item cost: " + to_string(equipment.masterGauntlet.gauntletCost) + " Stat change: phyDef " + to_string(equipment.masterGauntlet.gauntletPhysDef - player.equippedGauntlet.gauntletPhysDef) + " magAtt " + to_string(equipment.masterGauntlet.gauntletMagicDef - player.equippedGauntlet.gauntletMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 600, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
}

void Shops::armourGauntlets(Player& player, int& combatCursorPos, Equipment equipment, int& armourCursorPos)
{
	switch (combatCursorPos) {
	case 1:
		if (player.gold >= equipment.leatherGauntlet.gauntletCost) {
			player.equipGauntlet(equipment.leatherGauntlet);
			player.gold = player.gold - equipment.leatherGauntlet.gauntletCost;
		}
		break;
	case 2:
		if (player.gold >= equipment.chainmailGauntlet.gauntletCost) {
			player.equipGauntlet(equipment.chainmailGauntlet);
			player.gold = player.gold - equipment.chainmailGauntlet.gauntletCost;
		}
		break;
	case 3:
		if (player.gold >= equipment.kingGauntlet.gauntletCost) {
			player.equipGauntlet(equipment.kingGauntlet);
			player.gold = player.gold - equipment.kingGauntlet.gauntletCost;
		}
		break;
	case 4:
		if (player.gold >= equipment.apprenticeGauntlet.gauntletCost) {
			player.equipGauntlet(equipment.apprenticeGauntlet);
			player.gold = player.gold - equipment.apprenticeGauntlet.gauntletCost;
		}
		break;
	case 5:
		if (player.gold >= equipment.masterGauntlet.gauntletCost) {
			player.equipGauntlet(equipment.masterGauntlet);
			player.gold = player.gold - equipment.masterGauntlet.gauntletCost;
		}
		break;
	case 6:
		armourCursorPos = 1;
		combatCursorPos = 3;
		break;
	}
}

void Shops::drawArmouryChest(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment)
{
	screen.displayLeftText("Leather C.", 70, 528, fonts.font20);
	screen.displayLeftText("Chainmail C.", 370, 528, fonts.font20);
	screen.displayLeftText("King C.", 680, 528, fonts.font20);
	screen.displayLeftText("Apprentice C.", 70, 600, fonts.font20);
	screen.displayLeftText("Master C.", 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);
	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText("Item cost: " + to_string(equipment.leatherChest.chestCost) + " Stat change: phyDef " + to_string(equipment.leatherChest.chestPhysDef - player.equippedChestPiece.chestPhysDef) + " magAtt " + to_string(equipment.leatherChest.chestMagicDef - player.equippedChestPiece.chestMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 528, fonts.font18);
		break;
	case 2:
		screen.displayLeftText("Item cost: " + to_string(equipment.chainmailChest.chestCost) + " Stat change: phyDef " + to_string(equipment.chainmailChest.chestPhysDef - player.equippedChestPiece.chestPhysDef) + " magAtt " + to_string(equipment.chainmailChest.chestMagicDef - player.equippedChestPiece.chestMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 528, fonts.font18);
		break;
	case 3:
		screen.displayLeftText("Item cost: " + to_string(equipment.kingChest.chestCost) + " Stat change: phyDef " + to_string(equipment.kingChest.chestPhysDef - player.equippedChestPiece.chestPhysDef) + " magAtt " + to_string(equipment.kingChest.chestMagicDef - player.equippedChestPiece.chestMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 656, 528, fonts.font18);
		break;
	case 4:
		screen.displayLeftText("Item cost: " + to_string(equipment.apprenticeChest.chestCost) + " Stat change: phyDef " + to_string(equipment.apprenticeChest.chestPhysDef - player.equippedChestPiece.chestPhysDef) + " magAtt " + to_string(equipment.apprenticeChest.chestMagicDef - player.equippedChestPiece.chestMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 600, fonts.font18);
		break;
	case 5:
		screen.displayLeftText("Item cost: " + to_string(equipment.masterChest.chestCost) + " Stat change: phyDef " + to_string(equipment.masterChest.chestPhysDef - player.equippedChestPiece.chestPhysDef) + " magAtt " + to_string(equipment.masterChest.chestMagicDef - player.equippedChestPiece.chestMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 600, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
}

void Shops::armouryChestpiece(Player& player, int& combatCursorPos, Equipment equipment, int& armourCursorPos)
{
	switch (combatCursorPos) {
	case 1:
		if (player.gold >= equipment.leatherChest.chestCost) {
			player.equipChestPiece(equipment.leatherChest);
			player.gold = player.gold - equipment.leatherChest.chestCost;
		}
		break;
	case 2:
		if (player.gold >= equipment.chainmailChest.chestCost) {
			player.equipChestPiece(equipment.chainmailChest);
			player.gold = player.gold - equipment.chainmailChest.chestCost;
		}
		break;
	case 3:
		if (player.gold >= equipment.kingChest.chestCost) {
			player.equipChestPiece(equipment.kingChest);
			player.gold = player.gold - equipment.kingChest.chestCost;
		}
		break;
	case 4:
		if (player.gold >= equipment.apprenticeChest.chestCost) {
			player.equipChestPiece(equipment.apprenticeChest);
			player.gold = player.gold - equipment.apprenticeChest.chestCost;
		}
		break;
	case 5:
		if (player.gold >= equipment.masterChest.chestCost) {
			player.equipChestPiece(equipment.masterChest);
			player.gold = player.gold - equipment.masterChest.chestCost;
		}
		break;
	case 6:
		armourCursorPos = 1;
		combatCursorPos = 4;
		break;
	}
}

void Shops::drawArmouryBoots(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment)
{
	screen.displayLeftText("Leather B.", 70, 528, fonts.font20);
	screen.displayLeftText("Chainmail B.", 370, 528, fonts.font20);
	screen.displayLeftText("King B.", 680, 528, fonts.font20);
	screen.displayLeftText("Apprentice B.", 70, 600, fonts.font20);
	screen.displayLeftText("Master B.", 370, 600, fonts.font20);
	screen.displayLeftText("return", 680, 600, fonts.font20);
	screen.displayLeftText("Your gold: " + to_string(player.gold), 30, 393, fonts.font18);
	switch (shopCursorPos) {
	case 1:
		screen.displayLeftText("Item cost: " + to_string(equipment.leatherBoots.bootsCost) + " Stat change: phyDef " + to_string(equipment.leatherBoots.bootsPhysDef - player.equippedBoots.bootsPhysDef) + " magAtt " + to_string(equipment.leatherBoots.bootsMagicDef - player.equippedBoots.bootsMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 528, fonts.font18);
		break;
	case 2:
		screen.displayLeftText("Item cost: " + to_string(equipment.chainmailBoots.bootsCost) + " Stat change: phyDef " + to_string(equipment.chainmailBoots.bootsPhysDef - player.equippedBoots.bootsPhysDef) + " magAtt " + to_string(equipment.chainmailBoots.bootsMagicDef - player.equippedBoots.bootsMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 528, fonts.font18);
		break;
	case 3:
		screen.displayLeftText("Item cost: " + to_string(equipment.kingBoots.bootsCost) + " Stat change: phyDef " + to_string(equipment.kingBoots.bootsPhysDef - player.equippedBoots.bootsPhysDef) + " magAtt " + to_string(equipment.kingBoots.bootsMagicDef - player.equippedBoots.bootsMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 656, 528, fonts.font18);
		break;
	case 4:
		screen.displayLeftText("Item cost: " + to_string(equipment.apprenticeBoots.bootsCost) + " Stat change: phyDef " + to_string(equipment.apprenticeBoots.bootsPhysDef - player.equippedBoots.bootsPhysDef) + " magAtt " + to_string(equipment.apprenticeBoots.bootsMagicDef - player.equippedBoots.bootsMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 46, 600, fonts.font18);
		break;
	case 5:
		screen.displayLeftText("Item cost: " + to_string(equipment.masterBoots.bootsCost) + " Stat change: phyDef " + to_string(equipment.masterBoots.bootsPhysDef - player.equippedBoots.bootsPhysDef) + " magAtt " + to_string(equipment.masterBoots.bootsMagicDef - player.equippedBoots.bootsMagicDef), 30, 433, fonts.font18);
		screen.displayLeftText(">", 346, 600, fonts.font18);
		break;
	case 6:
		screen.displayLeftText(">", 656, 600, fonts.font18);
		break;
	}
}

void Shops::armouryBoots(Player& player, int& combatCursorPos, Equipment equipment, int& armourCursorPos)
{
	switch (combatCursorPos) {
	case 1:
		if (player.gold >= equipment.leatherBoots.bootsCost) {
			player.equipBoots(equipment.leatherBoots);
			player.gold = player.gold - equipment.leatherBoots.bootsCost;
		}
		break;
	case 2:
		if (player.gold >= equipment.chainmailBoots.bootsCost) {
			player.equipBoots(equipment.chainmailBoots);
			player.gold = player.gold - equipment.chainmailBoots.bootsCost;
		}
		break;
	case 3:
		if (player.gold >= equipment.kingBoots.bootsCost) {
			player.equipBoots(equipment.kingBoots);
			player.gold = player.gold - equipment.kingBoots.bootsCost;
		}
		break;
	case 4:
		if (player.gold >= equipment.apprenticeBoots.bootsCost) {
			player.equipBoots(equipment.apprenticeBoots);
			player.gold = player.gold - equipment.apprenticeBoots.bootsCost;
		}
		break;
	case 5:
		if (player.gold >= equipment.masterBoots.bootsCost) {
			player.equipBoots(equipment.masterBoots);
			player.gold = player.gold - equipment.masterBoots.bootsCost;
		}
		break;
	case 6:
		armourCursorPos = 1;
		combatCursorPos = 5;
		break;
	}
}

bool Shops::shopEvent(Player & player, Screen & screen, int shop, Fonts fonts, Equipment equipment)
{
	bool gameExit = false;
	bool quit = false;
	int mouseX = 0;
	int mouseY = 0;
	vector <int> buttonXCombat = { 19, 327, 636, 19, 327, 636 };
	vector <int> buttonYCombat = { 481, 481, 481, 545, 545, 545 };
	int combatButtonHeight = 60;
	int combatButtonWidth = 306;
	int combatCursorPos = 1;	//The location of the cursor on screen
	int optionSelected = 1; //Menu option chosen
	int armouryPos = 1; //1 = Main Menu, 2 = Weapons, 3 = Helmet, 4 = Gauntlets, 5 = Chest, 6 = Boots
	if (!screen.loadMedia(screen.gBattleTextBox, "images/messageLong.bmp"));
	{
		//printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
#

	SDL_Event event;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			//Exit Window Event
			if (event.type == SDL_QUIT)
			{
				quit = true;
				gameExit = true;
			}

			//Mouse Motion Event
			if (event.type == SDL_MOUSEMOTION)
			{
				mouseX = event.motion.x;
				mouseY = event.motion.y;
				//Mose hover event
				for (size_t i = 0; i < buttonXCombat.size(); i++)
				{
					if (mouseX > buttonXCombat[i] && mouseX < buttonXCombat[i] + combatButtonWidth)
					{
						if (mouseY > buttonYCombat[i] && mouseY < buttonYCombat[i] + combatButtonHeight)
						{
							combatCursorPos = i + 1;
						}
					}
				}
			}

			//Left Click Event
			if (event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED)
			{
				for (int i = 0; i < buttonXCombat.size(); i++)
				{
					if (mouseX > buttonXCombat[i] && mouseX < buttonXCombat[i] + combatButtonWidth)
					{
						if (mouseY > buttonYCombat[i] && mouseY < buttonYCombat[i] + combatButtonHeight)
						{
							/*  Menu
							case 0		case 1		case 2
							case 3		case 4		case 5
							*/
							switch (shop)
							{
							case 0:
								switch (combatCursorPos) //Potion Shop
								{
								case 1:
									buyItem(player, 1); //Health Potion
									break;
								case 2:
									buyItem(player, 4); //Iron Skin Potion
									break;
								case 3:
									buyItem(player, 5); //Berserk Potion
									break;
								case 4:
									buyItem(player, 2); //Magic Potion
									break;
								case 5:
									buyItem(player, 3); //Smoke Bomb
									break;
								case 6:
									quit = true;
									break;
								}
								break;
							case 1:	//Sell Potion Shop
								switch (combatCursorPos) {
								case 1:
									sellItem(player, 1); //Health Potion
									break;
								case 2:
									sellItem(player, 4); //Iron Skin Potion
									break;
								case 3:
									sellItem(player, 5); //Berserk Potion
									break;
								case 4:
									sellItem(player, 2); //Magic Potion
									break;
								case 5:
									sellItem(player, 3); //Smoke Bomb
									break;
								case 6:
									quit = true;
									break;
								}
								break;
							case 2:	//Buy Hat Shop
								switch (combatCursorPos) {
								case 1:
									buyHatShop(player, "red");
									break;
								case 2:
									buyHatShop(player, "shadow");
									break;
								case 3:
									buyHatShop(player, "gold");
									break;
								case 4:
									buyHatShop(player, "cerulean");
									break;
								case 5:
									buyHatShop(player, "rainbow");
									break;
								case 6:
									quit = true;
									break;
								}
								break;
							case 3:
								switch (armouryPos) {
								case 1:
									armouryMainMenu(player, combatCursorPos, armouryPos, quit);
									break;
								case 2:
									armouryWeapon(player, combatCursorPos, equipment, armouryPos);
									break;
								case 3:
									armouryHelmet(player, combatCursorPos, equipment, armouryPos);
									break;
								case 4:
									armourGauntlets(player, combatCursorPos, equipment, armouryPos);
									break;
								case 5:
									armouryChestpiece(player, combatCursorPos, equipment, armouryPos);
									break;
								case 6:
									armouryBoots(player, combatCursorPos, equipment, armouryPos);
									break;
								}
							}
						}
					}
				}
				SDL_Delay(500);
			}

			//Keyboard Event
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT)
				{
					moveLeft(combatCursorPos, shop);
				}

				if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
				{
					moveRight(combatCursorPos, shop);
				}

				if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
				{
					moveDown(combatCursorPos, shop);
				}

				if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP)
				{
					moveUp(combatCursorPos, shop);
				}

				if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE)
				{
					switch (shop)
					{
					case 0:
						switch (combatCursorPos) //Potion Shop
						{
						case 1:
							buyItem(player, 1); //Health Potion
							break;
						case 2:
							buyItem(player, 4); //Iron Skin Potion
							break;
						case 3:
							buyItem(player, 5); //Berserk Potion
							break;
						case 4:
							buyItem(player, 2); //Magic Potion
							break;
						case 5:
							buyItem(player, 3); //Smoke Bomb
							break;
						case 6:
							quit = true;
							break;
						}
						break;
					case 1:	//Sell Potion Shop
						switch (combatCursorPos) {
						case 1:
							sellItem(player, 1); //Health Potion
							break;
						case 2:
							sellItem(player, 4); //Iron Skin Potion
							break;
						case 3:
							sellItem(player, 5); //Berserk Potion
							break;
						case 4:
							sellItem(player, 2); //Magic Potion
							break;
						case 5:
							sellItem(player, 3); //Smoke Bomb
							break;
						case 6:
							quit = true;
							break;
						}
						break;
					case 2:	//Buy Hat Shop
						switch (combatCursorPos) {
						case 1:
							buyHatShop(player, "red");
							break;
						case 2:
							buyHatShop(player, "shadow");
							break;
						case 3:
							buyHatShop(player, "gold");
							break;
						case 4:
							buyHatShop(player, "cerulean");
							break;
						case 5:
							buyHatShop(player, "rainbow");
							break;
						case 6:
							quit = true;
							break;
						}
						break;
					case 3:
						switch (armouryPos) {
						case 1:
							armouryMainMenu(player, combatCursorPos, armouryPos, quit);
							break;
						case 2:
							armouryWeapon(player, combatCursorPos, equipment, armouryPos);
							break;
						case 3:
							armouryHelmet(player, combatCursorPos, equipment, armouryPos);
							break;
						case 4:
							armourGauntlets(player, combatCursorPos, equipment, armouryPos);
							break;
						case 5:
							armouryChestpiece(player, combatCursorPos, equipment, armouryPos);
							break;
						case 6:
							armouryBoots(player, combatCursorPos, equipment, armouryPos);
							break;
						}
					}
				}


			}

			//Controller move event
			if (event.type == SDL_JOYHATMOTION)
			{
				if (event.jhat.value == SDL_HAT_LEFT)
				{
					moveLeft(combatCursorPos, shop);
				}

				if (event.jhat.value == SDL_HAT_RIGHT)
				{
					moveRight(combatCursorPos, shop);
				}

				if (event.jhat.value == SDL_HAT_UP)
				{
					moveUp(combatCursorPos, shop);
				}

				if (event.jhat.value == SDL_HAT_DOWN)
				{
					moveDown(combatCursorPos, shop);
				}
			}

			//Controller button event
			if (event.type == SDL_JOYBUTTONDOWN)
			{
				if (event.jbutton.button == 0)
				{
					if (armouryPos == 1)
						quit = true;
					else
						armouryPos = 1;
				}

				if (event.jbutton.button == 1)
				{
					switch (shop)
					{
					case 0:
						switch (combatCursorPos) //Potion Shop
						{
						case 1:
							buyItem(player, 1); //Health Potion
							break;
						case 2:
							buyItem(player, 4); //Iron Skin Potion
							break;
						case 3:
							buyItem(player, 5); //Berserk Potion
							break;
						case 4:
							buyItem(player, 2); //Magic Potion
							break;
						case 5:
							buyItem(player, 3); //Smoke Bomb
							break;
						case 6:
							quit = true;
							break;
						}
						break;
					case 1:	//Sell Potion Shop
						switch (combatCursorPos) {
						case 1:
							sellItem(player, 1); //Health Potion
							break;
						case 2:
							sellItem(player, 4); //Iron Skin Potion
							break;
						case 3:
							sellItem(player, 5); //Berserk Potion
							break;
						case 4:
							sellItem(player, 2); //Magic Potion
							break;
						case 5:
							sellItem(player, 3); //Smoke Bomb
							break;
						case 6:
							quit = true;
							break;
						}
						break;
					case 2:	//Buy Hat Shop
						switch (combatCursorPos) {
						case 1:
							buyHatShop(player, "red");
							break;
						case 2:
							buyHatShop(player, "shadow");
							break;
						case 3:
							buyHatShop(player, "gold");
							break;
						case 4:
							buyHatShop(player, "cerulean");
							break;
						case 5:
							buyHatShop(player, "rainbow");
							break;
						case 6:
							quit = true;
							break;
						}
						break;
					case 3:
						switch (armouryPos) {
						case 1:
							armouryMainMenu(player, combatCursorPos, armouryPos, quit);
							break;
						case 2:
							armouryWeapon(player, combatCursorPos, equipment, armouryPos);
							break;
						case 3:
							armouryHelmet(player, combatCursorPos, equipment, armouryPos);
							break;
						case 4:
							armourGauntlets(player, combatCursorPos, equipment, armouryPos);
							break;
						case 5:
							armouryChestpiece(player, combatCursorPos, equipment, armouryPos);
							break;
						case 6:
							armouryBoots(player, combatCursorPos, equipment, armouryPos);
							break;
						}
					}
				}
			}
		}//POLL EVENT WHILE
		SDL_BlitSurface(screen.gBattleTextBox, NULL, screen.gScreenSurface, 0);
		switch (shop)
		{
		case 0:
			drawBuyShop(screen, player, combatCursorPos, fonts);
			break;
		case 1:
			drawSellShop(screen, player, combatCursorPos, fonts);
			break;
		case 2:
			drawHatShop(screen, player, combatCursorPos, fonts);
			break;
		case 3:
			drawArmouryShop(screen, player, combatCursorPos, fonts, armouryPos, equipment);
			break;
		}
		SDL_UpdateWindowSurface(screen.gWindow);
	}
	SDL_FreeSurface(screen.gBattleTextBox);		//MEMORY FIX
	screen.gBattleTextBox = NULL;					//MEMORY FIX
	return gameExit;
}

void Shops::moveLeft(int & combatCursorPos, int & shop)
{
	switch (combatCursorPos - 1)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		break;
	case 1:
		combatCursorPos = 1;
		break;
	case 2:
		combatCursorPos = 2;
		break;
	case 3:
		break;
	case 4:
		combatCursorPos = 4;
		break;
	case 5:
		combatCursorPos = 5;
		break;
	}
}

void Shops::moveRight(int & combatCursorPos, int & shop)
{
	switch (combatCursorPos - 1)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		combatCursorPos = 2;
		break;
	case 1:
		combatCursorPos = 3;
		break;
	case 2:
		break;
	case 3:
		combatCursorPos = 5;
		break;
	case 4:
		combatCursorPos = 6;
		break;
	case 5:
		break;
	}
	
}

void Shops::moveUp(int & combatCursorPos, int & shop)
{
	switch (combatCursorPos - 1)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		combatCursorPos = 1;
		break;
	case 4:
		combatCursorPos = 2;
		break;
	case 5:
		combatCursorPos = 3;
		break;
	}
}

void Shops::moveDown(int & combatCursorPos, int & shop)
{
	switch (combatCursorPos - 1)  //{  0    1    2  }
	{						  //{  3    4    5  }
	case 0:
		combatCursorPos = 4;
		break;
	case 1:
		combatCursorPos = 5;
		break;
	case 2:
		combatCursorPos = 6;
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
}
