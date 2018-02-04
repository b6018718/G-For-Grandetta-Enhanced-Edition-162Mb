#include "Music.h"
#include <vector>
#include <iostream>
using namespace std;

Music::Music()
{
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

	field = Mix_LoadMUS("sound/field.mp3");
	if (field == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	menu = Mix_LoadMUS("sound/menu.mp3");
	if (menu == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	village = Mix_LoadMUS("sound/village.mp3");
	if (village == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	hit = Mix_LoadWAV("sound/hit.wav");
	if (hit == NULL)
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());

	rat = Mix_LoadWAV("sound/rat.wav");
	if (rat == NULL)
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
	Mix_PlayMusic(field, -1);
}

void Music::PlayVillage()
{
	Mix_PlayMusic(village, -1);
}

void Music::PlayMenu()
{
	Mix_PlayMusic(menu, -1);
}

void Music::PlayRat()
{
	Mix_PlayChannel(-1, rat, 0);
}

void Music::PlayHit()
{
	Mix_PlayChannel(-1, hit, 0);
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
}

void Music::SetVolume(float volume)  //Volume should be a number equal or between 0 and 10
{
	if (volume >= 0 && volume <= 10)
	{
		int intVol = (int) floor((volume / 10) * 128);
		//int intVol = floor(volume);
		Mix_VolumeMusic(intVol);
		Mix_Volume(-1, intVol);
	}
}
