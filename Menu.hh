#pragma once
#include <iostream>
#include "Game.hh"

class Map;

class Menu{
	public:
		//Constructeur
		Menu();

		//Destructeur
		~Menu();

		//Fonctions Membres
		bool update();
		void render();

	private:
		Map* map;
		SDL_Texture* start;
		SDL_Texture* menu;
		SDL_Rect destStart, destMenu;
};