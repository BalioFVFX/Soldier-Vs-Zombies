#include "Player.h"
#include <SDL\SDL_image.h>
#include <iostream>
#include <cmath>


Player::Player(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY)
{
	if (alive == false)
	{
		delete this;
	}
	else
	{
		surface = IMG_Load(filePath.c_str());

		texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		SDL_FreeSurface(surface);

		SDL_QueryTexture(texture, NULL, NULL, &cropRect.w, &cropRect.h);


		positionRect.x = x;
		positionRect.y = y;

		WallRect.w = 50;
		WallRect.h = 50;


		firework_Rect.x = x;
		firework_Rect.y = y;
		firework_Rect.w = 240;
		firework_Rect.h = 240;

		secondZombieRect.x = 2242;
		secondZombieRect.y = 4444;
		secondZombieRect.w = 100;
		secondZombieRect.h = 100;

		laser_rect.x = 50;
		laser_rect.y = 400;
		laser_rect.w = 70;
		laser_rect.h = 20;

		upgradedLaser_Rect.x = 50;
		upgradedLaser_Rect.y = 400;
		upgradedLaser_Rect.w = 70;
		upgradedLaser_Rect.h = 20;

		explosion.x = x;
		explosion.y = y;
		explosion.w = 40;
		explosion.h = 40;

		textureWidth = cropRect.w;

		cropRect.w /= framesX;
		cropRect.h /= framesY;

		frameWidth = positionRect.w = cropRect.w;
		frameHeight = positionRect.h = cropRect.h;

		originX = frameWidth / 2;
		originY = frameHeight / 2;
		radius = frameWidth / 2;

		isActive = false;
		isSecondActive = false;



		keys[0] = SDL_SCANCODE_W;
		keys[1] = SDL_SCANCODE_S;
		keys[2] = SDL_SCANCODE_A;
		keys[3] = SDL_SCANCODE_D;
		keys[5] = SDL_SCANCODE_F;
		keys[6] = SDL_SCANCODE_Q;
		keys[7] = SDL_SCANCODE_E;
		keys[8] = SDL_SCANCODE_SPACE;



		moveSpeed = 200.0f;
	}
}

Player::Player()
{

}

Player::Player(int a, int b)
{
}

Player::~Player()
{
	
}

void Player::Draw(SDL_Renderer *renderTarget)
{
	if (alive == true)
	{
		SDL_RenderCopy(renderTarget, texture, &cropRect, &positionRect);
	}
}



void Player::Update(float delta, const Uint8 *keystate, SDL_Event ev)
{
	if (alive == true)
	{
		isActive = true;
		if (keystate[keys[0]])
		{
			if (positionRect.y <= 372)
			{

			}
			else
			{
				cropRect.y = 0;
				positionRect.y -= moveSpeed * delta;
				cropRect.y = 3;
				getPlayerY - 4;

			}
		}
		else if (keystate[keys[1]])
		{
			if (positionRect.y >= 417)
			{

			}
			else
			{
				cropRect.y = frameHeight * 2;
				positionRect.y += moveSpeed * delta;
				cropRect.y = frameHeight * 2;
			}
		}
		else if (keystate[keys[2]])
		{
			if (positionRect.x <= (-21))
			{

			}
			else
			{
				facingRight = false; //Player Is Facing Left So Right Is False
				facingLeft = true;
				cropRect.y = frameHeight;
				positionRect.x -= moveSpeed * delta;
				
			}
		}
		else if (keystate[keys[3]])
		{
			facingRight = true; //Player Is Facing Right So Left Is False
			facingLeft = false;
			cropRect.y = frameHeight;
			positionRect.x += moveSpeed* delta;
			cropRect.y = frameHeight * 3;
			
		}


		else
		{
			isActive = false;
		}

		if (positionRect.y <= 300)
		{
			falling = true;
		}

		if (positionRect.y >= 400)
		{
			falling = false;
		}

		if (positionRect.y > 0 && positionRect.y < 420)
		{
			if (keystate[keys[8]] && falling == false) {
				if (positionRect.y > 300) positionRect.y -= 7.0; // jump if below the top

			}
			else {
				if (positionRect.y < 400) positionRect.y += 5.0; // fall if below the bottom

			}

		}

		if (isActive)
		{
			frameCounter += delta;

			if (frameCounter >= 0.25f)
			{
				frameCounter = 0;
				cropRect.x += frameWidth;
				if (cropRect.x >= textureWidth)
				{
					cropRect.x = 0;
				}
			}
		}
		else
		{
			frameCounter = 0;
			cropRect.x = frameWidth;
		}
	}
}
/**
bool Player::IntersectwithWall(float delta, const Uint8 * keystate, SDL_Event ev, Player & p)
{

	if (zombieBullet_Rect.x + zombieBullet_Rect.w  < p.WallRect.x || zombieBullet_Rect.x > p.WallRect.x + p.WallRect.w ||
		zombieBullet_Rect.y + zombieBullet_Rect.h < p.WallRect.y || zombieBullet_Rect.y > p.WallRect.y + zombieBullet_Rect.h)
	{
		SDL_SetTextureColorMod(p.texture, 255, 255, 255);
		return false;
	}

	else
	{
		cropRect.y = frameHeight;
		positionRect.x += moveSpeed* delta;
		cropRect.y = frameHeight * 3;
		SDL_SetTextureColorMod(p.texture, 255, 0, 0);
		zombieBullet_Rect.x = -200;
	}
	return true;
}
*/
int Player::GetOriginX()
{
	return originX = positionRect.x;
}

