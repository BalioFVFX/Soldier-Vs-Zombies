#pragma once
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include "Player.h"
#include "Zombie.h"

class Coins
{
public:
	Coins(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY);
	~Coins();

	void SpawnCoin(SDL_Renderer *renderTarget);
	void UpdateCoin(Coins &coin, Zombie & zombie, float delta, unsigned int lastTime, int currentTime);
private:
	SDL_Surface * surface = nullptr;
	float frameCounter;
	bool isActive;
	int textureWidth;
	int frameWidth, frameHeight;
	SDL_Rect cropRect;
	int health = 100;
	int hit = true;
	SDL_Texture *texture;
	SDL_Rect positionRect;
	bool moving = true;
	float moveSpeed;
	bool spawnCoin = false;
};

