#include <iostream>
#include <vector>
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
class Bullet
{
public:
	static const int BULLET_WIDTH = 15;
	static const int BULLET_HEIGHT = 25;
	static const int BULLET_VEL = 5;
	SDL_Event event;
	Bullet();
	SDL_Renderer * renderer;

	//xFire, yFire - position relative to player
	void handle_input(int xFire, int yFire);

	void bullet_render(); //renders bullet
	void bullet_move(); //moves bullet

	bool isAlive;

private:

	//bullet offsets
	int bullet_x, bullet_y;

	//velocity of bullets
	int velX, velY;
};
std::vector<Bullet> bullets;

Bullet::Bullet()
{
	isAlive = false;

	bullet_x = 0;
	bullet_y = 0;

	velX = 0;
	velY = BULLET_VEL;
}

void Bullet::handle_input(int xFire, int yFire)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_z)
	{
		Bullet b;
		bullet_x = xFire;
		bullet_y = yFire;
		isAlive = true;
		bullets.push_back(b);
	}
}

void Bullet::bullet_move()
{
	if (isAlive == false) return; //do nothing

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].bullet_x += velX;
		bullets[i].bullet_y -= velY;
	}

	//if bullet goes off screen, delete
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].bullet_y -= velY;
	}

}

void Bullet::bullet_render()
{
	if (isAlive == true)
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			//SDL_RenderDrawLine(renderer, 10, 10, 20, 20);
		}
	}
}