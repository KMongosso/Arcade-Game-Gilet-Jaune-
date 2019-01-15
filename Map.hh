#pragma once
#include "Game.hh"

class Menu;

class Map{
	public:
		//Constructeur
		Map();

		//Destructeur
		~Map();

		//Fonctions Membres
		void LoadMap(int arr[20][20]);
		void Draw();
	private:
		SDL_Rect src, dest,destP;
		SDL_Texture* brown;
		SDL_Texture* green;
		SDL_Texture* blue;
		SDL_Texture* black;
		SDL_Texture* white;
		SDL_Texture* yellow;
		SDL_Texture* purple;
		SDL_Texture* red;
		SDL_Texture* paris;

		int map[20][20];
};