#include "Text.h"



Text::Text()
{

}

Text::~Text()
{
}


void Text::TextDraw(SDL_Renderer * renderTarget, TTF_Font * text)
{
	healthTextRectche.x = 200;
	healthTextRectche.y = 200;
	healthTextRectche.w = 50;
	healthTextRectche.h = 50;
	ZombieHealthTextSurfaceche = TTF_RenderText_Solid(text, "Zombie Healthche::", White);
	ZombieHealthTextTextureche = SDL_CreateTextureFromSurface(renderTarget, ZombieHealthTextSurfaceche);
	SDL_RenderCopy(renderTarget, ZombieHealthTextTextureche, NULL, &healthTextRectche);
}
