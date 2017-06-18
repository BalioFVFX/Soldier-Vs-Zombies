#include "Text.h"




Text::Text(SDL_Renderer * renderTarget, TTF_Font * text)
{
	//Zombie Text
	zombieHealthRect.x = 500;
	zombieHealthRect.y = 25;
	zombieHealthRect.w = 100;
	zombieHealthRect.h = 40;

	//Zombie Digit Text
	zombieHealthTextRect.x = 330;
	zombieHealthTextRect.y = 20;
	zombieHealthTextRect.w = 150;
	zombieHealthTextRect.h = 50;


	ZombieHealthTextSurface = TTF_RenderText_Solid(text, "Zombie Health ::", White);
	ZombieHealthTextTexture = SDL_CreateTextureFromSurface(renderTarget, ZombieHealthTextSurface);
	ZombieHealthSurface = TTF_RenderText_Solid(text, zombieHealthSTREAM.str().c_str(), White);
	ZombieHealthTexture = SDL_CreateTextureFromSurface(renderTarget, ZombieHealthSurface);

	playerHealthRect.x = 140;
	playerHealthRect.y = 25;
	playerHealthRect.w = 100;
	playerHealthRect.h = 40;

	playerHealthTextRect.x = 20;
	playerHealthTextRect.y = 25;
	playerHealthTextRect.w = 100;
	playerHealthTextRect.h = 40;

	PlayerHealthTextSurface = TTF_RenderText_Solid(text, "Player Health ::", White);
	PlayerHealthTextTexture = SDL_CreateTextureFromSurface(renderTarget, PlayerHealthTextSurface);
	PlayerHealthSurface = TTF_RenderText_Solid(text, playerHealthSTREAM.str().c_str(), White);
	PlayerHealthTexture = SDL_CreateTextureFromSurface(renderTarget, PlayerHealthSurface);


}

Text::~Text()
{
	TTF_Quit();
}


void Text::ZombieTextDraw(SDL_Renderer * renderTarget, TTF_Font * text)
{
	
	SDL_RenderCopy(renderTarget, ZombieHealthTextTexture, NULL, &zombieHealthTextRect);
	SDL_RenderCopy(renderTarget, ZombieHealthTexture, NULL, &zombieHealthRect);
}

void Text::ZombieUpdateText(SDL_Renderer * renderTarget, TTF_Font * text, Zombie &zombie)
{
	if (zombie.hit == true)
	{
		//if (zombie.alive == true) If Zombie Gets Killed HP Is Staying At 10
		//{
			zombieHealthSTREAM.str("");
			zombieHealthSTREAM << zombie.health;

			ZombieHealthSurface = TTF_RenderText_Solid(text, zombieHealthSTREAM.str().c_str(), White);
			ZombieHealthTexture = SDL_CreateTextureFromSurface(renderTarget, ZombieHealthSurface);
			zombie.hit = false;
		//}
	}
}

void Text::PlayerTextDraw(SDL_Renderer * renderTarget, TTF_Font * text)
{
	SDL_RenderCopy(renderTarget, PlayerHealthTextTexture, NULL, &playerHealthTextRect);
	SDL_RenderCopy(renderTarget, PlayerHealthTexture, NULL, &playerHealthRect);
}

void Text::PlayerUpdateText(SDL_Renderer * renderTarget, TTF_Font * text, Player & player)
{
	if (player.hit == true)
	{
		//if (zombie.alive == true) If Zombie Gets Killed HP Is Staying At 10
		//{
		playerHealthSTREAM.str("");
		playerHealthSTREAM << player.health;

		PlayerHealthSurface = TTF_RenderText_Solid(text, playerHealthSTREAM.str().c_str(), White);
		PlayerHealthTexture = SDL_CreateTextureFromSurface(renderTarget, PlayerHealthSurface);
		player.hit = false;
		//}
	}
}

void Text::CoinsTextDraw(SDL_Renderer * renderTarget, TTF_Font * text)
{

}

void Text::CoinsUpdateText(SDL_Renderer * renderTarget, TTF_Font * text)
{
}
