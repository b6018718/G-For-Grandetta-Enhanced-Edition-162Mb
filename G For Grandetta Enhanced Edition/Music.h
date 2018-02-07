#pragma once
#include "SDL.h"
#include "sdl_mixer.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <vector>


using namespace std;

class Music
{
public:
	Music();
	~Music();

	void PlayBattle();
	void PlayCamp();
	void PlayCasino();
	void PlayCastle();
	void PlayCastleTown();
	void PlayCave();
	void PlayField();
	void PlayVillage();
	void PlayMenu();

	void PlayRat();
	void PlayHit();

	void PauseMusic();
	void ResumeMusic();
	void HaltMusic();

	void FreeSounds();

	void SetVolume(float volume);

private:
	Mix_Music *battle;
	Mix_Music *camp;
	Mix_Music *casino;
	Mix_Music *castle;
	Mix_Music *castletown;
	Mix_Music *cave;
	Mix_Music *field;
	Mix_Music *village;
	Mix_Music *menu;

	Mix_Chunk *hit;
	Mix_Chunk *rat;

};

