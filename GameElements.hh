#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class GameElements {
	public:
		//Constructeur
		GameElements(SDL_Texture* objTexture,int x, int y, int w, int h);
		
		//Destructeur
		~GameElements();

		//Fonctions Membres
		virtual void update(int **screen) = 0;
		virtual void render(SDL_Renderer* renderer) = 0;

		void resetPos();
		void updateScreen(int **screen,int val);

	protected:
		 int _x;	//Postion horizontal
		 int _y;	//Position vertical

		 SDL_Rect srcRect, destRect;
		 SDL_Texture* _objTexture;
};