int Player::GetOriginY()
{
	return originY = positionRect.y;
}

int Player::GetRadius()
{
	return radius;
}



void Player::UpdateZombie(float delta, const Uint8 * keystate, SDL_Event ev, Player &p)
{
	isActive = true;
	currentTime = SDL_GetTicks();

	if (currentTime > lastTime + 150)
	{
		lastTime = currentTime;

		if (moving == true)
		{
			cropRect.y = frameHeight;
			p.positionRect.x -= moveSpeed * delta;

		}
		else
		{
			isActive = false;
		}
	}

	if (isActive)
	{
		frameCounter += delta;

		if (frameCounter >= 0.25f)
		{
			frameCounter = 0;
			cropRect.x += frameWidth;
			if (cropRect.x >= textureWidth)
			{
				cropRect.x = 0;
			}
		}
	}
	else
	{
		frameCounter = 0;
		cropRect.x = frameWidth;
	}

}

void Player::UpdateSecondZombie(float delta, const Uint8 * keystate, SDL_Event ev, Player &p)
{
	isActive = true;
	currentTime = SDL_GetTicks();

	if (currentTime > lastTime + 150)
	{
		lastTime = currentTime;

		if (moving == true)
		{
			cropRect.y = frameHeight;
			p.positionRect.x -= moveSpeed * delta;

		}
		else
		{
			isActive = false;
		}
	}

	if (isActive)
	{
		frameCounter += delta;

		if (frameCounter >= 0.25f)
		{
			frameCounter = 0;
			cropRect.x += frameWidth;
			if (cropRect.x >= textureWidth)
			{
				cropRect.x = 0;
			}
		}
	}
	else
	{
		frameCounter = 0;
		cropRect.x = frameWidth;
	}
}

void Player::UpdateThirdZombie(float delta, const Uint8 * keystate, SDL_Event ev, Player & p)
{
	isActive = true;
	currentTime = SDL_GetTicks();

	if (currentTime > lastTime + 150)
	{
		lastTime = currentTime;

		if (moving == true)
		{
			cropRect.y = frameHeight;
			p.positionRect.x -= moveSpeed * delta;

		}
		else
		{
			isActive = false;
		}
	}
	if (isActive)
	{
		frameCounter += delta;

		if (frameCounter >= 0.25f)
		{
			frameCounter = 0;
			cropRect.x += frameWidth;
			if (cropRect.x >= textureWidth)
			{
				cropRect.x = 0;
			}
		}
	}
	else
	{
		frameCounter = 0;
		cropRect.x = frameWidth;
	}
}

