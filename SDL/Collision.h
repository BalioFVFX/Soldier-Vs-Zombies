#include <iostream>
#include <SDL\SDL.h>
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Text.h"
#include <string>
#include <sstream>
class Collision : public Player , public Zombie, public Bullet, public Text
{
public:
	int a = 20;
	Collision() : Player(), Zombie(), Bullet(), Text() {};

	bool PlayerBulletToZombieCollision(Bullet bullet[], Zombie &zombie, Text &t);
};