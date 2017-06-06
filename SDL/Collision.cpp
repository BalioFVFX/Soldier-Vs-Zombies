#include "Collision.h"
#include  <cmath>

bool Collision::playerBulletCollision(Bullet bullet[], Zombie &zombie)
{
	if (sqrt(pow(bullet[0].GetOriginX() - zombie.GetOriginX(), 2) + pow(bullet[0].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[0].GetRadius() + zombie.GetRadius())
	{	

	}

	else 
	{
		zombie.zombieRect.x = 300;
	}
	if (sqrt(pow(bullet[1].GetOriginX() - zombie.GetOriginX(), 2) + pow(bullet[1].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[1].GetRadius() + zombie.GetRadius())
	{

	}

	else 
	{
		zombie.zombieRect.x = 300;
	}

	if (sqrt(pow(bullet[2].GetOriginX() - zombie.GetOriginX(), 2) + pow(bullet[2].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[2].GetRadius() + zombie.GetRadius())
	{

	}

	else
	{
		zombie.zombieRect.x = 300;
	}

	if (sqrt(pow(bullet[3].GetOriginX() - zombie.GetOriginX(), 2) + pow(bullet[3].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[3].GetRadius() + zombie.GetRadius())
	{

	}

	else
	{
		zombie.zombieRect.x = 300;
	}
	return true;
}

void Collision::test(Bullet bullet[], Player & p, Zombie & zombie)
{
	if (bullet[ammo].b.x >= 350 && bullet[ammo].b.x <= 355)
	{
		//p.positionRect.x = 100;
		//ammo++;
	}
	if (ammo == 4)
	{
		//ammo = 0;
	}

	/*if (bullet[ammo].b.x + bullet[ammo].b.w < zombie.zombieRect.x || bullet[ammo].b.x > zombie.zombieRect.x + zombie.zombieRect.w ||
		bullet[ammo].b.y + bullet[ammo].b.h < zombie.zombieRect.y || bullet[ammo].b.y > zombie.zombieRect.y + bullet[ammo].b.h)
	{
		std::cout << "nqma udar";
	}

	else
	{
		p.positionRect.x = 200;
		ammo++;
	}
	*/


}

bool Collision::tester(Bullet b[], Zombie &z)
{
		if (b[0].b.x <= 100)
		{
			z.zombieRect.x = 300;
			return true;
		}
		if (b[1].b.x <= 100)
		{
			z.zombieRect.x = 300;
			return true;
		}
		if (b[2].b.x <= 100)
		{
			z.zombieRect.x = 300;
			return true;
		}
		if (b[3].b.x <= 100)
		{
			z.zombieRect.x = 300;
			return true;
		}
		else
		{
			return false;
			
		}
		
}

bool Collision::oldTest(Bullet b[] , Zombie & z)
{
	if (b[0].b.x + b[0].b.w  < z.zombieRect.x || b[0].b.x > z.zombieRect.x + z.zombieRect.w ||
		b[0].b.y + b[0].b.h < z.zombieRect.y || b[0].b.y > z.zombieRect.y + b[0].b.h)
	{
		
	}
	else
	{
		z.zombieRect.x = 300;
	}

	if (b[1].b.x + b[1].b.w  < z.zombieRect.x || b[1].b.x > z.zombieRect.x + z.zombieRect.w ||
		b[1].b.y + b[1].b.h < z.zombieRect.y || b[1].b.y > z.zombieRect.y + b[1].b.h)
	{
	}
	else
	{
		z.zombieRect.x = 250;
	}
	
	if (b[2].b.x + b[2].b.w  < z.zombieRect.x || b[2].b.x > z.zombieRect.x + z.zombieRect.w ||
		b[2].b.y + b[2].b.h < z.zombieRect.y || b[2].b.y > z.zombieRect.y + b[2].b.h)
	{

	}

	else
	{
		z.zombieRect.x = 400;
	}

	if (b[3].b.x + b[3].b.w  < z.zombieRect.x || b[3].b.x > z.zombieRect.x + z.zombieRect.w ||
		b[3].b.y + b[3].b.h < z.zombieRect.y || b[3].b.y > z.zombieRect.y + b[3].b.h)
	{

	}

	else
	{
		z.zombieRect.x = 100;
	}
	return true;
}
