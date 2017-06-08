#include "Collision.h"
#include  <cmath>

void Collision::PlayerBulletToZombieCollision(Bullet bullet[], Zombie & zombie)
{
	if (zombie.alive == true)
	{
		if (sqrt(pow(bullet[0].GetOriginX() - zombie.GetOriginX(), 2) + pow(bullet[0].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[0].GetRadius() + zombie.GetRadius())
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

		}
		if (sqrt(pow(bullet[1].GetOriginX() - zombie.GetOriginX(), 2) + pow(bullet[1].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[1].GetRadius() + zombie.GetRadius())
		{

		}

		else
		{
			SDL_SetTextureColorMod(zombie.texture, 252, 29, 29);
			bullet[1].b.x = 9999;
			bullet[1].alive = false;
			zombie.health -= 10;
		}

		if (sqrt(pow(bullet[2].GetOriginX() - zombie.GetOriginX(), 2) + pow(bullet[2].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[2].GetRadius() + zombie.GetRadius())
		{

		}

		else
		{
			SDL_SetTextureColorMod(zombie.texture, 252, 29, 29);
			bullet[2].b.x = 9999;
			bullet[2].alive = false;
			zombie.health -= 10;
		}

		if (sqrt(pow(bullet[3].GetOriginX() - zombie.GetOriginX(), 2) + pow(bullet[3].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[3].GetRadius() + zombie.GetRadius())
		{

		}

		else
		{
			SDL_SetTextureColorMod(zombie.texture, 252, 29, 29);
			bullet[3].b.x = 9999;
			bullet[3].alive = false;
			zombie.health -= 10;
		}
		if (zombie.health <= 0)
		{
			zombie.alive = false;
		}
	}
}

