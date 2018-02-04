#pragma once
class Fonts
{
public:
	Fonts();
	~Fonts();

	TTF_Font* font18;
	TTF_Font* font20;
	TTF_Font* font24;
	TTF_Font* font28;
	TTF_Font* font48;

	void FreeFonts();
};

