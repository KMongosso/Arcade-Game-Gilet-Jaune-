#pragma once
#include <iostream>
#include "Character.hh"

using namespace std;

class Ennemy : public Character{
	public:
		//Constructeur
		Ennemy(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h);

		//Destructeur
		~Ennemy();

		//Fonctions Membres
		virtual void update(int **screen);
		void leftEnnemyUpdate(int **screen);
		void rightEnnemyUpdate(int **screen);
		void topEnnemyUpdate(int **screen);
		void bottomEnnemyUpdate(int **screen);

	protected:
		bool active;	//indique si l'ennemi est sur l'écran et donc existe
		bool back;		//indique si l'ennemi est en train de ressortir de l'écran
		int dir;		//indique l'endroit où est l'ennemi 
};
