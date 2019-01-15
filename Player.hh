#pragma once
#include <iostream>
#include "Character.hh"
#include "Game.hh"
#include <map>


using namespace std;

class Player : public Character{
	public:
		//Constructeur
		Player(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h);

		//Destructeur
		~Player();

		//Fonctions Membres
		virtual void update(int **screen);

		bool getDamage(){return damage;}
		map <string,int>getOldData(){return playerOldData;}
		map <string,int>getData(){return playerData;}
		
		void updateEvent2KEYDOWN();
		void updateEventKEYDOWN();
 		void updateEventKEYUP();

 		static map <string,int> playerData;		//Map contenant les informations du joueur (point de vie et score)
 		static map <string,int> playerOldData;		//Map contenant les informations du joueur à l'itération du jeu précédente (sert à afficher les évolutions du score et des points de vie)


	protected:
		bool *dir;		//Direction dans laquelle se déplace le joueur
		bool damage=0;		//Indique si le joueur est touché par un ennemi
};