void Player::win(SDL_Renderer * renderTarget)
{
	SDL_RenderCopy(renderTarget, texture, &cropRect, &firework_Rect);
}

void Player::updateWin(float delta, const Uint8 * keystate, SDL_Event ev, Player & p)
{
	isActive = true;
	currentTime = SDL_GetTicks();

	if (currentTime > lastTime + 1)
	{

		lastTime = currentTime;


		cropRect.y = frameHeight;

		cropRect.y = frameHeight * 3;
	}
		else
		{
			isActive = false;
		}
	

	if (isActive)
	{
		frameCounter += delta;

		if (frameCounter >= 0.25f)
		{
			frameCounter = 0;
			cropRect.x += frameWidth;
			if (cropRect.x >= textureWidth)
			{
				cropRect.x = 0;
			}
		}
	}
	else
	{
		frameCounter = 0;
		cropRect.x = frameWidth;
	}
}



void Player::drawLaser(SDL_Renderer *renderBullet, Player &p, const Uint8 *keystate)
{
	if (fired == false)
	{
		if (keystate[keys[6]])
		{
			laser_rect.x = p.positionRect.x;
			laser_rect.y = p.positionRect.y;
			fired = true;
		}
	}

		laser_rect.x += 20;

		if (laser_rect.x >= 700)
		{
			laser_rect.x = 9999;
			fired = false;
		}
	

	SDL_RenderCopy(renderBullet, texture, NULL, &laser_rect);
}

void Player::drawUpgradedLaser(SDL_Renderer *renderBullet, Player &p, const Uint8 *keystate)
{
	if (fired == false)
	{
		if (keystate[keys[7]])
		{
			upgradedLaser_Rect.x = p.positionRect.x;
			upgradedLaser_Rect.y = p.positionRect.y;
			fired = true;
		}
	}
		upgradedLaser_Rect.x += 20;
		
	if (upgradedLaser_Rect.x >= 700)
	{
		upgradedLaser_Rect.x = 9999;
		fired = false;
	}

	SDL_RenderCopy(renderBullet, texture, NULL, &upgradedLaser_Rect);
}
/*
void Player::DrawBullet4ZombieVer2(SDL_Renderer * renderBullet, Player & p, const Uint8 * keystate)
{
	currentTime = SDL_GetTicks();

	if (currentTime > lastTime + 0) {
		lastTime = currentTime;
		zombieBullet_Rect.x -= 20;
	}
	if (zombieBullet_Rect.x <= -752 )
	{
		zombieBullet_Rect.x = p.positionRect.x;
		zombieBullet_Rect.y = p.positionRect.y + 20;
	}

	SDL_RenderCopy(renderBullet, texture, NULL, &zombieBullet_Rect);
}
*/

bool Player::IntersectwithBullet(Player &p)
{

	if (bullet_rect.x + bullet_rect.w < p.positionRect.x || bullet_rect.x > p.positionRect.x + p.positionRect.w ||
		bullet_rect.y + bullet_rect.h < p.positionRect.y || bullet_rect.y > p.positionRect.y + bullet_rect.h)
	{
		SDL_SetTextureColorMod(p.texture, 255, 255, 255);
		return false;
	}


	else
	{
		p.firstZombieHealth -= 4;
		bullet_rect.x = 9999;
		
		if (p.firstZombieHealth <= 0)
		{
			p.positionRect.x = 0;
			p.positionRect.y = 10;
			p.moving = false;
			fired = false;
		}
		SDL_SetTextureColorMod(p.texture, 255, 0, 0);
		}
		fired = false;
		return true;
	}

bool Player::IntersectwithLaser(Player &p)
{

	if (laser_rect.x + laser_rect.w < p.positionRect.x || laser_rect.x > p.positionRect.x + p.positionRect.w ||
		laser_rect.y + laser_rect.h < p.positionRect.y || laser_rect.y > p.positionRect.y + laser_rect.h)
	{
		SDL_SetTextureColorMod(p.texture, 255, 255, 255);
		return false;
	}

	else
	{
		p.firstZombieHealth -= 7;
		laser_rect.x = 9999;
		if (p.firstZombieHealth <= 0)
		{
			p.positionRect.x = 0;
			p.positionRect.y = 10;
			p.moving = false;
			fired = false;
		}
		SDL_SetTextureColorMod(p.texture, 255, 0, 0);
	}
	fired = false;
	return true;
}

