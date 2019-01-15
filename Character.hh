#pragma once
#include <iostream>
#include "GameElements.hh"


class Character : public GameElements{
	public:
		//Constructeur
		Character(SDL_Texture* objTexture, int x, int y, int w, int h) : GameElements(objTexture,x,y,w,h){}

		//Destructeur
		~Character();

		//Fonctions Membres
		virtual void render(SDL_Renderer* renderer);
		int getX(){return _x;}
		int getY(){return _y;}

	protected:
		
};
