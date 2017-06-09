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
	Text(SDL_Renderer * renderTarget, TTF_Font *text);
	~Text();
	SDL_Color White = { 255, 255, 255 };
	void ZombieTextDraw(SDL_Renderer * renderTarget, TTF_Font *text);
	void ZombieUpdateText(SDL_Renderer * renderTarget, TTF_Font * text, Zombie & zombie);
	void PlayerTextDraw(SDL_Renderer * renderTarget, TTF_Font *text);
	void PlayerUpdateText(SDL_Renderer * renderTarget, TTF_Font *text, Player &player);

private:
	TTF_Font * text;
	SDL_Renderer * renderTarget;

	//Zombie Stuff
	SDL_Rect zombieHealthRect; //Zombie Health Text
	SDL_Rect zombieHealthTextRect; //Zombie Digit Text

	SDL_Surface* ZombieHealthTextSurface;
	SDL_Texture* ZombieHealthTextTexture;
	SDL_Surface * ZombieHealthSurface;
	SDL_Texture * ZombieHealthTexture;

	std::stringstream zombieHealthSTREAM; //So we can convert INTEGER to STRING

	//Player Stuff
	SDL_Rect playerHealthRect;
	SDL_Rect playerHealthTextRect;

	SDL_Surface* PlayerHealthTextSurface;
	SDL_Texture* PlayerHealthTextTexture;
	SDL_Surface * PlayerHealthSurface;
	SDL_Texture * PlayerHealthTexture;

	std::stringstream playerHealthSTREAM; //So we can convert INTEGER to STRING

};