bool Player::IntersectwithUpgradedLaser(Player &p)
{

	if (upgradedLaser_Rect.x + upgradedLaser_Rect.w < p.positionRect.x || upgradedLaser_Rect.x > p.positionRect.x + p.positionRect.w ||
		upgradedLaser_Rect.y + upgradedLaser_Rect.h < p.positionRect.y || upgradedLaser_Rect.y > p.positionRect.y + upgradedLaser_Rect.h)
	{
		SDL_SetTextureColorMod(p.texture, 255, 255, 255);
		return false;
	}

	else
	{
		p.firstZombieHealth -= 12;
		upgradedLaser_Rect.x = 9999;
		if (p.firstZombieHealth <= 0)
		{
			p.positionRect.x = 0;
			p.positionRect.y = 10;
			p.moving = false;
			fired = false;
		}
		SDL_SetTextureColorMod(p.texture, 255, 0, 0);
	}
	fired = false;
	return true;
}

void Player::drawExplosion(SDL_Renderer * renderTarget, Player &p)
{
	explosion.x = p.positionRect.x;
	explosion.y = p.positionRect.y;
	SDL_RenderCopy(renderTarget, texture, NULL, &explosion);
}

void Player::drawWall(SDL_Renderer *renderTarget, int x, int y)
{
	WallRect.x = x;
	WallRect.y = y;
	SDL_RenderCopy(renderTarget, texture, NULL, &WallRect);
}

void Player::updateWall(float delta, const Uint8 * keystate, SDL_Event ev, Player & p)
{
	isActive = true;
	currentTime = SDL_GetTicks();

	if (currentTime > lastTime + 1)
	{

		lastTime = currentTime;


		cropRect.y = frameHeight;

		cropRect.y = frameHeight * 3;
	}
	else
	{
		isActive = false;
	}


	if (isActive)
	{
		frameCounter += delta;

		if (frameCounter >= 0.25f)
		{
			frameCounter = 0;
			cropRect.x += frameWidth;
			if (cropRect.x >= textureWidth)
			{
				cropRect.x = 0;
			}
		}
	}
	else
	{
		frameCounter = 0;
		cropRect.x = frameWidth;
	}

}

void Player::drawExplosionFromZombie(SDL_Renderer * renderTarget, Player &p)
{
	explosion.x = p.positionRect.x + 25;
	explosion.y = p.positionRect.y + 10;
	SDL_RenderCopy(renderTarget, texture, NULL, &explosion);
}

/*
bool Player::IntersectwithZombieBullet(Player & p)
{

	if (zombieBullet_Rect.x + zombieBullet_Rect.w < p.positionRect.x || zombieBullet_Rect.x > p.positionRect.x + p.positionRect.w ||
		zombieBullet_Rect.y + zombieBullet_Rect.h < p.positionRect.y || zombieBullet_Rect.y > p.positionRect.y + zombieBullet_Rect.h)
	{
		SDL_SetTextureColorMod(p.texture, 255, 255, 255);
		return false;
	}

	else
	{
		zombieBullet_Rect.x = -200;
		SDL_SetTextureColorMod(p.texture, 255, 0, 0);
	}
	return true;
}
*/
/**
bool Player::IntersectwithZombieBulletVer2(Player & p)
{

	if (zombieBullet_Rect.x + zombieBullet_Rect.w < p.positionRect.x || zombieBullet_Rect.x > p.positionRect.x + p.positionRect.w ||
		zombieBullet_Rect.y + zombieBullet_Rect.h < p.positionRect.y || zombieBullet_Rect.y > p.positionRect.y + zombieBullet_Rect.h)
	{
		SDL_SetTextureColorMod(p.texture, 255, 255, 255);
		return false;
	}

	else
	{
		zombieBullet_Rect.x = -200;
		SDL_SetTextureColorMod(p.texture, 255, 0, 0);
	}
	return true;
}
*/