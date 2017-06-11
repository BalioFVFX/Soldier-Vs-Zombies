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
	~Bullet();
	
	bool alive = 0; //For bullet alive checking
	SDL_Rect b; //For SDL Fill Rectangle
	
	void init();
	void HandleInput(Bullet bullet[], Player & player);
	void HandleInputLeft(Bullet bullet[], Player &player);
	void Draw(SDL_Renderer * renderTarget, Bullet bullet[], Player &player);
	void DrawLeft(SDL_Renderer *renderTarget, Bullet bullet[], Player &player);
	int bullets = 4;
	int counter = 0;
	bool movingRight = false;
	bool updatingRight = false;
	bool facingRight = false;
	bool movingLeft = false;
	bool updatingLeft = false;
	bool facingLeft = false;
	int GetOriginX();
	int GetOriginY();
	int GetRadius();
private:
	SDL_Texture * texture;
	SDL_Renderer * renderTarget;
	SDL_Rect cropRect;
	int frameWidth, frameHeight;
	int textureWidth;
	
	int originX;
	int originY;
	int radius;
};

