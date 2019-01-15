#pragma once 
#include <iostream>
#include "Object.hh"
#include "Game.hh"


using namespace std;

class Flame : public Object{
	public:
		//Constructeur
		Flame(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h);

		//Destructeur
		~Flame();

		//Fnctions Membres
		virtual void update(int **screen);
		virtual void catchObject(int **screen);

		static int duree;	//duree d'apparition de l'item

	private:
		int iter;		//nombre d'iteration où l'item est affiché
};