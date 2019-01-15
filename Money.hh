#pragma once 
#include <iostream>
#include "Object.hh"
#include "Game.hh"


using namespace std;

class Money : public Object{
	public:
		//Constructeur
		Money(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h);

		//Destructeur
		~Money();

		//Fonctions membres
		virtual void update(int **screen);
		virtual void catchObject(int **screen);

	private: 
		int duree; 	//Duree d'affichage 
		int iter;	//Nombre d'iteration où l'item est affiché

};