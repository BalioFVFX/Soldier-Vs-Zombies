#pragma once
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <string>
#include "Player.h"
class Bullet
{
	
public:
	Bullet();



	Bullet(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY);
	bool alive = 0; //For bullet alive checking
	SDL_Rect b; //For SDL Fill Rectangle
	~Bullet();
	void init();
	void handleInput(Bullet bullet[], Player & player);
	void drawBulletche(SDL_Renderer * renderTarget, Bullet bullet[]);
	int ammo = 0;
	int GetOriginX();
	int GetOriginY();
	int GetRadius();
	int GetNumber();
	int testAmmo = 0;
private:
	SDL_Texture * texture;
	SDL_Renderer * renderTarget;
	int frameWidth, frameHeight;
	int textureWidth;
	SDL_Rect cropRect;
	int originX;
	int originY;
	int radius;
	int number = 5;
};

