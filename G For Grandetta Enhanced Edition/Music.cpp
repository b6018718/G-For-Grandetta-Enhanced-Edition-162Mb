#include "Music.h"
#include <vector>
#include <iostream>
using namespace std;

Music::Music()
{
	//Initialize SDL_mixer
	if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}

	battle = Mix_LoadMUS("sound/battle.mp3");
	if (battle == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	
	camp = Mix_LoadMUS("sound/camp.mp3");
	if (camp == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	casino = Mix_LoadMUS("sound/casino.mp3");
	if (casino == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	castle = Mix_LoadMUS("sound/castle.mp3");
	if (castle == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	castletown = Mix_LoadMUS("sound/castletown.mp3");
	if (castletown == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	cave = Mix_LoadMUS("sound/cave.mp3");
	if (cave == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	menu = Mix_LoadMUS("sound/menu.ogg");
	if (menu == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	goodend= Mix_LoadMUS("sound/goodend.mp3");
	if (menu == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	badend = Mix_LoadMUS("sound/badend.mp3");
	if (menu == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());


	hit = Mix_LoadWAV("sound/hit.wav");
	if (hit == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	rat = Mix_LoadWAV("sound/rat.wav");
	if (rat == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	encounter = Mix_LoadWAV("sound/encounter.wav");
	if (encounter == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	heal = Mix_LoadWAV("sound/heal.wav");
	if (encounter == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	magic = Mix_LoadWAV("sound/magic.wav");
	if (encounter == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
}


Music::~Music()
{
	
}

void Music::PlayBattle()
{
	Mix_PlayMusic(battle, -1);
}

void Music::PlayCamp()
{
	Mix_PlayMusic(camp, -1);
}

void Music::PlayCasino()
{
	Mix_PlayMusic(casino, -1);
}

void Music::PlayCastle()
{
	Mix_PlayMusic(castle, -1);
}

void Music::PlayCastleTown()
{
	Mix_PlayMusic(castletown, -1);
}

void Music::PlayCave()
{
	Mix_PlayMusic(cave, -1);
}

void Music::PlayField()
{
	field = Mix_LoadMUS("sound/field.mp3");
	if (field == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	Mix_PlayMusic(field, -1);
}

void Music::PlayVillage()
{
	village = Mix_LoadMUS("sound/village.mp3");
	if (village == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	Mix_PlayMusic(village, -1);
}



void Music::PlayMenu()
{
	Mix_PlayMusic(menu, -1);
}

void Music::PlayGoodEnd()
{
	Mix_PlayMusic(goodend, -1);
}

void Music::PlayBadEnd()
{
	Mix_PlayMusic(badend, -1);
}

void Music::PlayRat()
{
	Mix_PlayChannel(-1, rat, 0);
}

void Music::PlayHit()
{
	Mix_PlayChannel(-1, hit, 0);
}

void Music::PlayEncounter()
{
	Mix_PlayChannel(-1, encounter, 0);
}

void Music::PlayHeal()
{
	Mix_PlayChannel(-1, heal, 0);
}

void Music::PlayMagic()
{
	Mix_PlayChannel(-1, magic, 0);
}

void Music::PauseMusic()
{
	Mix_PauseMusic();
}

void Music::ResumeMusic()
{
	Mix_ResumeMusic();
}

void Music::HaltMusic()
{
	Mix_HaltMusic();
}

void Music::PlayMap(int map)
{
	switch (map)
	{
	case 0:
		PlayVillage();
		break;
	case 1:
		PlayField();
		break;
	case 2:
		PlayCastleTown();
		break;
	case 3:
		PlayCastle();
		break;
	case 4:
		PlayCamp();
		break;
	case 5:
		PlayCamp();
		break;
	case 6:
		PlayCave();
		break;
	case 7:
		PlayCasino();
		break;
	}
}

void Music::FreeSounds()
{
	Mix_FreeMusic(battle);
	Mix_FreeMusic(camp);
	Mix_FreeMusic(casino);
	Mix_FreeMusic(castle);
	Mix_FreeMusic(castletown);
	Mix_FreeMusic(cave);
	Mix_FreeMusic(field);
	Mix_FreeMusic(menu);
	Mix_FreeMusic(village);
	
	Mix_FreeChunk(hit);
	Mix_FreeChunk(rat);
	Mix_FreeChunk(encounter);
}

void Music::SetVolume(float newVolume)  //Volume should be a number equal or between 0 and 10
{
	if (newVolume >= 0 && newVolume <= 10)
	{
		int intVol = (int)  floor((newVolume / 10) * 128);
		Mix_VolumeMusic(intVol);
		Mix_Volume(-1, intVol);
		volume = newVolume;
	}
}
