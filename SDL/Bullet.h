#pragma once
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <string>
#include "Player.h"
class Bullet : public Player
{

public:
	Bullet() : Player() {};
#define Bullet_No = 4;
	Bullet(SDL_Renderer *renderTarget, std::string filePath);
	bool alive = 0; //For bullet alive checking
	SDL_Rect b; //For SDL Fill Rectangle
	char w, h; // The width & height of a bullet
	~Bullet();
	void init();
	void handleInput(Bullet bullet[], Player & player);
	void drawBulletche(SDL_Renderer * renderTarget, Bullet bullet[]);
private:
	SDL_Texture * texture;
	SDL_Renderer * renderTarget;
};

