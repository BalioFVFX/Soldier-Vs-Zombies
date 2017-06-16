#include "Coins.h"
#define Coins_NO 1000


Coins::Coins()
{
}

Coins::Coins(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY)
{

		surface = IMG_Load(filePath.c_str());

		texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		SDL_FreeSurface(surface);

		SDL_QueryTexture(texture, NULL, NULL, &cropRect.w, &cropRect.h);


		positionRect.x = x;
		positionRect.y = y;
		positionRect.w = 500;
		positionRect.h = 500;


		textureWidth = cropRect.w;

		cropRect.w /= framesX;
		cropRect.h /= framesY;

		frameWidth = positionRect.w = cropRect.w;
		frameHeight = positionRect.h = cropRect.h;

		originX = frameWidth / 2;
		originY = frameHeight / 2;
		radius = frameWidth / 2;

		isActive = false;

		moveSpeed = 200.0f;
}


Coins::~Coins()
{
}

int Coins::GetOriginX()
{
	return originX = positionRect.x;
}

int Coins::GetOriginY()
{
	return originY = positionRect.y;
}

int Coins::GetRadius()
{
	return radius;
}

void Coins::SpawnCoin(SDL_Renderer * renderTarget, Coins coins[])
{
	
		if (coins[0].alive == true)
		{
			SDL_RenderCopy(renderTarget, texture, &cropRect, &coins[0].positionRect);
		}
	

}

void Coins::UpdateCoin(Coins coins[], Zombie &zombie, float delta, unsigned int lastTime, int currentTime)
{
	for (int i = 0; i < 20; i++)
	{
		if (zombie.alive == false)
			if (coins[i].pickedUp == false)
			{
				coins[i].alive = true;
				coins[i].positionRect.x = zombie.zombieRect.x;
				coins[i].positionRect.y = zombie.zombieRect.y;
				coins[i].positionRect.w = 59;
				coins[i].positionRect.h = 59;
				break;
			}
		if (coins[i].pickedUp == true)
		{
			coins[i].alive = false;
		}
	}
	
		

		isActive = true;
		currentTime = SDL_GetTicks();

		if (currentTime > lastTime + 1)
		{

			lastTime = currentTime;


			cropRect.y = frameHeight;

			cropRect.y = frameHeight * 3;
		}
		else
		{
			isActive = false;
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

