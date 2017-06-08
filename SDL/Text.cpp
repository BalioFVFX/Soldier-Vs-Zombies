#include "Text.h"




Text::Text(SDL_Renderer * renderTarget, TTF_Font * text)
{
	ZombieHealthRect.x = 100;
	ZombieHealthRect.y = 100;
	ZombieHealthRect.w = 70;
	ZombieHealthRect.h = 70;

	healthTextRectche.x = 200;
	healthTextRectche.y = 200;
	healthTextRectche.w = 50;
	healthTextRectche.h = 50;
	ZombieHealthTextSurfaceche = TTF_RenderText_Solid(text, "Zombie Healthche::", White);
	ZombieHealthTextTextureche = SDL_CreateTextureFromSurface(renderTarget, ZombieHealthTextSurfaceche);
	ZombieHealthSurface = TTF_RenderText_Solid(text, zombiehealthSTREAM.str().c_str(), White);
	ZombieHealthTexture = SDL_CreateTextureFromSurface(renderTarget, ZombieHealthSurface);
}

Text::~Text()
{
	TTF_Quit();
}


void Text::TextDraw(SDL_Renderer * renderTarget, TTF_Font * text)
{
	
	SDL_RenderCopy(renderTarget, ZombieHealthTextTextureche, NULL, &healthTextRectche);
	SDL_RenderCopy(renderTarget, ZombieHealthTexture, NULL, &ZombieHealthRect);
}

void Text::UpdateText(SDL_Renderer * renderTarget, TTF_Font * text, Zombie &zombie)
{
	if (zombie.alive == true)
	{
		zombiehealthSTREAM.str("");
		zombiehealthSTREAM << zombie.health;

		ZombieHealthSurface = TTF_RenderText_Solid(text, zombiehealthSTREAM.str().c_str(), White);
		ZombieHealthTexture = SDL_CreateTextureFromSurface(renderTarget, ZombieHealthSurface);
	}
}
