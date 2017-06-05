#include <iostream>
#include <SDL\SDL.h>
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
class Collision : public Player , public Zombie, public Bullet
{
public:
	Collision() : Player(), Zombie(), Bullet() {};

	int counter = 0;
	
	bool playerBulletCollision(Bullet bullet[], Zombie &zombie);
	void test(Bullet b[], Player &p, Zombie & zombie);
	bool tester(Bullet b[], Zombie &z);
	bool oldTest(Bullet b[], Zombie &z);
};