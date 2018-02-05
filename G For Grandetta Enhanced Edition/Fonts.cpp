#include "Fonts.h"
#include "SDL.h"
#include "sdl_mixer.h"
#include "SDL_TTF.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>


Fonts::Fonts()
{


	TTF_Font* font18 = TTF_OpenFont("PressStart2P-Regular.ttf", 18);
	if (!font18) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
	
	TTF_Font* font20 = TTF_OpenFont("PressStart2P-Regular.ttf", 20);
	if (!font20) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
	
	TTF_Font* font24 = TTF_OpenFont("PressStart2P-Regular.ttf", 24);
	if (!font24) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}

	TTF_Font* font28 = TTF_OpenFont("PressStart2P-Regular.ttf", 28);
	if (!font28) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}

	TTF_Font* font48 = TTF_OpenFont("PressStart2P-Regular.ttf", 48);
	if (!font48) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
}


Fonts::~Fonts()
{
}

void Fonts::FreeFonts()
{
	TTF_CloseFont(font18);
	TTF_CloseFont(font20);
	TTF_CloseFont(font24);
	TTF_CloseFont(font28);
	TTF_CloseFont(font48);
	TTF_CloseFont(font18);
}
