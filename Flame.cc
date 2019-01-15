#include "Flame.hh"

int Flame::duree;

//////////////////*Constructeur*//////////////////

Flame::Flame(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h):Object(screen,objTexture,x,y,w,h){
	updateScreen(screen,2);
	duree = 1000;
	point = -5;
}

//////////////////*Destructeur*//////////////////

Flame::~Flame(){
	
}

//////////////////*Fonctions Membres*//////////////////


/* Met à jour l'item "Flame" :
	- si le nombre d'iteration atteint la duree d'apparition de l'objet, il disparait (1)
	- si il n'est pas attrapé, on met à jour la grille représentant l'écran (2)
	- si il est attrapé, l'objet disparait (3)
*/
void Flame::update(int **screen){
	iter++;

	if(iter==duree){	//(1)
		exist=false;
		updateScreen(screen,0);
	}

	if(!caught)		//(2)
		updateScreen(screen,2);

	else		//(3)
		exist = false;
}

/* Détermine si l'item est attrapé */
void Flame::catchObject(int **screen){
	for(int i=_y;i<_y+destRect.h;i++){
		for(int j=_x;j<_x+destRect.w;j++){
			if(screen[j][i]==1)		//l'écran est occupé par le joueur
				caught=true;
		}
	}
}