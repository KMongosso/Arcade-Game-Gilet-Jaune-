#pragma once 
#include <iostream>
#include "Object.hh"


using namespace std;

class Projectile : public Object{
	public:
		//Constructeur
		Projectile(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h, int xplayer, int yplayer);
		
		//Destructeur
		~Projectile();

		//Fonctions Membres
		virtual void update(int **screen);
		virtual void catchObject(int **screen);

		void updatePos(int **screen);

		static int duree;		//Duree d'apparition à l'écran

	private:
		int pente; 		//Pente de la droite reliant le projectile dans sa position de départ et le joueur
		int dirx;		//Direction de déplacement horizontal du projectile
		int diry;		//Direction de déplacement vertical du projectile
};