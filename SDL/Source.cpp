#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <SDL\SDL_ttf.h>
#include <SDL\SDL_mixer.h>
#include "Menu.h"
#include "Enviroment.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Bullet.h"
#include "Zombie.h"
#include "Collision.h"

int x = 0, y = 0;
int aTest = 0;
using namespace std;
//
bool testbool = false;
bool cantTouch = true;
int timesWereHitted = 0;
bool bricksAlive1st = true;
bool bricksAlive2nd = false;
bool bricksAlive3rd = false;
bool updateTheText = false;
bool isPressed = false;
bool inMenu = true;
bool inSettings = false;
bool playbutton = false;
bool inGame = false;
bool inShop = false;
bool needsUpdate = true;
int zombieHealth = 100;
int playerHealth = 100;
bool zombie1Alive = true;
bool zombie2Alive = true;
bool spawn2ndZombie = false;
bool spawn3rdZombie = false;
bool zombieAttack = false;
bool gameOver = false;
bool gameOverExit = false;
bool regularZombieUpdate = true;
bool slowZombieUpdate = false;
bool exitGame = false;

bool regularBullet = false;
bool laserBullet = false;
bool upgradedLaserBullet = false;
bool isgamewin = false;

bool FireTheBullet = false;
bool FireTheLaser = false;
bool FireTheUpgradedLaser = false;
bool isPaused = false;

bool isItUpgraded = false;

bool bKeyUP = 0, BkeyDown = 0, bKeyLeft = 0, bKeyRight = 0, bKeyA = 0;
int bKeyATick = 0;
int aTick = 0;

int drawPosX = 0;
int drawPosY = 0;

bool drawIt = false;

SDL_Surface * surface;
int globalCoins = 0;

