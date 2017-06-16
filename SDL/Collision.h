#include <iostream>
#include <SDL\SDL.h>
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Text.h"
#include <string>
#include <sstream>
#include "Coins.h"

class Collision : public Player , public Zombie, public Bullet, public Coins
{
public:
	int a = 20;
	Collision() : Player(), Zombie(), Bullet(), Coins() {};

	void PlayerBulletToZombieCollision(Bullet bullet[], Zombie &zombie);
	void ZombieBulletToPlayerCollision(Zombie &zombie, Player & player);
	void PlayerToZombieCollision(Player & player, Zombie & zombie);
	void PlayerToCoinsCollision(Player &player, Coins coin[]);
};