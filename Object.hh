#pragma once 
#include <iostream>
#include "GameElements.hh"

using namespace std;

class Object : public GameElements{
	public:
		Object(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h);
		~Object();

		virtual void render(SDL_Renderer* renderer);
		virtual void catchObject(int **screen) = 0;

		bool getCaught(){return caught;}
		bool getExist(){return exist;}
		int getPoint(){return point;}

		void newPos(int **screen);
		bool occupe(int **screen);

	protected:
		bool caught = false;		//indique si l'objet est attrapé
		bool exist = true;		//indique l'existence de l'objet
		int point;		//Les points ajoutés ou retirés au joueur lors de la capture de l'objet

};