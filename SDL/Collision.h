#include <iostream>
#include <SDL\SDL.h>
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
class Collision : public Player , public Zombie, public Bullet
{
public:
	Collision() : Player(), Zombie(), Bullet() {};
	
	bool PlayerBulletToZombieCollision(Bullet bullet[], Zombie &zombie);
};