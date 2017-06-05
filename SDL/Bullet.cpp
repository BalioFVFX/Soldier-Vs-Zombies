#include "Bullet.h"




Bullet::Bullet()
{
}

Bullet::Bullet(SDL_Renderer * renderTarget, std::string filePath, int x, int y, int framesX, int framesY)
{
	SDL_Surface *surface = IMG_Load(filePath.c_str());

	texture = SDL_CreateTextureFromSurface(renderTarget, surface);

	SDL_FreeSurface(surface);
	
	textureWidth = cropRect.w;

	cropRect.w /= framesX;
	cropRect.h /= framesY;

	frameWidth = b.w = cropRect.w;
	frameHeight = b.h = cropRect.h;

	originX = frameWidth / 2;
	originY = frameHeight / 2;

	radius = frameWidth / 2;

}


Bullet::~Bullet()
{
}

void Bullet::init()
{
	Bullet * bullet = new Bullet[4];
	for (int i = 0; i < 4; i++)
	{
		bullet[i].alive = 0;

	}
}

void Bullet::handleInput(Bullet bullet[], Player & player)
{
	for (int i = 0; i < 4; i++)
	{
		if (!bullet[i].alive)
		{
			bullet[i].alive = 1;
			bullet[i].b.x = player.positionRect.x + 30;
			bullet[i].b.y = player.positionRect.y + 15;
			bullet[i].b.w = 30;
			bullet[i].b.h = 20;
			break;
		}
	}

}

void Bullet::drawBulletche(SDL_Renderer * renderTarget, Bullet bullet[])
{
	for (int i = 0; i < 4; i++)
	{
		if (bullet[i].alive)
		{
			bullet[i].b.x += 2;
			SDL_RenderCopy(renderTarget, texture, NULL, &bullet[i].b);
			ammo = i;
		}
		if (bullet[i].b.x > 640)
		{
			bullet[i].alive = 0;
		}

	}


}

int Bullet::GetOriginX()
{
	return b.x + originX;
}

int Bullet::GetOriginY()
{
	return b.y + originY;
}

int Bullet::GetRadius()
{
	return radius;
}

int Bullet::GetNumber()
{
	return number;
}
