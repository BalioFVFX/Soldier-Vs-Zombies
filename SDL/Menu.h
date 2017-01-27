#pragma once
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <SDL\SDL_ttf.h>
#include <string>
class Menu
{
public:
	Menu(SDL_Renderer *renderTarget, std::string filePath, int x, int y);
	~Menu();

	void showMenu(SDL_Renderer *renderTarget);
	void shopwShop(SDL_Renderer *renderTarget);
	void showGameOver(SDL_Renderer * renderTarget);
	void playButton(SDL_Renderer *renderTarget);
	void shopButton(SDL_Renderer *renderTarget);
	void settingsButton(SDL_Renderer *renderTarget);
	void exitButton(SDL_Renderer *renderTarget);
	void settingsMenu(SDL_Renderer *renderTarget);
	void isGreyPlay(SDL_Renderer *renderTarget);
	void isGreySettings(SDL_Renderer *renderTarget, SDL_Event ev);
	void isGreyExit(SDL_Renderer *renderTarget);
	void inSettings(SDL_Renderer *renderTarget);
	void drawVolumeIcon(SDL_Renderer *renderTarget);
	bool exitMenu(Uint8 *keystate);
	void renderText(SDL_Renderer *renderTarget);
	void showUpgradedLaser(SDL_Renderer * renderTarget);

	int x = 0;
	int y = 0;

	SDL_Rect playButtonRect;
private:
	SDL_Texture *texture;
	SDL_Scancode buttonsforexit[5];
	
	
};
