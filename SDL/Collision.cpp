#include "Collision.h"
#include  <cmath>

bool Collision::PlayerBulletToZombieCollision(Bullet bullet[], Zombie &zombie)
{
	if (sqrt(pow(bullet[0].GetOriginX() - zombie.GetOriginX(), 2) + pow(bullet[0].GetOriginY() - zombie.GetOriginY(), 2)) >= bullet[0].GetRadius() + zombie.GetRadius())
	{	
		//If any if returning false collision is not working?
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