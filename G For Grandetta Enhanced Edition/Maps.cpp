#include "Maps.h"



Maps::Maps()
{
	//Vector of Maps
	zone.push_back(MapZone(60, 35, "images/bg0.bmp")); //Villages 0
	zone.push_back(MapZone(90, 55, "images/bg1.bmp")); //Field 1
	zone.push_back(MapZone(90, 55, "images/bg2.bmp")); //Town 2
	zone.push_back(MapZone(60, 45, "images/bg3.bmp")); //Castle 3
	zone.push_back(MapZone(60, 45, "images/bg4.bmp")); //Goblin Camp 4
	zone.push_back(MapZone(30, 25, "images/bg5.bmp")); //Nursary 5
	zone.push_back(MapZone(60, 25, "images/bg6.bmp")); //Cave 6
	zone.push_back(MapZone(30, 25, "images/bg7.bmp")); //Casino 7

	//Village Collisions
	zone[0].collisions.push_back(Collision("villageTopWall", 0, 0, 60, 1, true, "sign", { "You see a tall hedge", "It seems to go on forever", "It would be impossible", "to squeeze through this foilage" }));
	zone[0].collisions.push_back(Collision("villageLeftWall", 0, 0, 1, 29, true, "sign", { "You see a tall hedge", "It seems to go on forever", "It would be impossible", "to squeeze through this foilage" }));
	zone[0].collisions.push_back(Collision("villageRightWall", 59, 0, 1, 29, true, "sign", { "You see a tall hedge", "It seems to go on forever", "It would be impossible", "to squeeze through this foilage" }));
	zone[0].collisions.push_back(Collision("villageBottomWallLeft", 0, 28, 9, 2, true, "sign", { "You see a tall hedge", "It seems to go on forever", "It would be impossible", "to squeeze through this foilage" }));
	zone[0].collisions.push_back(Collision("villageBottomWallRight", 13, 28, 47, 2, true, "sign", { "You see a tall hedge", "It seems to go on forever", "It would be impossible", "to squeeze through this foilage" }));
	zone[0].collisions.push_back(Collision("villageHouse1", 20, 12, 5.75, 5, true, "sign", { "The village is silent", "Likewise is this house", "It appears no one is home" }));
	zone[0].collisions.push_back(Collision("villageHouse2", 33, 12, 5.5, 5, true, "sign", { "The house is eerily deserted", "The family that used to live here is", "nowhere to be seen..." }));
	zone[0].collisions.push_back(Collision("villageChest", 28, 1, 1, 1, true, "chest", {"", "" }, "chestFunction"));
	zone[0].collisions.push_back(Collision("villageLeftFence", 8, 25, 1, 3, true, "sign", { "You see a fence", "It looks handcrafted", "A fine specimen" }));
	zone[0].collisions.push_back(Collision("villageRightFence", 13, 25, 1, 3, true, "sign", { "You see a fence", "", "You wonder how well fence", "building pays these days", "Probably best not to dwell on it" }));
	zone[0].collisions.push_back(Collision("villageTopLeftFence", 1, 8, 9, 1, true, "sign", { "You see a fence", "It's a fence alright", "Don't make these like they used to" }));
	zone[0].collisions.push_back(Collision("villageTopRightFence", 12, 0, 1, 9, true, "sign", { "You see a fence", "", "You try to recall a poem about", "about a fence you once heard", "...", "", ".........", "", "You can't remember how it goes" }));
	zone[0].collisions.push_back(Collision("villageGransTopRightFence", 50, 1, 1, 4, true, "sign", { "You see a fence", "", "Grandma loved this fence" }));
	zone[0].collisions.push_back(Collision("villageGransMiddleLeftFence", 50, 7, 1, 5, true, "sign", { "You see a fence", "", "Grandma loved this fence" }));
	zone[0].collisions.push_back(Collision("villageGransMiddleFence", 51, 9, 7, 1, true, "sign", { "You see a fence", "", "Fences are the backbone", "of the economy" }));
	zone[0].collisions.push_back(Collision("villageGransBottomFence", 50, 14, 9, 1, true, "sign", { "You see a fence", "Wood, wood and more wood" }));
	zone[0].collisions.push_back(Collision("villageGrave1", 2, 2, 1, 1, true, "sign", { "The grave reads:", "Anthony D. 1998 - 2018", "You recall not so fond memories"} ));
	zone[0].collisions.push_back(Collision("villageGrave2", 4, 2, 1, 1, true, "sign", { "The grave reads:", "Jack C. 1997 - 2018", "You recall fond memories" } ));
	zone[0].collisions.push_back(Collision("villageGrave3", 6, 2, 1, 1, true, "sign", { "It's hard to read..." , "Something about someone called Ethan", "You've never heard of them"}));
	zone[0].collisions.push_back(Collision("villageGransGrave", 9, 2, 1, 1, true, "sign", { "The grave reads:", "RIP Grandma", "You see it has been disturbed" }));
	zone[0].collisions.push_back(Collision("villageHomeRightWall", 58, 2, 1, 10, true, "sign", { "You see a tall hedge", "It seems to go on forever", "It would be impossible", "to squeeze through this foilage" }));
	zone[0].collisions.push_back(Collision("villageHomeBed", 55, 1, 1.5, 2, true, "sign", { "You inspect Grandma's old bed","As you would expect the bed is cold" }));
	zone[0].collisions.push_back(Collision("villageHomeBottomWall", 54, 5.5, 10, 9, true, "sign", { "The house looks empty", "The house sounds empty", "It even smells empty!" }));
	zone[0].collisions.push_back(Collision("villageHomeLeftWall", 54, 1, 1, 3, true, "sign", { "It's a wall", "There's no two ways about it" }));
	
	
	

	//Field Collisions
	zone[1].collisions.push_back(Collision("fieldLeftFencePath", 8, 0, 0.5, 34, false, "none"));
	zone[1].collisions.push_back(Collision("fieldRightFencePath", 13, 0, 1, 6, false, "none"));
	zone[1].collisions.push_back(Collision("fieldBottomFencePath", 9, 10, 9, 1, false, "none"));
	zone[1].collisions.push_back(Collision("fieldFenceSign", 14, 5, 4, 1, true, "sign"));
	zone[1].collisions.push_back(Collision("fieldVillageSign", 18, 5, 1, 1, true, "sign", { "The sign reads:", "To the Village" }));
	zone[1].collisions.push_back(Collision("fieldCaveEntrance", 1, 30, 7, 1, false, "none"));
	zone[1].collisions.push_back(Collision("fieldTopWall", 14, 0, 89, 1, false, "none"));
	zone[1].collisions.push_back(Collision("fieldCaveSign", 4, 34, 1, 1, true, "sign", { "The sign reads:", "To the Cave" }));
	zone[1].collisions.push_back(Collision("fieldCaveLeftFence", 0, 31, 1, 6, false, "none"));
	zone[1].collisions.push_back(Collision("fieldLeftMoat", 0, 37, 39, 13, false, "none"));
	zone[1].collisions.push_back(Collision("fieldRightMoat", 44, 37, 46, 13, false, "none"));
	zone[1].collisions.push_back(Collision("fieldCastleSign", 38, 34, 1, 1, true, "sign", { "The sign reads:", "To Castletown" }));
	zone[1].collisions.push_back(Collision("fieldTopField", 48, 3, 23, 12, false, "none"));
	zone[1].collisions.push_back(Collision("fieldBottomField", 48, 20, 23, 12, false, "none"));
	zone[1].collisions.push_back(Collision("fieldTopRightHedge", 89, 1, 1, 15, false, "none"));
	zone[1].collisions.push_back(Collision("fieldTopRightHedge", 89, 20, 1, 17, false, "none"));
	zone[1].collisions.push_back(Collision("fieldCampSign", 78, 17, 1, 1, true, "sign", { "The sign reads:", "To the Goblin Camp" }));
	zone[1].collisions.push_back(Collision("fieldTopTents", 83, 13, 6, 3, false, "none"));
	zone[1].collisions.push_back(Collision("fieldBottomTents", 83, 20, 6, 3, false, "none"));

	//Town Collisons
	zone[2].collisions.push_back(Collision("townTopLeftWall", 0, 0, 39, 2, false, "none"));
	zone[2].collisions.push_back(Collision("townTopCourtYard", 0, 0, 32, 17, false, "none"));
	zone[2].collisions.push_back(Collision("townLeftWall", 0, 0, 2, 50, false, "none"));
	zone[2].collisions.push_back(Collision("townBuyStall", 9, 25, 2, 2, true, "buyShop"));
	zone[2].collisions.push_back(Collision("townSellStall", 13, 25, 2, 2, true, "sellShop"));
	zone[2].collisions.push_back(Collision("townHatsStall", 9, 29, 2, 2, true, "hatShop"));
	zone[2].collisions.push_back(Collision("townArmourStall", 13, 29, 2, 2, true, "equipShop"));
	zone[2].collisions.push_back(Collision("townMarketSign", 19, 27, 1, 1, true, "sign", { "The sign reads:", "The Market" }));
	zone[2].collisions.push_back(Collision("townBottomLeftCourtYard", 0, 38, 32, 11, false, "none"));
	zone[2].collisions.push_back(Collision("townBottomLeftWall", 0, 48, 39, 2, false, "none"));
	zone[2].collisions.push_back(Collision("townCastleSign", 38, 45, 1, 1, true, "sign", { "The sign reads:", "To the Castle" }));
	zone[2].collisions.push_back(Collision("townTopRightWall", 44, 0, 7, 2, false, "none"));
	zone[2].collisions.push_back(Collision("townLake", 34, 25, 15, 8, false, "none"));
	zone[2].collisions.push_back(Collision("townTopRightCourtYard", 51, 0, 31, 12, false, "none"));
	zone[2].collisions.push_back(Collision("townCasino", 82, 4, 6, 1, false, "none"));
	zone[2].collisions.push_back(Collision("townRightWall", 88, 0, 2, 50, false, "none"));
	zone[2].collisions.push_back(Collision("townChest", 82, 10, 1, 1, true, "chest", { "", "" }, "chestFunction"));
	zone[2].collisions.push_back(Collision("townCasinoLeftFence", 82, 11, 3, 1, false, "none"));
	zone[2].collisions.push_back(Collision("townCasinoRightFence", 87, 11, 1, 1, false, "none"));
	zone[2].collisions.push_back(Collision("townBottomRightHouses", 52, 30, 38, 19, false, "none"));
	zone[2].collisions.push_back(Collision("townBottomLeftHouses", 46, 38, 6, 10, false, "none"));
	zone[2].collisions.push_back(Collision("townBottomRightWall", 44, 48, 2, 2, false, "none"));
	zone[2].collisions.push_back(Collision("townTopRightHouses", 54, 13, 30, 15, false, "none"));


	//Castle Collisions
	zone[3].collisions.push_back(Collision("castleTopLeftWall", 0, 0, 39, 19, false, "none"));
	zone[3].collisions.push_back(Collision("castleLeftWall", 0, 0, 10, 45, false, "none"));
	zone[3].collisions.push_back(Collision("castleTopThrone", 14, 25, 1, 2, true, "quest", { "I was informed of the incident.", "Talk to the wizard over yonder." }, "kingFunction"s));
	zone[3].collisions.push_back(Collision("castleBottomThrone", 14, 28, 1, 2, false, "none"));
	zone[3].collisions.push_back(Collision("castleBottomWall", 0, 37, 60, 1, false, "none"));
	zone[3].collisions.push_back(Collision("castleBedrooms", 44, 0, 9, 25, false, "none"));
	zone[3].collisions.push_back(Collision("castleBedroomOutcrop", 44, 25, 2, 1, false, "none"));
	zone[3].collisions.push_back(Collision("castleWizardWall", 44, 30, 2, 8, false, "none"));
	zone[3].collisions.push_back(Collision("castleWizard", 55, 32, 1, 2, true, "quest", { "Who are you? I'm in the middle of ", "important work, leave please." }, "wizFunction"));
	zone[3].collisions.push_back(Collision("castleRightWall", 58, 0, 1, 40, false, "none"));
	zone[3].collisions.push_back(Collision("castlePrincessWall", 55, 24, 2, 1, true, "sign", { "Looks like she's sleeping...", "I shouldn't disturb her." }));
	zone[3].collisions.push_back(Collision("castleRightWallOutcrop", 57, 24, 1, 1, false, "none"));
	zone[3].collisions.push_back(Collision("castleLeftWallOutcrop", 53, 24, 2, 1, false, "none"));
	zone[3].collisions.push_back(Collision("castleTopBedroomWall", 52, 18, 10, 1, false, "none"));
	zone[3].collisions.push_back(Collision("castlePrincessBed", 55, 19, 2, 2, true, "sign", { "I just need to get that necklace.", "I'm sure she won't miss it." }));

	//Goblin Camp Collisons
	zone[4].collisions.push_back(Collision("1,1Tent", 10, 16, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("2,1Tent", 13, 9, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("2,2Tent", 13, 24, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("leftWall", 0, 0, 1, 35, false, "none"));
	zone[4].collisions.push_back(Collision("topWall", 0, 0, 59, 1, false, "none"));
	zone[4].collisions.push_back(Collision("rightWall", 59, 0, 1, 39, false, "none"));
	zone[4].collisions.push_back(Collision("bottomWall", 0, 39, 59, 39, false, "none"));
	zone[4].collisions.push_back(Collision("3,1Tent", 20, 3, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("4,1Tent", 24, 28, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("goblinNursery", 27, 2, 8, 4, false, "none"));
	zone[4].collisions.push_back(Collision("5,1Tent", 37, 30, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("6,1Tent", 39, 3, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("7,1Tent", 41, 36, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("8,1Tent", 43, 15, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("8,2Tent", 43, 25, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("9,1Tent", 50, 6, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("9,2Tent", 50, 15, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("9,3Tent", 50, 25, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("10,1Tent", 53, 31, 3, 3, false, "none"));
	zone[4].collisions.push_back(Collision("goblinChest", 48, 33, 1, 1, true, "quest", { "You try to take the goblin staff", "But a goblin appears and stops you" }, "campChestFunc"));

	//Nursary Collsions
	zone[5].collisions.push_back(Collision("nursaryLeftWall", 0, 0, 10, 19, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryLeftOutcrop", 9, 20, 5, 1, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryTopWall", 10, 13, 12, 1, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryChest", 10, 14, 1, 1, true, "chest", { "", "" }, "chestFunction"));
	zone[5].collisions.push_back(Collision("nursaryRightOutcrop", 16, 20, 10, 1, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryRightWall", 20, 14, 1, 10, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryTopLeftCot", 10, 15, 2, 1, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryMiddleLeftCot", 10, 17, 2, 1, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryBottomLeftCot", 10, 19, 2, 1, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryTopRightCot", 18, 15, 2, 1, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryMiddleRightCot", 18, 17, 2, 1, false, "none"));
	zone[5].collisions.push_back(Collision("nursaryBottomRightCot", 18, 19, 2, 1, false, "none"));

	//Cave Collisions
	zone[6].collisions.push_back(Collision("caveTopLeftWall", 0, 0, 41, 8, false, "none"));
	zone[6].collisions.push_back(Collision("caveTopBridge", 8, 8, 33, 1, false, "none"));
	zone[6].collisions.push_back(Collision("caveTopRightWall", 41, 0, 20, 1, false, "none"));
	zone[6].collisions.push_back(Collision("caveTopRightWall", 59, 0, 1, 19, false, "none"));
	zone[6].collisions.push_back(Collision("caveBottomRightOutcrop", 58, 19, 1, 1, false, "none"));
	zone[6].collisions.push_back(Collision("caveBottom", 8, 11, 33, 20, false, "none"));
	zone[6].collisions.push_back(Collision("caveBottomRightOutcrop", 41, 19, 14, 1, false, "none"));
	zone[6].collisions.push_back(Collision("caveLeftWall", 0, 6, 2, 20, false, "none"));
	zone[6].collisions.push_back(Collision("caveBottomLeftWall", 1, 18, 15, 1, false, "none"));
	zone[6].collisions.push_back(Collision("caveChest", 3, 16, 1, 1, true, "quest", { "You try to take the orb", "But the spider protecting it appears" }, "caveChestFunc"));

	//Casino Collisions
	zone[7].collisions.push_back(Collision("casinoLeftWall", 0, 0, 1, 20, false, "none"));
	zone[7].collisions.push_back(Collision("casinoBottomLeftOutcrop", 0, 19, 3, 1, false, "none"));
	zone[7].collisions.push_back(Collision("casinoBottomRightWall", 5, 19, 29, 1, false, "none"));
	zone[7].collisions.push_back(Collision("casinoTopWall", 0, 0, 29, 3, false, "none"));
	zone[7].collisions.push_back(Collision("casinoBar", 12, 3, 9, 1, false, "none"));
	zone[7].collisions.push_back(Collision("casinoRightWall", 29, 0, 1, 18, false, "none"));
	zone[7].collisions.push_back(Collision("casinoWheelSpinner", 4, 3, 5, 5, false, "none"));
	zone[7].collisions.push_back(Collision("casinoTopFruits", 23, 5, 6, 2, false, "none"));
	zone[7].collisions.push_back(Collision("casinoBottomFruits", 23, 9, 6, 2, false, "none"));
	zone[7].collisions.push_back(Collision("casinoLeftTable", 8, 15, 3, 2, false, "none"));
	zone[7].collisions.push_back(Collision("casinoMiddleTable", 16, 15, 3, 2, false, "none"));
	zone[7].collisions.push_back(Collision("casinoRightTable", 24, 15, 3, 2, false, "none"));
}




Maps::~Maps()
{
}

int Maps::findCollision(MapZone mapZone, string name)
{
	bool found = false;
	int i = 0;
	while (found == false && i < mapZone.collisions.size())
	{
		if (mapZone.collisions[i].name == name)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
		return i;
	else
	{
		return -1;
	}
}

void Maps::removeItem(int map, string name)
{
	int pos = findCollision(zone[map], name);
	if (pos != -1)
	{
		zone[map].collisions.erase(zone[map].collisions.begin() + pos);
	}
}
