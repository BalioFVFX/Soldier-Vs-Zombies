#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(SDL_Renderer * renderTarget, std::string filePath, int x, int y)
{
	SDL_Surface *surface = IMG_Load(filePath.c_str());

	texture = SDL_CreateTextureFromSurface(renderTarget, surface);

	buttonsforexit[0] = SDL_SCANCODE_ESCAPE;

}

Menu::~Menu()
{
}

void Menu::showMenu(SDL_Renderer * renderTarget)
{
	SDL_RenderCopy(renderTarget, texture, NULL, NULL);
}

void Menu::shopwShop(SDL_Renderer * renderTarget)
{
	SDL_RenderCopy(renderTarget, texture, NULL, NULL);
}

void Menu::showGameOver(SDL_Renderer * renderTarget)
{
	SDL_RenderCopy(renderTarget, texture, NULL, NULL);
}


void Menu::playButton(SDL_Renderer * renderTarget)
{
	playButtonRect.x = 257;
	playButtonRect.y = 100;
	playButtonRect.w = 120;
	playButtonRect.h = 45;

	SDL_RenderCopy(renderTarget, texture, NULL, &playButtonRect);
}

void Menu::shopButton(SDL_Renderer * renderTarget)
{
	SDL_Rect shopButton;
	shopButton.x = 235;
	shopButton.y = 150;
	shopButton.w = 150;
	shopButton.h = 75;

	SDL_RenderCopy(renderTarget, texture, NULL, &shopButton);
}

void Menu::settingsButton(SDL_Renderer * renderTarget)
{
	SDL_Rect settingsButton;
	settingsButton.x = 257;
	settingsButton.y = 240;
	settingsButton.w = 120;
	settingsButton.h = 45;

	SDL_RenderCopy(renderTarget, texture, NULL, &settingsButton);
}

void Menu::exitButton(SDL_Renderer * renderTarget)
{
	SDL_Rect exitButton;
	exitButton.x = 257;
	exitButton.y = 310;
	exitButton.w = 120;
	exitButton.h = 45;

	SDL_RenderCopy(renderTarget, texture, NULL, &exitButton);
}

void Menu::settingsMenu(SDL_Renderer * renderTarget)
{
	SDL_RenderCopy(renderTarget, texture, NULL, NULL);
}

void Menu::isGreyPlay(SDL_Renderer *renderTarget)
{
	SDL_Rect playButton;

	playButton.x = 257;
	playButton.y = 100;
	playButton.w = 120;
	playButton.h = 45;

	SDL_RenderCopy(renderTarget, texture, NULL, &playButton);
}


void Menu::isGreySettings(SDL_Renderer *renderTarget, SDL_Event ev)
{
	SDL_Rect settingsButton;
	settingsButton.x = 257;
	settingsButton.y = 240;
	settingsButton.w = 120;
	settingsButton.h = 45;

	//make the button green
	SDL_RenderCopy(renderTarget, texture, NULL, &settingsButton);

}

void Menu::isGreyExit(SDL_Renderer *renderTarget)
{
	SDL_Rect exitButton;
	exitButton.x = 257;
	exitButton.y = 310;
	exitButton.w = 120;
	exitButton.h = 45;

	SDL_RenderCopy(renderTarget, texture, NULL, &exitButton);
	
}

void Menu::inSettings(SDL_Renderer * renderTarget)
{
		SDL_RenderCopy(renderTarget, texture, NULL, NULL);
}

void Menu::drawVolumeIcon(SDL_Renderer * renderTarget)
{
	SDL_Rect volume;
	volume.x = 50;
	volume.y = 100;
	volume.w = 70;
	volume.h = 70;

	SDL_RenderCopy(renderTarget, texture, NULL, &volume);
}

bool Menu::exitMenu(Uint8 *keystate)
{
	if (keystate[buttonsforexit[0]])
	{
		SDL_Quit();
		return true;
	}
}

void Menu::renderText(SDL_Renderer * renderTarget)
{
	TTF_Init();
	TTF_Font* text = TTF_OpenFont("batmfa__.ttf", 24);
	SDL_Color White = { 255, 255, 255 };
	
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(text, "Volume: ", White); 
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderTarget, surfaceMessage); 
	
	SDL_Surface* minimalRender = TTF_RenderText_Solid(text, "Low", White);
	SDL_Texture* lowMessage = SDL_CreateTextureFromSurface(renderTarget, minimalRender); 

	SDL_Surface* mediumRender = TTF_RenderText_Solid(text, "Medium", White);
	SDL_Texture* mediumMessage = SDL_CreateTextureFromSurface(renderTarget, mediumRender); 

	SDL_Surface* highRender = TTF_RenderText_Solid(text, "High", White);
	SDL_Texture* highMessage = SDL_CreateTextureFromSurface(renderTarget, highRender); 

	SDL_Surface* menuRender = TTF_RenderText_Solid(text, "Menu", White);
	SDL_Texture* menuMessage = SDL_CreateTextureFromSurface(renderTarget, menuRender); 
	
	SDL_Rect Message_rect; //create a rect
	SDL_Rect Low_Rect;
	SDL_Rect Medium_Rect;
	SDL_Rect High_Rect;
	SDL_Rect Menu_Rect;

	Message_rect.x = 10; 
	Message_rect.y = 50; 
	Message_rect.w = 150; 
	Message_rect.h = 50;

	Low_Rect.x = 200;  
	Low_Rect.y = 50; 
	Low_Rect.w = 100; 
	Low_Rect.h = 50; 

	Medium_Rect.x = 350;  
	Medium_Rect.y = 50; 
	Medium_Rect.w = 100; 
	Medium_Rect.h = 50; 

	High_Rect.x = 500;  
	High_Rect.y = 50;
	High_Rect.w = 100; 
	High_Rect.h = 50;

	Menu_Rect.x = 265;  
	Menu_Rect.y = 350;
	Menu_Rect.w = 100; 
	Menu_Rect.h = 50;


	
	SDL_RenderCopy(renderTarget, Message, NULL, &Message_rect);
	SDL_RenderCopy(renderTarget, lowMessage, NULL, &Low_Rect);
	SDL_RenderCopy(renderTarget, mediumMessage, NULL, &Medium_Rect);
	SDL_RenderCopy(renderTarget, highMessage, NULL, &High_Rect);
	SDL_RenderCopy(renderTarget, menuMessage, NULL, &Menu_Rect);

}


void Menu::showUpgradedLaser(SDL_Renderer * renderTarget)
{

	SDL_Rect Menu_Rect;

	Menu_Rect.x = 500;
	Menu_Rect.y = 400;
	Menu_Rect.w = 100;
	Menu_Rect.h = 50;

	TTF_Font* text = TTF_OpenFont("batmfa__.ttf", 24);
	SDL_Color White = { 255, 255, 255 };
	SDL_Surface* menuRender = TTF_RenderText_Solid(text, "Menu", White);
	SDL_Texture* menuMessage = SDL_CreateTextureFromSurface(renderTarget, menuRender);

	SDL_RenderCopy(renderTarget, menuMessage, NULL, &Menu_Rect);
}
