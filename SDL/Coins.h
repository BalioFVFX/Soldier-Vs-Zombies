#pragma once
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "Zombie.h"

class Coins
{
public:
	Coins();
	Coins(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY);
	~Coins();

	void Init();
	void SpawnCoin(SDL_Renderer *renderTarget, Coins coins[]);
	void UpdateCoin(Coins coins[], Zombie zombie[], float delta, unsigned int lastTime, int currentTime);
	int GetOriginX();
	int GetOriginY();
	int GetRadius();
	bool alive = false;
	bool pickedUp = false;
	SDL_Rect positionRect;

	std::fstream writeFile;
	int line;
	int coinsFromFille;


private:
	SDL_Surface * surface = nullptr;
	int originX;
	int originY;
	int radius;
	float frameCounter;
	bool isActive;
	int textureWidth;
	int frameWidth, frameHeight;
	SDL_Rect cropRect;
	int health = 100;
	int hit = true;
	SDL_Texture *texture;

	bool moving = true;
	float moveSpeed;

};

