#pragma once
#include "screen.h"
#include "player.h"
#include "fonts.h"
#include "equipment.h"
class Shops
{
public:
	Shops();
	~Shops();
	bool buyShop(Screen& screen, Player& player, Fonts& fonts, Equipment equipment);
	bool sellShop(Screen& screen, Player& player, Fonts& fonts, Equipment equipment);
	bool hatShop(Screen& screen, Player& player, Fonts& fonts, Equipment equipment);
	bool armouryShop(Screen& screen, Player& player, Fonts& fonts, Equipment equipment);
	

private:
	//Buy = 0, Sell = 1, Hat = 2, Armour = 3
	void drawBuyShop(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts);
	void buyItem(Player& player, int item);
	void buyShopMenu(Player& player, int cursor, bool& quit);
	void sellItem(Player& player, int item);
	void drawSellShop(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts);
	void drawHatShop(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts);
	void buyHatShop(Player& player, string hat, Screen& screen, Fonts& fonts);
	void armouryMainMenu(Player& player, int& combatCursorPos, int& armouryPos, bool& quit);
	void drawArmouryShop(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, int combatCursorPos, Equipment equipment);
	void drawArmouryMainMenu(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts);
	void drawArmouryWeapons(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment);
	void armouryWeapon(Player& player, int& combatCursorPos, Equipment equipment, int& armourCursorPos);
	void drawArmouryHelmet(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment);
	void armouryHelmet(Player& player, int& combatCursorPos, Equipment equipment, int& armourCursorPos);
	void drawArmouryGauntlets(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment);
	void armourGauntlets(Player& player, int& combatCursorPos, Equipment equipment, int& armourCursorPos);
	void drawArmouryChest(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment);
	void armouryChestpiece(Player& player, int& combatCursorPos, Equipment equipment, int& armourCursorPos);
	void drawArmouryBoots(Screen& screen, Player& player, int shopCursorPos, Fonts& fonts, Equipment equipment);
	void armouryBoots(Player& player, int& combatCursorPos, Equipment equipment, int& armourCursorPos);
	bool shopEvent(Player& player, Screen& screen, int shop, Fonts fonts, Equipment equipment);
	void moveLeft(int& combatCursorPos, int& shop);
	void moveRight(int& combatCursorPos, int& shop);
	void moveUp(int& combatCursorPos, int& shop);
	void moveDown(int& combatCursorPos, int& shop);
};

