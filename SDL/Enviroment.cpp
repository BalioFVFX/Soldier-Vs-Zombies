#include "Enviroment.h"

Enviroment::Enviroment(SDL_Renderer * renderTarget, std::string filePath, int x, int y)
{
	SDL_Surface *surface = IMG_Load(filePath.c_str());

	texture = SDL_CreateTextureFromSurface(renderTarget, surface);

}

Enviroment::~Enviroment()
{
}

void Enviroment::drawEnviroment(SDL_Renderer * renderTarget)
{
	SDL_RenderCopy(renderTarget, texture, NULL, NULL);
}

void Enviroment::drawBarrel(SDL_Renderer * renderTarget)
{
	SDL_RenderCopy(renderTarget, texture, NULL, NULL);
}

void Enviroment::drawWall(SDL_Renderer * renderTarget)
{
	SDL_RenderCopy(renderTarget, texture, NULL, NULL);
}
