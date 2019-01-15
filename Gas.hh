#pragma once 
#include <iostream>
#include "Object.hh"
#include "Game.hh"


using namespace std;

class Gas : public Object{
	public:
		//Constructeur
		Gas(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h);
		
		//Destructeur
		~Gas();

		//Fonctions Membres
		virtual void update(int **screen);
		virtual void catchObject(int **screen);

};