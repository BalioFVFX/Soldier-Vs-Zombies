#pragma once
#include "Zombie.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <SDL\SDL_ttf.h>
class Text
{
public:
	Text();
	~Text();
	SDL_Color White = { 255, 255, 255 };
	void TextDraw(SDL_Renderer * renderTarget, TTF_Font *text);
	void UpdateText(SDL_Renderer * renderTarget, TTF_Font * text, Zombie & zombie);
	int chislo = 100;

private:
	SDL_Rect healthTextRectche;
	SDL_Surface* ZombieHealthTextSurfaceche;
	SDL_Texture* ZombieHealthTextTextureche;
	SDL_Surface * ZombieHealthSurface;
	SDL_Texture * ZombieHealthTexture;
	SDL_Renderer * renderTarget;
	SDL_Rect ZombieHealthRect;
	std::stringstream zombiehealthSTREAM;
	
};