int main(int argc, char** argv)
{
	const int FPS = 60;
	SDL_Window *window = nullptr;
	SDL_Renderer *renderTarget = nullptr;
	int currentTime = 0;
	int prevTime = 0;
	float delta = 0.0f;
	unsigned int lastTime = 0;
	const Uint8 *keyState;
	SDL_Scancode buttonsforExit[3];

	//Opening File

	std::fstream writeFile;

	ifstream myfile("coins.txt");
	
	int line;
	if (myfile.is_open())
	{
		while (myfile >> line)
		{
			int b = line;
		}
		int z = line;
		myfile.close();
	}
	
	int coinsFromFille = line;


	buttonsforExit[2] = SDL_SCANCODE_ESCAPE;
	TTF_Init();
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	TTF_Font *text;
	text = TTF_OpenFont("batmfa__.ttf", 24);
	SDL_Color White = { 255, 255, 255 };
	window = SDL_CreateWindow("Soldier vs Zombies 3.5", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_FOREIGN);
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0);
	
	//Player overall:
	Player player1(renderTarget, "soldier.png", 50, 400, 9, 4); //Position and croping..
	//Player testovBullet(renderTarget, "ball.png", 200, 400, 1, 1); //Thats how i found X / Y / Radius = 12 (Get Functions For The Bullet)
	Player Laser(renderTarget, "laser.png", 0, 0, 1, 1);
	Player UpgradedLaser(renderTarget, "upgradedlaser.png", 0, 0, 1, 1);
	Bullet ammo[4];
	Bullet bullet(renderTarget, "ball.png", 0, 0, 1, 1);



	//Zombie Overall:
	Zombie zombie1(renderTarget, "zombie1.png", 600, 400, 4, 4);
	Zombie zombieBullet(renderTarget, "zombiebullet.png", 0, 0, 1, 1);
	Zombie zombie2(renderTarget, "zombie2.png", 600, 400, 4, 4);
	Zombie zombie3(renderTarget, "zombie3.png", 600, 400, 4, 4);

	Player zombieDrawBullet(renderTarget, "zombiebullet.png", 0, 0, 1, 1);
	Player zombieDrawBulletVer2(renderTarget, "Zombie_Bullet Edited_Version_2.png", 0, 0, 1, 1);
	Player explosion(renderTarget, "explosion.gif", 0, 0, 1, 1);
	Player explosionFromZombie(renderTarget, "explosion.gif", 0, 0, 1, 1);
	
	Collision collision;
	
	//Win
	Player gameWin(renderTarget, "firework.png", 10, 100, 9, 4);
	Player secondfirework(renderTarget, "firework.png", 350, 100, 9, 4);

	//Player building events
	Player drawTheWall(renderTarget, "singlewall.png", 200, 400, 2, 1);
	Player drawSecondWall(renderTarget, "secondwall.png", 200, 400, 2, 1);
	Player drawThirdWall(renderTarget, "thirdwall.png", 200, 400, 2, 1);
	//Enviroment:
	Enviroment enviroment(renderTarget, "bg.png", 640, 480); //Sizes..
	Enviroment barrel(renderTarget, "barrel.png", 40, 40);
	
	//Enviroment wall(renderTarget, "howtowall.png", 500, 500);

	
	//Menu:
	Menu menu(renderTarget, "testbackground.png", 20, 480); //Sizes 
	Menu gameOverScreen(renderTarget, "gameover.png", 20, 480);
	Menu playButton(renderTarget, "Button_Play_Grey.png", 0, 0);
	Menu multiPlayerButton(renderTarget, "shopnow.png", 0, 0);
	Menu settingsButton(renderTarget, "Button_Settings_Grey.png", 0, 0);
	Menu exitButton(renderTarget, "Button_Exit_Grey.png", 0, 0);
	
	Menu playGreen(renderTarget, "Button_Play_Green.png", 0, 0);
	Menu multiPlayerGreen(renderTarget, "Button_MultiPlayer_Green.png", 0, 0);
	Menu settingsGreen(renderTarget, "Button_Settings_Green.png", 0, 0);
	Menu exitGreen(renderTarget, "Button_Exit_Green.png", 0, 0);

	Menu settingsMenu(renderTarget, "Settings_Bg.png", 0, 0);
	Menu volumeIcon(renderTarget, "VolumeIcon.png", 0, 0);
	Menu renderText(renderTarget, "", 0, 0);

	Menu shopMenu(renderTarget, "shop.png", 0, 0);
	Menu shopText(renderTarget, "", 0, 0);
	Menu UpgradedLaserInShop(renderTarget, "upgradedlaser.png", 0, 0);

	Text zombieText(renderTarget, text);
	Text playerText(renderTarget, text);

	Bullet * _bullet = new Bullet(renderTarget, "bullet.png", 0 , 0, 1 ,1);

	bool isRunning = true;
	SDL_Event ev;
	
	//Loading music and sound effects
	Mix_Music *bgmusic = Mix_LoadMUS("INTERSTELLAR.wav");
	Mix_Chunk *fire_bullet = Mix_LoadWAV("fire_bullet.wav");
	Mix_Chunk *laser_sound = Mix_LoadWAV("laser.wav");
	Mix_Chunk *upgradedLaser_sound = Mix_LoadWAV("upgradedlaser.wav");
	Mix_Chunk *hitmarker = Mix_LoadWAV("hitmarker.wav");
	Mix_Chunk *steps = Mix_LoadWAV("steps.wav"); 
	Mix_Chunk *buttonClick = Mix_LoadWAV("button_sound.wav");
	//Background music
	//Mix_PlayMusic(bgmusic, 1); 

	int LowVolume = 20;
	int mediumVolume = 70;
	int highvolume = 128; //128 is max


	std::stringstream playerHealthSTREAM;
	playerHealthSTREAM << playerHealth;
	

	

	//Coins

	//Text Rect
	SDL_Rect CoinsTextRect;
	CoinsTextRect.x = 410;
	CoinsTextRect.y = 70;
	CoinsTextRect.w = 100;
	CoinsTextRect.h = 40;

	//Numbers Rect
	SDL_Rect CoinsRect;
	CoinsRect.x = 520;
	CoinsRect.y = 70;
	CoinsRect.w = 100;
	CoinsRect.h = 40;

	int coins = 0;

	std::stringstream coinstream;
	

	coinstream << coins;
	
	SDL_Surface * CoinSurface = TTF_RenderText_Solid(text, coinstream.str().c_str(), White);
	SDL_Texture * CoinTexture = SDL_CreateTextureFromSurface(renderTarget, CoinSurface);
	
	SDL_Surface* CoinsTextSurface = TTF_RenderText_Solid(text, "Coins:", White);
	SDL_Texture* CoinsTextTexture = SDL_CreateTextureFromSurface(renderTarget, CoinsTextSurface); 


	int fixedCoins = 0;

	//Not enough Coins
	SDL_Rect noCoins_Rect;
	noCoins_Rect.x = 300;
	noCoins_Rect.y = 300;
	noCoins_Rect.w = 300;
	noCoins_Rect.h = 90;
	
	SDL_Surface* nocoincsSurface = TTF_RenderText_Solid(text, "Not enough coins!", White);
	SDL_Texture* nocoinsTexture = SDL_CreateTextureFromSurface(renderTarget, nocoincsSurface);


	while (isRunning)
	{
		aTick++; //For the bullet
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		delta = (currentTime - prevTime) / 1000.0f;
		SDL_RenderClear(renderTarget);

		if (inMenu == true)
		{
			menu.showMenu(renderTarget);
			playButton.playButton(renderTarget);
			multiPlayerButton.shopButton(renderTarget);
			settingsButton.settingsButton(renderTarget);
			exitButton.exitButton(renderTarget);
			
			/***************************************SHOWING THE MENU******************************************/

			//Play Button
			if (ev.type == SDL_MOUSEMOTION)
			{
				x = ev.motion.x;
				y = ev.motion.y;

				if ((x > 257) && (x < 257 + 120) && (y > 100) && (y < 100 + 45))
				{
					playGreen.isGreyPlay(renderTarget); //If the mouse was over the button make it green!

				}
			}

			//If a mouse button was pressed
			if (ev.type == SDL_MOUSEBUTTONDOWN)
			{

				//If the left mouse button was pressed
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					x = ev.button.x;
					y = ev.button.y;
					Mix_PlayChannel(1, buttonClick, 0); //Bullet sound!

					//If the mouse is over the button
					if ((x > 257) && (x < 257 + 120) && (y > 100) && (y < 100 + 45))
					{
						//Exit the menu
						inGame = true;
					}
				}
			}



			//Multiplayer Button

			//If a mouse button was pressed
			if (ev.type == SDL_MOUSEBUTTONDOWN && SDL_MOUSEMOTION)
			{


				//If the left mouse button was pressed
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					x = ev.button.x;
					y = ev.button.y;

					//If the mouse is over the button
					if ((x > 257) && (x < 257 + 120) && (y > 170) && (y < 170 + 45))
					{

						//Get in the settings menu:
						inShop = true;
					}
				}
			}


			//Settings button

			if (ev.type == SDL_MOUSEMOTION)
			{
				//Get the mouse offsets
				x = ev.motion.x;
				y = ev.motion.y;
				//Print mouse X / Y coordinates 
				std::cout << "X: " << ev.motion.x << std::endl;
				std::cout << "y: " << ev.motion.y << std::endl;
				//If the mouse is over the button
				if ((x > 257) && (x < 257 + 120) && (y > 240) && (y < 240 + 45))
				{
					//Change button color to green
					settingsGreen.isGreySettings(renderTarget, ev);  //If the mouse was over the button make it green!

				}
			}

			//If a mouse button was pressed
			if (ev.type == SDL_MOUSEBUTTONDOWN && SDL_MOUSEMOTION)
			{


				//If the left mouse button was pressed
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					x = ev.button.x;
					y = ev.button.y;

					//If the mouse is over the button
					if ((x > 257) && (x < 257 + 120) && (y > 240) && (y < 240 + 45))
					{

						//Get in the settings menu:
						inSettings = true;
					}
				}
			}



			//Exit Button
			if (ev.type == SDL_MOUSEMOTION)
			{
				x = ev.motion.x;
				y = ev.motion.y;

				//If the mouse is over the button
				if ((x > 257) && (x < 257 + 120) && (y > 310) && (y < 310 + 45))
				{
					exitGreen.isGreyExit(renderTarget);
				}

			}
			//If a mouse button was pressed
			if (ev.type == SDL_MOUSEBUTTONDOWN)
			{
				//If the left mouse button was pressed
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					//Get the mouse offsets
					x = ev.button.x;
					y = ev.button.y;

					//If the mouse is over the button
					if ((x > 257) && (x < 257 + 120) && (y > 310) && (y < 310 + 45))
					{
						isRunning = false;
					}
				}
			}

		}

		else
		{
			inMenu = false;
		}
		//If game over
		if (gameOver == true)
		{
				gameOverScreen.showGameOver(renderTarget);
				if (gameOver && gameOverExit == true)
				{
					break;
				}
		}

		//If in settings menu
		if (inSettings == true)
		{
			settingsMenu.inSettings(renderTarget);
			volumeIcon.drawVolumeIcon(renderTarget);
			renderText.renderText(renderTarget);



			//If a mouse button was pressed
			if (ev.type == SDL_MOUSEBUTTONUP)
			{
				//If the left mouse button was pressed
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					x = ev.button.x;
					y = ev.button.y;

					//If the mouse is over the button
					if ((x > 200) && (x < 200 + 100) && (y > 50) && (y < 50 + 50))
					{

						//Get in the settings menu:
						Mix_VolumeMusic(LowVolume);
					}
				}
				//Medium volume
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					x = ev.button.x;
					y = ev.button.y;

					//If the mouse is over the button
					if ((x > 350) && (x < 350 + 100) && (y > 50) && (y < 50 + 50))
					{

						//Get in the settings menu:
						Mix_VolumeMusic(mediumVolume);
					}
				}
				//High volume
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					x = ev.button.x;
					y = ev.button.y;

					//If the mouse is over the button
					if ((x > 500 && (x < 500 + 100) && (y > 50) && (y < 50 + 50)))
					{

						//Get in the settings menu:
						Mix_VolumeMusic(highvolume);
					}
				}
				
				//Going back to the menu button
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					x = ev.button.x;
					y = ev.button.y;

					//If the mouse is over the button
					if ((x > 265 && (x < 265 + 100) && (y > 350) && (y < 350 + 50)))
					{

						//Get in the settings menu:
						inSettings = false;
						inMenu = true;
					}
				}
			}
			
		}
	
		/***************************************SHOWING THE MENU******************************************/

		
		
		/***************************************SHOWING THE SHOP******************************************/
		
		if (inShop == true)
		{
			inMenu = false;
			shopMenu.showMenu(renderTarget);
		
			UpgradedLaserInShop.showUpgradedLaser(renderTarget);


			//Buy Option

			//Going back to the menu button
			if (ev.button.button == SDL_BUTTON_LEFT && SDL_MOUSEBUTTONUP)
			{
				x = ev.button.x;
				y = ev.button.y;
				//Upgraded Laser:

				//If the mouse is over the button
				if ((x > 325) && (x < 325 + 50) && (y > 140) && (y < 140 + 50))
				{

					//Get in the settings menu:
					if (coinsFromFille >= 100 && isItUpgraded == false)
					{
						coinsFromFille -= 100;
						isItUpgraded = true;
						
					}

					else if(coinsFromFille <= 100)
					{
						SDL_RenderCopy(renderTarget, nocoinsTexture, NULL, &noCoins_Rect);
					}
					
					//Show text that says laser is upgraded
				}

				//Health Regen:

				//If the mouse is over the button
				if ((x > 325) && (x < 325 + 50) && (y > 263) && (y < 263 + 50))
				{

					//Get in the settings menu:
					if (coinsFromFille >= 200 && playerHealth != 100)
					{
						coinsFromFille -= 200;
						playerHealth = 100;
					}

					else if (coinsFromFille <= 200)
					{
						SDL_RenderCopy(renderTarget, nocoinsTexture, NULL, &noCoins_Rect);
					}
				}

				//Slow zombie:

				//If the mouse is over the button
				if ((x > 348) && (x < 348 + 50) && (y > 370) && (y < 370 + 50))
				{
					//Show text that says slow zombie is purchased
					regularZombieUpdate = false;
				}

			}

			//Go back to the menu

			//If the mouse is over the button
			if ((x > 500 && (x < 500 + 100) && (y > 400) && (y < 400 + 50)))
			{

				//Get in the settings menu:
				inShop = false;
				inMenu = true;
			}
		}
	

	
		/***************************************SHOWING THE SHOP******************************************/
		if (inGame == true)
		{


			if (exitGame == true)
			{
				isRunning = false;
			}
			enviroment.drawEnviroment(renderTarget);

			player1.Draw(renderTarget);  //Draw first player
			zombie1.Draw(renderTarget);
			zombieText.ZombieTextDraw(renderTarget, text);
			playerText.PlayerTextDraw(renderTarget, text);

			SDL_RenderCopy(renderTarget, CoinsTextTexture, NULL, &CoinsTextRect);

			
			SDL_SetRenderDrawColor(renderTarget, 255, 255, 255, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLine(renderTarget, 320, 200, 300, 240);
			SDL_RenderDrawLine(renderTarget, 300, 240, 340, 240);
			SDL_RenderDrawLine(renderTarget, 340, 240, 320, 200);



			if (bKeyA == 1 && aTick % 10 == 1)
			{
				bullet.HandleInput(ammo, player1);
			}

			collision.PlayerBulletToZombieCollision(ammo, zombie1);
		

			zombieText.ZombieUpdateText(renderTarget, text, zombie1);
			playerText.PlayerUpdateText(renderTarget, text, player1);
			zombieBullet.Attack(renderTarget, zombie1);
		
			bullet.Draw(renderTarget, ammo);
			
			collision.ZombieBulletToPlayerCollision(zombieBullet, player1);

			if (timesWereHitted <= 3 && bricksAlive1st == true)
			{
				drawTheWall.drawWall(renderTarget, drawPosX, drawPosY);
			}
			else if (timesWereHitted >= 4)
			{
				bricksAlive1st = false;
				bricksAlive2nd = true;
			}

			if (timesWereHitted <= 7 && bricksAlive2nd == true)
			{
				drawSecondWall.drawWall(renderTarget, drawPosX, drawPosY);
			}
			else if (timesWereHitted >= 7)
			{
				bricksAlive2nd = false;
				bricksAlive3rd = true;
			}
			
			if (timesWereHitted <= 9 && bricksAlive3rd == true)
			{
				drawThirdWall.drawWall(renderTarget, drawPosX, drawPosY);
			}

			if (timesWereHitted >= 10)
			{
				bricksAlive3rd = false;
				bricksAlive1st = true;
				cantTouch = true;
				drawPosX = 0;
				drawPosY = 0;
				timesWereHitted = 0;

			}

		/*	
			if (zombieDrawBullet.IntersectwithWall(delta, keyState, ev, drawTheWall)) 
				{
					timesWereHitted += 1;
					
				}
		
	

			if (zombieDrawBullet.IntersectwithZombieBullet(player1))
			{
		
				explosionFromZombie.drawExplosionFromZombie(renderTarget, player1);
				

				playerHealth -= 3;
				playerHealthSTREAM.str("");
				playerHealthSTREAM << playerHealth;

				PlayerHealthSurface = TTF_RenderText_Solid(text, playerHealthSTREAM.str().c_str(), White);
				PlayerHealthTexture = SDL_CreateTextureFromSurface(renderTarget, PlayerHealthSurface);


				if (playerHealth <= 0)
				{
					gameOver = true;
					inGame = false;
					inMenu = true;
					inSettings = false;
					inShop = false;
				}
			}

			if (zombieDrawBulletVer2.IntersectwithZombieBulletVer2(player1))
			{
				explosionFromZombie.drawExplosionFromZombie(renderTarget, player1);
				playerHealth -= 5;
				playerHealthSTREAM.str("");
				playerHealthSTREAM << playerHealth;

				PlayerHealthSurface = TTF_RenderText_Solid(text, playerHealthSTREAM.str().c_str(), White);
				PlayerHealthTexture = SDL_CreateTextureFromSurface(renderTarget, PlayerHealthSurface);


				if (playerHealth <= 0)
				{
					gameOver = true;
					inGame = false;
					inMenu = false;
					inSettings = false;
					inShop = false;
				}
			}
			*/

	

			if (spawn2ndZombie && isPaused == false)
			{
				zombie2.Draw(renderTarget);
				//zombie2nd.Draw(renderTarget);
				//zombieDrawBullet.DrawBullet4Zombie(renderTarget, zombie2nd, keyState);
			}

			if (spawn3rdZombie && isPaused == false)
			{
				zombie3.Draw(renderTarget);
				//zombie3rd.Draw(renderTarget);
				//zombieDrawBulletVer2.DrawBullet4ZombieVer2(renderTarget, zombie3rd, keyState);
			}
			
			

			if (laserBullet == true && isPaused == false )
			{
				Laser.drawLaser(renderTarget, player1, keyState);
			}

			if (upgradedLaserBullet == true && isItUpgraded == true && isPaused == false)
			{
				UpgradedLaser.drawUpgradedLaser(renderTarget, player1, keyState);
			}
			
			if (isgamewin == true)
			
			{
				gameWin.win(renderTarget);
				secondfirework.win(renderTarget);
			}
			

}

		//Upgraded Laser 3RD
/*
		if (UpgradedLaser.IntersectwithUpgradedLaser(zombie3rd) == true)
		{
			Mix_PlayChannel(5, hitmarker, 0); //Hitmarker sound effect
			explosion.drawExplosion(renderTarget, zombie3rd);

			//Coins
			coinsFromFille++;
			writeFile.clear();
			writeFile.open("coins.txt", std::fstream::in | std::fstream::out | std::fstream::app);

			writeFile << coinsFromFille;
			writeFile << "\n";
			writeFile.close();



			coinstream.str("");
			coinstream << coinsFromFille++;

			CoinSurface = TTF_RenderText_Solid(text, coinstream.str().c_str(), White);
			CoinTexture = SDL_CreateTextureFromSurface(renderTarget, CoinSurface);

			if (zombieHealth <= 0)
			{
				zombieHealth = 100;
				zombiehealthSTREAM << zombieHealth + 100;
				spawn3rdZombie = false;
				isgamewin = true;

			}
		}
		*/
		if (isPaused == false)
		{
			//Keyboard events
			if (inGame == true)
			{
				keyState = SDL_GetKeyboardState(NULL);
				player1.Update(delta, keyState, ev);
				if (regularZombieUpdate == true)
				{
					zombie1.Update(zombie1, delta, lastTime, currentTime);
					if (spawn2ndZombie == true)
					{
						//zombie2.Update(zombie2, delta, lastTime, currentTime);
					}
					if (spawn3rdZombie == true)
					{
						//zombie3.Update(zombie3, delta, lastTime, currentTime);
					}

				}
				else

				{
					slowZombieUpdate = true;
				}


				if (slowZombieUpdate == true)
				{
					currentTime = SDL_GetTicks();

					if (currentTime > lastTime + 550)
					{
						lastTime = currentTime;

						//zombie.UpdateZombie(delta, keyState, ev, zombie);
						if (spawn2ndZombie == true)
						{
							//zombie2nd.UpdateZombie(delta, keyState, ev, zombie2nd);
						}
						if (spawn3rdZombie == true)
						{
							//zombie3rd.UpdateZombie(delta, keyState, ev, zombie3rd);
						}
					}
				}
			
				if (spawn2ndZombie == true)
				{
					//zombie2.Update(zombie2, delta, lastTime, currentTime);
				}

				if (spawn3rdZombie == true)
				{
					//zombie3.Update(zombie3, delta, lastTime, currentTime);
				}

				if (isgamewin == true)
				{
					gameWin.updateWin(delta, keyState, ev, gameWin);
					secondfirework.updateWin(delta, keyState, ev, gameWin);
				}
			}

			if (FireTheLaser == true)
			{
				Mix_PlayChannel(2, laser_sound, 0);
				FireTheLaser = false;
				laserBullet = true;
			}

			if (FireTheBullet == true)
			{
				//Mix_PlayChannel(1, fire_bullet, 0);
				FireTheBullet = false;
				regularBullet = true;
			}

			if (FireTheUpgradedLaser == true)
			{
				Mix_PlayChannel(3, upgradedLaser_sound, 0); //Hitmarker sound effect
				FireTheUpgradedLaser = false;
				upgradedLaserBullet = true;
			}
		}
		if (isPaused == true)
		{
			inGame = false;
			inMenu = false;
			inSettings = false;
			inShop = true;
		}

		if (SDL_QUIT)
		{
			myfile.open("coins.txt");

		}

		SDL_RenderPresent(renderTarget);

		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
				isRunning = false;
			else if (ev.type == SDL_KEYUP)
			{
				switch (ev.key.keysym.sym)
				{
				case SDLK_f:
					FireTheBullet = true;
					bKeyA = 0;
					break;
				case SDLK_e:
					FireTheUpgradedLaser = true;
					break;
				case SDLK_q:
					FireTheLaser = true;
					break;
				case SDLK_p:
					isPaused = true;
					break;
				case SDLK_c:
					inGame = true;
					isPaused = false;
					break;
				case SDLK_x:
					if (gameOver == true)
					{
						gameOverExit = true;
					}
					break;
					//Ultimate testing button :D
				case SDLK_r:
					break;
				case SDLK_ESCAPE:
					exitGame = true;
				}
			}
			else if (ev.type == SDL_KEYDOWN)
			{
				switch (ev.key.keysym.sym)
				{
				case SDLK_f:
					bKeyA = 1;
					break;
				}
			}
			else if (ev.type == SDL_MOUSEBUTTONDOWN && SDL_MOUSEMOTION && inGame && cantTouch == true)
			{
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					if (y > 424)
					{
						drawPosX = ev.button.x;
						drawPosY = ev.button.y;
						drawIt = true;
						cantTouch = false;
					}
				}
				// do something
				else if (ev.button.button == SDL_BUTTON_RIGHT)
				{

				}
				if (SDL_MOUSEMOTION)
				{

				}
				// do something
			}
		}

}

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_DestroyRenderer(renderTarget);


	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}
