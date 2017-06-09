#pragma once
#include<SDL\SDL.h>
#include <string>
#include <SDL\SDL_mixer.h>
#include <SDL\SDL_ttf.h>
#include <vector>
#include <sstream>



class Player
{
public:
	Player();
	Player(int a, int b);
	Player(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY);
	~Player();

	
	
	//Drawing Functions
	void Draw(SDL_Renderer *renderTarget);
	void drawLaser(SDL_Renderer * renderBullet, Player &p, const Uint8 *keystate);
	void drawUpgradedLaser(SDL_Renderer * renderBullet, Player &p, const Uint8 *keystate);

	

	//Collision Functions
	bool IntersectwithBullet(Player &p);
	bool IntersectwithLaser(Player &p);
	bool IntersectwithUpgradedLaser(Player &p);
	void drawExplosion(SDL_Renderer *renderTarget, Player &p);

	void drawExplosionFromZombie(SDL_Renderer * renderTarget, Player & p);
	
	//Player Updating
	void Update(float delta, const Uint8 *keystate, SDL_Event ev);
	
	//ZombieBullet Collision
	bool IntersectwithZombieBullet(Player &p);

	bool IntersectwithZombieBulletVer2(Player & p);

	//Zombie Drawing Functions
	void DrawBullet4ZombieVer2(SDL_Renderer * renderBullet, Player &p, const Uint8 *keystate);

	//Zombies Updating
	void UpdateZombie(float delta, const Uint8 *keystate, SDL_Event ev, Player &p);
	void UpdateSecondZombie(float delta, const Uint8 *keystate, SDL_Event ev, Player &p);
	void UpdateThirdZombie(float delta, const Uint8 *keystate, SDL_Event ev, Player &p);
	
	//Win
	void win(SDL_Renderer* renderTarget);
	void updateWin(float delta, const Uint8 *keystate, SDL_Event ev, Player &p);

	//Player building events

	void drawWall(SDL_Renderer *renderTarget, int x, int y);
	void updateWall(float delta, const Uint8 *keystate, SDL_Event ev, Player &p);
	
	//Wall Collision
	bool IntersectwithWall(float delta, const Uint8 * keystate, SDL_Event ev, Player &p);

	//Text updating and drawing

	int getPlayerY = 400;
	int getPlayerX = 50;

	bool moving = true;
	bool secondZombieMoving = true;
	bool dead = false;

	SDL_Rect positionRect;
	int GetOriginX();
	int GetOriginY();
	int GetRadius();
	int frameWidth, frameHeight;
	SDL_Rect cropRect;

private:
	
	SDL_Texture *texture;
	int originX;
	int originY;
	int radius;

	SDL_Rect firework_Rect;

	SDL_Rect bullet_rect;
	SDL_Rect laser_rect;
	SDL_Rect upgradedLaser_Rect;
	SDL_Rect explosion;
	
	SDL_Rect zombieRect;
	SDL_Rect secondZombieRect;
	
	//Player building
	SDL_Rect WallRect;

	SDL_Surface * surface = nullptr;
	
	float moveSpeed;
	float frameCounter;

	bool isActive;
	bool isSecondActive;
	bool isSecondMoving = true;
	int textureWidth;
	bool running = true;
	bool fired = false;
	
	int firstZombieHealth = 100;
	int secondZombieHealth = 100;
	bool firstZombieKilled = false;
	

	float jumpVel = 2;
	bool jumping = false;
	bool falling = false;
	float gravity = 0.2;
	bool isJumping = false;
	
	bool reloading = false;
	Mix_Chunk *fire_bullet = Mix_LoadWAV("fire_bullet.wav");
	Mix_Chunk *reloading_sound = Mix_LoadWAV("reload.wav");
	
	SDL_Rect bulletsRect;
	SDL_Rect bulletsTextRect;
	SDL_Surface* BulletDrawSurface;
	SDL_Texture* BulletDrawTexture;
	SDL_Surface* BulletDrawTextSurface;
	SDL_Texture* BulletDrawTextTexture;
	std::stringstream bulletsdrawStream;
	TTF_Font *text;
	SDL_Color White = { 255, 255, 255 };
	int bullets = 15;
	bool updateTheText = false;
	unsigned int lastTime = 0, currentTime;
	SDL_Scancode keys[9];
};

