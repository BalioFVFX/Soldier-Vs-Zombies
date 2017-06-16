#include "Collision.h"
#include  <cmath>

void Collision::PlayerBulletToZombieCollision(Bullet bullet[], Zombie & zombie)
{
	if (zombie.alive == true)
	{
		if (sqrt(pow(bullet[0].GetOriginX() - 25 - zombie.GetOriginX(), 2) + pow(bullet[0].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[0].GetRadius() + zombie.GetRadius())
		{
			//If any if returning false collision is not working?

			SDL_SetTextureColorMod(zombie.texture, 255, 255, 255);
		}

		else
		{
			SDL_SetTextureColorMod(zombie.texture, 252, 29, 29);
			bullet[0].b.x = 9999;
			bullet[0].alive = false;
			zombie.health -= 10;
			zombie.hit = true;

		}
		if (sqrt(pow(bullet[1].GetOriginX() - 25 - zombie.GetOriginX(), 2) + pow(bullet[1].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[1].GetRadius() + zombie.GetRadius())
		{

		}

		else
		{
			SDL_SetTextureColorMod(zombie.texture, 252, 29, 29);
			bullet[1].b.x = 9999;
			bullet[1].alive = false;
			zombie.health -= 10;
			zombie.hit = true;
		}

		if (sqrt(pow(bullet[2].GetOriginX() - 25 - zombie.GetOriginX(), 2) + pow(bullet[2].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[2].GetRadius() + zombie.GetRadius())
		{

		}

		else
		{
			SDL_SetTextureColorMod(zombie.texture, 252, 29, 29);
			bullet[2].b.x = 9999;
			bullet[2].alive = false;
			zombie.health -= 10;
			zombie.hit = true;
		}

		if (sqrt(pow(bullet[3].GetOriginX() - 25 - zombie.GetOriginX(), 2) + pow(bullet[3].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[3].GetRadius() + zombie.GetRadius())
		{

		}

		else
		{
			SDL_SetTextureColorMod(zombie.texture, 252, 29, 29);
			bullet[3].b.x = 9999;
			bullet[3].alive = false;
			zombie.health -= 10;
			zombie.hit = true;
		}
		if (zombie.health <= 0)
		{
			zombie.alive = false;
		}
	}
}

void Collision::ZombieBulletToPlayerCollision(Zombie & zombie, Player & player)
{
	if (player.alive == true)
	{

		if (sqrt(pow(zombie.GetBulletOriginX() - player.GetOriginX(), 2) + pow(zombie.GetBulletOriginY() - player.GetOriginY(), 2)) >= zombie.GetBulletRadius() + player.GetRadius())
		{
			SDL_SetTextureColorMod(player.texture, 255, 255, 255);
		}

		else
		{
			SDL_SetTextureColorMod(player.texture, 252, 29, 29);
			zombie.zombieBulletRect.x = -700;
			player.health -= 5;
			player.hit = true;
		}
		if (player.health <= 0)
		{
			player.alive = false;
		}
	}
}

void Collision::PlayerToZombieCollision(Player & player, Zombie & zombie)
{
	if (zombie.alive == true)
	{
		
		//If Infront The Zombie
		if (sqrt(pow(player.GetOriginX() - zombie.GetOriginX(), 2) + pow(player.GetOriginY() - zombie.GetOriginY(), 2)) >= player.GetRadius() + zombie.GetRadius())
		{

		}

		else
		{
			SDL_SetTextureColorMod(player.texture, 252, 29, 29);
			player.positionRect.x -= 5;

		}

		//If Behind The Zombie
		if (sqrt(pow(player.GetOriginX() - 3 - zombie.GetOriginX(), 2) + pow(player.GetOriginY() - zombie.GetOriginY(), 2)) >= player.GetRadius() + zombie.GetRadius())
		{

		}

		else
		{
			SDL_SetTextureColorMod(player.texture, 252, 29, 29);
			player.positionRect.x += 5;

		}

	}
}

void Collision::PlayerToCoinsCollision(Player & player, Coins coin[])
{
	std::cout << "Collision: " << coin[0].GetOriginX() << std::endl;
	if (coin[0].pickedUp == false)
	{
		//If Infront The Zombie
		if (sqrt(pow(player.GetOriginX() - coin[0].GetOriginX(), 2) + pow(player.GetOriginY() - coin[0].GetOriginY(), 2)) >= player.GetRadius() + coin[0].GetRadius() - 19)
		{

		}

		else
		{
			SDL_SetTextureColorMod(player.texture, 252, 29, 29);
			player.positionRect.x = 200;
			coin[0].pickedUp = true;

		}
	}
}


