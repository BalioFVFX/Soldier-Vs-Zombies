#include "Bullet.h"




Bullet::Bullet(SDL_Renderer * renderTarget, std::string filePath)
{
	SDL_Surface *surface = IMG_Load(filePath.c_str());

	texture = SDL_CreateTextureFromSurface(renderTarget, surface);

	SDL_FreeSurface(surface);
	Bullet * bullet = new Bullet[4];
	b.x = 20;
	b.y = 20;
	b.w = 300;
	b.h = 300;
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
		bullet[i].w = 20;
		bullet[i].h = 5; //Bulet Size Configuration
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
			bullet[i].b.y = player.positionRect.y + 30;
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
			bullet[i].b.x += 5;
			bullet[i].b.w = bullet[i].w;
			bullet[i].b.h = bullet[i].h;
			SDL_RenderCopy(renderTarget, texture, NULL, &bullet[i].b);
		}

		if (bullet[i].b.x > 640)
		{
			bullet[i].alive = 0;
		}

	}


}
