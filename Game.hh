#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.hh"
#include "Player.hh"
#include "Ennemy.hh"
#include "Map.hh"
#include "Menu.hh"
#include "Flame.hh"
#include "Gas.hh"
#include "Money.hh"
#include "Projectile.hh"
#include <list>
#include <stdlib.h>
#include <time.h>
#include <SDL2_Mixer/SDL_Mixer.h>
#include <map>
#include <string>
#include <SDL2/SDL_ttf.h>

/*https://freesound.org/people/joshuaempyre/sounds/251461/*/

using namespace std;

class Player;
//class Object;

class Game{
	public:
		//Constructeur
		Game(const char* title, int x, int y, int width, int height);

		//Destructeur
		~Game();

		//Fonctions Membres
		void sdlInit(const char* title, int x, int y, int width, int height);
		void gameElementsInit();
		void textureInit();
		void handleEvent();

		void update();
		void playerUpdate();
		void menuUpdate();
		void ennemyUpdate();
		void gameObjectsUpdate();

		void addNewFlame();
		void addNewStack();

		void render();

		bool getRunning(){return isRunning;}
		string getInfo(){return info_string;}
		Player* getPlayer(){return player;}

		static SDL_Renderer* renderer;
		static SDL_Event event;

		static TTF_Font *police;
		static SDL_Surface *text;
		static SDL_Rect destText;

	private:
		int _width,_height;		//Dimensions de l'écran

		SDL_Window *window;
		int **screen;		//Informations relatives à l'écran

		bool isRunning;		//Indique si le jeu est toujours en cours
	    int affichage=0;		//Indique ce qu'il faut afficher
	    int iterA=0,iterF=0,iterE=0, iterTot=0, iterEnd=0,newA,newF,newE, ennemyFrequency, flameFrequency;		//Itérations et fréquences d'apparition

	    list <Object *> gameObjects;		//Liste d'objet
	    list <Ennemy *> gameEnnemyes;		//Liste d'ennemie
	    list <Projectile *> gameProjectiles;		//Liste de projectile

	    SDL_Texture* PlayerText;
	   	SDL_Texture* EnnemyText; 
	    SDL_Texture* FlameText;
	    SDL_Texture* GasText;
	    SDL_Texture* MoneyText;
	    SDL_Texture* ProjectileText;

	    string info_string;
	    const char *info_char;

	    Player* player;

};



