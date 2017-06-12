#include "Zombie.h"



Zombie::Zombie(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY)
{
	if (alive == false)
	{
		delete this;
	}
	else
	{
		surface = IMG_Load(filePath.c_str());

		texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		SDL_FreeSurface(surface);

		SDL_QueryTexture(texture, NULL, NULL, &cropRect.w, &cropRect.h);


		zombieRect.x = x;
		zombieRect.y = y;


		zombieBulletRect.x = zombieRect.x;
		zombieBulletRect.y = zombieRect.y + 20;
		zombieBulletRect.w = 40;
		zombieBulletRect.h = 40;


		textureWidth = cropRect.w;

		cropRect.w /= framesX;
		cropRect.h /= framesY;

		frameWidth = zombieRect.w = cropRect.w;
		frameHeight = zombieRect.h = cropRect.h;

		originX = 0;
		originY = frameHeight / 2;
		radius = 5;

		bulletOriginX = frameWidth / 2;
		bulletOriginY = frameHeight / 2;
		bulletRadius = frameWidth / 2;

		isActive = false;
		isSecondActive = false;

		moveSpeed = 200.0f;
	}
	
}


Zombie::~Zombie()
{
	if (alive == false)
	{
		std::cout << "Destructor!";
	}

}

Zombie::Zombie()
{
}


void Zombie::Draw(SDL_Renderer *renderTarget)
{
	if (alive == false)
	{

	}
	else
	{
		SDL_RenderCopy(renderTarget, texture, &cropRect, &zombieRect);
	}
}

void Zombie::Update(Zombie & zombie, float delta, unsigned int lastTime, int currentTime)
{
	if (alive == true)
	{
	isActive = true;
	moveSpeed = 1;
	
		if (currentTime > lastTime)
		{

			lastTime = currentTime;

			if (moving == true)
			{
				cropRect.y = frameHeight;
				zombie.zombieRect.x -= moveSpeed * delta;

			}
			else
			{
				isActive = false;
			}
		}

		if (isActive)
		{
			frameCounter += delta;

			if (frameCounter >= 0.25f)
			{
				frameCounter = 0;
				cropRect.x += frameWidth;
				if (cropRect.x >= textureWidth)
				{
					cropRect.x = 0;
				}
			}
		}
		else
		{
			frameCounter = 0;
			cropRect.x = frameWidth;
		}
	}
}

void Zombie::Attack(SDL_Renderer * renderTarget, Zombie & zombie)
{
	if (zombie.alive == true)
	{
		currentTime = SDL_GetTicks();

		if (currentTime > lastTime + 0)
		{
			lastTime = currentTime;
			zombieBulletRect.x -= 10;
		}
		if (zombieBulletRect.x <= -752)
		{
			zombieBulletRect.x = zombie.zombieRect.x;
			zombieBulletRect.y = zombie.zombieRect.y + 20;
		}

		SDL_RenderCopy(renderTarget, texture, NULL, &zombieBulletRect);
	}
}


int Zombie::GetOriginX()
{
	return zombieRect.x + originX;
}

int Zombie::GetOriginY()
{
	return zombieRect.y + originY;
}

int Zombie::GetRadius()
{
	return radius;
}

int Zombie::GetBulletOriginX()
{
	return bulletOriginX + zombieBulletRect.x;
}

int Zombie::GetBulletOriginY()
{
	return bulletOriginY + zombieBulletRect.y;
}

int Zombie::GetBulletRadius()
{
	return bulletRadius;
}
