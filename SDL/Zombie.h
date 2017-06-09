#pragma once
#include <iostream>
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <string>
#include "Bullet.h"

class Zombie
{
public:
	Zombie();
	Zombie(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY);
	~Zombie();
	void Draw(SDL_Renderer * renderTarget);
	void Update(Zombie & zombie, float delta, unsigned int lastTime, int currentTime);
	void Attack(SDL_Renderer * renderTarget, Zombie & zombie);
	SDL_Rect zombieRect;
	int GetOriginX();
	int GetOriginY();
	int GetRadius();
	SDL_Texture *texture;
	bool alive = true;
	int health = 100;
	bool hit = true;
private:
	int originX;
	int originY;
	int radius;
	
	SDL_Rect zombieBulletRect;
	SDL_Rect cropRect;
	
	SDL_Surface *surface;
	float moveSpeed;
	float frameCounter;
	int frameWidth, frameHeight;
	bool isActive;
	bool isSecondActive;
	bool isSecondMoving = true;
	int textureWidth;
	bool running = true;
	bool fired = false;
	bool moving = true;

	unsigned int lastTime = 0, currentTime;
};

