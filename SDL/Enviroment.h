#pragma once
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include "Player.h"
#include <string>
using namespace std;
class Enviroment
{
public:
	Enviroment(SDL_Renderer *renderTarget, std::string filePath, int x, int y);
	~Enviroment();

	void drawEnviroment(SDL_Renderer *renderTarget);
	void drawBarrel(SDL_Renderer * renderTarget);
	void drawWall(SDL_Renderer * renderTarget);

private:
	SDL_Texture *texture;
};
