#include "Bullet.h"
#define Bullet_No 4



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

	this->originX = 12;
	this->originY = 12;
	this->radius = 12;


}


Bullet::~Bullet()
{
}

//Not begin used?
void Bullet::init()
{
	Bullet * bullet = new Bullet[4];
	for (int i = 0; i < 4; i++)
	{
		bullet[i].alive = 0;


	}
}

void Bullet::HandleInput(Bullet bullet[], Player & player)
{
	if (player.facingRight == true)
	{
		for (int i = 0; i < Bullet_No; i++)
		{
			if (!bullet[i].alive)
			{
				bullet[i].updatingRight = true;
				bullet[i].alive = 1;
				bullet[i].b.x = player.positionRect.x + 30;
				bullet[i].b.y = player.positionRect.y + 15;
				bullet[i].b.w = 30;
				bullet[i].b.h = 20;
				break;
			}
		}
	}
}

void Bullet::HandleInputLeft(Bullet bullet[], Player & player)
{
	if (player.facingLeft == true)
	{
		for (int i = 0; i < Bullet_No; i++)
		{
			if (!bullet[i].alive)
			{
				bullet[i].updatingLeft = true;
				bullet[i].alive = 1;
				bullet[i].b.x = player.positionRect.x + 30;
				bullet[i].b.y = player.positionRect.y + 15;
				bullet[i].b.w = 30;
				bullet[i].b.h = 20;
				break;
			}
		}
	}
}

void Bullet::Draw(SDL_Renderer * renderTarget, Bullet bullet[], Player &player)
{
	for (int i = 0; i < Bullet_No; i++)
	{
	if (bullet[i].updatingRight == true)
	{
				if (bullet[i].alive)
				{
					std::cout << "RIGHT: " << bullet[i].updatingRight << std::endl;
					std::cout << "LEFT: " << bullet[i].updatingLeft << std::endl;
					bullet[i].b.x += 5;
					SDL_RenderCopy(renderTarget, texture, NULL, &bullet[i].b);
				}
				if (bullet[i].b.x > 700)
				{
					bullet[i].alive = 0;
					bullet[i].updatingRight = false;
				}
			}
		}
}

void Bullet::DrawLeft(SDL_Renderer * renderTarget, Bullet bullet[], Player & player)
{
	for (int i = 0; i < Bullet_No; i++)
	{
	if (bullet[i].updatingLeft == true)
	{
			if (bullet[i].alive)
			{
				std::cout << "RIGHT: " << bullet[i].updatingRight << std::endl;
				std::cout << "LEFT: "<< bullet[i].updatingLeft << std::endl;
				bullet[i].b.x -= 5;
				SDL_RenderCopy(renderTarget, texture, NULL, &bullet[i].b);
			}
			if (bullet[i].b.x < - 70)
			{
				bullet[i].alive = 0;
				bullet[i].updatingLeft = false;
			}
		
		}
	}

}

int Bullet::GetOriginX()
{
	return b.x + 12; //Problem..
					//First made a object from Player class for the bullet, then had calculation framewidth /2 , frameheight / 2, radius / 2, So we have 12
					//Bullet constructor is not able to make the calculation.. ?
}

int Bullet::GetOriginY()
{
	return b.y + 12;
}

int Bullet::GetRadius()
{
	return 12;
}

